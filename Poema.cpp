#include "Poema.h"

Poema::Poema(int id, std::string &title, unsigned int minutes, unsigned int yearPublication, unsigned int verses) : Lectura(title, minutes, yearPublication) {
    this->type = 'P';
    this->id = id;
    this->title = title;
    this->minutes= minutes;
    this->yearPublication = yearPublication;
    this->verses = verses;
}

void Poema::mostrar() {
    std::cout << "Poema"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << yearPublication <<
              "\nCantidad de versos: " << verses << std::endl;
    if (id != 0 && this->getReader() != nullptr){
        std::cout << "Autor: " << this->getReader()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}