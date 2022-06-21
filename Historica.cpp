#include "Historica.h"


Historica::Historica(int id, std::string &title, unsigned int minutes, unsigned int yearPublication, Genres genre,
                     char* &theme) : Novela(id, title, minutes, yearPublication, genre) {
    this->id = id;
    this->title = title;
    this->genre = genre;
    (this->theme) = theme;
    this->yearPublication = yearPublication;
}


void Historica::mostrar(){
    std::cout << "Novela"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << yearPublication <<
              "\nGenero: HISTORICA" << std::endl;
    std::cout << "Tema: " << theme << std::endl;
    if (id != 0 && this->getReader() != nullptr){
        std::cout << "Autor: " << this->getReader()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}

Historica::~Historica() {
    delete[] theme;
}
