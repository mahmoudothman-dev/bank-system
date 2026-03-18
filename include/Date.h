#pragma once
#include <iostream>
#include <ctime>
using namespace std;



class Date {
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year, int hour, int minute, int second);

	int getDay();
	int getMonth();
	int getYear();
	int getHour();
	int getMinute();
	int getSecond();
	static Date getCurrentDate();

};

