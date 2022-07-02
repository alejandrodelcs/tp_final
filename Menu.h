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
    int option;
    List<Reading*> *readings;
    ReadingsFileParser pReadings;
    AuthorsFileParser  pAuthors;
    HashTable<Author*>* authors;
    Graph<int>* graph;
    Hamiltonian hamiltonian;
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
    void validateInputOption(int max);
    void buildListReadings();
    void buildGraph();
    void input();
    void options();
    void displayMenu();
    void optionsAdditional();
    void displayAdditionalFeatures();
public:
    /* Constructor
     * PRE:
     * POST:
     */
    Menu();
    void interaction();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~Menu();
};


#endif //TP_FINAL_MENU_H
