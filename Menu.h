#ifndef TP_FINAL_MENU_H
#define TP_FINAL_MENU_H
#include "List.h"
#include "Reading.h"
#include "Author.h"
#include "Hash.h"
#include "ReadingsFileParser.h"
#include "AuthorsFileParser.h"
#include "Graph.h"

class Menu {
private:
    int option;
    List<Reading*> *readings;
    ReadingsFileParser pReading;
    AuthorsFileParser  pAuthors;
    HashTable<Author*>* authors;

    bool end;

    void  newReading();
    void  displayReadings();
    void  newAuthor();
    void  displayAuthors();
    void searchAuthor();
    void removeAuthor();
    void  shorterReadingTime();
    void buildHashTable();
    void  validateInputOption();
    void buildListReadings();
    void input();
    void options();
    void displayMenu();
public:
    Menu();

    void interaction();

    ~Menu();

};


#endif //TP_FINAL_MENU_H
