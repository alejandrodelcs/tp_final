#include <iostream>
#include "Menu.h"


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
               "5. Encontrar el orden y tiempo mínimo que nos\n"
               "   llevaría leer todas las lecturas\n"
               "6. Salir"<<std::endl;

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
    while(option<1 || option>6){
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
    std::cout<<authors->getTable()->getNumberOfElements()<<std::endl;
}

void Menu::options() {
    switch (this->option) {
        case 1:
            newReading();
            break;
        case 2:
            displayReadings();
            break;
        case 3:
            newAuthor();
            break;
        case 4:
            displayAuthors();
            break;
        case 5:
            shorterReadingTime();
        case 6:
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








