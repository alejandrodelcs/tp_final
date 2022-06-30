#include "Hamiltonian.h"

Hamiltonian::Hamiltonian() {    
    this->readings = new List<Reading *>;
}

void Hamiltonian::cloneArray(Reading *A[], Reading *B[]) {
    for (int i = 0; i < readingsSize; i++) {
        A[i] = B[i];
    }
}

void Hamiltonian::hamiltonianRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime) {
    int linkCost = 0;
    if (arraySize == 0) {
        if (acumulatedTime < this->minimalReadingsTime || this->minimalReadingsTime == -1) {
            this->minimalReadingsTime = acumulatedTime;
            std::cout << RED << "Se a hallado un nuevo tiempo minimo de " << this->minimalReadingsTime << " minutos!" << std::endl;
            cloneArray(minimalOrder, currentOrder);
        }
        std::cout << "Tiempo acumulado por las aristas de [ "; 
        for (int i = 0; i < readingsSize; i++) {
            if (i < readingsSize-1) { std::cout << currentOrder[i]->getTitle() << ", "; } 
        }
        std::cout << currentOrder[readingsSize-1]->getTitle() << " ] = " << acumulatedTime << std::endl;
        std::cout << WHITE;
    } else { 
        for (int i=0; i < readingsSize; i++) {
            if (!(visited[i]) && (i != currentID)) {     
                if (currentID != -1) {
                    linkCost = pReadings->getCost(currentOrder[readingsSize-arraySize-1],readings->search(i+1));
                    //std::cout << "(" << currentOrder[readingsSize-arraySize-1]->getTitle() << " -> " << readings->search(i+1)->getTitle() << ") = " << linkCost << std::endl;
                } else {
                    linkCost = 0;
                    //std::cout << "(" << readings->search(i+1)->getTitle() << ") = new parent" << std::endl;
                }
                visited[i] = true;
                currentOrder[readingsSize-arraySize] = readings->search(i+1);
                hamiltonianRecursion(minimalOrder, i, currentOrder, visited, arraySize-1, acumulatedTime+linkCost);                
                visited[i] = false;
            }
        }
    }
}

void Hamiltonian::calculateHamiltonianShortestReadingTime(Reading *minimalOrder[]) {
    this->minimalReadingsTime = -1;
    bool visited[readingsSize];
    for (int i = 0; i < readingsSize; i++) {
        visited[i] = false;
    }
    Reading *readingsOrder[readingsSize];    
    hamiltonianRecursion(minimalOrder, -1, readingsOrder, visited, readingsSize, 0);
}

void Hamiltonian::getShortestReadingsTime(List<Reading *> *readings, ReadingsFileParser *pReadings) {
    this->pReadings = pReadings;
    this->readings = readings;
    int totalTime = 0;
    readings->startCursor();
    while (readings->moveCursor()) {
        totalTime += readings->getCursor()->getMinutes();
    }    
    readingsSize = readings->getNumberOfElements();
    Reading *minimalOrder[readingsSize];
    calculateHamiltonianShortestReadingTime(minimalOrder);
    totalTime += minimalReadingsTime;
    std::cout << "\nOrden de las lectuas:"<< std::endl;
    for (int i = 0; i < readingsSize-1; i++) {
        std::cout << "Leer \"" << minimalOrder[i]->getTitle() << "\" (Alrededor de " << minimalOrder[i]->getMinutes() << " minutos)" << std::endl;
        std::cout << "Descansar por " << pReadings->getCost(minimalOrder[i],minimalOrder[i+1]) << " minutos..." << std::endl;
    }
    std::cout << "Leer \"" << minimalOrder[readingsSize-1]->getTitle() << "\" (Alrededor de " << minimalOrder[readingsSize-1]->getMinutes() << " minutos)" << std::endl;
    std::cout << "\nTiempo minimo total: " << totalTime << "\n(De los cuales " << minimalReadingsTime << " minutos son descansando y " << totalTime - minimalReadingsTime << " son leyendo cuentos)\n" << std::endl;
}


void Hamiltonian::addArrayToList(Reading *B[], List<List<Reading*>*>*minimalOrders) {
    List<Reading*>* A = new List<Reading*>;
    for (int i = 0; i < readingsSize; i++) {
        A->add(B[i]);
    }
    minimalOrders->add(A);
}

