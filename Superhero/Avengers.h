#ifndef _AVNG_
#define _AVNG_

#include "AnimalBasedSuperHero.h"
#include "CaptainAmerica.h"
#include "ProfessionBasedSuperHero.h"
#include "Spiderman.h"
#include "SuperHero.h"

class Avengers {
   public:
    Avengers() : m_superHeros(nullptr), m_numSuperHeros(0), m_teamName(string()) {}
    Avengers(string teamName);
    ~Avengers();

   public:
    void setSuperHeros(SuperHero** superHeros, int size);
    void addSuperHero(SuperHero* superHero);
    SuperHero** getSuperHeros() const;
    void printAvengersTeam() const;
    void initiateTeamAttack(bool attackmode = false);
    int getNumSuperHeros() const;

   private:
    void clearSuperheros();
    SuperHero** m_superHeros;
    int m_numSuperHeros;
    string m_teamName;
};

ostream& operator<<(ostream& out, const Avengers& avengers);

#endif