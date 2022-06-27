#include <iostream>
#include "Menu.h"
#include "Constants.h"


Menu::Menu() {
    this->readings = new List<Reading*>;
    this->authors = new HashTable<Author *>(20);
    this->end = false;
}

void Menu::displayMenu() {
    std::cout<<"1. Nueva lectura\n"
               "2. Mostrar lecturas\n"
               "3. Nuevo autor/escritor\n"
               "4. Mostrar autores\n"
               "5. Buscar autor\n"
               "6- Eliminar autor\n"
               "7. Encontrar el orden y tiempo mínimo que nos\n"
               "   llevaría leer todas las lecturas\n"
               "8. Salir"<<std::endl;

}

void Menu::input() {
    std::cout<<"Ingrese opcion: ";
    std::cin>>this->option;
}

void Menu::displayReadings() {
    pReading.displayReadings();

}

void Menu::displayAuthors() {
    pAuthors.displayAuthors();
}

void Menu::newReading() {

}

void Menu::newAuthor() {

}

void Menu::shorterReadingTime() {

}


void Menu::validateInputOption() {
    while(option<ONE || option>EIGHT){  // NO SE COMO LLAMAR A LAS CONSTANTES
        std::cout<<"¡Error!. Opcion incorrecta"<<std::endl;
        this->input();
    }
}

void Menu::buildListReadings() {
    pReading.setReadingList(this->readings);
    this->readings = pReading.getReading();
}

void Menu::buildHashTable() {
    pAuthors.setReadings(readings);
    pAuthors.setAuthors(authors);
    this->authors = pAuthors.getAuthor();
}

void Menu::options() {
    switch (this->option) {
        case ONE:
            newReading();
            break;
        case TWO:
            displayReadings();
            break;
        case THREE:
            newAuthor();
            break;
        case FOUR:
            displayAuthors();
            break;
        case FIVE:
            shorterReadingTime();
            break;
        case SIX:
            std::cout<<"";
            break;
        case SEVEN:
            break;
        case EIGHT:
            this->end = true;
        default:
            std::cout<<"";
            break;
    }
}



void Menu::interaction() {
    this->buildListReadings();
    this->buildHashTable();
    while(!this->end) {
        this->displayMenu();
        this->input();
        this->validateInputOption();
        this->options();
    }
}



Menu::~Menu() {
    delete authors;
}








