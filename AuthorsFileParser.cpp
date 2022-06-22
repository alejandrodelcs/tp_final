#include "AuthorsFileParser.h"

AuthorsFileParser::AuthorsFileParser() {
    file.open("escritores.txt");
    this->newAuthor = nullptr;
}

void AuthorsFileParser::getAuthor(List<Author*> *e) {
    int count = 0;
    this->authors = e;
    while (!file.eof()) {
        fileLine = file.read();
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
    buildNewAuthor();
    addAuthor();
}

void AuthorsFileParser::addNewAuthor() {
    authors->add(this->newAuthor);
}

void AuthorsFileParser::buildNewAuthor() {
    this->newAuthor = new Author(
        this->isni,
        this->name,
        this->nationality,
        this->birth,
        this->death
    );
}

void AuthorsFileParser::validateEOFAuthor(int count) {
    if (file.eof() && count < 4) {
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
        case ISNI_ID:
            isni = getISNI();
            break;
        case NAME_ID:
            name = validateFileLine() ? " " : fileLine;
            break;
        case NATIONALITY_ID:
            nationality = validateFileLine() ? " " : fileLine;
            break;
        case BIRTH_ID:
            birth = validateFileLine() ? UNKNOWN_DATA : std::stoi(fileLine);
            break;
        case DEATH_ID:
            death = validateFileLine() ? UNKNOWN_DATA : std::stoi(fileLine);
            break;
        default:
            std::cout << std::endl;
            break;
    }
}

bool AuthorsFileParser::newReference() {
    return (this->fileLine[0] == '(');
}

int AuthorsFileParser::getISNI() {
    return std::stoi(this->fileLine.substr(REFERENCE, fileLine.find(')')));
}

bool AuthorsFileParser::validateFileLine() {
    return (this->fileLine.length() <= EMPTY_LINE);
}

AuthorsFileParser::~AuthorsFileParser() {
    authors->startCursor();
    while (authors->moveCursor())
        delete authors->getCursor();
    delete authors;
    authors = nullptr;
}
