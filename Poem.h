#ifndef TP_FINAL_POEM_H
#define TP_FINAL_POEM_H
#include "Reading.h"

class Poem : public Reading {
private:
    unsigned int verses;
public:
    /*
     * PRE: -
     * POST: Construye un Poema
     */
    Poem(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, unsigned int verses);

    /*
     * PRE: -
     * POST: Muestra sus atributos
     */
    void display();

    /*
     * PRE: -
     * POST: Destruye el Poema
     */
    ~Poem() = default;
};

#endif //TP_FINAL_POEM_H
