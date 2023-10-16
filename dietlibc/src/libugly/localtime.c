/* Convert timestamp from time_t to struct tm.  */

/*
** This file is in the public domain, so clarified as of
** 1996-06-05 by Arthur David Olson.
*/

/*
** Leap second handling from Bradley White.
** POSIX-style TZ environment variable handling from Guy Harris.
*/

/*LINTLIBRARY*/

#define LOCALTIME_IMPLEMENTATION
#include "private.h"

#include "tzfile.h"
#include <fcntl.h>

static int lock(void) { return 0; }
static void unlock(void) { }

#ifndef TZ_ABBR_CHAR_SET
# define TZ_ABBR_CHAR_SET \
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 :+-._"
#endif /* !defined TZ_ABBR_CHAR_SET */

#ifndef TZ_ABBR_ERR_CHAR
# define TZ_ABBR_ERR_CHAR    '_'
#endif /* !defined TZ_ABBR_ERR_CHAR */

/*
+** Support non-POSIX platforms that distinguish between text and binary files.
*/

#ifndef O_BINARY
# define O_BINARY 0
#endif

#ifndef WILDABBR
/*
** Someone might make incorrect use of a time zone abbreviation:
**  1.  They might reference tzname[0] before calling tzset (explicitly
**      or implicitly).
**  2.  They might reference tzname[1] before calling tzset (explicitly
**      or implicitly).
**  3.  They might reference tzname[1] after setting to a time zone
**      in which Daylight Saving Time is never observed.
**  4.  They might reference tzname[0] after setting to a time zone
**      in which Standard Time is never observed.
**  5.  They might reference tm.TM_ZONE after calling offtime.
** What's best to do in the above cases is open to debate;
** for now, we just set things up so that in any of the five cases
** WILDABBR is used. Another possibility: initialize tzname[0] to the
** string "tzname[0] used before set", and similarly for the other cases.
** And another: initialize tzname[0] to "ERA", with an explanation in the
** manual page of what this "time zone abbreviation" means (doing this so
** that tzname[0] has the "normal" length of three characters).
*/
# define WILDABBR    "   "
#endif /* !defined WILDABBR */

static const char       wildabbr[] = WILDABBR;

static char const etc_utc[] = "Etc/UTC";
static char const *utc = etc_utc + sizeof "Etc/" - 1;

/*
** The DST rules to use if TZ has no rules and we can't load TZDEFRULES.
** Default to US rules as of 2017-05-07.
** POSIX does not specify the default DST rules;
** for historical reasons, US rules are a common default.
*/
#ifndef TZDEFRULESTRING
# define TZDEFRULESTRING ",M3.2.0,M11.1.0"
#endif

struct ttinfo {              /* time type information */
    int_fast32_t tt_utoff; /* UT offset in seconds */
    bool         tt_isdst;   /* used to set tm_isdst */
    int          tt_desigidx; /* abbreviation list index */
    bool         tt_ttisstd; /* transition is std time */
    bool         tt_ttisut; /* transition is UT */
};

struct lsinfo {              /* leap second information */
    time_t       ls_trans;   /* transition time */
    int_fast32_t ls_corr;    /* correction to apply */
};

/* This abbreviation means local time is unspecified.  */
static char const UNSPEC[] = "-00";

/* How many extra bytes are needed at the end of struct state's chars array.
   This needs to be at least 1 for null termination in case the input
   data isn't properly terminated, and it also needs to be big enough
   for ttunspecified to work without crashing.  */
enum { CHARS_EXTRA = max(sizeof UNSPEC, 2) - 1 };

/* Limit to time zone abbreviation length in POSIX-style TZ strings.
   This is distinct from TZ_MAX_CHARS, which limits TZif file contents.  */
#ifndef TZNAME_MAXIMUM
# define TZNAME_MAXIMUM 255
#endif

struct state {
    int           leapcnt;
    int           timecnt;
    int           typecnt;
    int           charcnt;
    bool          goback;
    bool          goahead;
    time_t        ats[TZ_MAX_TIMES];
    unsigned char types[TZ_MAX_TIMES];
    struct ttinfo ttis[TZ_MAX_TYPES];
    char chars[max(max(TZ_MAX_CHARS + CHARS_EXTRA, sizeof "UTC"),
		         2 * (TZNAME_MAXIMUM + 1))];
    struct lsinfo lsis[TZ_MAX_LEAPS];
    /* The time type to use for early times or if no transitions.
       It is always zero for recent tzdb releases.
       It might be nonzero for data from tzdb 2018e or earlier.  */
    int defaulttype;
};

