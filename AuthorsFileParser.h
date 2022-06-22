#ifndef TP_2_PARSERESCRITOR_H
#define TP_2_PARSERESCRITOR_H
#include <iostream>
#include <string>
#include "Constants.h"
#include "File.h"
#include "Author.h"
#include "List.h"


class ParserEscritor {
private:
    File datos;
    std::string lineaFichero;
    Author *escritor;
    List<Author*> *escritores;
    int id;
    int anioNacimiento;
    int anioFallecimiento;
    std::string nombre;
    std::string nacionalidad;


    /*
     * PRE:-
     * POST: retorna el ID (numero de referencia) de la linea del fichero
     */
    int devuelveId();

    /*
      * PRE:-
      * POST: retorna el nombre de la linea del fichero
      */
    bool validarLineaFichero();

    /*
   * PRE:-
   * POST: Inicializa los datos traidos del archivos escritores
   */
    void procesarLineaEscritor(int contador);

    /*
   * PRE:-
   * POST: Retorna el número al que se hará referencia en el archivo de lecturas
   */
    bool nuevaReferencia();


    /*
     * PRE: -
     * POST: Valida el ultimo escritor del archivo
     */
    void validaFinFicheroEscritor(int contador);


    /*
     * PRE:  -
     * POST: Reserva espacio de memoria para un tipo de dato Escritor
     */
    void nuevoEscritor();

    /*
     * PRE: -
     * POST: da de alta en la lista Escritores un nuevo escritor
     */
    void altaNuevoEscritor();

    /*
   * PRE:-
   * POST:  Valida que los datos asociados a un escritor no pase el número de referencia,
    *       si es valido, crea un nuevo escritor y da de alta.
   */
    void validaNuevoEscritor();

public:

    /*
     * PRE:
     * POST: construye un nuevo parserEscritor
     */
    ParserEscritor();


    /*
     * PRE:
     * POST: crea la lista con los datos de los Escritoes(AutoreS)
     */
    void obtenerDatosEscritor(List<Author*> *e);


    /*
     * PRE: -
     * POST: Destruye la lista de Escritores
     */
    ~ParserEscritor();

};

#endif //TP_2_PARSERESCRITOR_H
