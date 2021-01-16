#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class MyDate
{
	
public:
	MyDate();
	MyDate(int day, int month, int year);
	MyDate(const MyDate & other);
	~MyDate() {};
	
public:	
	void init();
	bool isBefore(const MyDate& newDate)const;
	int delay(int num);
	int bringForward(int num);
	char* print() const;
	bool copy_date(const MyDate& new_date);
	
public:	
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	int get_day() const;
	int get_year() const;
	int get_month() const;
	char* get_print() const; // only return date's data without actually printing.
	bool valiDate(const MyDate& date) const; //return true if a given date is valid, false if not.
	bool valiDate(int day, int month, int year) const; //return true if a given date is valid, false if not.
	
private:
	void ConvertPositive(MyDate& date); //gets a date with too many days and converts it to a valid one
	void ConvertNegative(MyDate& date); //gets a date with a negative num of days and converts it to a valid one
	int m_day;
    int m_month;
    int m_year;
};

