#ifndef TP_2_STORY_H
#define TP_2_STORY_H
#include "Reading.h"

class Story : public Reading {
private:
    std::string book;
public:
    /*
     * PRE: -
     * POST: Construye un Cuento
     */
    Story(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, const std::string& book);

    /*
     * PRE: -
     * POST: Muestra sus atributos
     */
    void display();

    /*
     * PRE: -
     * POST: Destruye el Cuento
     */
    ~Story()= default;;
};

#endif //TP_2_STORY_H