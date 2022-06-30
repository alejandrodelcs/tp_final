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

HashTable<Author *>* AuthorsFileParser::getAuthors() {
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

void AuthorsFileParser::requestAuthorsInfo() {
    this->isni= requestISNI();
    this->name = requestAlpha( GREEN "Ingresar el nombre del escritor: " WHITE);
    this->nationality = requestAlpha( GREEN "Ingresar la nacionalidad del escritor: " WHITE);
    this->birth= requestNum( GREEN "Ingrese el anio de nacimiento del autor, si se desconoce ingresar -1: " WHITE);
    this->death = requestNum( GREEN "Ingresar el anio de fallecimiento del autor (Si se desconoce, o sigue vivo, ingresar -1): " WHITE);
    addNewAuthor();
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

void AuthorsFileParser::addReadingAuthor() {
    readings->startCursor();
    while (readings->moveCursor()) {
        Reading *reading = readings->getCursor();
        if (this->isni == reading->getIsni()) {
            reading->setAuthor(this->author);
        } else if (reading->getIsni() == 0) {
            reading->setAuthor(nullptr);
        }
    }
}

void AuthorsFileParser::displayAuthors() {
    List<Author*> *aux = authors->getTable();
    for (int i=0;i < authors->getSize();i++) {
        aux[i].startCursor();
        while(aux[i].moveCursor()){
            aux[i].getCursor()->display();
        }
    }
}

List<int>* AuthorsFileParser::displayNameAuthors() {
    List<int> *insi = new List<int>;
    List<Author *> *aux = authors->getTable();
    int j = 1;
    for (int i = 0; i < authors->getSize(); i++) {
        aux[i].startCursor();
        while (aux[i].moveCursor()) {
            std::cout << j << ") " << aux[i].getCursor()->getName() << std::endl;
            insi->add(aux[i].getCursor()->getISNI());
            j++;
        }
    }
    return insi;
}

AuthorsFileParser::~AuthorsFileParser() {
    delete author;
}




