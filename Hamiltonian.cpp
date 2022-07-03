#include "Hamiltonian.h"

Hamiltonian::Hamiltonian() {    
    this->readings = new List<Reading *>;
}

void Hamiltonian::cloneReadingsArray(Reading *A[], Reading *B[]) {
    for (int i = 0; i < readingsSize; i++) {
        A[i] = B[i];
    }
}

void Hamiltonian::hamiltonianRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime) {
    int linkCost = 0;
    if (arraySize == 0) {
        if (acumulatedTime < this->edgesTime || this->edgesTime == -1) {
            newRecord(minimalOrder, currentOrder, acumulatedTime);
        }
        if (explanation) {
            displayOrder(currentOrder,acumulatedTime);
        }
    } else { 
        for (int i=0; i < readingsSize; i++) {
            if (!(visited[i]) && (i != currentID)) {
                linkCost= getLinkCost(currentID, currentOrder, arraySize, i);
                visited[i] = true;
                currentOrder[readingsSize-arraySize] = readings->search(i+1);
                hamiltonianRecursion(minimalOrder, i, currentOrder, visited, arraySize-1, acumulatedTime+linkCost);                
                visited[i] = false;
            }
        }
    }
}

void Hamiltonian::calculateHamiltonianShortestReadingTime(Reading *minimalOrder[]) {
    this->edgesTime = -1;
    bool visited[readingsSize];
    for (int i = 0; i < readingsSize; i++) {
        visited[i] = false;
    }
    Reading *readingsOrder[readingsSize];    
    hamiltonianRecursion(minimalOrder, -1, readingsOrder, visited, readingsSize, 0);
}

void Hamiltonian::getShortestReadingsTime(List<Reading *> *readings, ReadingsFileParser *pReadings) {
    explainProcess();
    this->pReadings = pReadings;
    this->readings = readings;
    int VertexesTime = 0;
    readings->startCursor();
    while (readings->moveCursor()) {
        VertexesTime += readings->getCursor()->getMinutes();
    }    
    readingsSize = readings->getNumberOfElements();
    Reading *minimalOrder[readingsSize];
    calculateHamiltonianShortestReadingTime(minimalOrder);
    int totalTime = VertexesTime + edgesTime;
    std::cout << "\nOrden de las lecturas:\n"<< std::endl;
    for (int i = 0; i < readingsSize-1; i++) {
        std::cout << "Leer \"" << minimalOrder[i]->getTitle() << "\" (Alrededor de " << minimalOrder[i]->getMinutes() << " minutos)" << std::endl;
        std::cout << "Descansar por " << pReadings->getCost(minimalOrder[i],minimalOrder[i+1]) << " minutos..." << std::endl;
    }
    std::cout << "Leer \"" << minimalOrder[readingsSize-1]->getTitle() << "\" (Alrededor de " << minimalOrder[readingsSize-1]->getMinutes() << " minutos)" << std::endl;
    std::cout << "\nTiempo minimo total: " << totalTime << "\n(De los cuales " << edgesTime << " minutos son descansando y " << totalTime - edgesTime << " son leyendo cuentos)\n" << std::endl;
}

void Hamiltonian::addArrayToList(Reading *B[]) {
    List<Reading*>* A = new List<Reading*>;
    for (int i = 0; i < readingsSize; i++) {
        A->add(B[i]);
    }
    minimalOrders->add(A);
}

void Hamiltonian::hamiltonianRecursion(int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime) {
    int linkCost = 0;
    if (arraySize == 0) {
        if (acumulatedTime < this->edgesTime || this->edgesTime == -1) {
            this->edgesTime = acumulatedTime;
            newRecord(currentOrder, acumulatedTime);
        } else if (acumulatedTime == this->edgesTime) {
            if (explanation) {
                std::cout << RED << "Se a hallado otro orden con el mismo tiempo de " << this->edgesTime << " minutos!" << std::endl;
            }
            addArrayToList(currentOrder);
        }
        if (explanation) {
            displayOrder(currentOrder, acumulatedTime);
        }
    } else { 
        for (int i=0; i < readingsSize; i++) {
            if (!(visited[i]) && (i != currentID)) {
                linkCost = getLinkCost(currentID, currentOrder, arraySize, i);
                visited[i] = true;
                currentOrder[readingsSize-arraySize] = readings->search(i+1);
                hamiltonianRecursion(i, currentOrder, visited, arraySize-1, acumulatedTime+linkCost);                
                visited[i] = false;
            }
        }
    }
}

void Hamiltonian::calculateShortestReadingTimes() {
    this->edgesTime = -1;
    bool visited[readingsSize];
    for (int i = 0; i < readingsSize; i++) {
        visited[i] = false;
    }
    Reading *readingsOrder[readingsSize];    
    hamiltonianRecursion(-1, readingsOrder, visited, readingsSize, 0);
}

