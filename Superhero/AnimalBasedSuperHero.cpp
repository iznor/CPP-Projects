#include "AnimalBasedSuperHero.h"

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive,
                                           const char* animal, bool attack_mode = false)
    : SuperHero(name, age, radioactive, attack_mode) {
    m_animal = new char[strlen(animal) + 1]{};
    if (!Allocation_Check((char*)m_animal)) {
        return;
    }
    strcpy(m_animal, animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char* animal)
    : AnimalBasedSuperHero() {
    m_animal = new char[strlen(animal) + 1]{};
    if (!Allocation_Check((char*)m_animal)) {
        return;
    }
    strcpy(m_animal, animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero)
    : AnimalBasedSuperHero() {
    if (animalBasedSuperHero.isEmpty()) {
        return;
    }
    setNew_X(m_name, animalBasedSuperHero.m_name);
    m_age = animalBasedSuperHero.m_age;
    m_radioactive = animalBasedSuperHero.m_radioactive;
    m_attack_mode = animalBasedSuperHero.m_attack_mode;
    setNew_X(m_animal, animalBasedSuperHero.m_animal);
}
AnimalBasedSuperHero::~AnimalBasedSuperHero() {
    delete[] m_animal;
}
void AnimalBasedSuperHero::setAnimal(const char* animal) {
    setNew_X(m_animal, animal);
}
const char* AnimalBasedSuperHero::getAnimal() const {
    return m_animal == nullptr ? nullptr : m_animal;
}
void AnimalBasedSuperHero::print() const {
    if (isEmpty()) {
        cout << "(Empty)\n";
        return;
    }
    SuperHero::print();
    getAnimal() ? cout << "Animal: " << getAnimal() << "\n" : cout << "Animal: (Empty)\n";
}
bool AnimalBasedSuperHero::isEmpty() const {
    return (!m_name && !m_age && !m_radioactive && !m_animal && !m_attack_mode) ? true : false;
}
