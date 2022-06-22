#include "Cuento.h"

Cuento::Cuento(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, const std::string& book)
        : Reading(title, minutes, PublishYear) {
    this->type = 'C';
    this->id = id;
    this->title = title;
    this->book = book;
    this->minutes = minutes;
    this->PublishYear = PublishYear;
}

void Cuento::mostrar() {
    std::cout << "Cuento"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << PublishYear <<
              "\nTitulo libro: " << book << std::endl;
    if (id != 0 && this->getReader() != nullptr){
        std::cout << "Autor: " << this->getReader()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}