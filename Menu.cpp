#include "Menu.h"


Menu::Menu() {
    this->readings = new List<Reading *>;
    this->authors = new HashTable<Author *>(20);
    this->graph = new Graph<int>;
    this->end = false;
}

void Menu::displayMenu() {
    std::cout << "1. Ingresar una nueva lectura\n"
                 "2. Mostrar todas las lecturas\n" // TODO : SE PUEDE AGREGAR ELIMINAR Y ALTA (C/ SUBMENU), VA A DEPENDER COMO LLEGUEMOS
                 "3. Ingresar un nuevo escritor\n"
                 "4. Mostrar todos los escritores\n"
                 "5. Buscar un escritor\n"
                 "6. Eliminar un escritor\n"
                 "7. Encontrar el orden y tiempo mínimo que\n"
                 "   nos llevaría leer todas las lecturas\n"
                 "8. Extras\n"
                 "9. Salir del programa\n" << std::endl;

}

void Menu::input() {
    std::cout << "> ";
    std::cin >> this->option;
    std::cin.ignore();
    std::cout << std::endl;
}

void Menu::displayReadings() {
    pReading.displayReadings();
}

void Menu::displayAuthors() {
    pAuthors.displayAuthors();
}



void Menu::addNewReading() {
    int isni = requestISNI();
    int type = requestType();
    std::string title = requestTitle();
    unsigned int minutes = requestMinutes();
    unsigned int publishYear = requestPublishYear();

    switch (type) {
        case 1:
            this -> newReading = newNovel(isni, minutes, publishYear, title);
            break;
        case 2:
            this -> newReading = newTale(isni, minutes, publishYear, title);
            break;
        case 3:
            this -> newReading = newPoem(isni, minutes, publishYear, title);
            break;
    }
    readings->add(newReading);
}
void Menu::addNewAuthor() {
    int isni = requestISNI();
    std::string name = requestAuthorsName();
    std::string nationality = requestNationality();
    int birth = requestBirth();
    int death = requestDeath();
    newAuthor = new Author(isni,name,nationality,birth, death);
    authors->insertAuthor(newAuthor);
}


void Menu::shortestReadingsTime() {
    pReading.displayMst();
}

bool Menu::validateSearchOption(int totalAuthors) const {
    return (this->option < 1 || this->option > totalAuthors);
}

Author *Menu::getAuthorMenu() {
    Author *aux = nullptr;
    List<int> *insi = pAuthors.displayNameAuthors();
    if (insi->getNumberOfElements() > 0) {
        std::cout << std::endl;
        this->input();
        if (!(this->validateSearchOption(insi->getNumberOfElements()))) {
            aux = authors->searchElement(insi->search(this->option));
        } else {
            std::cout << RED "¡Escritor no encontrado!\n" WHITE << std::endl;
        }
    } else {
        std::cout << RED "¡No hay ningun escritor registrado!\n" WHITE << std::endl;
    }
    delete insi;
    return aux;
}

void Menu::searchAuthor() {
    Author *aux = getAuthorMenu();
    if (aux != nullptr) {
        std::cout << std::endl;
        aux->display();
        std::cout << std::endl;
    }
}

void Menu::removeAuthor() {
    Author *aux = getAuthorMenu();
    if (aux != nullptr) {
        std::cout << RED << "¡" << aux->getName() <<  " ha sido eliminado!\n\n" WHITE;
        authors->removeElement(aux->getISNI());
    }
}


void Menu::validateInputOption() {
    while (option < ONE || option > NINE) {  // NO SE COMO LLAMAR A LAS CONSTANTES
        std::cout << RED "¡Opcion incorrecta!\n" WHITE << std::endl;
        this->input();
    }
}

void Menu::displayAdditionalFeatures() {
    std::cout << "1. Mostrar Matriz de Adyacencia y vertices\n"
                 "2. Mostrar resultado de Algoritmo de Prim (solo MST)\n"
                 "3. Mostrar la tabla de hash\n"
                 "4. Encontrar el orden y tiempo mínimo que\n"
                 "   nos llevaría leer todas las lecturas usando\n"
                 "   un metodo alternativo con Hamilton"
                 "5. Salir\n" << std::endl;

}


void Menu::optionsAdditional() {
    switch (this->option) {
        case ONE:
            graph->displayGraph();
            break;
        case TWO:
            pReading._displayMst();
            break;
        case THREE:
            authors->display();
            std::cout << std::endl;
            break;
        case FOUR:
            this->hamiltonianShortestReadingsTime();
            break;
        case FIVE:
            std::cout << MAGENTA "\nGracias por llegar hasta aca\n" WHITE << std::endl;
            break;
    }
}

