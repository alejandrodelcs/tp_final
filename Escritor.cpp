#include "Escritor.h"

Escritor::Escritor(int id, std::string name, std::string nacionality, int yearBirth, int yearDeath) {
    this->id = id;
    this->name = name;
    this->nacionality = nacionality;
    this->yearBirth = yearBirth;
    this->yearDeath = yearDeath;
}

int Escritor::getId() {
    return this->id;
}

std::string Escritor::getName() {
    return this->name;
}

std::string Escritor::getNacionality() {
    return this->nacionality;
}

int Escritor::devolverBirth() const {
    return this->yearBirth;
}

int Escritor::devolverDeath() const {
    return this->yearDeath;
}

void Escritor::setYearDeath(int yearDeath) {
    this->yearDeath = yearDeath;
}

void Escritor::display() {
    std::cout << "Referencia: " << getId() << std::endl;
    std::cout << "Autor: " << getName() << std::endl;
    std::cout << "Nacionalidad: " << getNacionality() << std::endl;
    if (devolverBirth() != -1)
        std::cout << "Anio de nacimiento: " << devolverBirth() << std::endl;
    if (devolverDeath() != -1)
        std::cout << "Anio de fallecimiento: " << devolverDeath() << std::endl;
    std::cout << std::endl;
}