static struct tm *gmtsub(struct state const *, time_t const *, int_fast32_t,
			 struct tm *);
static bool increment_overflow(int *, int);
static bool increment_overflow_time(time_t *, int_fast32_t);
static bool normalize_overflow32(int_fast32_t *, int *, int);
static struct tm *timesub(time_t const *, int_fast32_t, struct state const *,
			  struct tm *);

#ifdef ALL_STATE
static struct state * lclptr;
static struct state * gmtptr;
#endif /* defined ALL_STATE */

#ifndef ALL_STATE
static struct state lclmem;
static struct state gmtmem;
static struct state *const lclptr = &lclmem;
static struct state *const gmtptr = &gmtmem;
#endif /* State Farm */

#ifndef TZ_STRLEN_MAX
# define TZ_STRLEN_MAX 255
#endif /* !defined TZ_STRLEN_MAX */

/*
** Section 4.12.3 of X3.159-1989 requires that
**  Except for the strftime function, these functions [asctime,
**  ctime, gmtime, localtime] return values in one of two static
**  objects: a broken-down time structure and an array of char.
** Thanks to Paul Eggert for noting this.
**
** This requirement was removed in C99, so support it only if requested,
** as support is more likely to lead to bugs in badly written programs.
*/

char *			tzname[2] = {
	(char *) wildabbr,
	(char *) wildabbr
};

long			timezone;

/* Initialize *S to a value based on UTOFF, ISDST, and DESIGIDX.  */
static void
init_ttinfo(struct ttinfo *s, int_fast32_t utoff, bool isdst, int desigidx)
{
  s->tt_utoff = utoff;
  s->tt_isdst = isdst;
  s->tt_desigidx = desigidx;
  s->tt_ttisstd = false;
  s->tt_ttisut = false;
}

/* Return true if SP's time type I does not specify local time.  */
static bool
ttunspecified(struct state const *sp, int i)
{
  char const *abbr = &sp->chars[sp->ttis[i].tt_desigidx];
  /* memcmp is likely faster than strcmp, and is safe due to CHARS_EXTRA.  */
  return memcmp(abbr, UNSPEC, sizeof UNSPEC) == 0;
}

static const int	mon_lengths[2][MONSPERYEAR] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static const int	year_lengths[2] = {
	DAYSPERNYEAR, DAYSPERLYEAR
};

static void
gmtload(struct state *const sp)
{
//	if (tzload(etc_utc, sp, true) != 0)
//	  tzparse("UTC0", sp, NULL);
}

/* Initialize *SP to a value appropriate for the TZ setting NAME.
   Return 0 on success, an errno value on failure.  */
static int
zoneinit(struct state *sp, char const *name)
{
    /*
    ** User wants it fast rather than right.
    */
    sp->leapcnt = 0;		/* so, we're off a little */
    sp->timecnt = 0;
    sp->typecnt = 0;
    sp->charcnt = 0;
    sp->goback = sp->goahead = false;
    init_ttinfo(&sp->ttis[0], 0, false, 0);
    strcpy(sp->chars, utc);
    sp->defaulttype = 0;
    return 0;
}

void
tzsetlcl(char const *name)
{
  struct state *sp = lclptr;
  zoneinit(sp, "");
}

void
tzset(void)
{
  tzsetlcl("");
}

static void
gmtcheck(void)
{
  static bool gmt_is_set;
  if (lock() != 0)
    return;
  if (! gmt_is_set) {
#ifdef ALL_STATE
    gmtptr = malloc(sizeof *gmtptr);
#endif
    if (gmtptr)
      gmtload(gmtptr);
    gmt_is_set = true;
  }
  unlock();
}

/*
** The easy way to behave "as if no library function calls" localtime
** is to not call it, so we drop its guts into "localsub", which can be
** freely called. (And no, the PANS doesn't require the above behavior,
** but it *is* desirable.)
*/

/*ARGSUSED*/
static struct tm *
localsub(struct state const *sp, time_t const *timep,
	 struct tm *const tmp)
{
	register const struct ttinfo *	ttisp;
	register int			i;
	register struct tm *		result;
	const time_t			t = *timep;

