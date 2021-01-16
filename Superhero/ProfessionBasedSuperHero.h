#ifndef _PBSH_
#define _PBSH_

#include "SuperHero.h"

class ProfessionBasedSuperHero : public SuperHero
{
public:
	ProfessionBasedSuperHero():SuperHero(), m_yearsExperience(0), m_profession(nullptr){}
	ProfessionBasedSuperHero(const char* name, double age, bool radioactive,const char* profession,\
							 int yearsExperience, bool attack_mode);
	ProfessionBasedSuperHero(const char* profession, int yearsExperience);
	ProfessionBasedSuperHero(const ProfessionBasedSuperHero& other);
	virtual ~ProfessionBasedSuperHero();
	virtual SuperHero * Copy_and_Cast()const {return new ProfessionBasedSuperHero(*this);}

public:
	void			setProfession(const char* profession);
	const char*		getProfession() const;
	void			setYearsExperience(int yearsExperience);
	int				getYearsExperience() const;
	bool virtual	Valid_YearsExperience(int n)const;
	void virtual	print()const;
	bool virtual	isEmpty()const;
	// ProfessionBasedSuperHero& operator=(const ProfessionBasedSuperHero& other);

protected:
	int		m_yearsExperience;
	char*	m_profession;
};

#endif