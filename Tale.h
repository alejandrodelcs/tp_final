#ifndef TP_2_TALE_H
#define TP_2_TALE_H
#include "Reading.h"

class Tale : public Reading {
    private:
    std::string book;
    public:
    /* Constructor
     * PRE:
     * POST: Builds a new Tale object
     */
    Tale(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, const std::string& book);
    /*
     * PRE:
     * POST: Displays the object's attributes in screen.
     */
    void display();
    /* 
     * PRE:
     * POST: Gets the genre of the Tale object
     */
    Genres getGenre();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~Tale() = default;;
};

#endif