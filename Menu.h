#ifndef TP_FINAL_MENU_H
#define TP_FINAL_MENU_H
#include "list.h"
#include "Reading.h"
#include "Author.h"
#include "ReadingsFileParser.h"
#include "AuthorsFileParser.h"

class Menu {
private:
    int option;
    List<Reading*> *readings;
    List<Author*> *authors;
    ReadingsFileParser pReading;
    AuthorsFileParser  pAuthors;
    bool end;

    void  newReading();
    void  newAuthor();
    void  displayAuthors();
    void  displayReadings();
    void  shorterReadingTime();
    void  validateInputOption();
    void generateList();
    void input();
    void options();

public:
    Menu();
    void displayMenu();

    void interaction();

    ~Menu();

};


#endif //TP_FINAL_MENU_H
