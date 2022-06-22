#ifndef TP_2_NOVELA_H
#define TP_2_NOVELA_H
#include "Reading.h"

enum class Genres {DRAMA=1,COMEDIA,FICCION,SUSPENSO,TERROR,ROMANTICA,HISTORICA,INEXISTENTE};

class Novela : public Reading {
protected:
    Genres genre;
public:
    /*
    * PRE: -
    * POST: Construye una Novela Historica
    */
    Novela(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre);

    /*
   * PRE: -
   * POST: Muestra sus atributos
   */
    void mostrar();

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
    ~Novela() = default;;
};

#endif //TP_2_NOVELA_H
