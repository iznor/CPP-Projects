#include "Spiderman.h"

Spiderman::Spiderman(const char* name, double age, bool radioactive, const char* animal,
                     double webSize, bool attack_mode = false)
    : AnimalBasedSuperHero(name, age, radioactive, animal, attack_mode) {
    if (webSize >= 0) {
        m_webSize = webSize;
    }
}
Spiderman::Spiderman(const char* animal, double webSize)
    : Spiderman() {
    setNew_X(m_animal, animal);
    if (webSize >= 0) {
        m_webSize = webSize;
    }
}
Spiderman::Spiderman(double webSize)
    : Spiderman() {
    if (webSize >= 0) {
        m_webSize = webSize;
    }
}
Spiderman::Spiderman(const Spiderman& other)
    : Spiderman() {
    if (other.isEmpty()) {
        return;
    }
    setNew_X(m_name, other.m_name);
    m_age = other.m_age;
    m_radioactive = other.m_radioactive;
    setNew_X(m_animal, other.m_animal);
    m_webSize = other.m_webSize;
    m_attack_mode = other.m_attack_mode;
}
double Spiderman::getWebSize() const {
    return m_webSize;
}
void Spiderman::setWebSize(double webSize) {
    if (webSize >= 0) {
        m_webSize = webSize;
    }
}
void Spiderman::print() const {
    AnimalBasedSuperHero::print();
    cout << "Web-Size: " << m_webSize << endl;
}
bool Spiderman::isEmpty() const {
    return (!m_name && !m_age && !m_radioactive && !m_animal && !m_attack_mode &&
            !m_webSize) ? true : false;
}
