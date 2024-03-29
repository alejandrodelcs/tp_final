#ifndef TP_FINAL_POEM_H
#define TP_FINAL_POEM_H

#include "Reading.h"

class Poem : public Reading {

private:
    unsigned int verses;
public:
    /* Constructor
     * PRE:
     * POST: Builds a new poem.
     */
    Poem(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, unsigned int verses);
    /*
     * PRE:
     * POST: Displays the object's attributes in screen.
     */
    void display();
    /*
     * PRE:
     * POST: Returns the Poem's genre.
     */
    Genres getGenre();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~Poem() = default;
};

#endif