	if (sp == NULL) {
	  /* Don't bother to set tzname etc.; tzset has already done it.  */
	  return gmtsub(gmtptr, timep, 0, tmp);
	}
	if ((sp->goback && t < sp->ats[0]) ||
		(sp->goahead && t > sp->ats[sp->timecnt - 1])) {
			time_t newt;
			register time_t		seconds;
			register time_t		years;

			if (t < sp->ats[0])
				seconds = sp->ats[0] - t;
			else	seconds = t - sp->ats[sp->timecnt - 1];
			--seconds;

			/* Beware integer overflow, as SECONDS might
			   be close to the maximum time_t.  */
			years = seconds / SECSPERREPEAT * YEARSPERREPEAT;
			seconds = years * AVGSECSPERYEAR;
			years += YEARSPERREPEAT;
			if (t < sp->ats[0])
			  newt = t + seconds + SECSPERREPEAT;
			else
			  newt = t - seconds - SECSPERREPEAT;

			if (newt < sp->ats[0] ||
				newt > sp->ats[sp->timecnt - 1])
					return NULL;	/* "cannot happen" */
			result = localsub(sp, &newt, tmp);
			if (result) {
#if defined ckd_add && defined ckd_sub
				if (t < sp->ats[0]
				    ? ckd_sub(&result->tm_year,
					      result->tm_year, years)
				    : ckd_add(&result->tm_year,
					      result->tm_year, years))
				  return NULL;
#else
				register int_fast64_t newy;

				newy = result->tm_year;
				if (t < sp->ats[0])
					newy -= years;
				else	newy += years;
				if (! (INT_MIN <= newy && newy <= INT_MAX))
					return NULL;
				result->tm_year = newy;
#endif
			}
			return result;
	}
	if (sp->timecnt == 0 || t < sp->ats[0]) {
		i = sp->defaulttype;
	} else {
		register int	lo = 1;
		register int	hi = sp->timecnt;

		while (lo < hi) {
			register int	mid = (lo + hi) >> 1;

			if (t < sp->ats[mid])
				hi = mid;
			else	lo = mid + 1;
		}
		i = sp->types[lo - 1];
	}
	ttisp = &sp->ttis[i];
	/*
	** To get (wrong) behavior that's compatible with System V Release 2.0
	** you'd replace the statement below with
	**	t += ttisp->tt_utoff;
	**	timesub(&t, 0L, sp, tmp);
	*/
	result = timesub(&t, ttisp->tt_utoff, sp, tmp);
	if (result) {
	  result->tm_isdst = ttisp->tt_isdst;
#ifdef TM_ZONE
	  result->TM_ZONE = (char *) &sp->chars[ttisp->tt_desigidx];
#endif /* defined TM_ZONE */
	}
	return result;
}

static struct tm *
localtime_tzset(time_t const *timep, struct tm *tmp)
{
  // http://b/31339449: POSIX says localtime(3) acts as if it called tzset(3), but upstream
  // and glibc both think it's okay for localtime_r(3) to not do so (presumably because of
  // the "not required to set tzname" clause). It's unclear that POSIX actually intended this,
  // the BSDs disagree with glibc, and it's confusing to developers to have localtime_r(3)
  // behave differently than other time zone-sensitive functions in <time.h>.
  tzset();

  tmp = localsub(lclptr, timep, tmp);
  return tmp;
}

struct tm *
localtime(const time_t *timep)
{
  static struct tm tm;
  return localtime_tzset(timep, &tm);
}

struct tm *
localtime_r(const time_t *restrict timep, struct tm *restrict tmp)
{
  return localtime_tzset(timep, tmp);
}

/*
** gmtsub is to gmtime as localsub is to localtime.
*/

static struct tm *
gmtsub(ATTRIBUTE_MAYBE_UNUSED struct state const *sp, time_t const *timep,
       int_fast32_t offset, struct tm *tmp)
{
	register struct tm *	result;

	result = timesub(timep, offset, gmtptr, tmp);
#ifdef TM_ZONE
	/*
	** Could get fancy here and deliver something such as
	** "+xx" or "-xx" if offset is non-zero,
	** but this is no time for a treasure hunt.
	*/
	tmp->TM_ZONE = ((char *)
			(offset ? wildabbr : gmtptr ? gmtptr->chars : utc));
#endif /* defined TM_ZONE */
	return result;
}

