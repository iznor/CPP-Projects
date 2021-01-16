#ifndef _ABSH_
#define _ABSH_

#include "SuperHero.h"
class AnimalBasedSuperHero : public SuperHero {
   public:
    AnimalBasedSuperHero() : SuperHero(), m_animal(nullptr) {}
    AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal,
                         bool attack_mode);
    AnimalBasedSuperHero(const char* animal);
    AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero);
    virtual ~AnimalBasedSuperHero();
    virtual SuperHero* Copy_and_Cast()const { return new AnimalBasedSuperHero(*this); }

   public:
    void setAnimal(const char* animal);
    const char* getAnimal() const;
    void virtual print() const;
    bool virtual isEmpty() const;
    // AnimalBasedSuperHero& operator=(const AnimalBasedSuperHero& other);

   protected:
    char* m_animal;
};

#endif