#define _CRT_SECURE_NO_WARNINGS
#include "MyDate.h"
#include "ColorText.h"
#include "C:\Users\Николай\Documents\GitHub\ooplab4_ukn-ExPikaPaka\OOPLab4T\MyDate.h"

Date::Date() {
	system("chcp 1251");
	system("cls");

	_t = time(NULL);
	_tPtr = localtime(&_t);
	second = _tPtr->tm_sec;
	minute = _tPtr->tm_min;
	hour = _tPtr->tm_hour;
	day = _tPtr->tm_mday;
	month = _tPtr->tm_mon + 1;
	year = 1900 + _tPtr->tm_year;
}

Date::Date(Date& a) {
	system("chcp 1251");
	system("cls");

	second = a.second;
	minute = a.minute;
	hour = a.hour;
	day = a.day;
	month = a.month;
	year = a.year;
	isNull = a.isNull;
}


Date::Date(int setYear, char setMonth, char setDay, char setHour, char setMinute, char setSecond) {
	system("chcp 1251");
	system("cls");

	_t = time(NULL);
	_tPtr = localtime(&_t);
	setDay = setDay < 0 ? -setDay : setDay;
	if (setDay > 31) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний день більший за 31! Встановлено поточний день.\n", 113);
		day = _tPtr->tm_mday;
	}
	else if (!setDay) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний день не може бути 0! Встановлено поточний день.\n", 113);
		day = _tPtr->tm_mday;
	}
	else
		day = setDay;


	setMonth = setMonth < 0 ? -setMonth : setMonth;
	if (setMonth > 12) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний місяць більший за 12! Встановлено поточний місяць.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else if (!setMonth) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний місяць не може бути 0! Встановлено поточний місяць.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else
		month = (char)setMonth;


	setYear = setYear < 0 ? -setYear : setYear;
	if (setYear > 65535) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний рік більший за 32767! Встановлено поточний рік.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else if (!setYear) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний рік не може бути 0! Встановлено поточний рік.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else
		year = setYear;


	setHour = setHour < 0 ? -setHour : setHour;
	if (setHour > 23) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана година більший за 23! Встановлено поточну годину.\n", 113);
		hour = _tPtr->tm_hour;
	}
	else if (!setHour) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана година не може бути 0! Встановлено поточну годину.\n", 113);
		hour = _tPtr->tm_hour;
	}
	else
		hour = setHour;


	setMinute = setMinute < 0 ? -setMinute : setMinute;
	if (setMinute > 59) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана хвилина більший за 59! Встановлено поточну хвилину.\n", 113);
		minute = _tPtr->tm_min;
	}
	else if (!setMinute) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана хвилина не може бути 0! Встановлено поточну хвилину.\n", 113);
		minute = _tPtr->tm_min;
	}
	else
		minute = setMinute;


	setSecond = setSecond < 0 ? -setSecond : setSecond;
	if (setSecond > 59) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана секунда більший за 59! Встановлено поточну секунду.\n", 113);
		second = _tPtr->tm_sec;
	}
	else if (!setSecond) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана секунда не може бути 0! Встановлено поточну секунду.\n", 113);
		second = _tPtr->tm_sec;
	}
	else
		second = setSecond;
}

void Date::setDate(int setYear, char setMonth, char setDay, char setHour, char setMinute, char setSecond) {
	system("chcp 1251");
	system("cls");

	_t = time(NULL);
	_tPtr = localtime(&_t);
	setDay = setDay < 0 ? -setDay : setDay;
	if (setDay > 31) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний день більший за 31! Встановлено поточний день.\n", 113);
		day = _tPtr->tm_mday;
	}
	else if (!setDay) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний день не може бути 0! Встановлено поточний день.\n", 113);
		day = _tPtr->tm_mday;
	}
	else
		day = setDay;


	setMonth = setMonth < 0 ? -setMonth : setMonth;
	if (setMonth > 12) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний місяць більший за 12! Встановлено поточний місяць.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else if (!setMonth) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний місяць не може бути 0! Встановлено поточний місяць.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else
		month = (char)setMonth;


	setYear = setYear < 0 ? -setYear : setYear;
	if (setYear > 65535) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний рік більший за 32767! Встановлено поточний рік.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else if (!setYear) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний рік не може бути 0! Встановлено поточний рік.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else
		year = setYear;


	setHour = setHour < 0 ? -setHour : setHour;
	if (setHour > 23) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана година більший за 23! Встановлено поточну годину.\n", 113);
		hour = _tPtr->tm_hour;
	}
	else
		hour = setHour;


	setMinute = setMinute < 0 ? -setMinute : setMinute;
	if (setMinute > 59) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана хвилина більший за 59! Встановлено поточну хвилину.\n", 113);
		minute = _tPtr->tm_min;
	}
	else
		minute = setMinute;


	setSecond = setSecond < 0 ? -setSecond : setSecond;
	if (setSecond > 59) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана секунда більший за 59! Встановлено поточну секунду.\n", 113);
		second = _tPtr->tm_sec;
	}
	else
		second = setSecond;
}

