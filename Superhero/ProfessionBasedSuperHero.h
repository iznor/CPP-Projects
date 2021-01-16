#pragma once

#include "SuperHero.h"

class ProfessionBasedSuperHero : public SuperHero
{
public:
	ProfessionBasedSuperHero();
	ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience);
	ProfessionBasedSuperHero(const char* profession, int yearsExperience);
	ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero);
	virtual ~ProfessionBasedSuperHero();


public:
	void		setProfession(const char* profession);
	const char* getProfession() const { return _profession; }
	void		setYearsExperience(int yearsExperience);
	int			getYearsExperience() const;


protected:
	int		m_yearsExperience;
	char*	m_profession;
};
