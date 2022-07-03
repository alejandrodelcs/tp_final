#ifndef TP_FINAL_AUTHORSFILEPARSER_H
#define TP_FINAL_AUTHORSFILEPARSER_H

#include <string>
#include "Constants.h"
#include "File.h"
#include "Author.h"
#include "List.h"
#include "Hash.h"
#include "Reading.h"
#include "Validation.h"

class AuthorsFileParser {
private:
    File file;
    List<Reading*> *readings;
    HashTable<Author*>* authors;
    std::string fileLine;
    Author* author;
    int isni;
    int birth;
    int death;
    std::string name;
    List<int> *insi;
    std::string nationality;
    Validation validation;
    /*
     * PRE:
     * POST: Returns the ID (reference number) of the line of the file
     */
    int getISNI();
    /*
     * PRE:
     * POST: Returns the filename of the line in the file
     */
    bool validateFileLine();
    /*
     * PRE:
     * POST: Initializes the data brought in from the file "autores.txt"
     */
    void validateAuthorFile(int count);
    /*
     * PRE:
     * POST: Returns the number to be referenced in the readings file.
     */
    bool newReference();
    /*
     * PRE:
     * POST: Validates the last writer of the file
     */
    void validateEOFAuthor(int count);
    /*
    * PRE:
    * POST:
    */
    void requestISNI();
    /*
     * PRE:-
     * POST: Adds the new author to the main list of authors.
     */
    void addNewAuthor();
public:
    /* Constructor
     * PRE:
     * POST: Builds a new AuthorsFileParser object.
     */
    AuthorsFileParser();
    /*
     * PRE:
     * POST: Returns the hash table with the authors.
     */
    HashTable<Author *>* getAuthors();
    /*
     * PRE:
     * POST: Adds the current author to the list of readings.
     */
    void addReadingAuthor();
    /*
     * PRE:
     * POST: Sets the list of readings to match the function's calling parameter.
     */
    void setReadings(List<Reading*>* &readings);
    /*
     * PRE:
     * POST: Sets the hash table of authors to the function's calling parameter.
     */
    void setAuthors(HashTable<Author*>* &authors);
    /*
     * PRE:
     * POST: Displays all of the elements in the hash table of authors.
     */
    void displayAuthors();
    /*
     * PRE:
     * POST: Request user's input to create a new author.
     */
    void requestAuthorsInfo();
    /*
     * PRE:
     * POST:
     */
    List<int>* displayNameAuthors();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used (Destroys the readings list).
     */
    ~AuthorsFileParser();
};

#endif
