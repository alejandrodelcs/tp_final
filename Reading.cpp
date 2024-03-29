#include "Reading.h"
#include <string>

Reading::Reading(const std::string& title, unsigned int minutes, unsigned int PublishYear) {
    this->minutes= minutes;
    this->PublishYear= PublishYear;
    this->author = nullptr;
}

unsigned int Reading::getPublishYear() const {
    return PublishYear;
}

Author* Reading::getAuthor(){
    return this->author;
}

std::string Reading::getTitle() {
    return title;
}

char Reading::getType() const {
    return type;
}

unsigned int Reading::getMinutes() const {
    return minutes;
}


int Reading::getIsni() const {
    return isni;
}

int Reading::comparar(Reading *l) const {
    int value = 0;
    if (this->PublishYear > l->getPublishYear() ) {
        value = 1;
    } else if (this->PublishYear < l->getPublishYear()) {
        value = -1;
    }
    return value;
}

void Reading::setAuthor(Author *newAuthor) {
    this->author =  newAuthor;
}

void Reading::setIsni(int isni) {
    this->isni = isni;
}