/*
* Re-entrant version of gmtime.
*/

struct tm *
gmtime_r(time_t const *restrict timep, struct tm *restrict tmp)
{
  gmtcheck();
  return gmtsub(gmtptr, timep, 0, tmp);
}

struct tm *
gmtime(const time_t *timep)
{
  static struct tm tm;
  return gmtime_r(timep, &tm);
}

/*
** Return the number of leap years through the end of the given year
** where, to make the math easy, the answer for year zero is defined as zero.
*/

static time_t
leaps_thru_end_of_nonneg(time_t y)
{
  return y / 4 - y / 100 + y / 400;
}

static time_t
leaps_thru_end_of(time_t y)
{
  return (y < 0
	  ? -1 - leaps_thru_end_of_nonneg(-1 - y)
	  : leaps_thru_end_of_nonneg(y));
}

static struct tm *
timesub(const time_t *timep, int_fast32_t offset,
	const struct state *sp, struct tm *tmp)
{
	register const struct lsinfo *	lp;
	register time_t			tdays;
	register const int *		ip;
	register int_fast32_t		corr;
	register int			i;
	int_fast32_t idays, rem, dayoff, dayrem;
	time_t y;

	/* If less than SECSPERMIN, the number of seconds since the
	   most recent positive leap second; otherwise, do not add 1
	   to localtime tm_sec because of leap seconds.  */
	time_t secs_since_posleap = SECSPERMIN;

	corr = 0;
	i = (sp == NULL) ? 0 : sp->leapcnt;
	while (--i >= 0) {
		lp = &sp->lsis[i];
		if (*timep >= lp->ls_trans) {
			corr = lp->ls_corr;
			if ((i == 0 ? 0 : lp[-1].ls_corr) < corr)
			  secs_since_posleap = *timep - lp->ls_trans;
			break;
		}
	}

	/* Calculate the year, avoiding integer overflow even if
	   time_t is unsigned.  */
	tdays = *timep / SECSPERDAY;
	rem = *timep % SECSPERDAY;
	rem += offset % SECSPERDAY - corr % SECSPERDAY + 3 * SECSPERDAY;
	dayoff = offset / SECSPERDAY - corr / SECSPERDAY + rem / SECSPERDAY - 3;
	rem %= SECSPERDAY;
	/* y = (EPOCH_YEAR
	        + floor((tdays + dayoff) / DAYSPERREPEAT) * YEARSPERREPEAT),
	   sans overflow.  But calculate against 1570 (EPOCH_YEAR -
	   YEARSPERREPEAT) instead of against 1970 so that things work
	   for localtime values before 1970 when time_t is unsigned.  */
	dayrem = tdays % DAYSPERREPEAT;
	dayrem += dayoff % DAYSPERREPEAT;
	y = (EPOCH_YEAR - YEARSPERREPEAT
	     + ((1 + dayoff / DAYSPERREPEAT + dayrem / DAYSPERREPEAT
		 - ((dayrem % DAYSPERREPEAT) < 0)
		 + tdays / DAYSPERREPEAT)
		* YEARSPERREPEAT));
	/* idays = (tdays + dayoff) mod DAYSPERREPEAT, sans overflow.  */
	idays = tdays % DAYSPERREPEAT;
	idays += dayoff % DAYSPERREPEAT + 2 * DAYSPERREPEAT;
	idays %= DAYSPERREPEAT;
	/* Increase Y and decrease IDAYS until IDAYS is in range for Y.  */
	while (year_lengths[isleap(y)] <= idays) {
		int tdelta = idays / DAYSPERLYEAR;
		int_fast32_t ydelta = tdelta + !tdelta;
		time_t newy = y + ydelta;
		register int	leapdays;
		leapdays = leaps_thru_end_of(newy - 1) -
			leaps_thru_end_of(y - 1);
		idays -= ydelta * DAYSPERNYEAR;
		idays -= leapdays;
		y = newy;
	}

#ifdef ckd_add
	if (ckd_add(&tmp->tm_year, y, -TM_YEAR_BASE)) {
	  errno = EOVERFLOW;
	  return NULL;
	}
#else
	if (!TYPE_SIGNED(time_t) && y < TM_YEAR_BASE) {
	  int signed_y = y;
	  tmp->tm_year = signed_y - TM_YEAR_BASE;
	} else if ((!TYPE_SIGNED(time_t) || INT_MIN + TM_YEAR_BASE <= y)
		   && y - TM_YEAR_BASE <= INT_MAX)
	  tmp->tm_year = y - TM_YEAR_BASE;
	else {
	  errno = EOVERFLOW;
	  return NULL;
	}
#endif
	tmp->tm_yday = idays;
	/*
	** The "extra" mods below avoid overflow problems.
	*/
	tmp->tm_wday = (TM_WDAY_BASE
			+ ((tmp->tm_year % DAYSPERWEEK)
			   * (DAYSPERNYEAR % DAYSPERWEEK))
			+ leaps_thru_end_of(y - 1)
			- leaps_thru_end_of(TM_YEAR_BASE - 1)
			+ idays);
	tmp->tm_wday %= DAYSPERWEEK;
	if (tmp->tm_wday < 0)
		tmp->tm_wday += DAYSPERWEEK;
	tmp->tm_hour = rem / SECSPERHOUR;
	rem %= SECSPERHOUR;
	tmp->tm_min = rem / SECSPERMIN;
	tmp->tm_sec = rem % SECSPERMIN;

	/* Use "... ??:??:60" at the end of the localtime minute containing
	   the second just before the positive leap second.  */
	tmp->tm_sec += secs_since_posleap <= tmp->tm_sec;

	ip = mon_lengths[isleap(y)];
	for (tmp->tm_mon = 0; idays >= ip[tmp->tm_mon]; ++(tmp->tm_mon))
		idays -= ip[tmp->tm_mon];
	tmp->tm_mday = idays + 1;
	tmp->tm_isdst = 0;
#ifdef TM_GMTOFF
	tmp->TM_GMTOFF = offset;
#endif /* defined TM_GMTOFF */
	return tmp;
}

