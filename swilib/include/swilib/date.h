#pragma once

/**
 * @addtogroup DateTime
 * @brief Functions for working with date and time.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/date.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

typedef struct TDate TDate;
typedef struct TTime TTime;
typedef struct TDateTimeSettings TDateTimeSettings;
typedef struct TZ TZ;

/**
 * Date of the day
 * */
struct TDate {
	unsigned long year;	/**< Year: 20XX */
	uint8_t month;		/**< Month: 1-12 */
	uint8_t day;		/**< Day: 1-31 */
};

/**
 * Time of the day
 * */
struct TTime {
	uint8_t hour;		/**< Hours: 0-23 */
	uint8_t min;		/**< Minutes: 0-59 */
	uint8_t sec;		/**< Seconds: 0-59 */
	uint32_t millisec;	/**< Milliseconds: 0-999 */
};

/**
 * Date & Time settings
 * */
struct TDateTimeSettings {
	char yearNormBudd;	/**< Year mode: 1 - normal, 2 - buddhist */
	char dateFormat;	/**< Unknown */
	char timeFormat;	/**< 0-24h, 1-12h */
	char timeZone;		/**< Internal ID of the selected timezone */
	char isAutoTime1;	/**< Unknown */
	char isAutoTime2;	/**< Unknown */
};

/**
 * Time zone
 * */
struct TZ {
	int lgp_id;
	int city_id;
	char *gmt;
};

/**
 * Initialize TDate structure.
 * @param date					pointer to the structure to be initialized
 * @param year, month, day		date of the day
 * */
__swi_begin(0x2CC)
void InitDate(TDate *date, unsigned long year, uint8_t month, uint8_t day)
__swi_end(0x2CC, InitDate, (date, year, month, day));

/**
 * Initialize TTime structure.
 * @param time						pointer to the structure to be initialized
 * @param hour, min, sec, millisec	time of the day
 * */
__swi_begin(0x2CD)
void InitTime(TTime *time, uint8_t hour, uint8_t min, uint8_t sec, unsigned long millisec)
__swi_end(0x2CD, InitTime, (time, hour, min, sec, millisec));

/**
 * Get date and time settings from the phone.
 * @return pointer to the settings
 * */
__swi_begin(0x822F)
TDateTimeSettings *RamDateTimeSettings(void)
__swi_end(0x822F, RamDateTimeSettings, ());

/**
 * Check if "Auto Time" setting enabled.
 * @return 1 or 0
 * */
__swi_begin(0x80D2)
char *RamIsAutoTimeEnabled(void)
__swi_end(0x80D2, RamIsAutoTimeEnabled, ());

/**
 * Get current date and time.
 * @param[out] date	output for current date
 * @param[out] time	output for current date
 * */
__swi_begin(0x0B4)
void GetDateTime(TDate *date, TTime *time)
__swi_end(0x0B4, GetDateTime, (date, time));

/**
 * Get current timezone shift.
 * @param date			current date
 * @param time			current time
 * @param timezone_id	ID of the timezone (see #RamDateTimeSettings)
 * @return timezone shift in minutes
 * */
__swi_begin(0x230)
int GetTimeZoneShift(const TDate *date, const TTime *time, int timezone_id)
__swi_end(0x230, GetTimeZoneShift, (date, time, timezone_id));

/**
 * Get week number by date.
 * @param date	date of the day
 * @return week number in the year
 * */
__swi_begin(0x0B5)
char GetWeek(const TDate *date)
__swi_end(0x0B5, GetWeek, (date));

/**
 * Get the days count.
 * @param date	date of the day
 * @return total number of days
 * */
__swi_begin(0x3E8)
int64_t GetDays(const TDate *date)
__swi_end(0x3E8, GetDays, (date));

/**
 * Check date for leap year.
 * @param date	date of the day
 * @return 1 is year is leap
 * */
__swi_begin(0x2D1)
int IsLeapYear(const TDate *date)
__swi_end(0x2D1, IsLeapYear, (date));

/**
 * Get the days count in the month.
 * @param date	date of the day
 * @return days count (28-31)
 * */
__swi_begin(0x2D0)
int GetDaysFromMonth(const TDate *date)
__swi_end(0x2D0, GetDaysFromMonth, (date));

/**
 * Convert date and time to seconds.
 * @param[out] seconds	output for calculated seconds
 * @param date			date of the day
 * @param time			time of the day
 * @param epoch			date of the epoch's start
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x2C6)
int GetSecondsFromDateTime(int *seconds, const TDate *date, const TTime *time, const TDate *epoch)
__swi_end(0x2C6, GetSecondsFromDateTime, (seconds, date, time, epoch));

/**
 * Convert date and time to seconds (since 1997-01-01 00:00:00).
 * @param[out] seconds	output for calculated seconds
 * @param date			date of the day
 * @param time			time of the day
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x2C7)
int GetSecondsFromDateTimeSince1997(int *seconds, const TDate *date, const TTime *time)
__swi_end(0x2C7, GetSecondsFromDateTimeSince1997, (seconds, date, time));

/**
 * Calculate seconds from TTime.
 * @param time		time of the day
 * @return seconds
 * */
__swi_begin(0x2C8)
int GetSecondsFromTime(const TTime *time)
__swi_end(0x2C8, GetSecondsFromTime, (time));

