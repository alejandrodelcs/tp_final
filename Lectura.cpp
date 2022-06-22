#include "Lectura.h"
#include <string>

Lectura::Lectura(const std::string& title, unsigned int minutes, unsigned int PublishYear) {
    this->minutes= minutes;
    this->PublishYear= PublishYear;
    this->author = nullptr;
}

unsigned int Lectura::GetPublishYear() const {
    return PublishYear;
}

void Lectura::setAutor(Escritor* escritor) {
    this->author = escritor;
}

Escritor* Lectura::getReader(){
    return this->author;
}

std::string Lectura::getTitle() {
    return title;
}

char Lectura::getType() const {
    return type;
}

unsigned int Lectura::getMinutes() const {
    return minutes;
}


int Lectura::getID() const {
    return id;
}


int Lectura::comparar(Lectura *l) const {
    int value = 0;
    if (this->PublishYear > l->GetPublishYear() ) {
        value = 1;
    } else if (this->PublishYear < l->GetPublishYear()) {
        value = -1;
    }
    return value;
}
