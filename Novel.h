#ifndef TP_FINAL_NOVEL_H
#define TP_FINAL_NOVEL_H
#include "Constants.h"
#include "Reading.h"

class Novel : public Reading {
    protected:
    Genres genre;
    public:
    /* Constructor
     * PRE:
     * POST: Construye una Novela Historica
     */
    Novel(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre);
    /*
     * PRE:
     * POST: Muestra sus atributos
     */
    virtual void display();
    /*
     * PRE:
     * POST: Muestra el genero de la novela
     */
    void displayGenre();
    /*
     * PRE:
     * POST: Devuelve el Genero
     */
    Genres getGenre();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~Novel() = default;;
};

#endif
