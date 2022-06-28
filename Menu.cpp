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
               "2. Mostrar lecturas\n" // SE PUEDE AGREGAR ELIMINAR Y ALTA (C/ SUBMENU), VA A DEPENDER COMO LLEGUEMOS
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

void Menu::addReading() {

}

void Menu::addAuthor() {

}

void Menu::shorterReadingTime() {

}

void Menu::searchAuthor() {

}

void Menu::removeAuthor() {

}

void Menu::validateInputOption() {
    while((option < ONE) || (option > EIGHT)) {
        std::cout<<"¡Error!. Opcion incorrecta"<<std::endl;
        this->input();
    }
}

void Menu::buildListReadings() {    
    pReading.setReadingList(this->readings);
    //this->readings = pReading.getReadings(); // TODO: Fix this error
}

void Menu::buildHashTable() {
    pAuthors.setReadings(readings);
    pAuthors.setAuthors(authors);
    //this->authors = pAuthors.getAuthors(); // TODO: Fix this error
}

void Menu::options() {
    switch (this->option) {
        case ONE:
            addReading();
            break;
        case TWO:
            displayReadings();
            break;
        case THREE:
            addAuthor();
            break;
        case FOUR:
            displayAuthors();
            break;
        case FIVE:
            searchAuthor();
            break;
        case SIX:
            removeAuthor();
            std::cout << "";
            break;
        case SEVEN:
            shorterReadingTime();
            break;
        case EIGHT:
            this->end = true;
        default:
            std::cout << "";
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
