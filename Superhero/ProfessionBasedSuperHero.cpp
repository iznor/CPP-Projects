#include "ProfessionBasedSuperHero.h"

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* name, double age, bool radioactive,
                                                   const char* profession, int yearsExperience, bool attack_mode = false)
    : SuperHero(name, age, radioactive, attack_mode) {
    setNew_X(m_profession, profession);
    if (Valid_YearsExperience(yearsExperience)) {
        m_yearsExperience = yearsExperience;
    }
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience)
    : ProfessionBasedSuperHero() {
    setNew_X(m_profession, profession);
    if (Valid_YearsExperience(yearsExperience)) {
        m_yearsExperience = yearsExperience;
    }
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero& other)
    : ProfessionBasedSuperHero() {
    if (other.isEmpty()) {
        return;
    }

    setNew_X(m_name, other.m_name);
    m_age = other.m_age;
    m_radioactive = other.m_radioactive;
    setNew_X(m_profession, other.m_profession);
    if (Valid_YearsExperience(other.m_yearsExperience)) {
        m_yearsExperience = other.m_yearsExperience;
    }
    m_attack_mode = other.m_attack_mode;
}
ProfessionBasedSuperHero::~ProfessionBasedSuperHero() {
    delete[] m_profession;
}
void ProfessionBasedSuperHero::setProfession(const char* profession) {
    setNew_X(m_profession, profession);
}
const char* ProfessionBasedSuperHero::getProfession() const {
    return m_profession;
}
void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience) {
    if (Valid_YearsExperience(yearsExperience)) {
        m_yearsExperience = yearsExperience;
    }
}
bool ProfessionBasedSuperHero::Valid_YearsExperience(int n) const {
    return (n < 0 || n > m_age && m_age != 0) ? false : true;
}
int ProfessionBasedSuperHero::getYearsExperience() const {
    return m_yearsExperience;
}
void ProfessionBasedSuperHero::print() const {
    if (isEmpty()) {
        cout << "(Empty)\n";
        return;
    }
    SuperHero::print();
    getProfession() ? cout << "Profession: " << getProfession() << "\n" : cout << "Profession: (Empty)\n";
    cout << "Years of experience: " << getYearsExperience() << endl;
}
bool ProfessionBasedSuperHero::isEmpty() const {
    return (!m_name && !m_age && !m_radioactive && !m_profession && !m_yearsExperience && !m_attack_mode) ? true : false;
}