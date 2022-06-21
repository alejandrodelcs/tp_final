#ifndef TP_2_POEMA_H
#define TP_2_POEMA_H
#include "Lectura.h"

class Poema : public Lectura {
private:
    unsigned int verses;
public:
    /*
     * PRE: -
     * POST: Construye un Poema
     */
    Poema(int id, std::string &title, unsigned int minutes, unsigned int yearPublication, unsigned int verses);

    /*
     * PRE: -
     * POST: Muestra sus atributos
     */
    void mostrar();

    /*
     * PRE: -
     * POST: Destruye el Poema
     */
    ~Poema() = default;
};

#endif //TP_2_POEMA_H
