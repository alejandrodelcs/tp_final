#ifndef TP_2_CUENTO_H
#define TP_2_CUENTO_H
#include "Reading.h"

class Cuento : public Reading {
private:
    std::string book;
public:
    /*
     * PRE: -
     * POST: Construye un Cuento
     */
    Cuento(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, const std::string& book);

    /*
     * PRE: -
     * POST: Muestra sus atributos
     */
    void mostrar();

    /*
     * PRE: -
     * POST: Destruye el Cuento
     */
    ~Cuento()= default;;
};

#endif //TP_2_CUENTO_H