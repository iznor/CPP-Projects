#pragma once

#include "CaptainSpider.h"
#include "SuperHero.h"
#include "Spiderman.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "CaptainAmerica.h"

class Avengers
{
public:
	Avengers();
	~Avengers();

public:
	void setSuperHeros(SuperHero** superHeros, int size);
	void addSuperHero(SuperHero* superHero);
	SuperHero** getSuperHeros() const;
	void printAvengersTeam()const;
	void initiateTeamAttack();

private:
	SuperHero** m_superHeros;
	int			m_numSuperHeros;
};
