#ifndef TP_2_TALE_H
#define TP_2_TALE_H
#include "Reading.h"

class Tale : public Reading {
private:
    std::string book;
public:
    /*
     * PRE: -
     * POST: Construye un Cuento
     */
    Tale(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, const std::string& book);

    /*
     * PRE: -
     * POST: Muestra sus atributos
     */
    void display();

    Genres getGenre();
    /*
     * PRE: -
     * POST: Destruye el Cuento
     */
    ~Tale()= default;;
};

#endif //TP_2_TALE_H