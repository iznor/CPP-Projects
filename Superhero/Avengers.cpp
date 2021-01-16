#include "Avengers.h"
Avengers::~Avengers() {
    clearSuperheros();
}
Avengers::Avengers(string teamName) : Avengers() {
    if (teamName.empty()) {
        cout << "Error";
        m_teamName = string();
    } else {
        m_teamName = string(teamName);
    }
}
void Avengers::setSuperHeros(SuperHero** superHeros, int size) {
    if (m_numSuperHeros > 0) {
        clearSuperheros();
    }
    if (size > 0) {
        if (m_superHeros) {
            for (int i = 0; i < m_numSuperHeros; i++) {
                delete m_superHeros[i];
            }
            delete[] m_superHeros;
        }
        m_numSuperHeros = size;
        m_superHeros = new SuperHero* [m_numSuperHeros] {};
        for (int i = 0; i < m_numSuperHeros; i++) {
            m_superHeros[i] = superHeros[i]->Copy_and_Cast();
        }
    }
}
void Avengers::addSuperHero(SuperHero* superHero) {
    SuperHero** superHeros = new SuperHero* [m_numSuperHeros + 1] {};
    if (m_superHeros) {
        for (int i = 0; i < m_numSuperHeros; i++) {
            superHeros[i] = m_superHeros[i];
        }
        delete[] m_superHeros;
    }
    ++m_numSuperHeros;
    superHeros[m_numSuperHeros - 1] = superHero;
    m_superHeros = superHeros;
}
SuperHero** Avengers::getSuperHeros() const {
    return m_superHeros;
}
int Avengers::getNumSuperHeros() const {
    return m_numSuperHeros;
}
void Avengers::printAvengersTeam() const {
    if (m_teamName.length())
        cout << "------------Team " << m_teamName << "------------" << endl;

    for (int i = 0; i < m_numSuperHeros; i++) {
        m_superHeros[i]->print();
        cout << endl;
    }
}
void Avengers::initiateTeamAttack(bool attackmode) {
    if (!m_superHeros) {
        cout << "Error";
        return;
    }
    for (int i = 0; i < m_numSuperHeros; i++) {
        if (m_superHeros[i]) {
            m_superHeros[i]->setAttackMode(true);
            string name = m_superHeros[i]->getName();
            if (!name.empty()) {
                attackmode ? cout << name << " Attack Mode: ON!" << endl : cout << name << " Attack Mode: OFF" << endl;
            }
        }
    }
}
void Avengers::clearSuperheros() {
    for (int i = 0; i < m_numSuperHeros; i++) delete m_superHeros[i];
    delete[] m_superHeros;
}
ostream& operator<<(ostream& out, const Avengers& avengers) {
    avengers.printAvengersTeam();
    return out;
}