void Hamiltonian::hamiltonianRecursion(List<List<Reading*>*>*minimalOrders, int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime) {
    int linkCost = 0;
    if (arraySize == 0) {
        if (acumulatedTime < this->minimalReadingsTime || this->minimalReadingsTime == -1) {
            this->minimalReadingsTime = acumulatedTime;
            std::cout << RED << "Se a hallado un nuevo tiempo minimo de " << this->minimalReadingsTime << " minutos!" << std::endl;            
            minimalOrders = new List<List<Reading*>*>;
            addArrayToList(currentOrder, minimalOrders);
        } else if (acumulatedTime == this->minimalReadingsTime) {
            std::cout << RED << "Se a hallado otro orden con el mismo tiempo de " << this->minimalReadingsTime << " minutos!" << std::endl;
            addArrayToList(currentOrder, minimalOrders);
        }
        std::cout << "Tiempo acumulado por las aristas de [ "; 
        for (int i = 0; i < readingsSize; i++) {
            if (i < readingsSize-1) { std::cout << currentOrder[i]->getTitle() << ", "; } 
        }
        std::cout << currentOrder[readingsSize-1]->getTitle() << " ] = " << acumulatedTime << std::endl;
        std::cout << WHITE;
    } else { 
        for (int i=0; i < readingsSize; i++) {
            if (!(visited[i]) && (i != currentID)) {     
                if (currentID != -1) {
                    linkCost = pReadings->getCost(currentOrder[readingsSize-arraySize-1],readings->search(i+1));
                    //std::cout << "(" << currentOrder[readingsSize-arraySize-1]->getTitle() << " -> " << readings->search(i+1)->getTitle() << ") = " << linkCost << std::endl;
                } else {
                    linkCost = 0;
                    //std::cout << "(" << readings->search(i+1)->getTitle() << ") = new parent" << std::endl;
                }
                visited[i] = true;
                currentOrder[readingsSize-arraySize] = readings->search(i+1);
                hamiltonianRecursion(minimalOrders, i, currentOrder, visited, arraySize-1, acumulatedTime+linkCost);                
                visited[i] = false;
            }
        }
    }
}

void Hamiltonian::calculateShortestReadingTimes(List<List<Reading*>*>*minimalOrders) {
    this->minimalReadingsTime = -1;
    bool visited[readingsSize];
    for (int i = 0; i < readingsSize; i++) {
        visited[i] = false;
    }
    Reading *readingsOrder[readingsSize];    
    hamiltonianRecursion(minimalOrders, -1, readingsOrder, visited, readingsSize, 0);
}

void Hamiltonian::getShortestReadingsTimes(List<Reading *> *readings, ReadingsFileParser *pReadings) {
    this->pReadings = pReadings;
    this->readings = readings;
    int totalTime = 0;
    readings->startCursor();
    while (readings->moveCursor()) {
        totalTime += readings->getCursor()->getMinutes();
    }    
    readingsSize = readings->getNumberOfElements();
    List<List<Reading*>*>* minimalOrders = new List<List<Reading*>*>;
    calculateShortestReadingTimes(minimalOrders);
    totalTime += minimalReadingsTime;
    int j=1;
    Reading *currentReading, *oldReading;
    minimalOrders->startCursor();
    while (minimalOrders->moveCursor()) {
        std::cout << "\nOrden de las lecturas (Opcion " << j << "/" << minimalOrders->getNumberOfElements() << "):\n" << std::endl;
        oldReading = NULL;
        minimalOrders->getCursor()->startCursor();
        while (minimalOrders->getCursor()->moveCursor()) {
            currentReading = minimalOrders->getCursor()->getCursor();
            if (oldReading != NULL) {
                std::cout << "Descansar por " << pReadings->getCost(oldReading,currentReading) << " minutos..." << std::endl;
            }
            std::cout << "Leer \"" << currentReading->getTitle() << "\" (Alrededor de " << currentReading->getMinutes() << " minutos)" << std::endl;            
            oldReading = currentReading;
        }
        std::cout << "\nTiempo minimo total: " << totalTime << "\n(De los cuales " << minimalReadingsTime << " minutos son descansando y " << totalTime - minimalReadingsTime << " son leyendo cuentos)" << std::endl;
        j++;
    }
}
