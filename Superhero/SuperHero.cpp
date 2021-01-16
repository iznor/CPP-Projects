#include "SuperHero.h"

SuperHero::SuperHero(const char* name, double age = 0, bool radioactive = false, bool attack_mode = false)
    : SuperHero() {
    if (!Valid_Age(age)) {
        return;
    }
    m_radioactive = radioactive;
    m_attack_mode = attack_mode;
    m_age = age;
    m_name = new char[strlen(name) + 1]{};
    if (!Allocation_Check((char*)m_name)) {
        return;
    }
    strcpy(m_name, name);
}
SuperHero::SuperHero(const SuperHero& superHero)
    : SuperHero() {
    if (superHero.isEmpty()) return;
    setNew_X(m_name, superHero.m_name);
    m_age = superHero.m_age;
    m_radioactive = superHero.m_radioactive;
    m_attack_mode = superHero.m_attack_mode;
}
SuperHero::~SuperHero() {
    delete[] m_name;
}
const char* SuperHero::getName() const {
    return m_name == nullptr ? nullptr : m_name;
}
double SuperHero::getAge() const {
    return m_age;
}
bool SuperHero::getRadioactive() const {
    return m_radioactive;
}
bool SuperHero::getAttackMode() const {
    return m_attack_mode;
}
void SuperHero::print() const {
    cout << "SuperHero Details:\n";
    if (isEmpty()) {
        cout << "(Empty)\n";
        return;
    }
    getName() ? cout << "Name: " << getName() << "\n" : cout << "Name: (Empty)\n";
    cout << "Age: " << (int)getAge() << endl;
    getRadioactive() ? cout << "Radioactive: ON\n" : cout << "Radioactive: OFF\n";
    getAttackMode() ? cout << "Attack Mode: ON\n" : cout << "Attack Mode: OFF\n";
}
void SuperHero::setName(const char* name) {
    setNew_X(m_name, name);
}
void SuperHero::setNew_X(char*& dest, const char* src) {
    dest = new char[strlen(src) + 1]{};
    if (!Allocation_Check((char*)dest)) {
        return;
    }
    strcpy(dest, src);
}
void SuperHero::setNew_X(char*& dest, char* src) {
    if (!src) {
        dest = nullptr;
        return;
    }
    if (dest) {
        delete[] dest;
    }
    dest = new char[strlen(src) + 1]{};
    if (!Allocation_Check((char*)dest)) {
        return;
    }
    strcpy(dest, src);
}
void SuperHero::setAge(double age) {
    if (Valid_Age(age)) {
        m_age = age;
    }
}
void SuperHero::setRadioactive(bool radioactive) {
    m_radioactive = radioactive;
}
void SuperHero::setAttackMode(bool attack_mode) {
    m_attack_mode = attack_mode;
}
bool SuperHero::Allocation_Check(void* p) const {
    return p == nullptr ? cout << "ERROR!, allocation failed\n", false : true;
}
bool SuperHero::Valid_Age(double n) const {
    return (n < 15 || n > 40) ? false : true;
}
bool SuperHero::isEmpty() const {
    return (!m_name && !m_age && !m_radioactive && !m_attack_mode) ? true : false;
}
ostream& operator<<(ostream& out, const SuperHero& superhero) {
    superhero.print();
    return out;
}