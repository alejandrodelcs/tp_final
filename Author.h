#ifndef TP_FINAL_AUTHOR_H
#define TP_FINAL_AUTHOR_H
#include <iostream>
#include <string>
#include "Constants.h"

class Author {
    
private:

    int isni;
    std::string name;
    std::string nationality;
    int birth;
    int death;

public:

    /* Constructor
    * PRE:
    * POST: Builds a new author.
    */
    Author(int isni, std::string name, std::string nationality, int yearBirth, int yearDeath);

    /*
     * PRE:
     * POST: Returns the author's ISNI.
     */
    int getISNI();

    /*
     * PRE:
     * POST: Returns the author's name.
     */
    std::string getName();

    /*
     * PRE:
     * POST: Returns the author's nationality.
     */
    std::string getNationality();

    /*
     * PRE:
     * POST: Returns the author's birth year.
     */
    int getBirth() const;

    /*
     * PRE:
     * POST: Returns the author's death year.
     */
    int getDeath() const;

    /*
     * PRE:
     * POST: Designates the author's death year.
     */
    void setDeath(int yearDeath);

    /*
     * PRE:
     * POST: Displays the object's attributes in screen.
     */
    void display();

};

#endif //TP_FINAL_AUTHOR_H
