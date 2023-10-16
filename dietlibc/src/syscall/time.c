#include <swilib.h>
#include <time.h>

time_t time(time_t *tm) {
	TDate date;
	TTime time;
	GetDateTime(&date, &time);
	
	struct tm t = {};
	t.tm_sec = time.sec;
	t.tm_min = time.min;
	t.tm_hour = time.hour;
	t.tm_mday = date.day;
	t.tm_mon = date.month - 1;
	t.tm_year = date.year - 1900;
	
	return tm ? *tm = mktime(&t) : mktime(&t);
}
