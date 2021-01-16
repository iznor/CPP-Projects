#include "Event.h"

    Event & Event :: operator= (const Event & other){
       
        // self assign check
        if (this == &other) return *this; 
        // free memory if "this" already contains data         
        if ((other.isEmpty() || !other.validEvent())){
            if (!this->isEmpty()) {                              
                // using our d'tor
                delete this;                                                  
            }
            clearEvent();
            return *this;
        }
        // create & initialize as "other" using our copy c'tor
        // cout<<"TESTY"<<endl;
        copy_Event(other);                                               
        return *this;
    }

	Event::Event() :
    serial_num(0),   // empty events will be given a "0" serial number. 
    event_name(nullptr),
    leader(nullptr),
    start(nullptr),
    end(nullptr)
    {}
	Event::Event(int serial, const char* EventName, const char* Leader, const MyDate& Start, const MyDate& End){
        serial_num=serial;
        event_name=new char[strlen(EventName)+1]{};
        strcpy(event_name, EventName);
        leader=new char[strlen(Leader)+1]{};
        strcpy(leader, Leader);
        start=new MyDate(Start);
        end=new MyDate(End);
        if (!this->validEvent()){
            serial_num=0;   // empty events will be given a "0" serial number.
            event_name=nullptr;
            leader=nullptr;
            start=nullptr;
            end=nullptr;
        }
        return;
    }
	Event::Event(const Event& e){
        if (!e.validEvent()){
            cout<<"ERROR! the event that was copied to this one was not valid";
            serial_num=0;   // empty events will be given a "0" serial number.
            event_name=nullptr;
            leader=nullptr;
            start=nullptr;
            end=nullptr;
            return;
        }
        
        serial_num=e.serial_num;
        event_name=new char[strlen(e.event_name)+1]{};
        strcpy(event_name, e.event_name);
        leader=new char[strlen(e.leader)+1]{};
        strcpy(leader, e.leader);
        start = new MyDate(*e.start);                                                  
        end = new MyDate(*e.end);                                                   
    }
	Event::~Event(){
        delete[] event_name;
        delete[] leader;
        delete start;
        delete end;
        return;
    }

    // essential setters & getters
    void Event::set_Serial(int num){
        serial_num=num;
    }
    void Event::set_EventName(const char* newName){
        // if event name exists already
        if (event_name!=nullptr){
            delete[] event_name;
        }
        // allocate a new string and copy newName into it
        event_name=new char[strlen(newName)+1]{};
        strcpy(event_name, newName);
    }
    void Event::set_LeaderName(const char* newName){
        // if event name exists already
        if (leader!=nullptr){
            delete[] leader;
        }
        // allocate a new string and copy newName into it
        leader=new char[strlen(newName)+1]{};
        strcpy(leader, newName);
    }
    int Event::set_Start(int day, int month, int year){
        // if start exists already
        if (start!=nullptr){
            delete start;
        }
        // allocate a new date and set it to the new day,month,year given (if its valid)
        if (valiDate(day,month,year)){
        start=new MyDate;
        start->set(day,month,year);
            return 0;
        }
        return -1;
    }
    int Event::set_Start(const MyDate& newDate){
        // if start exists already
        if (start!=nullptr){
            delete start;
        }
        // allocate a new date and set it to the new day,month,year given (if its valid)
        if (valiDate(newDate)){
        start=new MyDate(newDate);
            return 0;
        }
        return -1;
    }
    int Event::set_End(int day, int month, int year){
        if (start==nullptr){
            cout<<"Error! no start date yet (set start date first)";
            return -1;
        }
        

        // if start exists already
        if (end!=nullptr){
            delete end;
        }
        // allocate a new date and set it to the new day,month,year given (if its valid)
        if (valiDate(day,month,year)){
        end=new MyDate;
        end->set(day,month,year);
            return 0;
        }
        return -1;
    }
    int Event::set_End(const MyDate& newDate){
        if (start==nullptr){
            cout<<"Error! no start date yet (set start date first)";
            return -1;
        }      
          
        // if start exists already
        if (end!=nullptr){
            delete end;
        }
        // allocate a new date and set it to the new day,month,year given (if its valid)
        if (valiDate(newDate)){
            end=new MyDate(newDate);
            return 0;
        }
        return -1;
    }
	int Event::get_Serial() const{
        if (serial_num==0){
            return 0;
        }
        return serial_num;
    }
	char* Event::get_EventName() const{
        if (event_name==nullptr){
            // cout<<"ERROR! event name invalid"<<endl;
            return nullptr;
        }
        return event_name;
    }
	char* Event::get_LeaderName() const{
        if (leader==nullptr){
            // cout<<"ERROR! leader name invalid"<<endl;
            return nullptr;
        }
        return leader;
    }
	MyDate* Event::get_Start() const{
        if (start==nullptr){
            // cout<<"ERROR! start date invalid"<<endl;
            return nullptr;
        }
        
        return start;
    }
	MyDate* Event::get_End() const{
        if (end==nullptr){
            // cout<<"ERROR! end date invalid"<<endl;
            return nullptr;
        }
        return end;
    }

    // other setters & getters
	int Event::get_StartMonth() const{  // will help to check upcoming events later
        if (start==nullptr){
            // cout<<"ERROR! start date was not set"<<endl;
            return -1;
        }
        
        return start->get_month();
    }
    bool Event::valiDate(const MyDate& date)const {
        return date.valiDate(date);
    }
    bool Event::valiDate(int day, int month, int year)const {
        // make sure year is between 1900-2100
        if (year < 1900 || year > 2100) {
            return false;
        }

        // make sure month is between 1-12
        if (month < 1 || month > 12) {
            return false;
        }

        // if month is February, make sure day is between 1 to 28
        if (month == 2) {
            if (day < 1 || day > 28) {
                return false;
            }
        }

        // else make sure day is between 1 to 30
        if (month != 2) {
            if (day < 1 || day > 30) {
                return false;
            }
        }

        // if the date is legal
        return true;
    }
    bool Event::validEvent() const {
        if (!this)
        {
            return false;
        }
        
        if (event_name != nullptr && leader != nullptr &&
            start->valiDate(*start) && end->valiDate(*end) &&
            (start->isBefore(*end) || (!start->isBefore(*end) && !end->isBefore(*start)))) {
            return true;
        }
        return false;
    }
    char* Event::get_Print() const{
        if (!validEvent()){
        // cout<<"TEST"<<endl;
            cout<<"ERROR! invalid event"<<endl;
            return nullptr;
        }
        char * buf_start=start->get_print();
        char * buf_end=end->get_print();
        int bufferSize=0;
        bufferSize=get_SerialDigits()+2 +strlen(event_name)+2 +strlen(leader)+2\
                    +strlen(buf_start)+2 +strlen(buf_end)+2;
        char *buffer=new char[bufferSize+1]{};
        sprintf(buffer, "%d", serial_num);
        strcat(buffer, ", ");
        strcat(buffer, event_name);
        strcat(buffer, ", ");
        strcat(buffer, leader);
        strcat(buffer, ", ");
        strcat(buffer, buf_start);
        strcat(buffer, ", ");
        strcat(buffer, buf_end);
        strcat(buffer, " ");
        delete[]buf_start;
        delete[]buf_end;
        return buffer;
    }
	int Event::get_SerialDigits()const{
        int n=serial_num;
        int counter = 0;
        while (n != 0){
                counter++;
                n = n / 10;
            }
        return counter;
    }    
	bool Event::equalStartDates(const Event& other)const{
        if(other.get_Start()==nullptr){
            return false;
        }
        if (get_Start()==other.get_Start()){
            true;
        }
        return false;
        
    }

	// exercise 1 methods that i converted to Event type
	bool Event::isBefore(const Event& other)const{
        if (this && this->get_Start())
        {
        return this->get_Start()->isBefore(*other.get_Start());
        }
        return false;
        
    }
    int Event::delay(int num){
        if (this && this->get_Start())
        {
        this->get_Start()->delay(num);
        return this->get_End()->delay(num);
        }
        return -1;
    }
    int Event::bringForward(int num) {
        if (this && this->get_Start())
        {
        this->get_Start()->bringForward(num);
        return this->get_End()->bringForward(num);
        }
        return -1;
    }
	void Event::copy_Event(const Event& other){
        if (!other.validEvent()){
            // cout<<"ERROR! the event that was copied to this one was not valid";
            clearEvent();
            return;
        }
        
        serial_num=other.serial_num;
        event_name=new char[strlen(other.event_name)+1]{};
        strcpy(event_name, other.event_name);
        leader=new char[strlen(other.leader)+1]{};
        strcpy(leader, other.leader);
        start = new MyDate(*other.start);                                                  
        end = new MyDate(*other.end); 
    }                                                  
	bool Event::isEmpty()const{
        if (get_EventName()==nullptr && get_LeaderName()==nullptr &&\
            get_Start()==nullptr && get_End()==nullptr || this==nullptr){
                return true;
                }
        return false;
    }
    char* Event::Print() const{
        char* buffer=get_Print();
        if (buffer!=nullptr){
            cout<<buffer;
            return buffer;
        }
        
        delete[]buffer;
        return nullptr;
    }
    void Event::clearEvent(){
        serial_num=0;  
        event_name=nullptr;
        leader=nullptr;
        start=nullptr;
        end=nullptr;
    }
    bool Event::changeDate(const MyDate& newStartDate,const MyDate& newEndDate){
        Event *tmp= new Event;
        tmp=this;
        tmp->set_Start(newStartDate);    tmp->set_End(newEndDate);
        if (tmp->validEvent()){
            this->copy_Event(*tmp);
            delete tmp;
            return true;
        }
        return false;
    }