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

    /*
     * PRE:
     * POST:
     */
    void validateString();

    /*
     * PRE:
     * POST:
     */
    void validateNumber(std::string auxNumber);

public:
    /*
     * PRE:
     * POST:
     */
    Validation();

    /*
     * PRE: lenght text > 0 and text is string
     * POST: return number > 0
     */
    int requestNumber(const std::string& text);

    /*
     * PRE: lenght text > 0 and text is string
     * POST: return a non-alphanumeric text
     */
    std::string requestAlpha(const std::string& text);

    /*
     * PRE:
     * POST: return num>0
     */
    int validatePosition();
};


#endif //TP_FINAL_VALIDATION_H
