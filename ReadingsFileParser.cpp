#include "ReadingsFileParser.h"

ReadingsFileParser::ReadingsFileParser() {
    file.open("lecturas.txt");
    this->totalMinDistance = 0;
    this->totalReading = 0;
    this->theme = nullptr;
    this->insis = nullptr;
}


/// Creación de lista lecturas a partir de lecturas.txt///


void ReadingsFileParser::setReadingList(List<Reading *> *&l) {
    this->readings = l;
}

List<Reading *> *ReadingsFileParser::getReadings() {
    int count = 0;
    while (!file.eof()) {
        this->fileLine = file.read();
        if (this->newReference())
            count = 0;
        this->validateReading(count);
        this->reading = buildNewReading(count);
        sortReadingList();
        count++;
    }
    return this->readings;
}

void ReadingsFileParser::validateReading(int count) {
    switch (count) {
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
            this->publishYear = (unsigned int) std::stoi(this->fileLine);
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
            this->validateHistoricalReference();
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
    return ((this->fileLine.length() <= 1) && (this->fileLine[0] == NOVEL || this->fileLine[0] == TALE || this->fileLine[0] == POEM));
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
    std::string strGenres[] = {"HISTORICA", "DRAMA", "COMEDIA", "FICCION",
                               "SUSPENSO", "TERROR", "ROMANTICA"};
    Genres enumGenres[] = {Genres::HISTORICAL, Genres::DRAMA, Genres::COMEDY, Genres::FICTION,
                           Genres::THRILLER, Genres::HORROR, Genres::ROMANCE};
    Genres element;
    bool found = false;
    int pos = 0;
    while (pos < GENRES_SIZE && (!found)) {
        if (strGenres[pos] == this->fileLine) {
            element = enumGenres[pos];
            found = true;
        }
        pos++;
    }
    return element;
}

void ReadingsFileParser::validateReference() {
    this->theme = nullptr;
    if (fileLine[0] == '(') {
        this->id = this->getId();
    } else if (type == NOVEL) {
        this->buildNewTheme();
    } else {
        this->id = 0; // Anonymous author
    }
}

void ReadingsFileParser::validateHistoricalReference() {
    if ((type == NOVEL) && (this->genre == Genres::HISTORICAL)) {
        this->id = this->getId();
    }
}

bool ReadingsFileParser::validateNewReading(int count) const {
    return (count == 5 && this->theme == nullptr);
}

bool ReadingsFileParser::validateHistoricalNovel(int contador) const {
    return (contador == 6 && this->genre == Genres::HISTORICAL);
}

Reading *ReadingsFileParser::buildNewReading(int contador) {
    Reading *element = nullptr;
    if (validateNewReading(contador) || validateHistoricalNovel(contador)) {
        if (type == TALE) {
            this->genre = Genres::UNKNOWN;
            element = this->buildNewTale();
        } else if (type == POEM) {
            this->genre = Genres::UNKNOWN;
            element = this->buildNewPoem();
        } else {
            element = this->buildNewNovel();
        }
    }
    return element;
}

void ReadingsFileParser::buildNewTheme() {
    this->theme = this->reserveThemeMemory(this->fileLine.length());
    for (int i = 0; this->fileLine[i] != '\0'; i++) {
        *(this->theme + i) = this->fileLine[i];
    }
}

char* ReadingsFileParser::reserveThemeMemory(long unsigned int size) {
   char* t = new char[size];
   return t;
}

Reading *ReadingsFileParser::buildNewTale() {
    this->reading = new Tale(
            this->id,
            this->title,
            this->minutes,
            this->publishYear,
            book
    );
    return this->reading;
}

Reading *ReadingsFileParser::buildNewPoem() {
    this->reading = new Poem(
            this->id,
            this->title,
            this->minutes,
            this->publishYear,
            this->verses
    );
    return this->reading;
}

Reading *ReadingsFileParser::buildNewNovel() {
    if (this->genre != Genres::HISTORICAL) {
        this->reading = new Novel(
                this->id,
                this->title,
                this->minutes,
                this->publishYear, this->genre);
    } else {
        this->reading = buildNewHistoricalNovel();
    }
    return this->reading;
}

Reading *ReadingsFileParser::buildNewHistoricalNovel() {
    this->reading = new Historical(
            this->id,
            this->title,
            this->minutes,
            this->publishYear,
            Genres::HISTORICAL,
            theme
    );
    return this->reading;
}

void ReadingsFileParser::validateYearSorted() {
    int value = reading->comparar(this->readings->search(this->readings->getNumberOfElements()));
    if (value == 0 || value == 1) {
        this->readings->add(this->reading);
    } else {
        this->validateYearMinor();
    }
}

void ReadingsFileParser::sortReadingList() {
    if (this->reading != nullptr) {
        if (readings->getNumberOfElements() < 1) {
            readings->add(this->reading);
        } else {
            this->validateYearSorted();
        }
    }
}

void ReadingsFileParser::validateYearMinor() {
    int value = 0;
    int position = 0;
    this->readings->startCursor();
    while (readings->moveCursor() && value >= 0) {
        value = reading->comparar(readings->getCursor());
        position++;
    }
    this->readings->add(this->reading, position);
}


void ReadingsFileParser::displayReadings() {
    this->readings->startCursor();
    while (this->readings->moveCursor()) {
        this->readings->getCursor()->display();
    }
}

/// Grafos ///


void ReadingsFileParser::setGraph(Graph<int> *&graph) {
    this->graph = graph;
}

Graph<int> *ReadingsFileParser::getGraph() {
    return graph;
}

int ReadingsFileParser::getCost(Reading *initialReading, Reading *endingReading) {
    int costs[4][4] = {
            {8,  0,  10, 15},
            {0,  1,  5,  20},
            {10, 5,  30, 60},
            {15, 20, 60, 80}
    };
    int A = validateType(initialReading);
    int B = validateType(endingReading);
    return costs[A][B];
}

int ReadingsFileParser::validateType(Reading *reading) {
    int typeNum = 0;
    if (reading->getType() == TALE) {
        typeNum = 0;
    } else if (reading->getType() == POEM) {
        typeNum = 1;
    } else if (reading->getType() == NOVEL) {
        typeNum = 2;
        if (reading->getGenre() == Genres::HISTORICAL) {
            typeNum = 3;
        }
    }
    return typeNum;
}

void ReadingsFileParser::setGraphVertex() {
    this->readings->startCursor();
    int pos = 1;
    while (this->readings->moveCursor()) {
        graph->addVertex(pos);
        pos++;
    }
}


void ReadingsFileParser::setGraphNewVertex(){
    graph->addVertex(this->readings->getNumberOfElements());
}


void ReadingsFileParser::addGraphEdges() {
    for (int i = 1; i < readings->getNumberOfElements(); i++) {
        for (int j = i + 1; j < readings->getNumberOfElements() + 1; j++) {
            graph->addEdge(i,
                           j,
                           getCost(readings->search(i),
                           readings->search(j)));
        }
    }
}

void ReadingsFileParser::displayMst(int option) {
    Mst m(readings->getNumberOfElements(), graph->getAdjMAtrix());
    m.primAlgorithm();
    if (option == 0) {
        int *parent = m.getParent();
        int *weight = m.getWeight();
        std::cout << CYAN "ORDEN QUE DEBERÍA LEER LAS LECTURAS\n" WHITE << std::endl;
        for (int i = 1; i < readings->getNumberOfElements(); i++) {
            this->totalReading += readings->search(i)->getMinutes();
            if (parent[i] < i) {
                this->totalMinDistance += weight[i];
                std::cout << readings->search(parent[i] + 1)->getTitle() << RED " —— " WHITE
                          << readings->search(i + 1)->getTitle() << "\t"
                          << "Siesta: " << weight[i] << " minutos" << std::endl;

            } else {
                this->totalMinDistance += weight[i];
                std::cout << readings->search(i + 1)->getTitle() << RED " —— " WHITE
                          << readings->search(parent[i] + 1)->getTitle() << "\t"
                          << "Siesta: " << weight[i] << " minutos" << std::endl;
            }
        }
        this->displayTotalReading();
    }
    if (option == 1) {
        m.calcMinDistance();
    }
}

void ReadingsFileParser::displayTotalReading() const{
    std::cout << std::endl;
    std::cout << MAGENTA "Tiempo total que tardaria: " RED << totalMinDistance + totalReading << " minutos\n"
              << WHITE
              << MAGENTA "Tiempo total que tardaria: " RED << (totalMinDistance + totalReading) / 60 << " Horas"
              << WHITE
              << std::endl;
    std::cout << std::endl;
}


void ReadingsFileParser::displayMst() {
    displayMst(0);
}



/// Ingreso de una nueva lectura por usuario ///


void ReadingsFileParser::setNewGenres(){
    std::string strGenres[] = {"HISTORICA", "DRAMA", "COMEDIA", "FICCION",
                               "SUSPENSO", "TERROR", "ROMANTICA"};
    for(int i=0; i<GENRES_SIZE;i++){
        std::cout  << GREEN "[" << i + 1 << "] " WHITE << "- " << strGenres[i] << std::endl;
    }
    this->fileLine = strGenres[validation.validatePosition()];
    this->genre = this->validateGenre();

}

void ReadingsFileParser::setNewTheme() {
    std::string strTheme;
    std::cout << GREEN "> Ingrese Tema: " WHITE;
    getline(std::cin, strTheme);
    this->theme = this->reserveThemeMemory(strTheme.length());
    for (unsigned int i = 0; strTheme[i] != '\0'; i++) {
        *(this->theme + i) = strTheme[i];
    }
}


void ReadingsFileParser::setNewTitle() {
    std::cout << GREEN "Ingrese Titulo: " WHITE <<CYAN "\n>" WHITE;
    getline(std::cin, this->title);
}


void ReadingsFileParser::setInputNewReading(int option) {
    switch (option) {
        case O_NOVEL:
            this->setNewNovel();
            break;
        case O_TALE:
            this->setNewTale();
            break;
        case O_POEM:
            this->setNewPoem();
            break;
        default:
            std::cout << std::endl;
            break;

    }
}

void ReadingsFileParser::setNewNovel(){
    this->type = 'N';
    this->setNewGenres();
    if (genre == Genres::HISTORICAL){
        this->setNewTheme();
        this->reading = this->buildNewHistoricalNovel();
    }else{
        this->reading = this->buildNewNovel();
    }
}

void ReadingsFileParser::setNewTale(){
    this->type =
            'C';
    std::cout<<GREEN "Ingresar el titulo del libro de publicacion."<<CYAN "\n>" WHITE;
    getline(std::cin, this->book);
    this->reading = this->buildNewTale();
}

void ReadingsFileParser::setNewPoem() {
    this->type = 'P';
    this->verses = validation.requestNumber( GREEN "Ingrese la cantidad de versos del poema: " WHITE);
    this->reading = this->buildNewPoem();
}


void ReadingsFileParser::setAuthors(HashTable<Author *> *&a) {
    this->authors = a;
}


void ReadingsFileParser::setAuthorInReading() {
    pAuthors.setAuthors(authors);
    this->insis = pAuthors.displayNameAuthors();
    std::cout<<"6) Anonimo "<<std::endl;
    int option = validation.requestNumber("Ingrese opcion: ");
    if (option>0) {
        this->reading->setAuthor(authors->searchElement(insis->search(option)));
        this->reading->setIsni(insis->searchPosition(option));
    }
    delete insis;
}

void ReadingsFileParser::requestReadingsInfo(int option) {
    this->id = 0;
    this->setNewTitle();
    this->minutes = validation.requestNumber(GREEN "Ingrese los minutos estimados de la lectura: " WHITE);
    this->publishYear = validation.requestNumber(GREEN"Ingrese el año de publicacion de la lectura: " WHITE);
    this->setInputNewReading(option);
    this->setAuthorInReading();
    this->sortReadingList();
    std::cout<<GREEN "\n¡Se ha agregado con éxito "<< CYAN << this->title<<GREEN"! \n\n"<<WHITE<<std::endl;
}


ReadingsFileParser::~ReadingsFileParser() {
    if (readings != nullptr) {
        while (readings->moveCursor()) {
            delete readings->getCursor();
        }
        delete readings;
    }
}
