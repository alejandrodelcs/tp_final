#include "Novela.h"

Novela::Novela(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre) : Lectura(title, minutes, PublishYear) {
    this->type = 'N';
    this->id = id;
    this->title = title;
    this->minutes = minutes;
    this->PublishYear = PublishYear;
    this->genre = genre;
}


void Novela::mostrar() {
    std::cout << "Novela"
                 "\nTitulo: " << title <<
              "\nTiempo de lectura: " << minutes <<
              "\nAnio de publicacion: " << PublishYear << std::endl;
    this->displayGenre();
    if (id != 0 && this->getAuthor() != nullptr){
        std::cout << "Autor: " << this->getAuthor()->getName() << "\n" << std::endl;
    } else
        std::cout << "Autor: ANONIMO\n" << std::endl;
}


void Novela::displayGenre() {
    bool encontrado = false;
    int pos = 0;
    std::string gen[] = {"HISTORICA","DRAMA", "COMEDIA", "FICCION", "SUSPENSO",
                             "TERROR", "ROMANTICA"};
    Genres generosEnum[] = {Genres::HISTORICA, Genres::DRAMA, Genres::COMEDIA, Genres::FICCION, Genres::SUSPENSO,
                            Genres::TERROR, Genres::ROMANTICA};
    while (pos < GENRES_SIZE && (!encontrado)) {
        if (this->genre == generosEnum[pos]) {
            std::cout<<"Genero: "<<gen[pos]<<std::endl;
            encontrado = true;
        }
        pos++;
    }
}

Genres Novela::getGenre() {
    return this->genre;
}
