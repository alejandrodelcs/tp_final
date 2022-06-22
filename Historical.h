#ifndef TP_2_HISTORICAL_H
#define TP_2_HISTORICAL_H
#include "Novel.h"
class Historical : public Novel {
private:
    //Generos genero;

    char *theme;

public:
    /*
     * PRE: -
     * POST: Construye una Novela Historica
     */
    Historical(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre, char* &theme);

    /*
    * PRE: -
    * POST: Muestra sus atributos
    */
    void display();

    /*
    * PRE: -
    * POST: Destruye la Novela Historica
    */
    ~Historical();

};
#endif //TP_2_HISTORICAL_H