/*
** Adapted from code provided by Robert Elz, who writes:
**	The "best" way to do mktime I think is based on an idea of Bob
**	Kridle's (so its said...) from a long time ago.
**	It does a binary search of the time_t space. Since time_t's are
**	just 32 bits, its a max of 32 iterations (even at 64 bits it
**	would still be very reasonable).
*/

#ifndef WRONG
# define WRONG (-1)
#endif /* !defined WRONG */

/*
** Normalize logic courtesy Paul Eggert.
*/

static bool
increment_overflow(int *ip, int j)
{
#ifdef ckd_add
	return ckd_add(ip, *ip, j);
#else
	register int const	i = *ip;

	/*
	** If i >= 0 there can only be overflow if i + j > INT_MAX
	** or if j > INT_MAX - i; given i >= 0, INT_MAX - i cannot overflow.
	** If i < 0 there can only be overflow if i + j < INT_MIN
	** or if j < INT_MIN - i; given i < 0, INT_MIN - i cannot overflow.
	*/
	if ((i >= 0) ? (j > INT_MAX - i) : (j < INT_MIN - i))
		return true;
	*ip += j;
	return false;
#endif
}

static bool
increment_overflow32(int_fast32_t *const lp, int const m)
{
#ifdef ckd_add
	return ckd_add(lp, *lp, m);
#else
	register int_fast32_t const	l = *lp;

	if ((l >= 0) ? (m > INT_FAST32_MAX - l) : (m < INT_FAST32_MIN - l))
		return true;
	*lp += m;
	return false;
#endif
}

static bool
increment_overflow_time(time_t *tp, int_fast32_t j)
{
#ifdef ckd_add
	return ckd_add(tp, *tp, j);
#else
	/*
	** This is like
	** 'if (! (TIME_T_MIN <= *tp + j && *tp + j <= TIME_T_MAX)) ...',
	** except that it does the right thing even if *tp + j would overflow.
	*/
	if (! (j < 0
	       ? (TYPE_SIGNED(time_t) ? TIME_T_MIN - j <= *tp : -1 - j < *tp)
	       : *tp <= TIME_T_MAX - j))
		return true;
	*tp += j;
	return false;
#endif
}

static bool
normalize_overflow(int *const tensptr, int *const unitsptr, const int base)
{
	register int	tensdelta;

	tensdelta = (*unitsptr >= 0) ?
		(*unitsptr / base) :
		(-1 - (-1 - *unitsptr) / base);
	*unitsptr -= tensdelta * base;
	return increment_overflow(tensptr, tensdelta);
}

