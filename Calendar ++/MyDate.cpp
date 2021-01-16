#include "MyDate.h"

//return true if a given date is valid, false if not.
bool MyDate::valiDate(const MyDate& date)const {
    if (&date==nullptr)
    {
        return false;
    }
    
    // make sure year is between 1900-2100
    if (date.get_year() < 1900 || date.get_year() > 2100) {
        return false;
    }

    // make sure month is between 1-12
    if (date.get_month() < 1 || date.get_month() > 12) {
        return false;
    }

    // if month is February, make sure day is between 1 to 28
    if (date.get_month() == 2) {
        if (date.get_day() < 1 || date.get_day() > 28) {
            return false;
        }
    }

    // else make sure day is between 1 to 30
    if (date.get_month() != 2) {
        if (date.get_day() < 1 || date.get_day() > 30) {
            return false;
        }
    }

    // if the date is legal
    return true;
}

bool MyDate::valiDate(int day, int month, int year)const {
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

void MyDate::ConvertPositive(MyDate& date) {
    //assume the given date has more than 30 days in it.

    MyDate new_date;
    new_date.copy_date(date);

    //check if the additional days are crossing February.
    if ((new_date.m_month == 1 && new_date.m_day > 58) || (new_date.m_month == 3 && new_date.m_day >= 358)\
        || (new_date.m_month == 4 && new_date.m_day >= 335) || (new_date.m_month == 5 && new_date.m_day >= 305)\
        || (new_date.m_month == 6 && new_date.m_day >= 275) || (new_date.m_month == 7 && new_date.m_day >= 245)\
        || (new_date.m_month == 7 && new_date.m_day >= 215) || (new_date.m_month == 8 && new_date.m_day >= 185)\
        || (new_date.m_month == 9 && new_date.m_day >= 155) || (new_date.m_month == 10 && new_date.m_day >= 125)\
        || (new_date.m_month == 11 && new_date.m_day >= 95)|| (new_date.m_month == 12 && new_date.m_day >= 65)){
        new_date.m_day-=3;
    }

    // if month != 2
    if (new_date.m_month != 2) {
        // if days > 30 do the right conversion to months
        new_date.m_month += new_date.m_day / 30;
        new_date.m_day = (new_date.m_day % 30);
        if (new_date.m_day == 0) {
            ++new_date.m_day;
        }
                
        // if the date is valid then replace with original
        if (valiDate(new_date)) {
            date.copy_date(new_date);
            return;
        }
   
        // if month is bigger than 12 do the right conversion to years
        new_date.m_year += new_date.m_month / 12;
        new_date.m_month = (new_date.m_month % 12);
        if (new_date.m_month == 0) {
            ++new_date.m_month;
        }

        // if the date is valid then replace with original
        if (valiDate(new_date)==true) {
            date.copy_date(new_date);
            return;
        }
        
        // if year is bigger than 2100 return error
        return;
    }

    // if month==2 then if days > 28 do the right conversion to months
    new_date.m_month += new_date.m_day / 28;
    new_date.m_day = (new_date.m_day % 28);
    if (new_date.m_day == 0) {
        ++new_date.m_day;
    }

        // if the date is valid then replace with original
    if (valiDate(new_date.m_day, new_date.m_month, new_date.m_year)) {
        date.copy_date(new_date);
        return;
    }

    // if month is bigger than 12 do the right conversion to years
    new_date.m_year += new_date.m_month / 12;
    new_date.m_month = (new_date.m_month % 12);
        if (new_date.m_month == 0) {
            ++new_date.m_month;
        }
        // if the date is valid then replace with original
    if (valiDate(new_date.m_day, new_date.m_month, new_date.m_year)) {
        date.copy_date(new_date);
        return;
    }
    // if year is bigger than 2100 do nothing
    return;
}

void MyDate::ConvertNegative(MyDate& date) {
    //assume the given date has negative number of days in it.
    MyDate new_date;
    new_date.copy_date(date);

    //check if the minus days are crossing February.
    if ((new_date.m_month == 3 && new_date.m_day <= -30) || (new_date.m_month == 2 && new_date.m_day <= -358)\
        || (new_date.m_month == 1 && new_date.m_day <= -335) || (new_date.m_month == 12 && new_date.m_day <= -305)\
        || (new_date.m_month == 11 && new_date.m_day <= -275) || (new_date.m_month == 10 && new_date.m_day <= -245)\
        || (new_date.m_month == 9 && new_date.m_day <= -215) || (new_date.m_month == 8 && new_date.m_day <= -185)\
        || (new_date.m_month == 7 && new_date.m_day <= -155) || (new_date.m_month == 6 && new_date.m_day <= -125)\
        || (new_date.m_month == 5 && new_date.m_day <= -95)|| (new_date.m_month == 4 && new_date.m_day <= -65)){
        new_date.m_day+=3;
    }

    // do the right conversion
    while(new_date.m_day<1){
        if (new_date.m_month==3){
            new_date.m_day+=28;
        }else{
            new_date.m_day+=30;
        }
        --new_date.m_month;
        if (new_date.m_month<1 && new_date.m_year>1900){
            new_date.m_month+=12;
            --new_date.m_year;
        }
    }
    
    // assert that if month ==2 there are no more than 28 days
    if (new_date.m_month==2 && new_date.m_day>28){
        ConvertPositive(new_date);
    }
    
    if (new_date.m_day == 0) {
        --new_date.m_day;
    }

    // if the date is valid then replace with original
    if (valiDate(new_date)) {
        date.copy_date(new_date);
        return;
    }
    
    // if year is smaller than 1900 return error
    return;
}

MyDate::MyDate():
m_day(0), m_month(0), m_year(0){}

MyDate::MyDate(const MyDate & other){
    if (other.get_day()==0 && other.get_month()==0 && other.get_year()==0){
        m_day = 0;
        m_month = 0;
        m_year = 0;
    }
    
    this->set(other.get_day(),other.get_month(),other.get_year());
}

MyDate::MyDate(int day, int month, int year) {
    if (valiDate(day, month, year) == true) {
        setDay(day);
        setMonth(month);
        setYear(year);
        return;
    } else {
        setDay(0);
        setMonth(0);
        setYear(0);
    }
}

void MyDate::init() {
    set(29,11,2020);
}

bool MyDate::isBefore(const MyDate& newDate)const {
    if (!newDate.valiDate(newDate)){
        return false;
    }
    
    if (m_year < newDate.m_year || (m_year == newDate.m_year && m_month < newDate.m_month) \
        || (m_year == newDate.m_year && m_month == newDate.m_month && m_day < newDate.m_day)) {
        return true;
    }
    return false;
}

int MyDate::delay(int num) {
    MyDate cpy;
    cpy.copy_date(*this);

    if (num < 1 || num > 365 || !valiDate(*this)) {
        return -1;
    }

    if (m_month != 2 && m_day + num <= 30) {
        m_day += num;
        return 0;
    }
    if (m_month == 2 && m_day + num <= 28) {
        m_day += num;
        return 0;
    }
    if (cpy.m_month != 2 && cpy.m_day + num > 30) {
        cpy.m_day += num;
        ConvertPositive(cpy);
        if (valiDate(cpy)) {
            this->copy_date(cpy);
            return 0;
        }
        return -1;
    }
    if (cpy.m_month == 2 && cpy.m_day + num > 28) {
        cpy.m_day += num;
        ConvertPositive(cpy);
        if (valiDate(cpy)) {
            this->copy_date(cpy);
            return 0;
        }
        return -1;
    }
    return -1;
}

int MyDate::bringForward(int num) {
    MyDate cpy;
    cpy.copy_date(*this);

    if (num < 1 || num > 365 || !valiDate(*this)) {
        return -1;
    }

    if (m_day - num > 0) {
        m_day += num;
        return 0;
    }

    cpy.m_day -= num;
    ConvertNegative(cpy);
    if (valiDate(cpy)) {
        this->copy_date(cpy);
        return 0;
    }
    return -1;
}

char* MyDate::print() const {
    cout<<get_print()<<" ";
    return get_print();
}

char* MyDate::get_print() const {
    MyDate temp;
    temp.set(this->m_day, this->m_month, this->m_year);
    
    char *day_buffer=new char[3]; //XX+null
    itoa(temp.m_day, day_buffer,10);
    char *month_buffer=new char[3]; //XX+null
    itoa(temp.m_month, month_buffer,10);
    char *year_buffer=new char[5]; //XXXX+null
    itoa(temp.m_year, year_buffer,10);
    int size=strlen(day_buffer)+strlen(month_buffer)+4;

    // make an array of chars in the size of the date +4 ("/", "/",NULL) and initialize it.
    char *date=new char[size+=3]{}; 
    
    strcat(date,day_buffer);
    delete[] day_buffer;
    strcat(date,"/");
    strcat(date,month_buffer);
    delete[] month_buffer;
    strcat(date,"/");
    strcat(date,year_buffer);
    delete[] year_buffer;
    return date;
}

bool MyDate::copy_date(const MyDate& new_date) {
    if(&new_date != nullptr){
        this->m_day=new_date.m_day;
        this->m_month=new_date.m_month;
        this->m_year=new_date.m_year;
        return true;
    }
    return false;
}

// setters & getters
int MyDate::set(int day, int month, int year) {
    if (valiDate(day, month, year) == true) {
        m_day = day;
        m_month = month;
        m_year = year;
        return 1;
    }
    return -1;
}

int MyDate::setDay(int day) {
    if (valiDate(day, 1, 1900) == true) {
        m_day = day;
        return day;
    } else {
        return -1;
    }
}

int MyDate::setMonth(int month) {
    if (valiDate(1, month, 1900) == true) {
        m_month = month;
        return month;
    } else {
        return -1;
    }
}

int MyDate::setYear(int year) {
    if (valiDate(1, 1, year) == true) {
        m_year = year;
        return year;
    } else {
        return -1;
    }
}

int MyDate::get_day() const {
    return this->m_day;
}

int MyDate::get_year() const {
    return this->m_year;
}

int MyDate::get_month() const {
    return this->m_month;
}
