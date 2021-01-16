#ifndef PLDRM
#define PLDRM

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50

class Pallindrome{
public:
    Pallindrome(): original(nullptr), pallindrome(nullptr) ,size(0){}
    Pallindrome(const char* string, int Size); 
    Pallindrome(const char* pallindrome_string); 
    Pallindrome(const Pallindrome& other);
    ~Pallindrome();
public:
    // Binar Operators
    Pallindrome& operator=(const Pallindrome& other);// Deep copy
    Pallindrome operator+(const Pallindrome& other)const;
    Pallindrome& operator+=(const Pallindrome& other);
    Pallindrome& operator+=(const char to_append);
    Pallindrome& operator-=(const Pallindrome& other);
    bool operator==(const Pallindrome& other)const;
    bool operator<(const Pallindrome& other)const;
    // Unar Operators
    Pallindrome& operator!();
    Pallindrome operator++(int);
    const char* operator()()const;
    const char& operator[](int index)const;

public:
    void Print()const;
    char* get_original()const;
    char* get_pallindrome()const;
    int get_size()const;
    bool odd_original()const;
    bool short_pallindrome()const;
    bool empty()const;
    bool sub_pallindrome(const Pallindrome& other)const;
    bool valid_index(int index)const;

private:
    char *pallindrome;
    char *original;
    int size;
    void set_size(int new_size);
    void set_original(char* new_org);
    void set_pallindrome(char* new_pall);
    int leftShift(char* string);// deletes the first char of a given string
    char *strremove(char *str, const char *sub);
    void reverse_string(char* string,int pallindrome_size); // Especially reverse a string according to a specific size given (can only work for 2*strlen or (2*strlen)-1)
    void clear_obj();
    friend ostream &operator<<(ostream &out, const Pallindrome& p);

};
    char* get_original_from_pallindrome(const char* string);// get a copy of the original string from a given pallindrome (doesn't change the given string)
    bool isPallindrome(const char *str);
    bool isPallindrome(char *str);
    bool ValidChars(const char *string);// Valid chars check (doesn't change the given string)
    istream &operator>>(istream &in, Pallindrome &pallindrome);// Input a string to Pallindrome object: if the string is a valid pallindrome - object will represent it. else, default c'tor.
    ostream &operator<<(ostream &out, const Pallindrome &pallindrome);

#endif