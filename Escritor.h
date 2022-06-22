#ifndef TP_2_AUTHOR_H
#define TP_2_AUTHOR_H
#include <iostream>
#include <string>

class Author{
private:
    int id;
    std::string name;
    std::string nacionality;
    int yearBirth;
    int yearDeath;
public:
    /* Constructor
    * PRE: -
    * POST: Builds a new Author.
    */
    Author(int id, std::string name, std::string nacionality, int yearBirth, int yearDeath);

    /*
     * PRE:
     * POST: Retorna el ID o número de referencia del Escrtor (Autor)
     */
    int getId();

    /*
     * PRE:
     * POST: Retorna el nombre del Escrtor (Autor)
     */
    std::string getName();

    /*
     * PRE:
     * POST: Retorna la nacionalidad del Escrtor (Autor)
     */
    std::string getNationality();

    /*
     * PRE:
     * POST: Retorna la fecha de nacimiento del Escrtor (Autor)
     */
    int devolverBirth() const;

    /*
     * PRE:
     * POST: Retorna la fecha de fallecimiento del Escrtor (Autor)
     */
    int devolverDeath() const;

    /*
     * PRE:
     * POST: Setea (Asigna) la fecha del fallecimiento del Escrtor (Autor)
     */
    void setYearDeath(int yearDeath);

    /*
     * PRE:
     * POST: Muestra los atributos del Escrtor (Autor)
     */
    void display();

};

#endif //TP_2_AUTHOR_H
