#ifndef TP_FINAL_MENU_H
#define TP_FINAL_MENU_H
#include <iostream>
#include "List.h"
#include "Constants.h"
#include "Reading.h"
#include "Author.h"
#include "Hash.h"
#include "ReadingsFileParser.h"
#include "AuthorsFileParser.h"
#include "Graph.h"
#include "PRUEBA.h"

class Menu {
private:
    int option;
    List<Reading*> *readings;
    ReadingsFileParser pReading;
    AuthorsFileParser  pAuthors;
    HashTable<Author*>* authors;
    Graph<int>* graph;
    Reading* newReading;
    Author* newAuthor;
    bool end;

    void addNewReading();
    void displayReadings();
    bool validateSearchOption(int totalAuthors) const;
    void addNewAuthor();
    void displayAuthors();
    void searchAuthor();
    Author* getAuthorMenu();
    void removeAuthor();
    void shortestReadingsTime();
    void additionalFeatures();
    void buildHashTable();
    void validateInputOption();
    void buildListReadings();
    void buildGraph();
    void input();
    void options();
    void displayMenu();
    void optionsAdditional();
    void displayAdditionalFeatures();
    void alternativeShortestReadingsTime();

    int minimalReadingsTime = -1;
    int totalSize = 0;    
    void cloneArray(Reading *A[], Reading *B[]);
    void hamiltonianRecursion(Reading *minimalOrder[], int currentID, Reading *currentOrder[], bool visited[], int arraySize, int acumulatedTime);
    void calculateHamiltonianShortestReadingTime(Reading *minimalOrder[]);
    void hamiltonianShortestReadingsTime();

public:
    Menu();

    void interaction();

    ~Menu();

};


#endif //TP_FINAL_MENU_H
