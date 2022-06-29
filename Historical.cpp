#include "Historical.h"


Historical::Historical(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre,
                     char* &theme) : Novel(id, title, minutes, PublishYear, genre) {
    this->type = 'H';
    this->isni = id;
    this->title = title;
    this->genre = genre;
    (this->theme) = theme;
    this->PublishYear = PublishYear;
}


void Historical::display(){
    std::cout << MAGENTA "Novela" WHITE
              "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAño de publicacion: " << PublishYear <<
              "\nGenero: HISTORICA" << std::endl;
    std::cout << "Tema: " << theme << std::endl;
    if (isni != 0 && this->getAuthors() != nullptr){
        std::cout << "Autor: " << this->getAuthors()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}

Historical::~Historical() {
    delete[] theme;
}
