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
#include "Hamiltonian.h"
#include "Validation.h"

class Menu {
private:
    Validation validation;
    int option;
    List<Reading*> *readings;
    ReadingsFileParser pReadings;
    AuthorsFileParser  pAuthors;
    HashTable<Author*>* authors;
    Graph<int>* graph;
    Hamiltonian hamiltonian;
    bool end;
    /*
     * PRE:
     * POST:
     */
    void addNewReading();
    /*
     * PRE:
     * POST:
     */
    void displayReadings();
    /*
     * PRE:
     * POST:
     */
    bool validateSearchOption(int totalAuthors) const;
    /*
     * PRE:
     * POST:
     */
    void addNewAuthor();
    /*
     * PRE:
     * POST:
     */
    void displayAuthors();
    /*
     * PRE:
     * POST:
     */
    void searchAuthor();
    /*
     * PRE:
     * POST:
     */
    Author* getAuthorMenu();
    /*
     * PRE:
     * POST:
     */
    void removeAuthor();
    /*
     * PRE:
     * POST:
     */
    void shortestReadingsTime();
    /*
     * PRE:
     * POST:
     */
    void additionalFeatures();
    /*
     * PRE:
     * POST:
     */
    void buildHashTable();
    /*
     * PRE:
     * POST:
     */
    void validateInputOption(int max);
    /*
     * PRE:
     * POST:
     */
    void buildListReadings();
    /*
     * PRE:
     * POST:
     */
    void buildGraph();
    /*
     * PRE:
     * POST:
     */
    void input();
    /*
     * PRE:
     * POST:
     */
    void options();
    /*
     * PRE:
     * POST:
     */
    void optionsAdditional();
    /*
     * PRE:
     * POST:
     */
    void displayAdditionalFeatures();
    /*
     * PRE:
     * POST:
     */
    void displayTypeReading();
public:
    /* Constructor
     * PRE:
     * POST: Builds a new Menu object (initializing the attributes: readings, authors, graph and end)
     */
    Menu();
    /*
     * PRE:
     * POST:
     */
    void buildLists();
    /*
     * PRE:
     * POST:
     */
    bool processInput(int input);    
    /*
     * PRE:
     * POST:
     */
    void displayMenu();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used by authors and graph.
     */
    ~Menu();
};

#endif
