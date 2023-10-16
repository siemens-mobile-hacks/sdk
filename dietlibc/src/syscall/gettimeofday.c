#include <time.h>
#include <sys/time.h>
#include <swilib.h>

int gettimeofday (struct timeval *tv, struct timezone *tz)
{
	if (NULL != tv) {
		tv->tv_sec = time(NULL);
	}
	
	if (NULL != tz) {
		TTime tt;
		TDate td;
		GetDateTime(&td, &tt);
		tz->tz_dsttime = -1;
		tz->tz_minuteswest = GetTimeZoneShift(&td, &tt, RamDateTimeSettings()->timeZone);
	}
	
    return 0;
}


int settimeofday (const struct timeval *tv, const struct timezone *tz)
{
    TTime tt;
    TDate td;

    if (NULL != tv)
    {
        struct tm t = {};
        tt.sec   = t.tm_sec;
        tt.min = t.tm_min;
        tt.hour  = t.tm_hour;
        td.day   = t.tm_mday;
        td.month = t.tm_mon+1;
        td.year  = t.tm_year+1900;

        SetDateTime(&td, &tt);
    }

    if (NULL != tz)
    {
        /* а шо тут делать? */
    }

    return 0;
}

