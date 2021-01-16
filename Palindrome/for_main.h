#ifndef MN_
#define MN_
#include "Pal.h"
#include <limits> //used to make sure the input is int)

// I used MACRO so the code is more readable, it includes:
// 1. showing the main menu 2. clear cin 3. print an error message 4. both clear cin & print an error message
#define SHOW_MENU cout << endl<< "\tPallindrome Menu" << endl;\
        cout << "1 - Create\t6 - Comparison\n2 - Update\t7 - Increment\n3 - Threading\t8 - Print Spcific Letter\n4 - Subtraction\t9 - Print\n5 - Add Char\t10 - Exit";\
        cout << "\t\nSelection: ";
#define CLR_CIN cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define ERR cout << "error" << endl;
#define CLR_CIN_AND_ERR cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');ERR;
#define INIT_PALLINDROM_ARRAY     for (int i = 0; i < 3; i++) {pal_arr[i] = Pallindrome();};
typedef enum{LeftBefore=-1, Equal, RightBefore}cmp;


//main funcs
bool Create(int i, Pallindrome p[]);
bool Update(int i, Pallindrome p[]);
bool Threading(int left, int right, int primary, Pallindrome p[]);
bool Subtraction(int left, int right, Pallindrome p[]);
bool Add_Char(int left, Pallindrome p[]);
bool Comparison(int left, int right, Pallindrome p[]);
bool Increment(int left, Pallindrome p[]);
bool Print_Spcific_Letter(int left, int index, Pallindrome p[]);
bool Print(int operand_index, Pallindrome p[]);

//helper Functions
bool create(Pallindrome *p);
int get_index(int i);
int what_to_init();
const char get_char();
bool does_exist(Pallindrome arr[], Pallindrome p);
void insert(Pallindrome arr[], Pallindrome p, int index);

#endif