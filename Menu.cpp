#include <iostream>
#include "Menu.h"



Menu::Menu() {
    this->readings = new List<Reading*>;
    this->authors = new List<Author*>;
}


void Menu::displayMenu() {
    std::cout<<"1. Ingresar nueva lectura\n"
               "2. Lista las lecturas\n"
               "3. Ingresar nuevo autor/escritor\n"
               "4. Listar los autores\n"
               "4. Encontrar el orden y tiempo mínimo que nos\n"
               "llevaría leer todas las lecturas\n";

}


int Menu::input() {
    std::cout<<"Ingrese opcion: "<<std::endl;
    std::cin>>option;
    while(option<1 && option>4){
        std::cout<<"¡Error!. Opcion incorrecta"<<std::endl;
        std::cin>>option;
    }
    return this->option;
}

void * Menu::displayReadings() {

}

void * Menu::displayAuthors() {

}

void * Menu::newReading() {

}

void * Menu::newAuthor() {

}

void *Menu::shorterReadingTime() {

}




void Menu::generateList() {
    pReading.getReading(this->readings);
    pAuthors.getAuthor(this->authors);
}

void Menu::options() {
    this->generateList();
    void* arrayOptionsMenu[] = {newReading(),
                                displayReadings()
                                ,newAuthor(),
                                displayAuthors(),
                                shorterReadingTime()};
}



