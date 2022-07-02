#ifndef TP_FINAL_VALIDATION_H
#define TP_FINAL_VALIDATION_H
#include <string>
#include <iostream>

#include "Constants.h"

class Validation {
private:
    std::string string;
    int number;
    bool valid;
    bool haveNumbers;
    bool haveLetters;
    void validateString();
    void validateNumber(std::string auxNumber);
public:
    Validation();
    int requestNumber(const std::string& text);
    std::string requestAlpha(const std::string& text);
    int validatePositionGenres();
};


#endif //TP_FINAL_VALIDATION_H
