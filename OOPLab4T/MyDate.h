#pragma once
#include <ctime>
#include <Windows.h>
#include <iostream>

class Date {
	time_t  _t;
	tm* _tPtr;
	char date[12][12] = { "Січня", "Лютого", "Березня", "Квітня", "Травня", "Червня",
						 "Липня", "Серпня", "Вересня", "Жовтня", "Листопада", "Грудня" };
	char day;
	char month;
	int year;
	char hour;
	char minute;
	char second;


public:	
	bool isNull = 0;
	Date();
	Date(Date& a);
	Date(int setYear, char setMonth, char setDay, char setHour, char setMinute, char setSecond);

	void setDate(int setYear, char setMonth, char setDay, char setHour, char setMinute, char setSecond);
	unsigned int getSecond();
	unsigned int getMinute();
	unsigned int getHour();
	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();

	void setSecond(char setSecond);
	void setMinute(char setMinute);
	void setHour(char setHour);
	void setDay(char setDay);
	void setMonth(int setMonth);
	void setYear(int setYear);
	
	void now();
	void zero();

	void printDate();
	void printTextDate();

	void operator=(Date& a);
};
