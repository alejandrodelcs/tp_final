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
    std::string strGenres[] = {"HISTORICA", "DRAMA", "COMEDIA", "FICCION", "SUSPENSO", "TERROR", "ROMANTICA"};
    Genres enumGenres[] = {Genres::HISTORICAL, Genres::DRAMA, Genres::COMEDY, Genres::FICTION, Genres::THRILLER, Genres::HORROR, Genres::ROMANCE};
    bool found = false;
    int position = 0;
    while (position < GENRES_SIZE && (!found)) {
        if (this->genre == enumGenres[position]) {
            std::cout<<"Genero: "<<strGenres[position]<<std::endl;
            found = true;
        }
        position++;
    }
}

Genres Novel::getGenre() {
    return this->genre;
}
