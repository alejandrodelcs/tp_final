#ifndef TP_FINAL_HAMILTON_H
#define TP_FINAL_HAMILTON_H
#include <iostream>
#include "List.h"
#include "Reading.h"
#include "ReadingsFileParser.h"

class Hamiltonian {
    private:
    List<Reading*> *readings;
    int minimalReadingsTime;
    int readingsSize;    
    ReadingsFileParser* pReading;

    void cloneArray(Reading *A[], Reading *B[]);
    void hamiltonianRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime);
    void calculateHamiltonianShortestReadingTime(Reading *minimalOrder[]);

    void addArrayToList(Reading *B[], List<List<Reading*>*>*minimalOrders);
    void hamiltonianRecursion(List<List<Reading*>*>*minimalOrders, int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime);
    void calculateShortestReadingTimes(List<List<Reading*>*>*minimalOrders);
    public:
    Hamiltonian();
    void getShortestReadingsTime(List<Reading *> *readings);
    void getShortestReadingsTimes(List<Reading *> *readings);
    
};

#endif