#include "ReadingsFileParser.h"

ReadingsFileParser::ReadingsFileParser() {
    file.open("lecturas.txt");
    this->reading = nullptr;
}

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
    std::string strGenres[] = {"HISTORICA", "DRAMA", "COMEDIA", "FICCION", "SUSPENSO",
                               "TERROR", "ROMANTICA"};
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
        this->id = 0; //AUTOR ANONIMO
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
    this->reserveThemeMemory(this->theme);
    for (int i = 0; this->fileLine[i] != '\0'; i++) {
        *(this->theme + i) = this->fileLine[i];
    }
}

void ReadingsFileParser::reserveThemeMemory(char *&t) {
    t = new char[this->fileLine.length()];
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


void ReadingsFileParser::addSortedReading(Reading *l) {
    this->readings->startCursor();
    int value;
    int position = 1;
    bool minorFound = false;
    while (this->readings->moveCursor() && !minorFound) {
        this->publishYear = this->readings->getCursor()->getPublishYear();
        value = reading->comparar(l);
        if (value >= 0) {
            this->readings->add(l, position);
            minorFound = true;
        }
        position++;
    }
}

void ReadingsFileParser::displayReadings() {
    this->readings->startCursor();
    while (this->readings->moveCursor()) {
        this->readings->getCursor()->display();
    }
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

void ReadingsFileParser::setGraph(Graph<int> *&graph) {
    this->graph = graph;
}

Graph<int> *ReadingsFileParser::getGraph() {
    return graph;
}

void ReadingsFileParser::addGraphEdges() {
    for (int i = 1; i < readings->getNumberOfElements(); i++) {
        for (int j = i + 1; j < readings->getNumberOfElements() + 1; j++) {
            graph->addEdge(i, j, getCost(readings->search(i), readings->search(j)));
        }
    }
}

void ReadingsFileParser::displayMst() {
    Mst m(readings->getNumberOfElements(), graph->getAdjMAtrix());
    m.primAlgorithm();
    int totalMinDistance = 0;
    int *parent = m.getParent();
    int *weight = m.getWeight();
    std::cout << CYAN "ORDEN QUE DEBERÍA LEER LAS LECTURAS\n" WHITE << std::endl;
    for (int i = 1; i < readings->getNumberOfElements(); i++) {
        if (parent[i] < i) {
            totalMinDistance += weight[i];
            std::cout << readings->search(parent[i] + 1)->getTitle() << RED " -> " WHITE
                      << readings->search(i + 1)->getTitle() << "\t"
                      << "Siesta: " << weight[i] << std::endl;
        } else {
            totalMinDistance += weight[i];
            std::cout << readings->search(i + 1)->getTitle() << RED " -> " WHITE
                      << readings->search(parent[i] + 1)->getTitle() << "\t"
                      << "Siesta: " << weight[i] << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << MAGENTA "Tiempo total que tardaria: " RED << totalMinDistance << WHITE << std::endl;
    std::cout << std::endl;
}

void ReadingsFileParser::_displayMst() {
    Mst m(readings->getNumberOfElements(), graph->getAdjMAtrix());
    m.primAlgorithm();
    m.calcMinDistance();
}

void ReadingsFileParser::hamiltonCloneOrder(Reading *A[], Reading *B[]) {
    std::cout << "[ ";
    for (int i = 0; i < totalSize; i++) {
        A[i] = B[i];
        if (i < totalSize-1) { std::cout << B[i]->getTitle() << ", "; }
    }
    std::cout << B[totalSize-1]->getTitle() << " ]\n" << std::endl;
}

void ReadingsFileParser::hamiltonRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime) {
    int linkCost = 0;
    if (arraySize == 0) { // An ending has been reached
        if (acumulatedTime < this->minimalTime || this->minimalTime == -1) { // A new shorter path has been set
            minimalTime = acumulatedTime;
            std::cout << RED << "A new record of " << minimalTime << " minutes was set!" << WHITE << std::endl;
            hamiltonCloneOrder(minimalOrder, currentOrder);
        }
    } else { 
        for (int i=0; i < totalSize; i++) {
            if (visited[i] == false) {      
                if (currentID != 0) {
                    linkCost = getCost(readings->search(currentID),readings->search(i));
                    //std::cout << "Cost between " << readings->search(currentID)->getTitle() << " and " << readings->search(i+1)->getTitle() << " = " << linkCost << std::endl; 
                }
                visited[i] = true;
                //std::cout << "totalSize==" << totalSize << ";arraySize==" << arraySize << ";currentID==" << currentID << ";i==" << i << ";linkCost==" << linkCost << std::endl;
                currentOrder[totalSize-arraySize] = readings->search(i+1);
                if (totalSize == arraySize) {
                    //std::cout << GREEN << "> Trying the parent: "<< currentOrder[totalSize-arraySize]->getTitle() << WHITE << std::endl;
                }                
                hamiltonRecursion(minimalOrder, i+1, currentOrder, visited, arraySize-1, acumulatedTime+linkCost);                
                visited[i] = false;
            }
        }
    }
}

void ReadingsFileParser::hamiltonFunction(Reading *minimalOrder[]) {
    this->minimalTime = -1;
    bool visited[totalSize];  
    // Main loop

    for (int i = 0; i < totalSize; i++) {
        visited[i] = false;
    }
    Reading *readingsOrder[totalSize];
    hamiltonRecursion(minimalOrder, 0, readingsOrder, visited, totalSize, 0);
}

void ReadingsFileParser::displayHamilton() {
    int totalTime = 0;
    readings->startCursor();
    while (readings->moveCursor()) {
        totalTime += readings->getCursor()->getMinutes();
    }
    // Nombre de la variable: graph
    // Una matriz con el peso de cada conneccion

    
    totalSize = readings->getNumberOfElements();
    Reading *minimalOrder[totalSize];
    hamiltonFunction(minimalOrder);
    totalTime += minimalTime;
    std::cout << "\n\nReading order:"<< std::endl;
    for (int i = 0; i < totalSize-1; i++) {
        std::cout << i+1 << ") " << minimalOrder[i]->getTitle() << std::endl;
        std::cout<< getCost(minimalOrder[i],minimalOrder[i+1]) << " minutes of rest later..." << std::endl;
    }
    std::cout << totalSize << ") " << minimalOrder[totalSize-1]->getTitle() << std::endl;
    std::cout << "\nTotal time spent: " << totalTime << " (including " << minimalTime << " minutes of rest and " << totalTime - minimalTime << " reading stories)" << std::endl;
}


ReadingsFileParser::~ReadingsFileParser() {
    readings->startCursor();
    while (readings->moveCursor()) {
        delete readings->getCursor();
    }
    delete readings;
    readings = nullptr;
}




