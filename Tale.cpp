#include "Tale.h"

Tale::Tale(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, const std::string& book)
        : Reading(title, minutes, PublishYear) {
    this->type = 'C';
    this->id = id;
    this->title = title;
    this->book = book;
    this->minutes = minutes;
    this->PublishYear = PublishYear;
}

void Tale::display() {
    std::cout << "Cuento"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << PublishYear <<
              "\nTitulo libro: " << book << std::endl;
    if (id != 0 && this->getAuthor() != nullptr){
        std::cout << "Autor: " << this->getAuthor()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}