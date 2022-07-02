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
    std::string fileLine;
    HashTable<Author*>* authors;
    List<Reading*> *readings;
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
     * POST: returns the ID (reference number) of the line of the file
     */
    int getISNI();
    /*
     * PRE:
     * POST: returns the filename of the line in the file
     */
    bool validateFileLine();
    /*
     * PRE:
     * POST: Initializes the data brought in from the writers' files
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
     * POST:
     */
    AuthorsFileParser();
    /*
     * PRE:
     * POST: Returns the hash table with the authors
     */
    HashTable<Author *>* getAuthors();
    /*
     * PRE:
     * POST: Adds the author to his reading
     */
    void addReadingAuthor();
    /*
     * PRE:
     * POST: Set the list of readings to  Readings File Parser
     */
    void setReadings(List<Reading*>* &l);
    /*
     * PRE:
     * POST: Set the table hash of Readings File Parser
     */
    void setAuthors(HashTable<Author*>* &a);
    /*
     * PRE:
     * POST:
     */
    void displayAuthors();
    /*
     * PRE:
     * POST:  author's data request
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
