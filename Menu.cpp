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
    std::cout << std::endl;
}

void Menu::displayReadings() {
    pReading.displayReadings();
}

void Menu::displayAuthors() {
    pAuthors.displayAuthors();
}

void Menu::newReading() {

}

void Menu::newAuthor() {

}

void Menu::cloneArray(Reading *A[], Reading *B[]) {
    std::cout << "[ ";  // DEBUG PURPOSES ONLY
    for (int i = 0; i < totalSize; i++) {
        A[i] = B[i];
        if (i < totalSize-1) { std::cout << B[i]->getTitle() << ", "; }  // DEBUG PURPOSES ONLY
    }
    std::cout << B[totalSize-1]->getTitle() << " ]\n" << std::endl; // DEBUG PURPOSES ONLY
}

void Menu::hamiltonRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime) {
    int linkCost = 0;
    if (arraySize == 0) { // An ending has been reached
        if (acumulatedTime < this->minimalReadingsTime || this->minimalReadingsTime == -1) {
            this->minimalReadingsTime = acumulatedTime;
            std::cout << RED << "A new minimal time of " << this->minimalReadingsTime << " minutes was found!" << WHITE << std::endl; // DEBUG PURPOSES ONLY
            cloneArray(minimalOrder, currentOrder);
        }
    } else { 
        for (int i=0; i < totalSize; i++) {
            if (visited[i] == false) {      
                if (currentID != 0) {
                    linkCost = pReading.getCost(readings->search(currentID),readings->search(i));
                }
                visited[i] = true;
                currentOrder[totalSize-arraySize] = readings->search(i+1);
                hamiltonRecursion(minimalOrder, i+1, currentOrder, visited, arraySize-1, acumulatedTime+linkCost);                
                visited[i] = false;
            }
        }
    }
}

void Menu::calculateShortestReadingTime(Reading *minimalOrder[]) {
    this->minimalReadingsTime = -1;
    bool visited[totalSize];
    for (int i = 0; i < totalSize; i++) {
        visited[i] = false;
    }
    Reading *readingsOrder[totalSize];    
    hamiltonRecursion(minimalOrder, 0, readingsOrder, visited, totalSize, 0);
}

void Menu::shortestReadingsTime() {

    //pReading.displayMst();

    int totalTime = 0;
    readings->startCursor();
    while (readings->moveCursor()) {
        totalTime += readings->getCursor()->getMinutes();
    }    
    totalSize = readings->getNumberOfElements();
    Reading *minimalOrder[totalSize];
    calculateShortestReadingTime(minimalOrder);
    totalTime += minimalReadingsTime;
    std::cout << "\nReading order:"<< std::endl;
    for (int i = 0; i < totalSize-1; i++) {
        std::cout << "Read \"" << minimalOrder[i]->getTitle() << "\" (about " << minimalOrder[i]->getMinutes() << " minutes)" << std::endl;
        std::cout<< pReading.getCost(minimalOrder[i],minimalOrder[i+1]) << " minutes of rest later..." << std::endl;
    }
    std::cout << totalSize << ") " << minimalOrder[totalSize-1]->getTitle() << std::endl;
    std::cout << "\nTotal time spent: " << totalTime << "\n(including " << minimalReadingsTime << " minutes of rest and " << totalTime - minimalReadingsTime << " reading stories)\n" << std::endl;
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
                 "4. Salir\n" << std::endl;

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
            newReading();
            break;
        case TWO:
            displayReadings();
            break;
        case THREE:
            newAuthor();
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









