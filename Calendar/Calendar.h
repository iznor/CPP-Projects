#pragma once
#include "MyDate.h"

class Calendar
{
public:
	Calendar();
	~Calendar();

public:	
	int setDate(const MyDate& newDate, int num);
	bool isFree(int num)const;
	int firstFree()const;
	int insert(const MyDate& newDate);
	int oldest()const;
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print() const;
	void sortDates();
	void swapDates(int date1_index, int date2_index); // swaps between 2 dates positions 
	bool isEmpty()const; // checks if the list is empty
private:
	MyDate **list;
};

