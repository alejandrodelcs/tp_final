#include "Menu.h"

Menu::Menu() {
    this->readings = new List<Reading *>;
    this->authors = new HashTable<Author *>(20);
    this->graph = new Graph<int>;
    this->end = false;
}

void Menu::displayMenu() {
    std::cout << "1. Nueva lectura\n"
                 "2. Mostrar lecturas\n" // SE PUEDE AGREGAR ELIMINAR Y ALTA (C/ SUBMENU), VA A DEPENDER COMO LLEGUEMOS
                 "3. Nuevo autor/escritor\n"
                 "4. Mostrar autores\n"
                 "5. Buscar autor\n"
                 "6. Eliminar autor\n"
                 "7. Encontrar el orden y tiempo mínimo que nos\n"
                 "   llevaría leer todas las lecturas\n"
                 "8. Extras\n"
                 "9. Salir" << std::endl;

}

void Menu::input() {
    std::cout << "Ingrese opcion: ";
    std::cin >> this->option;
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


void Menu::shorterReadingTime() {
    pReading.displayMst();

}

bool Menu::validateSearchOption(int totalAuthors) const {
    return (this->option < 0 || this->option > totalAuthors);
}

Author *Menu::getAuthorMenu() {
    Author *aux = nullptr;
    List<int> *insi = pAuthors.displayNameAuthors();
    std::cout << std::endl;
    this->input();
    if (!(this->validateSearchOption(insi->getNumberOfElements()))) {
        aux = authors->searchElement(insi->search(this->option));
    } else {
        std::cout << RED "\n¡Autor no encontrado!\n" WHITE << std::endl;
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
        std::cout << std::endl;
        std::cout << aux->getName() << RED " ¡Ha sido eliminado!" WHITE;
        std::cout << std::endl;
        std::cout << std::endl;
        authors->removeElement(aux->getISNI());

    }
}


void Menu::validateInputOption() {
    while (option < ONE || option > NINE) {  // NO SE COMO LLAMAR A LAS CONSTANTES
        std::cout << RED "¡Error!. Opcion incorrecta" WHITE << std::endl;
        this->input();
    }
}

void Menu::displayAdditionalFeatures() {
    std::cout << "1. Mostrar Matriz de Adyacencia y vertices\n"
                 "2. Mostrar resultado de Algoritmo de Prim (sin formato)\n" // SE PUEDE AGREGAR ELIMINAR Y ALTA (C/ SUBMENU), VA A DEPENDER COMO LLEGUEMOS
                 "3. Mostrar tabla de hash\n"
                 "4. Salir" << std::endl;

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
    this->readings = pReading.getReadings(); // TODO : Error en linux
}

void Menu::buildHashTable() {
    pAuthors.setReadings(readings);
    pAuthors.setAuthors(authors);
    this->authors = pAuthors.getAuthors(); // TODO : Error en linux
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
            shorterReadingTime();
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