static bool
normalize_overflow32(int_fast32_t *tensptr, int *unitsptr, int base)
{
	register int	tensdelta;

	tensdelta = (*unitsptr >= 0) ?
		(*unitsptr / base) :
		(-1 - (-1 - *unitsptr) / base);
	*unitsptr -= tensdelta * base;
	return increment_overflow32(tensptr, tensdelta);
}

static int
tmcomp(register const struct tm *const atmp,
       register const struct tm *const btmp)
{
	register int	result;

	if (atmp->tm_year != btmp->tm_year)
		return atmp->tm_year < btmp->tm_year ? -1 : 1;
	if ((result = (atmp->tm_mon - btmp->tm_mon)) == 0 &&
		(result = (atmp->tm_mday - btmp->tm_mday)) == 0 &&
		(result = (atmp->tm_hour - btmp->tm_hour)) == 0 &&
		(result = (atmp->tm_min - btmp->tm_min)) == 0)
			result = atmp->tm_sec - btmp->tm_sec;
	return result;
}

/* Copy to *DEST from *SRC.  Copy only the members needed for mktime,
   as other members might not be initialized.  */
static void
mktmcpy(struct tm *dest, struct tm const *src)
{
  dest->tm_sec = src->tm_sec;
  dest->tm_min = src->tm_min;
  dest->tm_hour = src->tm_hour;
  dest->tm_mday = src->tm_mday;
  dest->tm_mon = src->tm_mon;
  dest->tm_year = src->tm_year;
  dest->tm_isdst = src->tm_isdst;
#if defined TM_GMTOFF && ! UNINIT_TRAP
  dest->TM_GMTOFF = src->TM_GMTOFF;
#endif
}

