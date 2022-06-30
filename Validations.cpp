#include "Validations.h"

/// DATA INPUT AND VALIDATIONS ///

bool validateNumber(std::string string) {
    bool haveLetters = false;
    int digit = 0;
    while((digit <= (int)string.length()) && !haveLetters) {
        if (std::isalpha(string[digit]))
            haveLetters = true;
        digit++;
    }
    return haveLetters;
}

int requestNum(const std::string& text){
    bool valid = false, haveLetters;
    int number;
    std::string auxNumero;

    while (!valid) {
        std::cout << text << "\n" << CYAN "> " WHITE;
        getline(std::cin, auxNumero);
        haveLetters = validateNumber(auxNumero);
        if(!haveLetters){
            number = stoi(auxNumero);
            valid = true;
        } else
            std::cout << RED "Error: Entrada invalida!\n" WHITE;
    }
    return number;
}

bool validateString(std::string string) {
    bool haveNumbers = false;
    int character = 0;
    while ((character <= (int)string.length()) && !haveNumbers) {
        if ((std::isdigit(string[character])))
            haveNumbers = true;
        character++;
    }
    return haveNumbers;
}

std::string requestAlpha(const std::string& text) {
    bool valid = false;
    bool haveNumbers;
    std::string cadena;

    if (!text.empty()) {
        std::cout << text << std::endl;
    }
    while (!valid) {
        std::cout << CYAN "> " WHITE;
        getline(std::cin, cadena);
        haveNumbers = validateString(cadena);
        if (haveNumbers) {
            std::cout << RED "Error: Entrada invalida!\n" WHITE;
        } else
            valid = true;
    }
    std::cout << std::endl;
    return cadena;
}

std::string requestAlphanum(std::string text){
    bool valid = false;
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

/// NEW READINGS ///

int requestISNI(){
    srand((unsigned int)time(NULL));
    int isni = 1000+rand()%(9999-1000);
    return isni;
}

int requestType(){
    std::cout   << GREEN "Ingrese el numero dependiendo del tipo de lectura que quiera agregar\n" WHITE
                << GREEN "[1] " << WHITE "- Novelas\n"
                << GREEN "[2] " << WHITE "- Cuentos\n"
                << GREEN "[3] " << WHITE "- Poemas" << std::endl;
    int type = requestNum( GREEN "Ingrese una opcion: " WHITE);

    while (type < 1 || type > 4){
        std::cout << RED "\n¡Error!. Opcion Incorrecta" WHITE << std::endl;
        type = requestNum( GREEN"Ingrese una opcion: " WHITE);
    }
    return type;
}

std::string requestTitle() {
    std::string title = requestAlphanum(GREEN "Ingresar el titulo: " WHITE);
    return title;
}

unsigned int requestMinutes() {
    int minutes = requestNum( GREEN "Ingrese los minutos estimados de la lectura: " WHITE);
    while (minutes < 1) {
        std::cout << RED "¡Error!. Minutos Incorrectos" WHITE << std::endl;
        minutes = requestNum( GREEN "Ingrese los minutos estimados de la lectura: " WHITE);
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

char* reserveMemoryTheme(unsigned long stringLength){
    char* theme = new char[stringLength];
    return theme;
}

char *themeCreation() {
    std::string stringTheme;
    char* newTheme = nullptr;
    std::cout << GREEN "Ingrese Tema: " WHITE;
    getline(std::cin, stringTheme);
    newTheme = reserveMemoryTheme(stringTheme.length());
    for (unsigned int i = 0; stringTheme[i] != '\0'; i++) {
        *(newTheme + i) = stringTheme[i];
    }
    return newTheme;
}

Reading* newNovel(int isni ,unsigned int minutes, unsigned int publishYear, std::string title){
    Genres genre = requestGenre();
    Reading* novel;
    if (genre == Genres::HISTORICAL) {
        char* theme = themeCreation();
        novel = new Historical(isni, title, minutes, publishYear, genre, theme);
    } else
        novel = new Novel(isni, title, minutes, publishYear, genre);
    return novel;
}

Reading* newTale(int isni ,unsigned int minutes, unsigned int publishYear, std::string title) {
    //int referencia = this->validarReferencia();
    Reading* tale;
    std::string book = requestAlphanum( GREEN "Ingresar el titulo del libro de publicacion." WHITE);
    tale = new Tale(isni, title, minutes, publishYear, book);
    return tale;

}

Reading* newPoem(int isni ,unsigned int minutes, unsigned int publishYear, std::string title){
    Reading* poem;
    int verses = requestNum( GREEN "Ingrese la cantidad de versos del poema: " WHITE);
    poem = new Poem(isni, title, minutes, publishYear, verses);
    return poem;
}