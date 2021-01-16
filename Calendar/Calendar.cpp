#include "Calendar.h"
#include "MyDate.h"
	
    Calendar::Calendar()
    {
        list = new MyDate*[30];
        for (int i = 0; i < 30; i++)
        {
            list[i]=new MyDate;
            list[i]->setDay(0);
            list[i]->setMonth(0);
            list[i]->setYear(0);
        }
        
        
    }
	Calendar::~Calendar(){
        for (int i = 0; i < 30; i++){
            delete list[i];
        }
        delete list;
    }

    bool Calendar::isEmpty()const{
        int empties=0;
        for (int i = 0; i < 30; i++){
            if (list[i]->get_day()==0 && list[i]->get_month()==0 && list[i]->get_year()==0){
                ++empties;
            }
            if (empties==30){
                return true;
            }
        }
        return false;
    }

	int Calendar::setDate(const MyDate& newDate, int num){
        //if the cell was empty before, then create a new MyDate, set it. 
        if (num<0 || num >30){
            return -1;
        }
        if (newDate.valiDate(newDate)){
            delete list[num];
            list[num] = new MyDate;
            list[num]->set(newDate.get_day(),newDate.get_month(),newDate.get_year());
            return 0;
        }
        
        return -1;
    }

	bool Calendar::isFree(int num)const{
        if (num<0 || num >30){
            return 0;
        }
        if (list[num]->get_day()==0 && list[num]->get_month()==0 && list[num]->get_year()==0){
            return 1;
        }
        return 0;
    }

	int Calendar::firstFree()const{
        for (int i = 0; i < 30; i++){
            if (list[i]->get_day()==0 && list[i]->get_month()==0 && list[i]->get_year()==0){
                return i;
            }
        }
        return -1;
    }

	int Calendar::insert(const MyDate& newDate){
        //if the list is full - return fail.
        int index=firstFree();
        if (index==-1){
            return -1;
        }
        
        if (newDate.valiDate(newDate)){
            setDate(newDate,index);
        return index;
        }
        return -1;
    }

    int Calendar::oldest()const{
        // if list is empty return -1
        if (isEmpty()) return -1;
        
        // count how many cells contain dates
        int n=0;
        for (int i = 0; i < 30; i++){
            if (!list[i]->valiDate(*list[i])) continue;
            else ++n;
        }
        MyDate *oldest=new MyDate;
        int oldest_index=0;
        
        // if list is full - pick some cell and assume its the oldest date (it doesnt matter).
        if (n==30){
        oldest->copy_date(*list[0]);
        oldest_index=0;
        }
        
        // else pick other cell date and say its the oldest (again - doesnt matter).
        else {
        oldest->copy_date(*list[firstFree()-1]);
        oldest_index=firstFree()-1;
        }

        // then run the whole calendar and check ecach cell
        for (int i = 0; i < 30; i++){
            //if the date in list[i] is older than "oldest" - replace it (skip 0/0/0 dates)
            if (list[i]->valiDate(*list[i]) && list[i]->isBefore(*oldest)==true){
                oldest->copy_date(*list[i]);
                oldest_index=i;
            }
        }
        delete oldest;
        return oldest_index;
    }

	int Calendar::datesNum(const MyDate& newDate){
        int counter=0;
        // if date is invalid, then it appears 0 times.
        if (!newDate.valiDate(newDate)){
            return 0;
        } 
        for (int i = 0; i < 30; i++){
            if (list[i]->get_day()==newDate.get_day() && list[i]->get_month()==newDate.get_month()\
                && list[i]->get_year()==newDate.get_year()){
                ++counter;
            }
        }
        
        return counter;
    }

	void Calendar::deleteAll(){
        for (int i = 0; i < 30; i++){
            deleteDate(i);
        }
        return;
    }

	int Calendar::deleteDate(int num){
        if (num<0 || num >30){
            return -1;
        }
        if (list[num]->get_day()!=0 && list[num]->get_month()!=0 && list[num]->get_year()!=0){
            delete list[num];
            list[num]=new MyDate;
            list[num]->setDay(0);
            list[num]->setMonth(0);
            list[num]->setYear(0);
            return 0;
        }
        
        return -1;
    }

	char* Calendar::print() const{
        // if the list is empty - print a message.
        if (isEmpty()){
            char* buffer=new char[15];
            buffer="Empty Calendar";
            cout<<buffer;
            return buffer;
        }
        
        char *Buf=new char[331]{};
        // else copy all the dates to a buffer, print & return it.
        for (int i = 0; i < 30; i++){  
            if(list[i]->get_day()==0 && list[i]->get_month()==0 && list[i]->get_year()==0){continue;}          
            strcat(Buf,list[i]->print());
        }
        return Buf;
    }

	void Calendar::swapDates(int date1_index, int date2_index){
        MyDate *temp=new MyDate;
        temp->copy_date(*list[date1_index]);
        list[date1_index]->copy_date(*list[date2_index]);
        list[date2_index]->copy_date(*temp);
        delete temp;
    }

	void Calendar::sortDates(){
        // if the list is empty return
        if (isEmpty()) return;

        // first, move empty cells to the end of the array.
        int i,j;
        for (i = 0; i < 29; i++){
            for (j = 0; j < 29-i; j++){
                if (list[j]->valiDate(*list[j])==false){
                    swapDates(j+1,j);
                }  
            }  
        }       
        // sort from bigest to smallest
        for (i = 0; i < 29; i++){
            for (j = 0; j < 29-i; j++){
                if (!list[j+1]->isBefore(*list[j])){
                    swapDates(j+1,j);
                }  
            }  
        }

        int n=0;
        // count how many cells contain dates
        for (int i = 0; i < 30; i++){
            if (!list[i]->valiDate(*list[i])) continue;
            else ++n;
        }

        // make it from the smallest to the biggest (reverse the previous order)
        for (int i = 0; i < n; i++){
            swapDates(i,--n);
        }
        

        return;
    }
