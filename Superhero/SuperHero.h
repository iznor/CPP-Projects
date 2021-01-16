#pragma once


class SuperHero
{
public:
	SuperHero();
	SuperHero(const char* name, double age, bool radioactive=false);
	SuperHero(const SuperHero& superHero);
	virtual ~SuperHero();

public:
	const char* getName() const;
	double		getAge() const;
	bool		getRadioactive() const;
	void		setName(const char* name);
	void		setAge(double age);
	void		setRadioactive(bool radioactive);


protected:
	char*	m_name;
	double	m_age;
	bool	m_radioactive;
};
