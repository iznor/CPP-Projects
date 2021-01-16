#pragma once
#include "MyDate.h"

class Event
{
public:
	Event();											// default c'tor
	Event(int serial, const char* EventName, const char* Leader, const MyDate& Start, const MyDate& End); // c'tor
	Event(const Event& e); 							    // copy c'tor
    Event& operator=(const Event& other);				// operator "=" assignment
	~Event();											// d'tor

public:	
    void set_Serial(int num);							// set the unique event's serial number
    void set_EventName(const char* newName);			//
    void set_LeaderName(const char* newName);			// 
    int set_Start(const MyDate& newDate);				// set start date (a whole date type is given)
    int set_Start(int day, int month, int year);		// set start date
    int set_End(const MyDate& newDate);					//
    int set_End(int day, int month, int year);			//
	int get_StartMonth() const;  						// will help to check upcoming events later
	int bringForward(int num); 							// same as exercise 1 (refer to start & end date)
	int delay(int num);									// same as exercise 1 (refer to start & end date)
	int get_SerialDigits()const; 						// return the number of digits in a given serial number (used in get_print())
	int get_Serial() const;								// get the unique event's serial number
	MyDate* get_Start() const;							// gets start date
	MyDate* get_End() const;							// gets end date
	char* get_EventName() const;						//
	char* get_LeaderName() const;						//
	char* get_Print()const; 							// return event data string (without actually printing)
	char* Print() const; 								// prints Event type as a string instead of MyDate type
	void copy_Event(const Event& other); 				// used to be "copy_Date"
	void clearEvent();									// set all fields to null (&set serial to 0)
	bool valiDate(int day, int month, int year)const; 	// returns 1 if date is valid, 0 if not
	bool valiDate(const MyDate& date)const;
	bool equalStartDates(const Event& other)const;
	bool validEvent()const;
	bool isBefore(const Event& other)const;				// same as exercise 1 (refer to start date)
	bool isEmpty()const; 								// return 1 if an Event is empty
	bool changeDate(const MyDate& newStartDate,const MyDate& newEndDate);

private:
	int serial_num;
    char *event_name;
    char *leader;
    MyDate *start;
    MyDate *end;
};

