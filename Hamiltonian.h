#ifndef TP_FINAL_HAMILTON_H
#define TP_FINAL_HAMILTON_H

#include <iostream>
#include "List.h"
#include "Reading.h"
#include "ReadingsFileParser.h"
#include "Validation.h"

class Hamiltonian {
private:
    List<Reading *> *readings;
    int edgesTime;
    int readingsSize;
    ReadingsFileParser *pReadings;
    Validation validation;
    bool explanation;
    List<List<Reading*>*>* minimalOrders;
    List<List<Reading*>*>* minimalOrders;

    /*
     * PRE:
     * POST:
     */
    void displayPossibileOrder(int option);

    /*
     * PRE:
     * POST:
     */
    void ordersMenu(int totalTime);

    /*
     * PRE:
     * POST:
     */
    void explainProcess();

    /*
     * PRE:
     * POST:
     */
    void cloneReadingsArray(Reading *A[], Reading *B[]);

    /*
     * PRE:
     * POST:
     */
    void hamiltonianRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime);

    /*
     * PRE:
     * POST:
     */
    void calculateHamiltonianShortestReadingTime(Reading *minimalOrder[]);

    /*
     * PRE:
     * POST:
     */
    void addArrayToList(Reading *B[]);

    /*
     * PRE:
     * POST:
     */
    void
    hamiltonianRecursion(int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime);

    /*
     * PRE:
     * POST:
     */
    void newRecord(Reading *minimalOrder[], Reading *currentOrder[], int acumulatedTime);

    /*
     * PRE:
     * POST:
     */
    void newRecord(Reading *currentOrder[], int acumulatedTime);

    /*
     * PRE:
     * POST:
     */
    void displayOrder(Reading *currentOrder[], int acumulatedTime);

    /*
     * PRE:
     * POST:
     */

    int getLinkCost(int currentID, Reading *currentOrder[], int arraySize, int i);

    void calculateShortestReadingTimes();

public:
    Hamiltonian();
    /*
     * PRE:
     * POST:
     */
    void getShortestReadingsTime(List<Reading *> *readings, ReadingsFileParser *pReadings);

    /*
     * PRE:
     * POST:
     */
    void getShortestReadingsTimes(List<Reading *> *readings, ReadingsFileParser *pReadings);

    /*
     * PRE:
     * POST
     */
    ~Hamiltonian();

};

#endif