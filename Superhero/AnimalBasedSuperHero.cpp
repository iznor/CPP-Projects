#include "AnimalBasedSuperHero.h"

AnimalBasedSuperHero::~AnimalBasedSuperHero(){}
AnimalBasedSuperHero::AnimalBasedSuperHero() : SuperHero() {
    m_animal = nullptr;
}

void AnimalBasedSuperHero::setMissing(const char* animal) {
    if (!animal) {
        cout << "generic error";
        animal = nullptr;
    } else {
        int len = strlen(animal) + 1;
        m_animal = new char[len];
        strncpy(m_animal, animal, len);
    }
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal) : SuperHero(name, age, radioactive) {
    setMissing(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char* animal) : SuperHero() {
    setMissing(animal);
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero) : SuperHero(animalBasedSuperHero) {
    setMissing(animalBasedSuperHero.m_animal);
}

void AnimalBasedSuperHero::setAnimal(const char* animal) {
    if (!animal) {
        cout << "generic error";
        return;
    }
    if (m_animal) delete[] m_animal;
    int len = strlen(animal) + 1;
    m_animal = new char[len];
    strncpy(m_animal, animal, len);
}

const char* AnimalBasedSuperHero::getAnimal() const {
    return m_animal;
}