/**
 * Convert seconds to TTime.
 * @param[out] time		output for calculated time
 * @param seconds		number of seconds
 * */
__swi_begin(0x2CB)
void GetTimeFromSeconds(TTime *time, int seconds)
__swi_end(0x2CB, GetTimeFromSeconds, (time, seconds));

/**
 * Convert milliseconds to TTime.
 * @param[out] time		output for calculated time
 * @param milliseconds	number of seconds
 * */
__swi_begin(0x3E4)
void GetTimeFromMilliseconds(TTime *time, uint32_t milliseconds)
__swi_end(0x3E4, GetTimeFromSeconds, (time, milliseconds));

/**
 * Convert seconds to date and time.
 * @param seconds		a pointer to the seconds
 * @param[out] date		output for calculated date
 * @param[out] time		output for calculated time
 * @param epoch			date of the epoch's start
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x2C9)
int GetDateTimeFromSeconds(const int *seconds, TDate *date, TTime *time, const TDate *epoch)
__swi_end(0x2C9, GetDateTimeFromSeconds, (seconds, date, time, epoch));

/**
 * Convert seconds to date and time (since 1997-01-01 00:00:00).
 * @param seconds		a pointer to the seconds
 * @param[out] date		output for calculated date
 * @param[out] time		output for calculated time
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x2CA)
int GetDateTimeFromSecondsSince1997(const int *seconds, TDate *date, TTime *time)
__swi_end(0x2CA, GetDateTimeFromSecondsSince1997, (seconds, date, time));

/**
 * Compare two dates.
 * @param date1		date to be compared
 * @param date2		date to be compared
 * @return -1 - date1 < date2
 * @return 0 - date1 == date2
 * @return 1 - date1 > date2
 * */
__swi_begin(0x2CE)
int CmpDates(const TDate *date1, const TDate *date2)
__swi_end(0x2CE, CmpDates, (date1, date2));

/**
 * Compare two timestamps.
 * @param time1		timestamp to be compared
 * @param time2		timestamp to be compared
 * @return -1 - time1 < time2
 * @return 0 - time1 == time2
 * @return 1 - time1 > time2
 * */
__swi_begin(0x2CF)
int CmpTimes(const TTime *time1, const TTime *time2)
__swi_end(0x2CF, CmpTimes, (time1, time2));

/**
 * Put date into ws string.
 * @param[out] ws	output ws string
 * @param date		date
 * @param unk		unknown parameter for formatting: 0x7, 0xF, ...
 * */
__swi_begin(0x3B4)
void GetDate_ws(WSHDR *ws, const TDate *date, unsigned int unk)
__swi_end(0x3B4, GetDate_ws, (ws, date, unk));

/**
 * Put time into ws string.
 * @param[out] ws	output ws string
 * @param time		time
 * @param unk		unkwnow parameter for formatting: 0x223, 0x227, ...
 * */
__swi_begin(0x3B5)
void GetTime_ws(WSHDR *ws, const TTime *time, unsigned int unk)
__swi_end(0x3B5, GetTime_ws, (ws, time, unk));

/**
 * Add or subtract days from a date.
 * @param date	date of the day
 * @param days	number of days to add (positive) or subtract (negative)
 * */
__swi_begin(0x3E5)
void DateAddDays(TDate *date, int days)
__swi_end(0x3E5, DateAddDays, (date, days));

/**
 * Add or subtract days from a date.
 * @param date		date of the day
 * @param months	number of months to add (positive) or subtract (negative)
 * */
__swi_begin(0x3E6)
void DateAddMonths(TDate *date, int months)
__swi_end(0x3E6, DateAddMonths, (date, months));

/**
 * Add or subtract days from a date.
 * @param date		date of the day
 * @param years	number of years to add (positive) or subtract (negative)
 * */
__swi_begin(0x3E7)
void DateAddYears(TDate *date, int years)
__swi_end(0x3E7, DateAddYears, (date, years));

/**
 * Get array of time zones.
 * @return pointer to the array
 * */
__swi_begin(0x83DF)
TZ *RamTimeZones()
__swi_end(0x83DF, RamTimeZones, ());

/**
 * Get current time zone id.
 * @return time zone id
 * */
__swi_begin(0x3E0)
int GetCurrentTimeZone()
__swi_end(0x3E0, GetCurrentTimeZone, ());

/**
 * Get time zone id by time zone.
 * @param gmt	pointer to the time zone (GMT+03:00, GMT+04:00, etc...).
 * @return time zone id
 * */
__swi_begin(0x3E1)
int GetTimeZoneByGMT(const char *gmt)
__swi_end(0x3E1, GetTimeZoneByGMT, (gmt));

/**
 * Check time zone for summer time.
 * @param time_zone	time zone id
 * @return 0 or 1
 * */
__swi_begin(0x3E2)
int IsSummerTime(int time_zone)
__swi_end(0x3E2, IsSummerTime, (time_zone));

/**
 * Set time zone.
 * @param time_zone	time zone id
 * */
__swi_begin(0x3E3)
void SetTimeZone(int time_zone)
__swi_end(0x3E3, SetTimeZone, (time_zone));

__swilib_end

/** @} */
