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
     * POST: add new reading is created and added as a new vertex in the graph.
     */
    void addNewReading();
    /*
     * PRE:
     * POST:
     */
    void displayReadings();
    /*
     * PRE:
     * POST: valid menu option
     */
    bool validateSearchOption(int totalAuthors) const;
    /*
     * PRE:
     * POST:  build a new writer and inserts it into the hash table
     */
    void addNewAuthor();
    /*
     * PRE:
     * POST:
     */
    void displayAuthors();
    /*
     * PRE:
     * POST: searching author in hash table
     */
    void searchAuthor();
    /*
     * PRE:
     * POST: show the authors in the hash table and returns them
     */
    Author* getAuthorMenu();
    /*
     * PRE:
     * POST: delete the author in the table hash
     */
    void removeAuthor();
    /*
     * PRE:
     * POST: shows minimum total reading (MST)
     */
    void shortestReadingsTime();
    /*
     * PRE:
     * POST: additional menu options
     */
    void additionalFeatures();
    /*
     * PRE:
     * POST: build the hash table
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
     * POST: constructs the graph from the reading list
     */
    void buildGraph();

    /*
     * PRE:
     * POST: menu options
     */
    void options();
    /*
     * PRE:
     * POST: additional menu options
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
     * POST:  builds new list in menu
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
