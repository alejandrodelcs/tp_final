#include <iostream>
#include "Menu.h"


Menu::Menu() {
    this->readings = new List<Reading*>;
    this->authors = new List<Author*>;
    this->end = false;
}

void Menu::displayMenu() {
    std::cout<<"1. Ingresar nueva lectura\n"
               "2. Lista las lecturas\n"
               "3. Ingresar nuevo autor/escritor\n"
               "4. Listar los autores\n"
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


void Menu::generateList() {
    pReading.getReading(this->readings);
    pAuthors.getAuthor(this->authors);
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
    this->generateList();
    while(!this->end) {
        this->displayMenu();
        this->input();
        this->validateInputOption();
        this->options();
    }
}

Menu::~Menu() {

}






