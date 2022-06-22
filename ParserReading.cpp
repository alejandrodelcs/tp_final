#include "ParserReading.h"



ParserReading::ParserReading() {
    data.open("lecturas.txt");
    this->reading = nullptr;
}

void ParserReading::getReading(List<Lectura*> *l) {
    int count = 0;
    this->newReadingList(l);
    while (!data.endOfFile()) {
        this->fileLine = data.read();
        if (this->newReference())
            count = 0;
        this->validateReading(count);
        this->reading = newReading(count);
        sortReadingList();
        count++;
    }
}

void ParserReading::validateReading(int count) {
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
        case YEAR_PUBLICATION :
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


int ParserReading::getId() const {
    return std::stoi(this->fileLine.substr(REFERENCE, this->fileLine.find(')')));
}

bool ParserReading::newReference() const {
    return ((this->fileLine.length() <= 1) &&
            (this->fileLine[0] == NOVEL || this->fileLine[0] == TALE || this->fileLine[0] == POEM));
}

void ParserReading::validateTypeReading() {
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

Genres ParserReading::validateGenre() {
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

void ParserReading::validateReference() {
    this->theme =  nullptr;
    if (fileLine[0] == '(') {
        this->id = this->getId();
    } else if (type == NOVEL) {
        this->newTheme();
    } else {
        this->id = 0; //AUTOR ANONIMO
    }
}

void ParserReading::validateHistoricReference() {
    if ((type == NOVEL) && (this->genre == Genres::HISTORICA)) {
        this->id = this->getId();
    }
}

bool ParserReading::validateNewReading(int count) const {
    return (count == 5 && this->theme == nullptr);

}

bool ParserReading::validateHistoricNovel(int contador) const {
    return (contador == 6 && this->genre == Genres::HISTORICA);
}

Lectura *ParserReading::newReading(int contador) {
    Lectura *element = nullptr;
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

void ParserReading::newTheme() {
    this->reserveThemeMemory(this->theme);
    for(int i=0; this->fileLine[i] != '\0'; i++){
        *(this->theme + i) = this->fileLine[i];
    }

    for(int i=0; this->fileLine[i] != '\0'; i++) {
        theme[i].setName(fileLine[i].c_ss)
    }
}

void ParserReading::reserveThemeMemory(char* &t) {
    t = new char[this->fileLine.length()];
}


Lectura *ParserReading::newTale() {
    (this->reading) = new Cuento(
            this->id,
            this->title,
            this->minutes,
            this->yearPublication,
            book
    );
    return this->reading;
}

Lectura *ParserReading::newPoem() {
    (this->reading) = new Poema(
            this->id,
            this->title,
            this->minutes,
            this->yearPublication,
            this->verses
    );
    return this->reading;
}

Lectura *ParserReading::newNovel() {
    if (this->genre != Genres::HISTORICA) {
        this->reading = new Novela(
                this->id,
                this->title,
                this->minutes,
                this->yearPublication, this->genre);
    } else {
        this->reading = newHistoricNovel();
    }
    return this->reading;
}

Lectura *ParserReading::newHistoricNovel() {
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


void ParserReading::validateYearSorted() {
    int value = reading->comparar(this->readings->search(this->readings->getNumberOfElements()));
    if (value == 0 || value == 1){
        this->readings->add(this->reading);
    }else{
        this->validateYearMinor();
    }
}


void ParserReading::sortReadingList(){
    if (this->reading != nullptr) {
        if (readings->getNumberOfElements() < 1) {
            readings->add(this->reading);
        } else {
            this->validateYearSorted();
        }
    }
}

void ParserReading::newReadingList(List<Lectura*> *l) {
    this->readings = l;
}

void ParserReading::validateYearMinor() {
    int value = 0;
    int position = 0;
    this->readings->startCursor();
    while (readings->moveCursor() && value >= 0){
        value = reading->comparar(readings->getCursor());
        position++;
    }
    this->readings->add(this->reading, position);

}


ParserReading::~ParserReading() {
    readings->startCursor();
    while (readings->moveCursor()) {
        delete readings->getCursor();
    }
    delete readings;
    readings = nullptr;
}

void ParserReading::addReadingSorted(Lectura* l) {
    this->readings->startCursor();
    int value;
    int position = 1;
    bool minorFound = false;
    while (this->readings->moveCursor() && !minorFound) {
        this->yearPublication = this->readings->getCursor()->getYearPublication();
        value = reading->comparar(l);
        if (value >= 0) {
            this->readings->add(l, position);
            minorFound = true;
        }
        position++;
    }
}



