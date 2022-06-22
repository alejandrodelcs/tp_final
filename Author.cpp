#include "Author.h"

Author::Author(int isni, std::string name, std::string natonality, int birth, int death) {
    this->isni = isni;
    this->name = name;
    this->nationality = natonality;
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
    std::cout << "ISNI: " << getISNI() << std::endl;
    std::cout << "Author: " << getName() << std::endl;
    std::cout << "Nationality: " << getNationality() << std::endl;
    if (getBirth() != -1) {
        std::cout << "Birth: " << getBirth() << std::endl;
    }
    if (getDeath() != -1) {
        std::cout << "Death: " << getDeath() << std::endl;
    }
    std::cout << std::endl;
}