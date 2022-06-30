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
     * POST: metodo virtual que muestra los atributos de sus clases derivadas
     */
    virtual void display() = 0;
    /*
     * PRE:
     * POST: Get the genre of the reading object
     */
    virtual Genres getGenre()=0;
    /*
     * PRE:
     * POST: Get the type of the reading object
     */
    char getType() const;
    /*
     * PRE:
     * POST: Get the minutes of the reading object
     */
    unsigned int getMinutes() const;
    /*
     * PRE:
     * POST: Get the year of publishment of the reading object
     */
    unsigned int getPublishYear() const;
    /*
     * PRE:
     * POST: Get the author of the reading object
     */
    Author *getAuthor();
    /*
     * PRE:
     * POST: Get the isni of the reading object
     */
    int getIsni() const;
    /*
     * PRE:
     * POST: Get the title of the reading object
     */
    std::string getTitle();
    /*
     * PRE: Recibe una lectura
     * POST: Si la lectura es menor a la que se pasa por parametro ---> -1
     *       Si la lectura es mayor a la que se pasa por parametro --->  1
     *       Si la lectura es igual a la que se pasa por parametro --->  0
     */
    int comparar(Reading *l) const;
    /* 
     * PRE:
     * POST: Sets an author to the reading object.
     */
    void setAuthor(Author *newAuthor);
    /* Destructor
     * PRE:
     * POST:
     */
    virtual ~Reading() = default;
};

#endif