unsigned int Date::getSecond() {
	return (int)second;
}

unsigned int Date::getMinute() {
	return (int)minute;
}

unsigned int Date::getHour() {
	return (int)hour;
}

unsigned int Date::getDay() {
	return (int)day;
}

unsigned int Date::getMonth() {
	return (int)month;
}

unsigned int Date::getYear() {
	return year;
}

void Date::setSecond(char setSecond) {
	setSecond = setSecond < 0 ? -setSecond : setSecond;
	if (setSecond > 31) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана секунда більша за 59! Встановлено поточну секунду.\n", 113);
		second = _tPtr->tm_sec;
	}
	else if (!setSecond) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана секунда не може бути 0! Встановлено поточну секунду.\n", 113);
		second = _tPtr->tm_sec;
	}
	else
		second = setSecond;
}

void Date::setMinute(char setMinute) {
	setMinute = setMinute < 0 ? -setMinute : setMinute;
	if (setMinute > 59) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана хвилина більший за 59! Встановлено поточну хвилину.\n", 113);
		minute = _tPtr->tm_min;
	}
	else if (!setMinute) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана хвилина не може бути 0! Встановлено поточну хвилину.\n", 113);
		minute = _tPtr->tm_min;
	}
	else
		minute = setMinute;
}

void Date::setHour(char setHour) {
	setHour = setHour < 0 ? -setHour : setHour;
	if (setHour > 23) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана година більший за 23! Встановлено поточну годину.\n", 113);
		hour = _tPtr->tm_hour;
	}
	else if (!setHour) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказана година не може бути 0! Встановлено поточну годину.\n", 113);
		hour = _tPtr->tm_hour;
	}
	else
		hour = (unsigned char)setHour;
}
void Date::setDay(char setDay) {
	setDay = setDay < 0 ? -setDay : setDay;
	if (setDay > 31) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний день більший за 31! Встановлено поточний день.\n", 113);
		day = _tPtr->tm_mday;
	}
	else if (!setDay) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний день не може бути 0! Встановлено поточний день.\n", 113);
		day = _tPtr->tm_mday;
	}
	else
		day = (unsigned char)setDay;
}

void Date::setMonth(int setMonth) {
	setMonth = setMonth < 0 ? -setMonth : setMonth;
	if (setMonth > 12) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний місяць більший за 12! Встановлено поточний місяць.\n", 113);
		month = _tPtr->tm_mon;
	}
	else if (!setMonth) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний місяць не може бути 0! Встановлено поточний місяць.\n", 113);
		month = _tPtr->tm_mon + 1;
	}
	else
		month = (char)setMonth;
}

void Date::setYear(int setYear) {
	setYear = setYear < 0 ? -setYear : setYear;
	if (setYear > 32767) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний рік більший за 32767! Встановлено поточний рік.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else if (!setYear) {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Вказаний рік не може бути 0! Встановлено поточний рік.\n", 113);
		year = 1900 + _tPtr->tm_year;
	}
	else
		year = setYear;
}




void Date::now() {
	_t = time(NULL);
	_tPtr = localtime(&_t);
	second = _tPtr->tm_sec;
	minute = _tPtr->tm_min;
	hour = _tPtr->tm_hour;
	day = _tPtr->tm_mday;
	month = _tPtr->tm_mon + 1;
	year = 1900 + _tPtr->tm_year;
}

void Date::zero() {
	second = 0;
	minute = 0;
	hour = 0;
	day = 0;
	month = 0;
	year = 0;

	isNull = 1;
}



void Date::printDate() {
	std::cout << ((hour < 10) ? '0' : '\0') << (int)hour << ':'
			  << ((minute < 10) ? '0' : '\0') << (int)minute << ':'
			  << ((second < 10) ? '0' : '\0') << (int)second << "  "
			  << ((day < 10) ? '0' : '\0') << (int)day << '.'
			  << ((month < 10) ? '0' : '\0') << (int)month << '.'
			  << year;
}

void Date::printTextDate() {
	std::cout << ((hour < 10) ? '0' : '\0') << (int)hour << ':'
		<< ((minute < 10) ? '0' : '\0') << (int)minute << ':'
		<< ((second < 10) ? '0' : '\0') << (int)second << "  "
		<< ((day < 10) ? '0' : '\0') << (int)day << ' '
		<< date[month - 1] << ' '
		<< year << " року";
}

void Date::operator=(Date& a) {
	second = a.second;
	minute = a.minute;
	hour = a.hour;
	day = a.day;
	month = a.month;
	year = a.year;
	isNull = a.isNull;

}
