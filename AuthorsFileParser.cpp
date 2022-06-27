#include "AuthorsFileParser.h"

AuthorsFileParser::AuthorsFileParser() {
    file.open("escritores.txt");
}

void AuthorsFileParser::setReadings(List<Reading *>* &l) {
    this->readings = l;
}

void AuthorsFileParser::setAuthors(HashTable<Author *>* &a) {
    this->authors = a;
}

HashTable<Author *>* AuthorsFileParser::getAuthor() {
    int count = 0;
    while (!file.eof()) {
        fileLine = file.read();
        if (newReference()) {
            count = 0;
        }
        validateAuthorFile(count);
        if (count == 4) {
            addNewAuthor();
        }
        validateEOFAuthor(count);
        this->addReadingAuthor();
        count++;
    }
    return this->authors;
}

void AuthorsFileParser::addNewAuthor() {
    this->author = new Author(
            this->isni,
            this->name,
            this->nationality,
            this->birth,
            this->death
    );
    authors->insertAuthor(this->author);
}

void AuthorsFileParser::validateEOFAuthor(int count) {
    if (file.eof() && count < 4) {
        count += 1;
        fileLine = " ";
        while (count <= 4) {
            validateAuthorFile(count);
            count += 1;
        }
        addNewAuthor();
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
    delete author;
}

void AuthorsFileParser::addReadingAuthor() {
    readings->startCursor();
    while (readings->moveCursor()) {
        Reading *reading = readings->getCursor();
        if (this->isni == reading->getID()) {
            reading->setAuthor(this->author);
        } else if (reading->getID() == 0) {
            reading->setAuthor(nullptr);
        }
    }
}

void AuthorsFileParser::displayAuthors() {
    int pos = 0;
    List<Author*> *aux = authors->getTable();
    std::cout<<"Hola"<<std::endl;
    while (aux->moveCursor()){
        if (aux->getNumberOfElements() > 0 ){
            while(aux[pos].moveCursor()){
                aux[pos].getCursor()->display();
            }
        }
        pos++;
    }
}





