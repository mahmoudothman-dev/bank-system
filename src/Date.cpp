#include "Date.h"



Date::Date() {};

Date::Date(int day, int month, int year, int hour, int minute, int second) 
	: day(day), month(month), year(year), hour(hour), minute(minute), 
	second(second) { }


int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}

int Date::getHour() {
	return hour;
}
int Date::getMinute() {
	return minute;
}
int Date::getSecond() {
	return second;
}

Date Date::getCurrentDate() {
	time_t now = time(0);
	tm lt;
	localtime_s(&lt, &now);

	return Date(lt.tm_mday,
		lt.tm_mon + 1,
		lt.tm_year + 1900,
		lt.tm_hour,
		lt.tm_min,
		lt.tm_sec );
}
