#include "Poema.h"

Poema::Poema(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, unsigned int verses) : Lectura(title, minutes, PublishYear) {
    this->type = 'P';
    this->id = id;
    this->title = title;
    this->minutes= minutes;
    this->PublishYear = PublishYear;
    this->verses = verses;
}

void Poema::mostrar() {
    std::cout << "Poema"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << PublishYear <<
              "\nCantidad de versos: " << verses << std::endl;
    if (id != 0 && this->getReader() != nullptr){
        std::cout << "Autor: " << this->getReader()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}