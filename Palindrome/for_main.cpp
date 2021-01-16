#include "for_main.h"
// main functions
bool Create(int i, Pallindrome p[]){
    Pallindrome *tmp = new Pallindrome;
    i = what_to_init();
    if (i == -1) {ERR;}
    if (!p[i].empty()) {ERR;i = -1;return false;}
    if (!create(tmp)) {ERR;return false;}
    if (does_exist(p, *tmp)) {ERR;return false;}
    insert(p, *tmp, i);
    delete tmp;
    i = -1;
    return true;
}
bool Update(int i, Pallindrome p[]){
    if (!(cin >> i)) {CLR_CIN_AND_ERR;i = -1;return false;} // wrong input error
    if (p[i - 1].empty()) {ERR;return false;}
    if (i < 1 || i > 3) {ERR;return false;}
    --i;
    cin >> p[i];
    i = -1;
    return true;
}
bool Threading(int left, int right, int primary, Pallindrome p[]){
    if (!(cin >> left)) {CLR_CIN_AND_ERR;return false;} // wrong input error
    if (p[left - 1].empty()) {ERR;return false;}
    if (!(cin >> right)) {CLR_CIN_AND_ERR;return false;}
    if (p[right - 1].empty()) {ERR;return false;}
    if (!(cin >> primary)) {CLR_CIN_AND_ERR;return false;}
    if (left < 1 || left > 3 || right < 1 || right > 3 || primary < 1 || primary > 3) {ERR;return false;}
    --primary;
    --left;
    --right;
    if (left == primary) {
        p[primary] += p[right];
    } else {
        p[primary] = p[left] + p[right];
    }
    primary = -1;
    right = -1;
    left = -1;
    return true;
}
bool Subtraction(int left, int right, Pallindrome p[]){
        if (!(cin >> left)) {CLR_CIN_AND_ERR;return false;} // wrong input error
        if (p[left - 1].empty()) {ERR;return false;}
        if (!(cin >> right)) {CLR_CIN_AND_ERR;return false;}
        if (p[right - 1].empty()) {ERR;return false;}
        if (left < 1 || left > 3 || right < 1 || right > 3) {ERR;return false;}
        --left;
        --right;
        p[left] -= p[right];
        right = -1;
        left = -1;
    return true;
}
bool Add_Char(int left, Pallindrome p[]){
    if (!(cin >> left)) {CLR_CIN_AND_ERR;return false;} // wrong input error
    if (p[left - 1].empty()) {ERR;return false;}
    if (left < 1 || left > 3) {ERR;return false;}
    --left;
    p[left] += get_char();
    left = -1;
    return true;
}
bool Comparison(int left, int right, Pallindrome p[]){
    if (!(cin >> left)) {CLR_CIN_AND_ERR;return false;} // wrong input error
    if (p[left - 1].empty()) {ERR;return false;}
    if (!(cin >> right)) {CLR_CIN_AND_ERR;return false;
    }
    if (p[right - 1].empty()) {ERR;return false;}
    if (left < 1 || left > 3 || right < 1 || right > 3) {ERR;return false;}
    --left;
    --right;
    if (p[left] < p[right]) {cout << LeftBefore << endl;}
    if (p[right] < p[left]) {cout << RightBefore << endl;}
    if (p[left] == p[right]) {cout << Equal << endl;}
    left = -1;
    right = -1;
    return true;
}
bool Increment(int left, Pallindrome p[]){
    if (!(cin >> left)) {CLR_CIN_AND_ERR;left = -1;return false;} // wrong input error
    if (p[left - 1].empty()) {ERR;left = -1;return false;}
    if (left < 1 || left > 3) {ERR;left = -1;return false;}
    --left;
    p[left]++;
    left = -1;
    return true;
}
bool Print_Spcific_Letter(int left, int index, Pallindrome p[]){
    if (!(cin >> left)) {CLR_CIN_AND_ERR;return false;}
    if (p[left - 1].empty()) {ERR;return false;}
    if (left < 1 || left > 3) {ERR;return false;}
    if (!(cin >> index)) {CLR_CIN_AND_ERR;return false;}
    if (p[left - 1].valid_index(index)) {
        --left;
        cout << p[left][index];
        left = -1;
        index = -1;
        return true;
    }
    ERR;
    return false;
}
bool Print(int operand, Pallindrome p[]){
    if (!(cin >> operand)) {CLR_CIN_AND_ERR;return false;}
    if (p[operand - 1].empty()) {ERR;return false;}
    if (operand < 1 || operand > 3) {ERR;return false;}
    --operand;
    cout << p[operand];
    operand = -1;
    return true;
}
// helper functions
bool create(Pallindrome *p) {
    char *buffer = new char[MAX]{};
    // int size=0;
    // cout<<"Size=> ";
    // cin>>size;
    cin.get();
    cout << "Palindrome String=> ";
    gets(buffer);
    // *p=Pallindrome(buffer,size);
    *p = Pallindrome(buffer);
    delete []buffer;
    if (p->empty()) {
        return false;
    }

    return true;
}
int get_index(int i) {
    i = -1;
    if (!(cin >> i)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return i = -1;
    }
    return i;
}
int what_to_init() {
    int i = -1;
    cout << "Which Pallindrome To Initialize(1-3)=> ";
    while (!(cin >> i))  // make sure input is a number !
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return i = -1;
    }

    if (i < 1 || i > 3) {
        i = -1;
        return i;
    }
    if (i == 1) i = 0;
    if (i == 2) i = 1;
    if (i == 3) i = 2;
    return i;
}
const char get_char() {
    char t;
    cin >> t;
    const char c = t;
    return c;
}
bool does_exist(Pallindrome arr[], Pallindrome p) {
    for (int i = 0; i < 3; i++) {
        if (p == arr[i]) {
            return true;
        }
    }
    return false;
}
void insert(Pallindrome arr[], Pallindrome p, int index) {
    arr[index] = p;
}