void Hamiltonian::getShortestReadingsTimes(List<Reading *> *readings, ReadingsFileParser *pReadings) {
    explainProcess();
    this->pReadings = pReadings;
    this->readings = readings;
    int VertexesTime = 0;
    readings->startCursor();
    while (readings->moveCursor()) {
        VertexesTime += readings->getCursor()->getMinutes();
    }    
    readingsSize = readings->getNumberOfElements();
    calculateShortestReadingTimes();
    ordersMenu(VertexesTime + edgesTime);
}

void Hamiltonian::displayPossibileOrder(int option) {
    int j=1;
    Reading *currentReading, *oldReading;
    minimalOrders->startCursor();
    while (minimalOrders->moveCursor()) {
        if (j == option) {
            std::cout << "\nOrden de las lecturas (Opcion " << j << "/" << minimalOrders->getNumberOfElements() << "):\n" << std::endl;
            oldReading = nullptr;
            minimalOrders->getCursor()->startCursor();
            while (minimalOrders->getCursor()->moveCursor()) {
                currentReading = minimalOrders->getCursor()->getCursor();
                if (oldReading != nullptr) {
                    std::cout << "Descansar por " << pReadings->getCost(oldReading,currentReading) << " minutos..." << std::endl;
                }
                std::cout << "Leer \"" << currentReading->getTitle() << "\" (Alrededor de " << currentReading->getMinutes() << " minutos)" << std::endl;            
                oldReading = currentReading;
            }
        }
        j++;
    }
}

void Hamiltonian::ordersMenu(int totalTime) {
    int input = -1;
    int optionsAmount = minimalOrders->getNumberOfElements();
    while (input != 0) {
        std::cout << "\nEl menor tiempo posible requerido para leer todas las lecturas es " << totalTime << 
                     "\n(De los cuales " << edgesTime << " minutos son descansando y " << totalTime - edgesTime << " son leyendo cuentos)\n\n"
                     "Hay " << optionsAmount << " ordenes posibles para lograr esto.\n"
                     "Ingresar una opcion valida para mostrarla en pantalla (0 para no mostrar proceso)\n" << std::flush;
        input = validation.requestNumber("");
        if (input > 0 && input <= optionsAmount) {
            displayPossibileOrder(input);
        } else if (input < 0 || input > optionsAmount){                
            std::cout << RED "¡Ingresar una opcion valida entre 0 y " << optionsAmount << "!\n" WHITE;
        } 
        std::cout << std::endl;
    }
}


void Hamiltonian::newRecord(Reading *minimalOrder[], Reading *currentOrder[], int acumulatedTime) {
    this->edgesTime = acumulatedTime;
    if (explanation) {
        std::cout << RED << "Se a hallado un nuevo tiempo minimo de " << this->edgesTime << " minutos!" << std::endl;
    }
    cloneReadingsArray(minimalOrder, currentOrder);
}

void Hamiltonian::newRecord(Reading *currentOrder[], int acumulatedTime) {
    this->edgesTime = acumulatedTime;
    if (explanation) {
        std::cout << RED << "Se a hallado un nuevo tiempo minimo de " << this->edgesTime << " minutos!" << std::endl;
    }
    minimalOrders = new List<List<Reading*>*>;
    addArrayToList(currentOrder);
}

void Hamiltonian::explainProcess() {
    bool valid = false;
    std::string input;
    while (!valid) {
        std::cout << "Desea ver la explicacion del proceso? (Y/n)\n\n> " << std::flush;
        getline(std::cin, input);
        if (input == "y" || input == "Y") {
            this->explanation = true;
            valid = true;
            std::cout << std::endl;
        } else if (input == "n" || input == "N") {
            this->explanation = false;
            valid = true;
        } else {
            std::cout << RED "\n¡Ingreso invalido!\n\n" WHITE << std::endl;
        }
    }
}

void Hamiltonian::displayOrder(Reading *currentOrder[], int acumulatedTime) {
    std::cout << "Tiempo acumulado por las aristas de [ ";
    for (int i = 0; i < readingsSize; i++) {
        if (i < readingsSize-1) { std::cout << currentOrder[i]->getTitle() << ", "; }
    }
    std::cout << currentOrder[readingsSize-1]->getTitle() << " ] = " << acumulatedTime << std::endl;
    std::cout << WHITE;
}

int Hamiltonian::getLinkCost(int currentID, Reading *currentOrder[],int arraySize,int i) {
    int linkCost;
    if (currentID != -1) {
        linkCost = pReadings->getCost(currentOrder[readingsSize-arraySize-1],readings->search(i+1));
        //std::cout << "(" << currentOrder[readingsSize-arraySize-1]->getTitle() << " -> " << readings->search(i+1)->getTitle() << ") = " << linkCost << std::endl;
    } else {
        linkCost = 0;
        //std::cout << "(" << readings->search(i+1)->getTitle() << ") = new parent" << std::endl;
    }
    return linkCost;
}

Hamiltonian::~Hamiltonian() {
    if (readings != nullptr) {
        readings->startCursor();
        while (readings->moveCursor()) {
            delete readings->getCursor();
        }
        delete readings;
    }
}
