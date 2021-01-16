#pragma once
#include "MyDate.h"
#include "Event.h"

#define MAX_SIZE 12000 // assume maximum size of a string to 12,000 chars

class Calendar
{
public:
	Calendar();
    Calendar(Event** Cal, MyDate* Today, int last_indx);
	~Calendar();

public:	
	Calendar UpcomingEvents(); 			// return an array of upcoming events that didnt occur yet
	void deleteAll(); 									 
	void printEvent(int index) const;					 
	void sortEvents(); 									 
	char* get_printCal()const;
	char* printCal() const;								 
	int deleteEvent(int num);							 
	int get_LastIndex();
	int getMonthEvents()const;  		// return the number of upcoming events that didnt occur yet
	int setEvent(const Event & newEvent, int num);
	int oldest()const;									 
	int insert(const Event & newEvent);
	int firstFree()const;
	bool isEmpty()const; 				// checks if calendar is empty (make sure)
	bool changeDate(int event_index, const MyDate& newStartDate, const MyDate& newEndDate);
	bool isFree(int num)const;						 	 
	bool overridesOther(const Event & newEvent)const;

private:
	int last_index;
	MyDate *today;
	Event **calendar;
	
};