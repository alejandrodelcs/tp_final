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

bool Menu::processInput(int input) {
    this->option = input;
    validateInputOption(NINE);
    options();
    return this->end;
}

void Menu::displayReadings() {
    pReadings.displayReadings();
}

void Menu::displayAuthors() {
    pAuthors.displayAuthors();
}

void Menu::displayTypeReading() {
    std::cout << GREEN "Ingrese el numero dependiendo del tipo de lectura que quiera agregar\n" WHITE
              << GREEN  "[1] " << WHITE "- Novelas\n"
              << GREEN "[2] " << WHITE "- Cuentos\n"
              << GREEN "[3] " << WHITE "- Poemas" << std::endl;
}

void Menu::addNewReading() {
    this->displayTypeReading();
    this->option = validation.requestNumber("");
    this->validateInputOption(THREE);
    pReadings.setAuthors(authors);
    pReadings.requestReadingsInfo(this->option);
    pReadings.setGraphNewVertex();
    pReadings.addGraphEdges();
}

void Menu::addNewAuthor() {
    pAuthors.requestAuthorsInfo();
}

void Menu::shortestReadingsTime() {
    pReadings.displayMst();
}

bool Menu::validateSearchOption(int totalAuthors) const {
    return (this->option < 1 || this->option > totalAuthors);
}

Author *Menu::getAuthorMenu() {
    Author *aux = nullptr;
    List<int> *insi = pAuthors.displayNameAuthors();
    if (insi->getNumberOfElements() > 0) {
        std::cout << std::endl;
        this->option = validation.requestNumber("");
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
        std::cout << RED << "¡" CYAN << aux->getName() <<  RED " ha sido eliminado!\n\n" WHITE;
        authors->removeElement(aux->getISNI());
    }
}

void Menu::validateInputOption(int max) {
    while (option < ONE || option > max) {
        std::cout << RED "¡Opcion incorrecta!\n" WHITE << std::endl;
        this->option = validation.requestNumber("");
    }
}

void Menu::displayAdditionalFeatures() {
    std::cout << "1. Mostrar Matriz de Adyacencia y vertices\n"
                 "2. Mostrar resultado de Algoritmo de Prim (solo MST)\n"
                 "3. Mostrar la tabla de hash\n"
                 "4. Encontrar el orden y tiempo mínimo usando Hamilton (simplificado)\n"
                 "5. Encontrar todos los ordenes y tiempos minimos usando Hamilton con una lista\n"
                 "6. Salir\n" << std::endl;

}

void Menu::optionsAdditional() {
    switch (this->option) {
        case ONE:
            graph->displayGraph();
            break;
        case TWO:
            pReadings.displayMst(1);
            break;
        case THREE:
            authors->display();
            break;
        case FOUR:
            hamiltonian.getShortestReadingsTime(readings,&pReadings);
            break;
        case FIVE:
            hamiltonian.getShortestReadingsTimes(readings,&pReadings);
            std::cout << std::endl;
            break;
        case SIX:
            std::cout << MAGENTA "\nGracias por llegar hasta aca\n" WHITE << std::endl;
            break;
        default:
            std::cout << "";
            break;
    }
}

void Menu::additionalFeatures() {
    this->displayAdditionalFeatures();
    this->option = validation.requestNumber("");
    this->validateInputOption(SIX);
    this->optionsAdditional();
}

void Menu::buildGraph() {
    pReadings.setGraph(graph);
    graph = pReadings.getGraph();
    pReadings.setGraphVertex();
    pReadings.addGraphEdges();
}

void Menu::buildListReadings() {
    pReadings.setReadingList(this->readings);
    this->readings = pReadings.getReadings();
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
            addNewAuthor();
            break;
        case FOUR:
            displayAuthors();
            break;
        case FIVE:
            searchAuthor();
            break;
        case SIX:
            removeAuthor();
            break;
        case SEVEN:
            shortestReadingsTime();
            break;
        case EIGHT:
            additionalFeatures();
            break;
        case NINE:
            this->end = true;
            break;
        default:
            std::cout << "";
            break;
    }
}

void Menu::buildLists() {
    buildListReadings();
    buildGraph();
    buildHashTable();
}

Menu::~Menu() {
    delete authors;
    delete graph;
}
