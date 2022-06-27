#include "Author.h"

Author::Author(int isni, std::string name, std::string nationality, int birth, int death) {
    this->isni = isni;
    this->name = name;
    this->nationality = nationality;
    this->birth = birth;
    this->death = death;
}

int Author::getISNI() {
    return this->isni;
}

std::string Author::getName() {
    return this->name;
}

std::string Author::getNationality() {
    return this->nationality;
}

int Author::getBirth() const {
    return this->birth;
}

int Author::getDeath() const {
    return this->death;
}

void Author::setDeath(int death) {
    this->death = death;
}

void Author::display() {
    //std::cout << "ISNI: " << getISNI() << std::endl; Para el docente
    std::cout << "Autor : " << getName() << std::endl;
    std::cout << "Nacionalidad : " << getNationality() << std::endl;
    if (getBirth() != -1) {
        std::cout << "Año de Nacimiento : " << getBirth() << std::endl;
    }
    if (getDeath() != -1) {
        std::cout << "Año de fallecimiento : " << getDeath() << std::endl;
    }
    std::cout << std::endl;
}