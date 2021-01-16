#include "Pal.h"

Pallindrome::Pallindrome(const char* string, int Size) : Pallindrome(){
    // Valid chars check
    if (!ValidChars(string)){
        cout<<"ERROR! Invalid Letter(s) Input"<<endl;
        return;
    }
    // Size validation Check:
    if (!(Size == strlen(string)*2 || Size == (strlen(string)*2)-1)){
        cout<<"ERROR - Size Can Only Be "<<strlen(string)*2<<" OR "<<(strlen(string)*2)-1<<endl;
        return;
    }
    // If passed the validation check, assign Size as the pallindrome object's size
    // Allocate 3 new strings,'original' to save the original given string,
    // 'pallindrome' for the 1st part of the pallindrome, 'appendix' for the 2nd part of the pallindrome
    size=Size;
    original=new char[strlen(string)+1]{};
    pallindrome= new char[Size+1]{};
    char *appendix=new char[strlen(string)+1]{};
    strncpy(original, string, strlen(string));// Copy the given string to 'original' & to the 1st part of the pallindrome
    strncat(pallindrome, string,strlen(string));
    strncpy(appendix,string,strlen(string));// Copy the given string to the 2nd part
    reverse_string(appendix, size);// Reverse the 2nd part
    strcat(pallindrome,appendix);// Merge both parts into one
    delete[]appendix;// 'appendix' can now be deleted
}
Pallindrome::Pallindrome(const Pallindrome& other){
    *this=other;
}
Pallindrome::Pallindrome(const char* pallindrome_string):Pallindrome(){
    if (!isPallindrome(pallindrome_string)){
        return;
    }
    
    char *buffer=new char[MAX]{};
    strcpy(buffer,pallindrome_string);
    int size=strlen(buffer);
    if (!ValidChars(buffer) || !(isPallindrome(buffer))){
        return;
    }
    buffer=get_original_from_pallindrome(buffer);

    if (buffer){
        *this=Pallindrome(buffer,size);
        return;
    }else{
        return;
    }
    return;
}
Pallindrome::~Pallindrome(){
    delete []original;
    delete []pallindrome;
    size=0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
Pallindrome& Pallindrome::operator=(const Pallindrome& other)
{
    if (!(&other) || !(other.get_original()) || !(other.get_pallindrome()) || !(other.get_size())){
        clear_obj();
        return *this;
    }
    
    set_size(other.get_size());
    set_original(other.get_original());
    set_pallindrome(other.get_pallindrome());
    return *this;
}
Pallindrome Pallindrome::operator+(const Pallindrome& other)const{
    Pallindrome *tmp = new Pallindrome(*this);
    return *tmp+=other;

    // return Pallindrome(tmp);
    // return Pallindrome(this+=other);
}
Pallindrome& Pallindrome::operator!(){
    strlwr(original); strlwr(pallindrome);
    return *this;
}
const char* Pallindrome::operator()()const{
    if(empty())return nullptr;
    const char *result(pallindrome);
    return result;
}
Pallindrome& Pallindrome::operator+=(const Pallindrome& other){
    // If object is empty, deep copy 'other' object to original
    if (empty()) return *this=other;
    char* temp=new char[strlen(original)+strlen(other.original)+1]{};
    strcat(temp,original); strcat(temp,other.original);
    int new_size=size+other.size;
    if ((odd_original() && size!=strlen(original)*2)|| (size<strlen(original)*2 || size<strlen(original)*2-1))
    {
        ++new_size;
    }    
    *this=Pallindrome(temp,new_size);
    delete []temp;
    return *this;
}
Pallindrome& Pallindrome::operator+=(const char to_append){
    // Char validation check
    if (!(to_append>='0'&&to_append<='9') && !(to_append>='a'&&to_append<='z') && !(to_append>='A'&&to_append<='Z')){
        cout<<"ERROR! Invalid Letter(s) Input"<<endl;
        return *this;
    }
    
    char *temp=new char[2]{};
    temp[0]=to_append; //error 
    
    // add a term for ++size ?? like the other += method

    if (empty()){
        Pallindrome *temPallindrome = new Pallindrome(temp,2);
        *this=*temPallindrome;
        delete temPallindrome;
        delete []temp;
        return *this;
    }

    char *buffer=new char[strlen(original)+2]{}; //error
    strcat(buffer,temp);
    strcat(buffer,original);
    Pallindrome *temPallindrome= new Pallindrome(buffer,strlen(pallindrome)+2);
    clear_obj();
    *this=*temPallindrome;
    delete []buffer; delete []temp; delete temPallindrome;
    return *this;
}
Pallindrome& Pallindrome::operator-=(const Pallindrome& other){
    if (sub_pallindrome(other)){
        char *tmp=get_original_from_pallindrome(other.get_pallindrome());
        char *new_org=new char[strlen(get_original())+1]{};
        strcpy(new_org,original);
        if (strcmp(new_org,tmp)==0){
            if (other.get_size()==get_size()){
                delete []tmp;
                delete []new_org;
                clear_obj();
            }
            return *this;
        }
        strremove(new_org,tmp);
        int new_size=0;
        if (short_pallindrome()){
            new_size=2*strlen(new_org)-1;
        }else{
            new_size=2*strlen(new_org);
        }
        *this=Pallindrome(new_org,new_size);
        delete []tmp;
        delete []new_org;
        return *this;
    }     
    return *this;
}
Pallindrome Pallindrome::operator++(int){
    char* old_string=new char[strlen(original)+1]{};
    strcpy(old_string,original);
    Pallindrome tmp(old_string,size);
    if (original[0]=='9'){
        original[0]='0';
        Pallindrome *tmp2=new Pallindrome(original,size);
        *this=*tmp2;
        delete tmp2;
        return tmp;
    }
    if (original[0]=='z'){
        original[0]='a';
        Pallindrome *tmp2=new Pallindrome(original,size);
        *this=*tmp2;
        delete tmp2;
        return tmp;
    }
    if (original[0]=='Z'){
        original[0]='A';
        Pallindrome *tmp2=new Pallindrome(original,size);
        *this=*tmp2;
        delete tmp2;
        return tmp;
    }
    if (!(original[0]=='9')&&!(original[0]=='z')||!(original[0]=='Z')){
        ++original[0];
        Pallindrome *tmp2=new Pallindrome(original,size);
        *this=*tmp2;
        delete tmp2;
        return tmp;
    }
    return *this;
}
bool Pallindrome::operator==(const Pallindrome& other)const{
    if(empty())return false;
    if (size!=other.size || other.empty()){
        return false;
    }
    
    char *str1=new char[strlen(original)+1];
    char *str2=new char[strlen(original)+1];
    strcpy(str1,original); strcpy(str2,other.original);
    strupr(str1); strupr(str2);
    if (strcmp(str1,str2)==0){
        delete []str1; delete []str2;
        return true;
    }
    delete []str1; delete []str2;
    return false;
    
}
bool Pallindrome::operator<(const Pallindrome& other)const{
    if(empty())return false;
    if (*this==other || other.empty()){
        return false;
    }
    char *str1=new char[strlen(pallindrome)+1];
    char *str2=new char[strlen(pallindrome)+1];
    strcpy(str1,pallindrome); strcpy(str2,other.pallindrome);
    strupr(str1); strupr(str2);
    
    if (strcmp(str1,str2)<0){
        delete []str1; delete []str2;
        return true;
    }
    if (strcmp(str1,str2)>0){
        delete []str1; delete []str2;
        return false;
    }
    
    delete []str1; delete []str2;
    return false;
}
const char& Pallindrome::operator[](int index)const{
    if (valid_index(index)){
        return pallindrome[index];
    }
	return '\0';
}
ostream& operator<<(ostream &out, const Pallindrome &p){
    if (p.empty()){
        return out;
    }
    
    out<<p()<<endl;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
bool Pallindrome::valid_index(int index)const{
        if (index >= 0 && index < strlen(get_pallindrome())){
            return true;
        }
        return false;
    }
bool Pallindrome::odd_original()const{
    if (strlen(original)%2==0){
        return false;
    }
    return true;
}
bool Pallindrome::short_pallindrome()const{
    if (size==2*strlen(original)){
        return false;
    }
    if (size==2*strlen(original)-1){
        return true;
    }
    return false;
}
void Pallindrome::reverse_string(char* appendix,int pallindrome_size){
    // Set a flag, according to the desired size (short version of a pallindrome ot long version)
    bool shorty=false;
    bool longy=false;
    if (pallindrome_size==2*strlen(appendix)) longy=true;
    if (pallindrome_size==(2*strlen(appendix))-1) shorty=true;
    if (!shorty && !longy){
        return;
    }
    // Make a reverse copy of the original string, call it "mirror" (a temp string)
    int len = strlen(appendix);
    char* mirror=new char[len+1];
    int i = 0;
    while (len > 0){
        mirror[i] = appendix[len - 1];
        i++;
        len--;
    }
    mirror[strlen(appendix)]='\0';  //  Handle last char

    // Handle a short version of a pallindrome
    if (shorty){
        strncpy(appendix,mirror,strlen(mirror));// Copy the remain "mirror" to "string"
        leftShift(appendix);// Take out the first letter
    }
    // Handle a long version of a pallindrome
    if (longy){
        strncpy(appendix,mirror,strlen(mirror));
    }
    delete []mirror; // Delete temp string "mirror"
}
void Pallindrome::Print()const{
    if (get_pallindrome()==nullptr || get_original()==nullptr){
        cout<<"Pallindrome: NULL"<<endl;
        cout<<"Original: NULL"<<endl;
        return;
    }
    cout<<"Original: "<<get_original()<<endl;
    cout<<"Pallindrome: "<<get_pallindrome()<<endl;
}
bool Pallindrome::empty()const{
    if (get_size()==0 && !(get_original()) && !(get_pallindrome())){
        return true;
    }
    return false;
}
char* Pallindrome::get_original()const{
    return original;
}
char* Pallindrome::get_pallindrome()const{
    return pallindrome;
}
int Pallindrome::get_size()const{
    return size;
}
bool Pallindrome::sub_pallindrome(const Pallindrome& other)const{
    // Extract original string from a given pallindrome.
    const char *tmp=other.get_pallindrome();
    tmp=get_original_from_pallindrome(tmp);
    return strstr(original,tmp) ? true : false;
}
char *Pallindrome::strremove(char *str, const char *sub) {
    int len = strlen(sub);
    if (len > 0) {
        char *p = str;
        while ((p = strstr(p, sub)) != NULL) {
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }
    return str;
}
int Pallindrome::leftShift(char* string) 
{
    int i;
    int len=strlen(string);
    int last_index=len-1;
    for(i = 1; i < len; i++)
    {
        string[i - 1] = string[i];
    }
    len--;
    string[last_index]='\0';
    len--;
    return len;
}
void Pallindrome::set_size(int new_size){
    size=new_size;
}
void Pallindrome::set_original(char* new_org){
    if (original){
        original=nullptr;
    }
    original=new char[strlen(new_org)+1]{};
    strcat(original,new_org);
}
void Pallindrome::set_pallindrome(char* new_pall){
    if (pallindrome){
        pallindrome=nullptr;
    }
    pallindrome=new char[strlen(new_pall)+1]{};
    strcpy(pallindrome,new_pall);
}
void Pallindrome::clear_obj(){
    size=0; original=nullptr; pallindrome=nullptr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//=========================
// Non-Member Functions  //
//=========================
// Returns true if a given string is pallindrome, else false (doesn't change the given string)
bool isPallindrome(const char *str) 
{
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
            return false;
    }

    return true;
}
bool isPallindrome(char *str) 
{
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
            return false;
    }

    return true;
}
char* get_original_from_pallindrome(const char* string){
        int size=strlen(string);
        char *result=new char[size+1]{};
    if (isPallindrome(string)){
        if (size%2==0){
            for (int i = 0; i < size/2; i++){
                result[i]=string[i];
            }
            return result;
        } else {
            for (int i = 0; i <= size/2; i++){
                result[i]=string[i];
            }
            return result;        
            }
        }
    delete []result;
    return nullptr;
}
bool ValidChars(const char *string){
    int String_size=strlen(string);
    for (int i = 0; i < String_size; i++){
        if (!(string[i]>='0'&&string[i]<='9') && !(string[i]>='a'&&string[i]<='z') && !(string[i]>='A'&&string[i]<='Z')){
            cout<<"ERROR! Invalid Letter(s) Input"<<endl;
            return false;
        }
    }
    return true;
    
}
istream &operator>>(istream &in, Pallindrome &pallindrome){
    char *buffer=new char[MAX]{};
    in>>buffer;
    int size=strlen(buffer);
    if (!ValidChars(buffer) || !(isPallindrome(buffer))){
        return cin;
    }
    buffer=get_original_from_pallindrome(buffer);
    if (buffer){
        pallindrome=Pallindrome(buffer,size);
    }else{
        pallindrome=Pallindrome();
    }
    return cin;
}