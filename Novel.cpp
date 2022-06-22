#include "Novel.h"

Novel::Novel(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre) : Reading(title, minutes, PublishYear) {
    this->type = 'N';
    this->id = id;
    this->title = title;
    this->minutes = minutes;
    this->PublishYear = PublishYear;
    this->genre = genre;
}


void Novel::display() {
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


void Novel::displayGenre() {
    bool finded = false;
    int position = 0;
    std::string gen[] = {"HISTORICA","DRAMA", "COMEDIA", "FICCION", "SUSPENSO",
                             "TERROR", "ROMANTICA"};
    Genres generosEnum[] = {Genres::HISTORICA, Genres::DRAMA, Genres::COMEDIA, Genres::FICCION, Genres::SUSPENSO,
                            Genres::TERROR, Genres::ROMANTICA};
    while (position < GENRES_SIZE && (!finded)) {
        if (this->genre == generosEnum[position]) {
            std::cout<<"Genero: "<<gen[position]<<std::endl;
            finded = true;
        }
        position++;
    }
}

Genres Novel::getGenre() {
    return this->genre;
}
