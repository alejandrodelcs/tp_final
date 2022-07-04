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


class Menu {
private:
    Validation validation;
    int option;
    List<Reading*> *readings;
    ReadingsFileParser pReadings;
    AuthorsFileParser  pAuthors;
    HashTable<Author*>* authors;
    Graph<int>* graph;
    bool end;
    /*
     * PRE:
     * POST: Creates a new reading and adds it (as a vertex) to the graph.
     */
    void addNewReading();
    /*
     * PRE:
     * POST:
     */
    void displayReadings();
    /*
     * PRE:
     * POST: Validates the input when searching for an author.
     */
    bool validateSearchOption(int totalAuthors) const;
    /*
     * PRE:
     * POST: Builds a new writer and inserts it in the hash table.
     */
    void addNewAuthor();
    /*
     * PRE:
     * POST:
     */
    void displayAuthors();
    /*
     * PRE:
     * POST: Searches an author in the hash table.
     */
    void searchAuthor();
    /*
     * PRE:
     * POST: Shows the authors in the hash table and allows the user to select one of them.
     */
    Author* getAuthorMenu();
    /*
     * PRE:
     * POST: Removes an author from the hash table.
     */
    void removeAuthor();
    /*
     * PRE:
     * POST: Displays the MST for the minimal total time reading.
     */
    void shortestReadingsTime();
    /*
     * PRE:
     * POST: Handles the additional menu options.
     */
    void additionalFeatures();
    /*
     * PRE:
     * POST: Builds the hash table
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
     * POST: Builds the graph using the readings list.
     */
    void buildGraph();
    /*
     * PRE:
     * POST: Handles the possible options of the menu.
     */
    void options();
    /*
     * PRE:
     * POST: Handles the possible options of the additional menu.
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
     * POST: Builds the necessary lists of the menu.
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
