//
// Created by julim on 29/06/2022.
//
#include "Constants.h"
#include "Reading.h"
#include "Historical.h"
#include "Novel.h"
#include "Tale.h"
#include "Poem.h"
#include <string>
#include <iostream>
///VALIDACIONES E INGRESOS///
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
    bool valid = false;
    int number;
    std::string auxNumber;

    while(!valid){
        std::cout << text << "\n" << CYAN "> " WHITE;
        getline(std::cin, auxNumber);
        bool haveLetters = validateNum(auxNumber);
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
    bool valid = false;
    std::string string;

    if (!text.empty()) {
        std::cout << text << std::endl;
    }

    while(!valid) {
        std::cout << CYAN "> " WHITE;
        getline(std::cin, string);
        bool haveNums= validateString(string);
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

Genres requestGenre(){
    bool valid= false;
    std::cout   << GREEN "[1] " << WHITE "- DRAMA\n"
                << GREEN "[2] " << WHITE "- COMEDIA\n"
                << GREEN "[3] " << WHITE "- FICCION\n"
                << GREEN "[4] " << WHITE "- SUSPENSO\n"
                << GREEN "[5] " << WHITE "- TERROR\n"
                << GREEN "[6] " << WHITE "- ROMANTICA\n";
    Genres enumGenre[] = {Genres::DRAMA, Genres::COMEDY, Genres::FICTION,
                          Genres::THRILLER, Genres::HORROR, Genres::ROMANCE};
    int position= requestNum("Ingrese el genero de la novela: ");

    while(!valid){
        if( position >= 1 && position <= 6 )
            valid = true;
        else
            std::cout << RED "Error: Entrada invalida!\n";
    }
    return enumGenre[(position-1)];
}

char *reserveMemoryTheme(unsigned long stringLength){
    char* t = new char[stringLength];
    return t;
}

char *requestTheme(){
    std::string stringTheme;
    char* newTheme = nullptr;
    stringTheme= requestAlphanum("Ingrese tema: ");
    newTheme = reserveMemoryTheme(stringTheme.length());
    for (unsigned int i = 0; stringTheme[i] != '\0'; i++){
        *(newTheme + i) = stringTheme[i];
    }
    return newTheme;
}

Reading* newNovel(int insi, std::string title, unsigned int minutes, unsigned int publishYear){
    Reading* novel;
    Genres genre = requestGenre();

    if (genre == Genres::HISTORICAL){
        char* theme = requestTheme();
        novel = new Historical(insi, title, minutes, publishYear, Genres::HISTORICAL, theme); //FALTA EL TEMA
    }
    else
        novel = new Novel(insi, title, minutes, publishYear, Genres::HISTORICAL);
    return novel;
}

Reading* newTale(int insi, std::string title, unsigned int minutes, unsigned int publishYear){
    Reading* tale;
    std::string book = requestAlphanum( GREEN "Ingresar el titulo del libro de publicacion." WHITE);
    tale= new Tale(insi, title, minutes,publishYear, book);
    return tale;
}

Reading* newPoem(int insi, std::string title, unsigned int minutes, unsigned int publishYear){
    Reading* poem;
    int verses = requestNum( GREEN "Ingrese la cantidad de versos del poema: " WHITE);
    poem = new Poem(insi, title, minutes, publishYear, verses);
    return poem;
}


///NUEVO AUTOR///

std::string requestName(){
    std::string name = requestAlpha(GREEN "Ingrese el nombre del autor: " WHITE);
    return name;
}

std::string validateNationality(){

}

std::string requestNationality(){
    std::string nationality = requestAlpha(GREEN "Ingrese la nacionalidad del autor: " WHITE);
    return nationality;
}

int requestBirth(){
    bool valid = false;
    int birth= requestNum(GREEN "Ingrese el año de nacimiento del autor, si se desonoce ingresar -1: " WHITE);
    while(!valid){
        if (birth > 0 || birth == (-1)){
            valid = true;
        } else
            std::cout << RED "Error: Entrada invalida" WHITE << std::endl;
    }
    return birth;
}

int requestDeath(int birth){
    bool valid = false;
    int death= requestNum(GREEN "Ingrese el año de fallecimiento del autor, si se desonoce ingresar -1: " WHITE);
    while(!valid){
        if (death > 0 || birth == (-1) && death > birth){
            valid = true;
        } else
            std::cout << RED "Error: Entrada invalida" WHITE << std::endl;
    }
    return birth;
}