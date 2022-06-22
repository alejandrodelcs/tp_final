#ifndef TP_FINAL_NOVEL_H
#define TP_FINAL_NOVEL_H
#include "Reading.h"

enum class Genres {DRAMA=1,COMEDY,FICTION,THRILLER,HORROR,ROMANCE,HISTORICAL,MISSING};

class Novel : public Reading {
protected:
    Genres genre;
public:
    /*
    * PRE: -
    * POST: Construye una Novela Historica
    */
    Novel(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre);

    virtual /*
   * PRE: -
   * POST: Muestra sus atributos
   */
    void display();

    /*
     * PRE: -
     * POST: Muestra el genero de la novela
     */
    void displayGenre();

    /*
     * PRE: -
     * POST: Devuelve el Genero
     */
    Genres getGenre();

    /*
     * PRE: -
     * POST: Destruye la Novela
     */
    ~Novel() = default;;
};

#endif //TP_FINAL_NOVEL_H
