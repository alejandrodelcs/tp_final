#ifndef TP_FINAL_HISTORICAL_H
#define TP_FINAL_HISTORICAL_H
#include "Novel.h"
class Historical : public Novel {
private:
    //Generos genero;

    char *theme;

public:
    /* Constructor
     * PRE:
     * POST: Builds a new historical novel
     */
    Historical(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre, char* &theme);
    /*
     * PRE:
     * POST: Displays the object's attributes in screen.
     */
    void display();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~Historical() override;

};
#endif //TP_FINAL_HISTORICAL_H
