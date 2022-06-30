//
// Created by julim on 29/06/2022.
//
#include "Constants.h"
#include "Reading.h"
#include <string>
#include <iostream>

bool validateNum(std::string number) {
    bool haveLetters;
    int digit = 0;
    while(digit <= number.length() && !haveLetters){
        if(std::isalpha(number[digit]))
            haveLetters = true;
        digit++;
    }
    return haveLetters;
}

int requestNum(std::string text){
    bool valid = false, haveLetters;
    int number;
    std::string auxNumber;

    while(!valid){
        std::cout << text << "\n" << CYAN "> " WHITE;
        getline(std::cin, auxNumber);
        haveLetters = validateNum(auxNumber);
        if(!haveLetters){
            number = std::stoi(auxNumber);
            valid = true;
        } else
            std::cout << RED "Error: Entrada invalida! \n" WHITE;
    }
    return number;
}

bool validateString(std::string string) {
    bool haveNums = false;
    int digit = 0;
    while((digit <= string.length()) && !haveNums){
        if (std::isdigit(string[digit]))
            haveNums = true;
        digit++;
    }
    return haveNums;
}

std::string requestAlpha(std::string text){
    bool valid = false, haveNums;
    std::string string;

    if (!text.empty()) {
        std::cout << text << std::endl;
    }

    while(!valid) {
        std::cout << CYAN "> " WHITE;
        getline(std::cin, string);
        haveNums= validateString(string);
        if (!haveNums) {
            valid = true;
        } else
            std::cout << RED "Error: Entrada invalida!\n" WHITE;
    }
    return string;
}

std::string requestAlphanum(std::string text){
    bool valid= false;
    std::string string;

    if (!text.empty()) {
        std::cout << text << std::endl;
    }
   while(!valid){
       std::cout << CYAN "> " WHITE;
       getline(std::cin, string);
       if (!string.empty()){
           valid = true;
       } else
           std::cout << RED "Error: Entrada invalida!\n" WHITE;
   }
    return string;
}


///NUEVA LECTURA///

unsigned int requestINSI(){
    bool valid = false;
    int insi = requestNum(GREEN "Ingrese el numero INSI si se desconoce ingresar 0: " WHITE);
    while (!valid){
        if (insi >= 1000 && insi <= 9999 || insi == 0)
            valid = true;
        else
            std::cout << RED "Error: El valor del INSI no es valido!\n";
    }
}

int requestType() {
    std::cout   << GREEN "Ingrese el TIPO de lectura a agregar\n" WHITE
                << GREEN  "[1] " << WHITE "- Novela\n"
                << GREEN "[2] " << WHITE "- Cuento\n"
                << GREEN "[3] " << WHITE "- Poema" << std::endl;
    int type= requestNum("Ingrese una opcion");
    while (type <1 || type > 4) {
        std::cout << RED "\n¡Error!. Opcion Incorrecta" WHITE << std::endl;
        type= requestNum(GREEN "Ingrese una opcion: " WHITE);
    }
    return type;
}

std::string requestTitle() {
    std::string title= requestAlphanum(GREEN "Ingresar el titulo: " WHITE);
    return title;
}

unsigned int requestMinutes(){
    int minutes= requestNum(GREEN "Ingrese los minutos estimados de la lectura: " WHITE);
    while (minutes < 1) {
        std::cout << RED "¡Error!. Minutos Incorrectos" WHITE << std::endl;
        minutes = requestNum(GREEN "Ingrese los minutos estimados de la lectura: " WHITE);
    }
    return minutes;
}

unsigned int requestPublishYear() {
    unsigned int publishYear = requestNum( GREEN "Ingrese el anio de publicacion de la lectura: " WHITE);
    while (publishYear < MINIMUM_YEAR) {
        std::cout << RED "¡\nError!. Anio incorrecto.\n" WHITE;
        publishYear = requestNum( GREEN "Ingrese el anio de publicacion de la lectura: " WHITE);
    }
    return publishYear;
}

Reading* newNovel(){

}

Reading* newTale(){

}

Reading* newPoem(){

}

void newReading(){
    int insi = requestINSI();
    int type = requestType();
    std::string title = requestTitle();
    unsigned int minutes = requestMinutes();
    unsigned int publishYear = requestPublishYear();

    switch (type) {
        case 1:
            newNovel();
        case 2:
            newTale();
        case 3:
            newPoem();
    }
}