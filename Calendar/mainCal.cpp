#include "MyDate.h"
#include "Calendar.h"

int main(int argc, char const *argv[])
{
    Calendar *f=new Calendar;
    MyDate date1(10,9,1992);   MyDate date9(30,12,2007);   MyDate date17(13,12,1950);
    MyDate date2(9,9,1992);    MyDate date10(1,1,2008);    MyDate date18(30,5,2020);
    MyDate date3(11,9,1992);   MyDate date11(29,12,2007);  MyDate date19(1,6,2020);
    MyDate date4(15,1,1993);   MyDate date12(28,2,2001);   MyDate date20(30,12,2020);
    MyDate date5(15,1,1994);   MyDate date13(25,10,2000);  MyDate date21(1,1,2021);
    MyDate date6(1,3,2005);    MyDate date14(18,02,1967);  MyDate date22(29,12,2020);
    MyDate date7(28,2,2005);   MyDate date15(16,7,1963);   MyDate date23(1,4,1996);
    MyDate date24(30,6,1997);  MyDate date25(22,1,1998);   MyDate date26(18,2,1993);
    MyDate date27(29,6,1997);  MyDate date28(7,8,1988);    MyDate date29(22,11,1994);
    MyDate date30(1,7,1997);   MyDate date8(28,2,2005);    MyDate date16(28,2,2006);
    

    // cout<<"8 dates inserted: "<<endl;

    f->insert(date1);       f->insert(date11);       f->insert(date21);
    f->insert(date2);       f->insert(date12);       f->insert(date22);
    f->insert(date3);       f->insert(date13);       f->insert(date23);
    f->insert(date4);       f->insert(date14);       f->insert(date24);
    f->insert(date5);       f->insert(date15);       f->insert(date25);
    f->insert(date6);       f->insert(date16);       f->insert(date26);
    f->insert(date7);       f->insert(date17);       f->insert(date27);
    f->insert(date8);       f->insert(date18);       f->insert(date28);  
    f->insert(date9);       f->insert(date19);       f->insert(date29);
    f->insert(date10);      f->insert(date20);       f->insert(date30);
    cout<<endl;

                                            // f->print();
                                            // cout<<"0 deleted"<<endl;
                                            // f->deleteDate(0);
                                            // cout<<"0,1 swapped"<<endl;
                                            // f->swapDates(0,1);
                                            // cout<<"PRINT"<<endl;
                                            // f->print();

    f->sortDates();
    cout<<"SORTED: "<<endl;
    f->print();
    cout<<"oldest date: "<<f->oldest()<<endl;
    cout<<"is the 9th spot free ? (yes->1, no->0): "<<f->isFree(8)<<endl;
    cout<<"is the 3rd spot free ? (yes->1, no->0): "<<f->isFree(3)<<endl;

    cout<<"List:\n";
    f->print();
    cout<<"\n";
    cout<<"index of the first free cell is now: "<<f->firstFree()<<endl;
    cout<<endl;
    // f->deleteDate(3);   f->deleteDate(1); f->deleteDate(6);
    cout<<"23/4/1993, 10/9/1993, 2/5/1993 - Deleted: "<<endl;
    cout<<"List:\n";
    f->print();
    cout<<"10/9/1992 - Inserted twice: "<<endl;
    // f->insert(date1);
    // f->insert(date1);
    cout<<"times date1 appears: "<<f->datesNum(date1)<<endl;
    cout<<"List:\n";
    f->print();
    cout<<endl;
    // f->deleteDate(2);   f->deleteDate(8);   f->deleteDate(16);   f->deleteDate(25);   f->deleteDate(29);
    f->deleteDate(0);
    cout<<"print regular"<<endl;
    f->print();
    cout<<endl;
    cout<<"sort: "<<endl;
    f->sortDates();
    f->print();
    cout<<endl;
    cout<<"oldest date now is: "<< f->oldest()<<"\n";
    cout<<"Delete all: "<<endl;
    f->deleteAll();
    cout<<"first free: "<<f->firstFree()<<endl;
    cout<<"List:\n";
    f->print();
    cout<<endl;
    cout<<"oldest date now is: "<< f->oldest()<<"\nthe end.";

    return 0;
}
