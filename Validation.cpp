#include "Validation.h"


Validation::Validation() {
    this->string = "";
}

std::string Validation::requestAlpha(const std::string& text) {
    std::cout << text << std::endl;
    this->valid = false;
    while (!valid) {
        this->number = 0;
        this->haveNumbers = false;
        std::cout << CYAN "> " WHITE;
        getline(std::cin, this->string);
        this->validateString();
        if (haveNumbers || this->string.empty()) {
            std::cout << RED "Error: Entrada invalida!\n" WHITE;
        } else
            valid = true;
    }
    std::cout << std::endl;
    return this->string;
}


int Validation::requestNumber(const std::string &text) {
    std::string input;
    this->valid = false;
    while (!(this->valid)) {
        std::cout << text << "\n" << CYAN "> " WHITE;
        this->number = 0;
        this->haveLetters = false;
        getline(std::cin, input);
        this->validateNumber(input);
        if (!(this->haveLetters) || input.empty()) {
            this->number = stoi(input);
            this->valid = true;
        } else
            std::cout << RED "Error: Entrada invalida!\n" WHITE;
    }
    return this->number;
}


void Validation::validateNumber(std::string auxNumber) {
    while ((this->number <= (int) auxNumber.length()) && !haveLetters) {
        if (std::isalpha(auxNumber[this->number]))
            this->haveLetters = true;
        this->number++;
    }
}


void Validation::validateString() {
    while ((this->number <= (int) (this->string.length())) && !(this->haveNumbers)) {
        if ((std::isdigit(string[this->number])))
            this->haveNumbers = true;
        this->number++;
    }
}

int Validation::validatePosition() {
    int position = this->requestNumber(GREEN "Ingresar opcion del genero de novela: " WHITE);
    while (position < 1 || position > 6){
        std::cout << RED "¡Error!. Opcion Incorrecta" WHITE << std::endl;
        position = this->requestNumber(GREEN "Ingresar opcion del genero de novela: " WHITE);
    }
    return position - 1;
}