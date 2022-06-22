#ifndef TP_2_HISTORICA_H
#define TP_2_HISTORICA_H
#include "Novela.h"
class Historica : public Novela {
private:
    //Generos genero;

    char *theme;

public:
    /*
     * PRE: -
     * POST: Construye una Novela Historica
     */
    Historica(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre, char* &theme);

    /*
    * PRE: -
    * POST: Muestra sus atributos
    */
    void mostrar();

    /*
    * PRE: -
    * POST: Destruye la Novela Historica
    */
    ~Historica();

};
#endif //TP_2_HISTORICA_H
