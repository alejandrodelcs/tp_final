#include "Historica.h"


Historica::Historica(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre,
                     char* &theme) : Novela(id, title, minutes, PublishYear, genre) {
    this->id = id;
    this->title = title;
    this->genre = genre;
    (this->theme) = theme;
    this->PublishYear = PublishYear;
}


void Historica::mostrar(){
    std::cout << "Novela"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << PublishYear <<
              "\nGenero: HISTORICA" << std::endl;
    std::cout << "Tema: " << theme << std::endl;
    if (id != 0 && this->getAuthor() != nullptr){
        std::cout << "Autor: " << this->getAuthor()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}

Historica::~Historica() {
    delete[] theme;
}
