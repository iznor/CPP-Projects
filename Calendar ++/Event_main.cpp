#include "MyDate.h"
#include "Event.h"
#include "Calendar.h"

int main(int argc, char const *argv[])
{
    Calendar *tashfa=new Calendar;
    
    const MyDate date1s(25,12,2020);
    const MyDate date1e(25,12,2020);
    const MyDate date2s(15,1,2021);
    const MyDate date2e(15,1,2021);
    const MyDate date3s(18,12,2020);
    const MyDate date3e(18,12,2020);
    const MyDate date4s(2,12,2020);
    const MyDate date4e(2,12,2020);
    const MyDate date5s(3,1,2020);
    const MyDate date5e(5,1,2020);

    
    // Event e1(0, "Google DSC", "Yuval Ozeri",date1s, date1e);
    // Event e2(0, "Meeting in TLV", "Lior Keynan",date2s, date2e);
    // Event e3(0, "AIPAC", "Washington DC",date3s, date3e);

    Event *e1= new Event;   Event *e2= new Event;   Event *e3= new Event;   Event *e4= new Event; Event *e5= new Event;

    e1->set_Serial(0);  e1->set_EventName("Google DSC"); e1->set_LeaderName("Yuval Ozeri"); e1->set_Start(date1s); e1->set_End(date1e);
    e2->set_Serial(0);  e2->set_EventName("Meeting in TLV"); e2->set_LeaderName("Lior Keynan"); e2->set_Start(date2s); e2->set_End(date2e);
    e3->set_Serial(0);  e3->set_EventName("AIPAC"); e3->set_LeaderName("Washington DC"); e3->set_Start(date3s); e3->set_End(date3e);
    e4->set_Serial(0);  e4->set_EventName("Part"); e4->set_LeaderName("Nebraska"); e4->set_Start(date4s); e4->set_End(date4e);
    e5->set_Serial(0);  e5->set_EventName("Hille"); e5->set_LeaderName("Oragon"); e5->set_Start(date5s); e5->set_End(date5e);

    cout<<"================="<<endl;
    cout<<"is the Calendar empty ? (yes=1) => ";
    cout<<tashfa->isEmpty()<<endl;
    cout<<"is index 4 empty ? (yes=1) => ";
    cout<<tashfa->isFree(4)<<endl;
    cout<<"================="<<endl;
    cout<<"==3 dates inserted=="<<endl;
    tashfa->insert(*e1);
    tashfa->insert(*e2);
    tashfa->insert(*e3);
    cout<<"====getMonthEvents===="<<endl;
    cout<<tashfa->getMonthEvents()<<endl;
    cout<<"================="<<endl;
    cout<<"===printCal==="<<endl;
    tashfa->printCal();
    cout<<"===FirstFree==="<<endl;
    cout<<tashfa->firstFree()<<endl;
    cout<<"===Oldest==="<<endl;
    cout<<tashfa->oldest()<<endl;
    cout<<"===Sort==="<<endl;
    tashfa->sortEvents();
    tashfa->printCal();
    cout<<"===Delete(0) & sort again==="<<endl;
    tashfa->deleteEvent(0);
    tashfa->sortEvents();
    tashfa->printCal();
    cout<<"===insert(e4)==="<<endl;
    cout<<tashfa->get_LastIndex()<<endl;
    // tashfa->printEvent(0);
    tashfa->insert(*e4);
    // e4->Print();cout<<endl;
    tashfa->printCal();
    cout<<"===sort again==="<<endl;
    tashfa->sortEvents();
    tashfa->printCal();
    cout<<"===OverridesOther==="<<endl;
    cout<<"is (e1) ovveriding another event? =>"<<tashfa->overridesOther(*e1)<<endl;
    cout<<"is (e3) ovveriding another event? =>"<<tashfa->overridesOther(*e3)<<endl;
    cout<<"===try to add a date that overrides another and see if there a change:==="<<endl;
    tashfa->insert(*e5);
    tashfa->printCal();
    cout<<"===change ID 0's Dates:==="<<endl;
    const MyDate date6s(30,11,2020);
    const MyDate date6e(30,11,2020);
    tashfa->changeDate(0, date6s, date6e);
    tashfa->sortEvents();
    tashfa->printCal();
    cout<<"===2 more dates inserted===="<<endl;
    tashfa->insert(*e2); tashfa->insert(*e4); tashfa->insert(*e3); 
    tashfa->sortEvents();
    tashfa->printCal();
    cout<<"===upcoming==="<<endl;
    tashfa->UpcomingEvents();
    tashfa->sortEvents();
    tashfa->printCal();
    cout<<"\n";
    tashfa->printCal();
    cout<<"===the end==="<<endl;

    



    return 0;
}
