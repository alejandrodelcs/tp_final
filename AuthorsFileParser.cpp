#include "AuthorsFileParser.h"

AuthorsFileParser::AuthorsFileParser() {
    data.open("escritores.txt");
    this->author = nullptr;
}

void AuthorsFileParser::getAuthor(List<Author*> *e) {
    int count = 0;
    this->authores = e;
    while (!data.eof()) {
        fileLine = data.read();
        if (newReference())
            count = 0;
        validateAuthorFile(count);
        if (count == 4) {
            validateNewAuthor();
        }
        validateEOFAuthor(count);
        count++;
    }
}

void AuthorsFileParser::validateNewAuthor() {
    newAuthor();
    addAuthor();
}


void AuthorsFileParser::validateEOFAuthor(int count) {
    if (data.eof() && count < 4) {
        count += 1;
        fileLine = " ";
        while (count <= 4) {
            validateAuthorFile(count);
            count += 1;
        }
        validateNewAuthor();
    }
}

void AuthorsFileParser::validateAuthorFile(int count) {
    switch (count) {
        case ID:
            id = getId();
            break;
        case NAME:
            name = validateFileLine() ? " " : fileLine;
            break;
        case NATIONALITY:
            nationality = validateFileLine() ? " " : fileLine;
            break;
        case BIRTH_YEAR:
            birth = validateFileLine() ? UNKNOWN_DATA : std::stoi(fileLine);
            break;
        case DEATH_YEAR:
            death = validateFileLine() ? UNKNOWN_DATA : std::stoi(fileLine);
            break;
        default:
            std::cout<<std::endl;
            break;
    }
}

void AuthorsFileParser::addAuthor() {
    authores->add(this->author);
}

void AuthorsFileParser::newAuthor() {
    author = new Author(this->id, this->name, this->nationality,
                        this->birth, this->death);
}


bool AuthorsFileParser::newReference() {
    return (this->fileLine[0] == '(');
}

int AuthorsFileParser::getId() {
    return std::stoi(this->fileLine.substr(REFERENCE, fileLine.find(')')));
}

bool AuthorsFileParser::validateFileLine() {
    return (this->fileLine.length() <= EMPTY_LINE);
}

AuthorsFileParser::~AuthorsFileParser() {
    authores->startCursor();
    while (authores->moveCursor())
        delete authores->getCursor();
    delete authores;
    authores= nullptr;
}
