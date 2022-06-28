#include "Poem.h"

Poem::Poem(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, unsigned int verses) : Reading(title, minutes, PublishYear) {
    this->type = 'P';
    this->isni = id;
    this->title = title;
    this->minutes= minutes;
    this->PublishYear = PublishYear;
    this->verses = verses;
}

void Poem::display() {
    std::cout << MAGENTA "Poema" WHITE
              "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAño de publicacion: " << PublishYear <<
              "\nCantidad de versos: " << verses << std::endl;
    if (isni != 0 && this->getAuthor() != nullptr){
        std::cout << "Autor: " << this->getAuthor()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}


Genres Poem::getGenre(){
    return Genres::UNKNOWN;
}