static time_t
time2sub(struct tm *const tmp,
	 struct tm *(*funcp)(struct state const *, time_t const *,
			     int_fast32_t, struct tm *),
	 struct state const *sp,
	 const int_fast32_t offset,
	 bool *okayp,
	 bool do_norm_secs)
{
	register int			dir;
	register int			i, j;
	register int			saved_seconds;
	register int_fast32_t		li;
	register time_t			lo;
	register time_t			hi;
	int_fast32_t			y;
	time_t				newt;
	time_t				t;
	struct tm			yourtm, mytm;

	*okayp = false;
	mktmcpy(&yourtm, tmp);

	if (do_norm_secs) {
		if (normalize_overflow(&yourtm.tm_min, &yourtm.tm_sec,
			SECSPERMIN))
				return WRONG;
	}
	if (normalize_overflow(&yourtm.tm_hour, &yourtm.tm_min, MINSPERHOUR))
		return WRONG;
	if (normalize_overflow(&yourtm.tm_mday, &yourtm.tm_hour, HOURSPERDAY))
		return WRONG;
	y = yourtm.tm_year;
	if (normalize_overflow32(&y, &yourtm.tm_mon, MONSPERYEAR))
		return WRONG;
	/*
	** Turn y into an actual year number for now.
	** It is converted back to an offset from TM_YEAR_BASE later.
	*/
	if (increment_overflow32(&y, TM_YEAR_BASE))
		return WRONG;
	while (yourtm.tm_mday <= 0) {
		if (increment_overflow32(&y, -1))
			return WRONG;
		li = y + (1 < yourtm.tm_mon);
		yourtm.tm_mday += year_lengths[isleap(li)];
	}
	while (yourtm.tm_mday > DAYSPERLYEAR) {
		li = y + (1 < yourtm.tm_mon);
		yourtm.tm_mday -= year_lengths[isleap(li)];
		if (increment_overflow32(&y, 1))
			return WRONG;
	}
	for ( ; ; ) {
		i = mon_lengths[isleap(y)][yourtm.tm_mon];
		if (yourtm.tm_mday <= i)
			break;
		yourtm.tm_mday -= i;
		if (++yourtm.tm_mon >= MONSPERYEAR) {
			yourtm.tm_mon = 0;
			if (increment_overflow32(&y, 1))
				return WRONG;
		}
	}
#ifdef ckd_add
	if (ckd_add(&yourtm.tm_year, y, -TM_YEAR_BASE))
	  return WRONG;
#else
	if (increment_overflow32(&y, -TM_YEAR_BASE))
		return WRONG;
	if (! (INT_MIN <= y && y <= INT_MAX))
		return WRONG;
	yourtm.tm_year = y;
#endif
	if (yourtm.tm_sec >= 0 && yourtm.tm_sec < SECSPERMIN)
		saved_seconds = 0;
	else if (yourtm.tm_year < EPOCH_YEAR - TM_YEAR_BASE) {
		/*
		** We can't set tm_sec to 0, because that might push the
		** time below the minimum representable time.
		** Set tm_sec to 59 instead.
		** This assumes that the minimum representable time is
		** not in the same minute that a leap second was deleted from,
		** which is a safer assumption than using 58 would be.
		*/
		if (increment_overflow(&yourtm.tm_sec, 1 - SECSPERMIN))
			return WRONG;
		saved_seconds = yourtm.tm_sec;
		yourtm.tm_sec = SECSPERMIN - 1;
	} else {
		saved_seconds = yourtm.tm_sec;
		yourtm.tm_sec = 0;
	}
	/*
	** Do a binary search (this works whatever time_t's type is).
	*/
	lo = TIME_T_MIN;
	hi = TIME_T_MAX;
	for ( ; ; ) {
		t = lo / 2 + hi / 2;
		if (t < lo)
			t = lo;
		else if (t > hi)
			t = hi;
		if (! funcp(sp, &t, offset, &mytm)) {
			/*
			** Assume that t is too extreme to be represented in
			** a struct tm; arrange things so that it is less
			** extreme on the next pass.
			*/
			dir = (t > 0) ? 1 : -1;
		} else	dir = tmcomp(&mytm, &yourtm);
		if (dir != 0) {
			if (t == lo) {
				if (t == TIME_T_MAX)
					return WRONG;
				++t;
				++lo;
			} else if (t == hi) {
				if (t == TIME_T_MIN)
					return WRONG;
				--t;
				--hi;
			}
			if (lo > hi)
				return WRONG;
			if (dir > 0)
				hi = t;
			else	lo = t;
			continue;
		}
#if defined TM_GMTOFF && ! UNINIT_TRAP
		if (mytm.TM_GMTOFF != yourtm.TM_GMTOFF
		    && (yourtm.TM_GMTOFF < 0
			? (-SECSPERDAY <= yourtm.TM_GMTOFF
			   && (mytm.TM_GMTOFF <=
			       (min(INT_FAST32_MAX, LONG_MAX)
				+ yourtm.TM_GMTOFF)))
			: (yourtm.TM_GMTOFF <= SECSPERDAY
			   && ((max(INT_FAST32_MIN, LONG_MIN)
				+ yourtm.TM_GMTOFF)
			       <= mytm.TM_GMTOFF)))) {
		  /* MYTM matches YOURTM except with the wrong UT offset.
		     YOURTM.TM_GMTOFF is plausible, so try it instead.
		     It's OK if YOURTM.TM_GMTOFF contains uninitialized data,
		     since the guess gets checked.  */
		  time_t altt = t;
		  int_fast32_t diff = mytm.TM_GMTOFF - yourtm.TM_GMTOFF;
		  if (!increment_overflow_time(&altt, diff)) {
		    struct tm alttm;
		    if (funcp(sp, &altt, offset, &alttm)
			&& alttm.tm_isdst == mytm.tm_isdst
			&& alttm.TM_GMTOFF == yourtm.TM_GMTOFF
			&& tmcomp(&alttm, &yourtm) == 0) {
		      t = altt;
		      mytm = alttm;
		    }
		  }
		}
#endif
		if (yourtm.tm_isdst < 0 || mytm.tm_isdst == yourtm.tm_isdst)
			break;
		/*
		** Right time, wrong type.
		** Hunt for right time, right type.
		** It's okay to guess wrong since the guess
		** gets checked.
		*/
		if (sp == NULL)
			return WRONG;
		for (i = sp->typecnt - 1; i >= 0; --i) {
			if (sp->ttis[i].tt_isdst != yourtm.tm_isdst)
				continue;
			for (j = sp->typecnt - 1; j >= 0; --j) {
				if (sp->ttis[j].tt_isdst == yourtm.tm_isdst)
					continue;
				if (ttunspecified(sp, j))
				  continue;
				newt = (t + sp->ttis[j].tt_utoff
					- sp->ttis[i].tt_utoff);
				if (! funcp(sp, &newt, offset, &mytm))
					continue;
				if (tmcomp(&mytm, &yourtm) != 0)
					continue;
				if (mytm.tm_isdst != yourtm.tm_isdst)
					continue;
				/*
				** We have a match.
				*/
				t = newt;
				goto label;
			}
		}
		return WRONG;
	}
label:
	newt = t + saved_seconds;
	if ((newt < t) != (saved_seconds < 0))
		return WRONG;
	t = newt;
	if (funcp(sp, &t, offset, tmp))
		*okayp = true;
	return t;
}

