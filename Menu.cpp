#include "Menu.h"


Menu::Menu() {
    this->readings = new List<Reading *>;
    this->authors = new HashTable<Author *>(20);
    this->graph = new Graph<int>;
    this->end = false;
    this->hamiltonian = new Hamiltonian();
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
    pAuthors.requestAuthorsInfo();
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


void Menu::validateInputOption(int max) {
    while (option < ONE || option > max) {  // NO SE COMO LLAMAR A LAS CONSTANTES
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
                 "   un metodo alternativo con Hamilton (simplificado)\n"
                 "5. Encontrar todos los ordenes y tiempo mínimos posibles que\n"
                 "   nos llevaría leer todas las lecturas usando\n"
                 "   un metodo alternativo con Hamilton con una lista\n"
                 "6. Salir\n" << std::endl;

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
            hamiltonian->getShortestReadingsTime(readings);
            break;
        case FIVE:
            hamiltonian->getShortestReadingsTimes(readings);
            std::cout << std::endl;
            break;
        case SIX:
            std::cout << MAGENTA "\nGracias por llegar hasta aca\n" WHITE << std::endl;
            break;
    }
}

void Menu::additionalFeatures() {
    this->displayAdditionalFeatures();
    this->input();
    this->validateInputOption(SIX);
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
        this->validateInputOption(NINE);
        this->options();
    }
}

Menu::~Menu() {
    delete authors;
    delete graph;
}









