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



void AuthorsFileParser::requestAuthorsInfo() {
    this->requestISNI();
    std::cout<<CYAN "Datos del Autor \n" WHITE<<std::endl;
    this->name = validation.requestAlpha(GREEN "Nombres y Apellido: " WHITE);
    this->nationality = validation.requestAlpha(GREEN "Nacionalidad: " WHITE);
    this->birth= validation.requestNumber(GREEN "Año de Nacimiento del autor (Si se desconoce -1) : " WHITE);
    this->death = validation.requestNumber(
            GREEN "Año de fallecimiento del autor (Si se desconoce, o sigue vivo, ingresar -1): " WHITE);
    addNewAuthor();
    std::cout<<GREEN "¡Se ha agregado con exito!\n" WHITE<<std::endl;
}


void AuthorsFileParser::requestISNI() {
    srand((unsigned int)time(nullptr));
    this->isni = rand()%(9999-1000+1)+1000;

}


AuthorsFileParser::~AuthorsFileParser() {
   delete authors;

}
