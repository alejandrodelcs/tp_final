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
    * PRE: -
    * POST: Construye una nueva Lectura.
    */
    Reading(const std::string &title, unsigned int minutes, unsigned int PublishYear);

    /*
    * PRE: -
    * POST: metodo virtual que muestra los atributos de sus clases derivadas
    */
    virtual void display() = 0;

    virtual Genres getGenre()=0;

    /*
     * PRE:
     * POST: retorna el tipo de lectura
     */
    char getType() const;

    /*
     * PRE:
     * POST: retorna los minutos de Lectura
     */
    unsigned int getMinutes() const;

    /*
     * PRE:
     * POST: retorna el año de publicacion de la Lectura
     */
    unsigned int getPublishYear() const;

    /*
     * PRE:
     * POST: devuelve el Autor (escritor)
     */
    Author *getAuthors();

    /*
     * PRE:
     * POST: devuelve el número de referencia a la Lectura
     */
    int getIsni() const;

    /*
     * PRE:
     * POST: devuelve el título de la Lectura
     */
    std::string getTitle();

    /*
    * PRE: Recibe una lectura
    * POST: Si la lectura es menor a la que se pasa por parametro ---> -1
    *       Si la lectura es mayor a la que se pasa por parametro --->  1
    *       Si la lectura es igual a la que se pasa por parametro --->  0
    */
    int comparar(Reading *l) const;

    void setAuthor(Author *newAuthor);

    /* Destructor
     * PRE:
     * POST:
     */
    virtual ~Reading() = default;

};

#endif //TP_FINAL_READING_H
