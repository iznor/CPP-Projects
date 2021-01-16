#ifndef _SM_
#define _SM_
#include "AnimalBasedSuperHero.h"
#include "SuperHero.h"

class Spiderman :
	public AnimalBasedSuperHero
{
public:
	Spiderman(): AnimalBasedSuperHero(), m_webSize(0){}
	Spiderman(const char* name, double age, bool radioactive, const char* animal,\
			  double webSize, bool attack_mode);
	Spiderman(const char* animal, double webSize);
	Spiderman(double webSize);
	Spiderman(const Spiderman& other);
	virtual SuperHero * Copy_and_Cast()const {return new Spiderman(*this);}

	virtual ~Spiderman(){}

	double getWebSize() const;
	void setWebSize(double webSize);
public:
	void virtual print()const;
	bool virtual isEmpty()const;

protected:
	double m_webSize;
};

#endif