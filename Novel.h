#ifndef TP_FINAL_NOVEL_H
#define TP_FINAL_NOVEL_H

#include "Constants.h"
#include "Reading.h"

class Novel : public Reading {
    protected:
    Genres genre;
    public:
    /* Constructor
     * PRE:
     * POST: Builds a new novel.
     */
    Novel(int id, std::string &title, unsigned int minutes, unsigned int PublishYear, Genres genre);
    /*
     * PRE:
     * POST: Displays the object's attributes in screen.
     */
    virtual void display();
    /*
     * PRE:
     * POST: Displays the novel's genre in screen.
     */
    void displayGenre();
    /*
     * PRE:
     * POST: Gets the novel's genre.
     */
    Genres getGenre();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~Novel() = default;
};

#endif
