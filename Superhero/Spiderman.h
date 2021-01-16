#ifndef SPIDERMAN__H_
#define SPIDERMAN__H_

#include "AnimalBasedSuperHero.h"
#include "SuperHero.h"

class Spiderman :
	public AnimalBasedSuperHero
{
public:
	Spiderman();
	Spiderman(const char* name, double age, bool radioactive, const char* animal, double webSize);
	Spiderman(const char* animal, double webSize);
	Spiderman(double webSize);
	Spiderman(const Spiderman& spiderman);
	virtual ~Spiderman();

	double getWebSize() const;
	void setWebSize(double webSize);

	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;

protected:
	double _webSize;
};

#endif