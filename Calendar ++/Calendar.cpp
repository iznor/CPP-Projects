#include "Calendar.h"

    Calendar::Calendar()
    : calendar(new Event*[30]), today(new MyDate(1,12,2020)), last_index(0)
    {                                                         
        for (int i = 0; i < 30; i++){
            calendar[i]=nullptr;
        }
    }                                                        
    Calendar::Calendar(Event** Cal, MyDate* Today, int last_indx)
    :
    today(new MyDate(*Today)), last_index(last_indx), calendar(new Event*[30])
    {                                                         
        for (int i = 0; i < 30; i++)
        {
            calendar[i]=nullptr;
        }

        for (int i = 0; i < 30; i++){
            if (Cal[i]==nullptr || Cal[i]->isEmpty()){
                continue;
            }
            calendar[i]=new Event(*Cal[i]);
            
        }        
    }                                                        
	Calendar::~Calendar(){                                   
        for (int i = 0; i < 30; i++){                        
            delete calendar[i];                                  
        }                                                   
        delete []calendar;
    }
    int Calendar::get_LastIndex(){
        return last_index;
    }
    bool Calendar::isEmpty()const{
        int empties=0;
        for (int i = 0; i < 30; i++){
            if (calendar[i]==nullptr || calendar[i]->isEmpty()){++empties;}
            if (empties==30){return true;}
        }
        return false;
    }
    int Calendar::firstFree()const{
        for (int i = 0; i < 30; i++){
                if (calendar[i]==nullptr || calendar[i]->isEmpty()){return i;}
            }
        return -1;
    }
	bool Calendar::changeDate(int event_index, const MyDate& newStartDate, const MyDate& newEndDate){
        if (event_index <0 || event_index>29 || calendar[event_index]==nullptr || calendar[event_index]->isEmpty()){
            return false;
        }
        int original_serial=calendar[event_index]->get_Serial();
        Event *tmp=new Event(*calendar[event_index]);
        Event *tmp_org=new Event(*calendar[event_index]);
        tmp->set_Start(newStartDate);    tmp->set_End(newEndDate); tmp->set_Serial(original_serial);
        
        calendar[event_index]->clearEvent();
        
        if (tmp->validEvent() && !overridesOther(*tmp)){
            *calendar[event_index]=*tmp;
            delete tmp;
            delete tmp_org;
            return true;
        }
        delete tmp_org;
        delete tmp;
        return false;
    }
    Calendar Calendar::UpcomingEvents(){
        sortEvents();
        int upcoming_last_index=last_index;
        MyDate *upcoming_today=new MyDate(*today);
        Event **upcoming_cal=new Event*[30];
        for (int i = 0; i < 30; i++){
            upcoming_cal[i]=calendar[i];
        }
        for (int i = 0; i < 30; i++){
            if (upcoming_cal[i]==nullptr || upcoming_cal[i]->isEmpty()){
                continue;
            }
            if ((today->get_month()!=upcoming_cal[i]->get_Start()->get_month() || \
                today->get_year()!=upcoming_cal[i]->get_Start()->get_year()) ||\
                today->get_day()> upcoming_cal[i]->get_Start()->get_day())
            {
                upcoming_cal[i]->clearEvent();
            }
        }
        Calendar *upcoming=new Calendar(upcoming_cal,upcoming_today,upcoming_last_index);
            
        return *upcoming;
    }
	bool Calendar::overridesOther(const Event & newEvent)const{
        for (int i = 0; i < 30; i++){
            if (calendar[i]==nullptr || calendar[i]->isEmpty()){
                continue;
            }
            // if newEvent's start-date OR end-date is equal to another's
            if ((calendar[i]->get_Start()->get_year() == newEvent.get_Start()->get_year() &&\
                calendar[i]->get_Start()->get_month() == newEvent.get_Start()->get_month()&&\
                calendar[i]->get_Start()->get_day() == newEvent.get_Start()->get_day())\
                || \
                calendar[i]->get_End()->get_year() == newEvent.get_End()->get_year() &&\
                calendar[i]->get_End()->get_month() == newEvent.get_End()->get_month()&&\
                calendar[i]->get_End()->get_day() == newEvent.get_End()->get_day()\
                || \
                (calendar[i]->get_Start()->get_year() == newEvent.get_End()->get_year() &&\
                calendar[i]->get_Start()->get_month() == newEvent.get_End()->get_month()&&\
                calendar[i]->get_Start()->get_day() == newEvent.get_End()->get_day())\
                || \
                (calendar[i]->get_End()->get_year() == newEvent.get_Start()->get_year() &&\
                calendar[i]->get_End()->get_month() == newEvent.get_Start()->get_month()&&\
                calendar[i]->get_End()->get_day() == newEvent.get_Start()->get_day())){
                return true;
            // OR if newEvent is between start and end dates of another event
            if (calendar[i]->get_Start()->isBefore(*newEvent.get_Start()) && \
                newEvent.get_Start()->isBefore(*calendar[i]->get_Start())){
                return true;
            }    
        }

    }
    return false;
    }
	int Calendar::setEvent(const Event & newEvent, int num){
        //if the cell was empty before, then create a new Event, set it. 
        if (num<0 || num >29){
            cout<<"Error! invalid index"<<endl;
            return -1;
        }

        if(!newEvent.validEvent()){
            cout<<"Error! invalid event input"<<endl;
            return -1;
        }

        if (newEvent.validEvent() && !overridesOther(newEvent)){
            delete calendar[num];
            calendar[num] = new Event;
            calendar[num]->set_Serial(num);
            calendar[num]->set_EventName(newEvent.get_EventName());
            calendar[num]->set_LeaderName(newEvent.get_LeaderName());
            calendar[num]->set_Start(*newEvent.get_Start());
            calendar[num]->set_End(*newEvent.get_End());
            return 0;
        } 
        return -1;
    }
	int Calendar::deleteEvent(int num){
        if (num<0 || num >29){
            cout<<"Error! wrong index"<<endl;
            return -1;
        }
        calendar[num]->clearEvent();
        return 0;
        }       
    int Calendar::insert(const Event & newEvent){
        //if the list is full - return fail.
        int index=firstFree();
        if (index==-1){
            return -1;
        }       
        if (newEvent.validEvent() && !overridesOther(newEvent)){
            // make sure there is no other event with the same ID
            for (int i = 0; i <30; i++)
            {
                if (calendar[i]==nullptr||calendar[i]->isEmpty()){
                    continue;
                }
                if (calendar[i]->get_Serial()==last_index+1){
                    return -1;
                }
            }
            
            setEvent(newEvent,index);
            calendar[index]->set_Serial(++last_index);
            
        return index;
        }
        return -1;
    }
	bool Calendar::isFree(int num)const{
        if (num<0 || num >29){
            return false;
        }
        if (calendar[num]==nullptr){
            return true;
        }
        return false;
    }
    int Calendar::oldest()const{
        // if list is empty return -1
        if (isEmpty()) return -1;      
        // assume event in cell 0 is the oldest
        int oldest_index=0;            
        // then run the whole calendar and check each cell
        for (int i = 0; i < 30; i++){
            //if the start date in calendar[i] is older than "oldest" - replace it (skip nullptrs dates)
            if (calendar[i]!=nullptr && !calendar[i]->isEmpty() && calendar[i]->get_Start()->isBefore(*calendar[oldest_index]->get_Start())){
                oldest_index=i;
            }
        }
        return oldest_index;
    }
	int Calendar::getMonthEvents()const{
        int counter=0;
        // if date is invalid, then it appears 0 times.
        if (today->get_year() < 1900 || today->get_year() > 2100 || today->get_month() < 1 || today->get_month() > 12){
            return 0;
        } 
        for (int i = 0; i < 30; i++){
            if (calendar[i]==nullptr){
                continue;
            }
            if (calendar[i]->get_StartMonth()==today->get_month() && today->isBefore(*calendar[i]->get_Start())){
                ++counter;
            }
        }    
        return counter;
    }
	void Calendar::deleteAll(){
        for (int i = 0; i < 30; i++){
            deleteEvent(i);
        }
        return;
    }
    char* Calendar::get_printCal()const{
        // if the list is empty - print a message.
        if (isEmpty()){
            cout<<"Empty Calendar"<<endl;
            return nullptr;
        }
        char *big_buffer=new char[MAX_SIZE]{};
        for (int i = 0; i < 30; i++){

            if (calendar[i]==nullptr || calendar[i]->isEmpty() || !(calendar[i]->validEvent())){
                continue;
            }
            strcat(big_buffer,calendar[i]->get_Print());
            strcat(big_buffer, "\n");
        }
        int size=strlen(big_buffer);
        char *final_buffer=new char[size+1]{};
        strcpy(final_buffer,big_buffer);
        delete []big_buffer;
        return final_buffer;
    }
	char* Calendar::printCal() const{
        char* buffer=get_printCal();
        if (buffer!=nullptr){
            cout<<buffer;
            return buffer;
        }
        delete[]buffer;
        return nullptr;
    }
    void Calendar::printEvent(int index) const{
        cout<<"Event in index "<< index<<endl;
        if (calendar[index]==nullptr || calendar[index]->isEmpty()){
            cout<<"(cell is empty)"<<endl;
            return;
        }
        
        calendar[index]->Print();
        cout<<endl;
    } 
    void Calendar::sortEvents(){
        // if the list is empty return
        if (isEmpty()) return;
        for (int i=0; i < 30; i++){
                for (int j=i; j > 0 && !calendar[i] ; j--){
                    if (!calendar[j]){
                        swap(calendar[j], calendar[i]);
                    }
                }
            }

        for (int i=1; i < 30; i++){
            if (calendar[i]){
                for (int j=i; j > 0 && calendar[j]->isBefore(*calendar[j-1]) ; j--){
                    if (calendar[j]){
                        swap(calendar[j], calendar[j-1]);
                    }
                }
            }
        }
    }
