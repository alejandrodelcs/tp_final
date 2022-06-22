#include "ReadingsFileParser.h"

ReadingsFileParser::ReadingsFileParser() {
    data.open("lecturas.txt");
    this->reading = nullptr;
}

void ReadingsFileParser::getReading(List<Reading*> *l) {
    int count = 0;
    this->newReadingList(l);
    while (!data.eof()) {
        this->fileLine = data.read();
        if (this->newReference())
            count = 0;
        this->validateReading(count);
        this->reading = newReading(count);
        sortReadingList();
        count++;
    }
}

void ReadingsFileParser::validateReading(int count) {
    switch(count){
        case TYPE:
            this->type = this->fileLine[0];
            break;
        case TITLE:
            this->title = this->fileLine;
            break;
        case MINUTES:
            this->minutes = (unsigned int) std::stoi(this->fileLine);
            break;
        case PUBLISH_YEAR :
            this->yearPublication = (unsigned int) std::stoi(this->fileLine);
            break;
        case READING_TYPES:
            this->book = "";
            this->validateTypeReading();
            break;
        case ID_THEME:
            this->validateReference();
            break;
        case ID_HISTORIC:
            this->verses = 0;
            this->validateHistoricReference();
            break;
        default:
            std::cout << "";
            break;
    }
}

int ReadingsFileParser::getId() const {
    return std::stoi(this->fileLine.substr(REFERENCE, this->fileLine.find(')')));
}

bool ReadingsFileParser::newReference() const {
    return ((this->fileLine.length() <= 1) &&
            (this->fileLine[0] == NOVEL || this->fileLine[0] == TALE || this->fileLine[0] == POEM));
}

void ReadingsFileParser::validateTypeReading() {
    switch (type) {
        case POEM:
            this->verses = std::stoi(this->fileLine);
            break;
        case NOVEL:
            this->genre = validateGenre();
            break;
        case TALE:
            this->book = this->fileLine;
            break;
        default:
            std::cout << "";
            break;
    }
}

Genres ReadingsFileParser::validateGenre() {
    Genres element;
    bool foundOut = false;
    int pos = 0;
    std::string genres[] = {"HISTORICA", "DRAMA", "COMEDIA", "FICCION", "SUSPENSO",
                            "TERROR", "ROMANTICA"};
    Genres generosEnum[] = {Genres::HISTORICA, Genres::DRAMA, Genres::COMEDIA, Genres::FICCION, Genres::SUSPENSO,
                            Genres::TERROR, Genres::ROMANTICA};
    while (pos < GENRES_SIZE && (!foundOut)) {
        if (genres[pos] == this->fileLine) {
            element = generosEnum[pos];
            foundOut = true;
        }
        pos++;
    }
    return element;
}

void ReadingsFileParser::validateReference() {
    this->theme =  nullptr;
    if (fileLine[0] == '(') {
        this->id = this->getId();
    } else if (type == NOVEL) {
        this->newTheme();
    } else {
        this->id = 0; //AUTOR ANONIMO
    }
}

void ReadingsFileParser::validateHistoricReference() {
    if ((type == NOVEL) && (this->genre == Genres::HISTORICA)) {
        this->id = this->getId();
    }
}

bool ReadingsFileParser::validateNewReading(int count) const {
    return (count == 5 && this->theme == nullptr);

}

bool ReadingsFileParser::validateHistoricNovel(int contador) const {
    return (contador == 6 && this->genre == Genres::HISTORICA);
}

Reading *ReadingsFileParser::newReading(int contador) {
    Reading *element = nullptr;
    if (validateNewReading(contador) || validateHistoricNovel(contador)) {
        if (type == TALE) {
            this->genre = Genres::INEXISTENTE;
            element = this->newTale();
        } else if (type == POEM) {
            this->genre = Genres::INEXISTENTE;
            element = this->newPoem();
        } else {
            element = this->newNovel();
        }
    }
    return element;
}

void ReadingsFileParser::newTheme() {
    this->reserveThemeMemory(this->theme);
    for(int i=0; this->fileLine[i] != '\0'; i++){
        *(this->theme + i) = this->fileLine[i];
    }
}

void ReadingsFileParser::reserveThemeMemory(char* &t) {
    t = new char[this->fileLine.length()];
}

Reading *ReadingsFileParser::newTale() {
    (this->reading) = new Cuento(
            this->id,
            this->title,
            this->minutes,
            this->yearPublication,
            book
    );
    return this->reading;
}

Reading *ReadingsFileParser::newPoem() {
    (this->reading) = new Poema(
            this->id,
            this->title,
            this->minutes,
            this->yearPublication,
            this->verses
    );
    return this->reading;
}

Reading *ReadingsFileParser::newNovel() {
    if (this->genre != Genres::HISTORICA) {
        this->reading = new Novela(
                this->id,
                this->title,
                this->minutes,
                this->yearPublication, this->genre);
    } else {
        this->reading = newHistoricalNovel();
    }
    return this->reading;
}

Reading *ReadingsFileParser::newHistoricalNovel() {
    this->reading = new Historica(
            this->id,
            this->title,
            this->minutes,
            this->yearPublication,
            Genres::HISTORICA,
            theme
    );
    return this->reading;
}

void ReadingsFileParser::validateYearSorted() {
    int value = reading->comparar(this->readings->search(this->readings->getNumberOfElements()));
    if (value == 0 || value == 1){
        this->readings->add(this->reading);
    }else{
        this->validateYearMinor();
    }
}

void ReadingsFileParser::sortReadingList(){
    if (this->reading != nullptr) {
        if (readings->getNumberOfElements() < 1) {
            readings->add(this->reading);
        } else {
            this->validateYearSorted();
        }
    }
}

void ReadingsFileParser::newReadingList(List<Reading*> *l) {
    this->readings = l;
}

void ReadingsFileParser::validateYearMinor() {
    int value = 0;
    int position = 0;
    this->readings->startCursor();
    while (readings->moveCursor() && value >= 0){
        value = reading->comparar(readings->getCursor());
        position++;
    }
    this->readings->add(this->reading, position);
}

ReadingsFileParser::~ReadingsFileParser() {
    readings->startCursor();
    while (readings->moveCursor()) {
        delete readings->getCursor();
    }
    delete readings;
    readings = nullptr;
}

void ReadingsFileParser::addSortedReading(Reading* l) {
    this->readings->startCursor();
    int value;
    int position = 1;
    bool minorFound = false;
    while (this->readings->moveCursor() && !minorFound) {
        this->yearPublication = this->readings->getCursor()->getPublishYear();
        value = reading->comparar(l);
        if (value >= 0) {
            this->readings->add(l, position);
            minorFound = true;
        }
        position++;
    }
}
