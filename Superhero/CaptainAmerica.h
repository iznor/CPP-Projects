#ifndef _CA_
#define _CA_

#include "ProfessionBasedSuperHero.h"
#include "SuperHero.h"

class CaptainAmerica : public ProfessionBasedSuperHero {
   public:
    CaptainAmerica() : ProfessionBasedSuperHero(), m_ageIncludingFreezing(0) {}
    CaptainAmerica(const char* name, double age, bool radioactive, const char* profession,
                   int yearsExperience, bool attack_mode, double ageIncludingFreezing);
    CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing);
    CaptainAmerica(double ageIncludingFreezing);
    CaptainAmerica(const CaptainAmerica& other);
    virtual SuperHero* Copy_and_Cast()const { return new CaptainAmerica(*this); }
    virtual ~CaptainAmerica() {}

   public:
    double getAgeIncludingFreezing() const;
    void setAgeIncludingFreezing(double ageIncludingFreezing);

   public:
    void virtual print() const;
    bool virtual isEmpty() const;
    bool virtual Valid_YearsExperience(int n) const;

   protected:
    double m_ageIncludingFreezing;
};

#endif