void Menu::additionalFeatures() {
    this->displayAdditionalFeatures();
    this->input();
    this->optionsAdditional();
    this->interaction();
}

void Menu::cloneArray(Reading *A[], Reading *B[]) {
    for (int i = 0; i < totalSize; i++) {
        A[i] = B[i];
    }
}

void Menu::hamiltonianRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime) {
    int linkCost = 0;
    if (arraySize == 0) {
        if (acumulatedTime < this->minimalReadingsTime || this->minimalReadingsTime == -1) {
            this->minimalReadingsTime = acumulatedTime;
            std::cout << RED << "Se a hallado un nuevo tiempo minimo de " << this->minimalReadingsTime << " minutos!" << std::endl;
            cloneArray(minimalOrder, currentOrder);
        }
        std::cout << "Tiempo acumulado por las aristas de [ "; 
        for (int i = 0; i < totalSize; i++) {
            if (i < totalSize-1) { std::cout << currentOrder[i]->getTitle() << ", "; } 
        }
        std::cout << currentOrder[totalSize-1]->getTitle() << " ] = " << acumulatedTime << std::endl;
        std::cout << WHITE;
    } else { 
        for (int i=0; i < totalSize; i++) {
            if (visited[i] == false) {      
                if (currentID != 0) {
                    linkCost = pReading.getCost(readings->search(currentID),readings->search(i));
                }
                visited[i] = true;
                currentOrder[totalSize-arraySize] = readings->search(i+1);
                hamiltonianRecursion(minimalOrder, i+1, currentOrder, visited, arraySize-1, acumulatedTime+linkCost);                
                visited[i] = false;
            }
        }
    }
}

void Menu::calculateHamiltonianShortestReadingTime(Reading *minimalOrder[]) {
    this->minimalReadingsTime = -1;
    bool visited[totalSize];
    for (int i = 0; i < totalSize; i++) {
        visited[i] = false;
    }
    Reading *readingsOrder[totalSize];    
    hamiltonianRecursion(minimalOrder, 0, readingsOrder, visited, totalSize, 0);
}

void Menu::hamiltonianShortestReadingsTime() {
    int totalTime = 0;
    readings->startCursor();
    while (readings->moveCursor()) {
        totalTime += readings->getCursor()->getMinutes();
    }    
    totalSize = readings->getNumberOfElements();
    Reading *minimalOrder[totalSize];
    calculateHamiltonianShortestReadingTime(minimalOrder);
    totalTime += minimalReadingsTime;
    std::cout << "\nReading order:"<< std::endl;
    for (int i = 0; i < totalSize-1; i++) {
        std::cout << "Read \"" << minimalOrder[i]->getTitle() << "\" (about " << minimalOrder[i]->getMinutes() << " minutes)" << std::endl;
        std::cout<< pReading.getCost(minimalOrder[i],minimalOrder[i+1]) << " minutes of rest later..." << std::endl;
    }
    std::cout << totalSize << ") " << minimalOrder[totalSize-1]->getTitle() << std::endl;
    std::cout << "\nTotal time spent: " << totalTime << "\n(including " << minimalReadingsTime << " minutes of rest and " << totalTime - minimalReadingsTime << " reading stories)\n" << std::endl;
}

void Menu::buildGraph() {
    pReading.setGraph(graph);
    graph = pReading.getGraph();
    pReading.setGraphVertex();
    pReading.addGraphEdges();
}


void Menu::buildListReadings() {
    pReading.setReadingList(this->readings);
    this->readings = pReading.getReadings();
}

void Menu::buildHashTable() {
    pAuthors.setReadings(readings);
    pAuthors.setAuthors(authors);
    this->authors = pAuthors.getAuthors();
}

void Menu::options() {
    switch (this->option) {
        case ONE:
            addNewReading();
            break;
        case TWO:
            displayReadings();
            break;
        case THREE:
            //addNewAuthor();
            break;
        case FOUR:
            displayAuthors();
            break;
        case FIVE:
            searchAuthor();
            break;
        case SIX:
            removeAuthor();
            std::cout << "";
            break;
        case SEVEN:
            shortestReadingsTime();
            break;
        case EIGHT:
            additionalFeatures();
        case NINE:
            this->end = true;
        default:
            std::cout << "";
            break;
    }
}


void Menu::interaction() {
    this->buildListReadings();
    this->buildGraph();
    this->buildHashTable();
    while (!this->end) {
        this->displayMenu();
        this->input();
        this->validateInputOption();
        this->options();
    }
}

Menu::~Menu() {
    delete authors;
    delete graph;
}









