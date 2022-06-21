#include "Cuento.h"

Cuento::Cuento(int id, std::string &title, unsigned int minutes, unsigned int yearPublication, const std::string& book)
        : Lectura(title, minutes, yearPublication) {
    this->type = 'C';
    this->id = id;
    this->title = title;
    this->book = book;
    this->minutes = minutes;
    this->yearPublication = yearPublication;
}

void Cuento::mostrar() {
    std::cout << "Cuento"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << yearPublication <<
              "\nTitulo libro: " << book << std::endl;
    if (id != 0 && this->getReader() != nullptr){
        std::cout << "Autor: " << this->getReader()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}