#include "CaptainAmerica.h"

CaptainAmerica::CaptainAmerica(const char* name, double age, bool radioactive,
                               const char* profession, int yearsExperience, bool attack_mode, double ageIncludingFreezing)
    : ProfessionBasedSuperHero(name, age, radioactive, profession, yearsExperience, attack_mode),
      m_ageIncludingFreezing(0) {
    if (ageIncludingFreezing < m_age) {
        return;
    } else {
        m_ageIncludingFreezing = ageIncludingFreezing;
    }
    if (Valid_YearsExperience(yearsExperience)) {
        m_yearsExperience = yearsExperience;
    }
}
CaptainAmerica::CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing)
    : ProfessionBasedSuperHero(profession, yearsExperience) {
    setAgeIncludingFreezing(ageIncludingFreezing);
}
CaptainAmerica::CaptainAmerica(double ageIncludingFreezing)
    : ProfessionBasedSuperHero() {
    setAgeIncludingFreezing(ageIncludingFreezing);
}
CaptainAmerica::CaptainAmerica(const CaptainAmerica& other)
    : CaptainAmerica() {
    if (other.isEmpty()) {
        return;
    }
    setNew_X(m_name, other.m_name);
    m_age = other.m_age;
    m_radioactive = other.m_radioactive;
    setNew_X(m_profession, other.m_profession);
    m_yearsExperience = other.m_yearsExperience;
    m_attack_mode = other.m_attack_mode;
    m_ageIncludingFreezing = other.m_ageIncludingFreezing;
}
double CaptainAmerica::getAgeIncludingFreezing() const {
    return m_ageIncludingFreezing;
}
void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing) {
    if (ageIncludingFreezing < m_age) {
        return;
    } else {
        m_ageIncludingFreezing = ageIncludingFreezing;
    }
}
void CaptainAmerica::print() const {
    ProfessionBasedSuperHero::print();
    cout << "Age Including Freezing: " << m_ageIncludingFreezing << endl;
}
bool CaptainAmerica::isEmpty() const {
    return (!m_name && !m_age && !m_radioactive && !m_profession && !m_yearsExperience &&
            !m_attack_mode && m_ageIncludingFreezing == 0)? true: false;
}
bool CaptainAmerica::Valid_YearsExperience(int n) const {
    return (n < 0 || n > m_ageIncludingFreezing && m_age != 0) ? false : true;
}