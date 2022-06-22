#ifndef TP_2_LECTURA_H
#define TP_2_LECTURA_H

#include <string>
#include <iostream>
#include "Escritor.h"
#include <list>
#include "ReadingsFileParser.h"

class Lectura {
protected:
    std::string title;
    unsigned int minutes;
    unsigned int PublishYear;
    Escritor *author; // Pasar esto a variable tipo puntero
    int id;
    char type;

public:
    /*
    * PRE: -
    * POST: Construye una nueva Lectura.
    */
    Lectura(const std::string &title, unsigned int minutes, unsigned int PublishYear);

    /*
    * PRE: -
    * POST: metodo virtual que muestra los atributos de sus clases derivadas
    */
    virtual void mostrar() = 0;

    /*
     * PRE:
     * POST: retorna el tipo de lectura
     */
    char getType() const;

    /*
     * PRE:
     * POST: retorna los minutos de Lectura
     */
    unsigned int getMinutes() const;

    /*
     * PRE:
     * POST: retorna el año de publicacion de la Lectura
     */
    unsigned int getPublishYear() const;

    /*
     * PRE:
     * POST: Setea un nuevoEscritor relacionado con la Lectura
     */
    void setAutor(Escritor *nuevoEscritor);

    /*
     * PRE:
     * POST: devuelve el Autor (escritor)
     */
    Escritor *getReader();

    /*
     * PRE:
     * POST: devuelve el número de referencia a la Lectura
     */
    int getID() const;

    /*
     * PRE:
     * POST: devuelve el título de la Lectura
     */
    std::string getTitle();

    /*
    * PRE: Recibe una lectura
    * POST: Si la lectura es menor a la que se pasa por parametro ---> -1
    *       Si la lectura es mayor a la que se pasa por parametro --->  1
    *      Si la lectura es igual a la que se pasa por parametro --->   0
    */
    int comparar(Lectura *l) const;

    /*
     *
     * Destructor virtural
     */
    virtual ~Lectura() = default;

};

#endif //TP_2_LECTURA_H
