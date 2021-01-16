#ifndef _SH_
#define _SH_
using namespace std;
#include <cstring>
#include <iostream>

class SuperHero {
   public:
    SuperHero() : m_name(nullptr), m_age(0), m_radioactive(false), m_attack_mode(false) {}  //default c'tor
    SuperHero(const char* name, double age, bool radioactive, bool attack_mode);
    SuperHero(const SuperHero& superHero);
    virtual ~SuperHero();

   public:
    const char* getName() const;
    double getAge() const;
    bool getRadioactive() const;
    bool getAttackMode() const;
    void setName(const char* name);
    void setAge(double age);
    void setRadioactive(bool radioactive);
    void setNew_X(char*& dest, const char* src);
    void setNew_X(char*& dest, char* src);
    void setAttackMode(bool attack_mode);
    virtual SuperHero* Copy_and_Cast()const { return new SuperHero(*this);}

   public:
    void virtual print() const;             // override in derived
    bool Allocation_Check(void* p) const;   // prints an error if allocation went wrong, else returns true.
    bool Valid_Age(double n) const;
    bool virtual isEmpty() const;           // override in derived
                                            // SuperHero& operator=(const SuperHero& other);

   protected:
    char* m_name;
    double m_age;
    bool m_radioactive;
    bool m_attack_mode;
};

/*--------------------------------------------------------------*/
ostream& operator<<(ostream& out, const SuperHero& superhero);

#endif