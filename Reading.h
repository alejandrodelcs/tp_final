#ifndef TP_FINAL_READING_H
#define TP_FINAL_READING_H

#include <string>
#include <iostream>
#include "Author.h"
#include "Constants.h"

enum class Genres {DRAMA=1,COMEDY,FICTION,THRILLER,HORROR,ROMANCE,HISTORICAL,UNKNOWN};

class Reading {

protected:
    std::string title;
    unsigned int minutes;
    unsigned int PublishYear;
    Author *author;
    int isni;
    char type;
public:
    /* Constructor
     * PRE:
     * POST: Builds a new reading.
     */
    Reading(const std::string &title, unsigned int minutes, unsigned int PublishYear);
    /*
     * PRE:
     * POST: Inherited method that will display the attributes of the child classes.
     */
    virtual void display() = 0;
    /*
     * PRE:
     * POST: Returns the genre of the reading object
     */
    virtual Genres getGenre()=0;
    /*
     * PRE:
     * POST: Returns the type of the reading object
     */
    char getType() const;
    /*
     * PRE:
     * POST: Returns the minutes of the reading object
     */
    unsigned int getMinutes() const;
    /*
     * PRE:
     * POST: Returns the year of publishment of the reading object
     */
    unsigned int getPublishYear() const;
    /*
     * PRE:
     * POST: Returns the author of the reading object
     */
    Author *getAuthor();
    /*
     * PRE:
     * POST: Returns the isni of the reading object
     */
    int getIsni() const;

    /*
     * PRE:
     * POST: inicializa el isni
     */
    void setIsni(int isni);
    /*
     * PRE:
     * POST: Returns the title of the reading object
     */
    std::string getTitle();
    /*
     * PRE:
     * POST: If the reading is lower than the one passed as parameter ---> -1
     *       If the reading is greater than the one passed as parameter ---> 1
     *       If the reading is equal to the one passed as parameter ---> 0
     */
    int comparar(Reading *l) const;
    /* 
     * PRE:
     * POST: Sets an author to the reading object.
     */
    void setAuthor(Author *newAuthor);
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    virtual ~Reading() = default;
};

#endif
