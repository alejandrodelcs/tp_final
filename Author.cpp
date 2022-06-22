#include "Author.h"

Author::Author(int id, std::string name, std::string nacionality, int yearBirth, int yearDeath) {
    this->id = id;
    this->name = name;
    this->nacionality = nacionality;
    this->yearBirth = yearBirth;
    this->yearDeath = yearDeath;
}

int Author::getId() {
    return this->id;
}

std::string Author::getName() {
    return this->name;
}

std::string Author::getNationality() {
    return this->nacionality;
}

int Author::devolverBirth() const {
    return this->yearBirth;
}

int Author::devolverDeath() const {
    return this->yearDeath;
}

void Author::setYearDeath(int yearDeath) {
    this->yearDeath = yearDeath;
}

void Author::display() {
    std::cout << "Referencia: " << getId() << std::endl;
    std::cout << "Autor: " << getName() << std::endl;
    std::cout << "Nacionalidad: " << getNationality() << std::endl;
    if (devolverBirth() != -1)
        std::cout << "Anio de nacimiento: " << devolverBirth() << std::endl;
    if (devolverDeath() != -1)
        std::cout << "Anio de fallecimiento: " << devolverDeath() << std::endl;
    std::cout << std::endl;
}