static time_t
time2(struct tm * const	tmp,
      struct tm *(*funcp)(struct state const *, time_t const *,
			  int_fast32_t, struct tm *),
      struct state const *sp,
      const int_fast32_t offset,
      bool *okayp)
{
	time_t	t;

	/*
	** First try without normalization of seconds
	** (in case tm_sec contains a value associated with a leap second).
	** If that fails, try with normalization of seconds.
	*/
	t = time2sub(tmp, funcp, sp, offset, okayp, false);
	return *okayp ? t : time2sub(tmp, funcp, sp, offset, okayp, true);
}

static time_t
time1(struct tm *const tmp,
      struct tm *(*funcp)(struct state const *, time_t const *,
			  int_fast32_t, struct tm *),
      struct state const *sp,
      const int_fast32_t offset)
{
	register time_t			t;
	register int			samei, otheri;
	register int			sameind, otherind;
	register int			i;
	register int			nseen;
	char				seen[TZ_MAX_TYPES];
	unsigned char			types[TZ_MAX_TYPES];
	bool				okay;

	if (tmp == NULL) {
		errno = EINVAL;
		return WRONG;
	}
	if (tmp->tm_isdst > 1)
		tmp->tm_isdst = 1;
	t = time2(tmp, funcp, sp, offset, &okay);
	if (okay)
		return t;
	if (tmp->tm_isdst < 0)
#ifdef PCTS
		/*
		** POSIX Conformance Test Suite code courtesy Grant Sullivan.
		*/
		tmp->tm_isdst = 0;	/* reset to std and try again */
#else
		return t;
#endif /* !defined PCTS */
	/*
	** We're supposed to assume that somebody took a time of one type
	** and did some math on it that yielded a "struct tm" that's bad.
	** We try to divine the type they started from and adjust to the
	** type they need.
	*/
	if (sp == NULL)
		return WRONG;
	for (i = 0; i < sp->typecnt; ++i)
		seen[i] = false;
	nseen = 0;
	for (i = sp->timecnt - 1; i >= 0; --i)
		if (!seen[sp->types[i]] && !ttunspecified(sp, sp->types[i])) {
			seen[sp->types[i]] = true;
			types[nseen++] = sp->types[i];
		}
	for (sameind = 0; sameind < nseen; ++sameind) {
		samei = types[sameind];
		if (sp->ttis[samei].tt_isdst != tmp->tm_isdst)
			continue;
		for (otherind = 0; otherind < nseen; ++otherind) {
			otheri = types[otherind];
			if (sp->ttis[otheri].tt_isdst == tmp->tm_isdst)
				continue;
			tmp->tm_sec += (sp->ttis[otheri].tt_utoff
					- sp->ttis[samei].tt_utoff);
			tmp->tm_isdst = !tmp->tm_isdst;
			t = time2(tmp, funcp, sp, offset, &okay);
			if (okay)
				return t;
			tmp->tm_sec -= (sp->ttis[otheri].tt_utoff
					- sp->ttis[samei].tt_utoff);
			tmp->tm_isdst = !tmp->tm_isdst;
		}
	}
	return WRONG;
}

time_t
mktime(struct tm *tmp)
{
	gmtcheck();
	return time1(tmp, gmtsub, gmtptr, 0);
}

time_t
timelocal(struct tm *tmp)
{
	if (tmp != NULL)
		tmp->tm_isdst = -1;	/* in case it wasn't initialized */
	return mktime(tmp);
}

time_t
timeoff(struct tm *tmp, long offset)
{
  if (tmp)
    tmp->tm_isdst = 0;
  gmtcheck();
  return time1(tmp, gmtsub, gmtptr, offset);
}

time_t
timegm(struct tm *tmp)
{
  time_t t;
  struct tm tmcpy;
  mktmcpy(&tmcpy, tmp);
  tmcpy.tm_wday = -1;
  t = timeoff(&tmcpy, 0);
  if (0 <= tmcpy.tm_wday)
    *tmp = tmcpy;
  return t;
}
