#ifndef TP_FINAL_AUTHORS_FILE_PARSER_H
#define TP_FINAL_AUTHORS_FILE_PARSER_H
#include <iostream>
#include <string>
#include "Constants.h"
#include "File.h"
#include "Author.h"
#include "list.h"

class AuthorsFileParser {
private:
    File data;
    std::string fileLine;
    Author *author;
    List<Author*> *authores;
    int id;
    int birth;
    int death;
    std::string name;
    std::string nationality;


    /*
     * PRE:-
     * POST: retorna el ID (numero de referencia) de la linea del fichero
     */
    int getId();

    /*
      * PRE:-
      * POST: retorna el nombre de la linea del fichero
      */
    bool validateFileLine();

    /*
   * PRE:-
   * POST: Inicializa los datos traidos del archivos escritores
   */
    void validateAuthorFile(int count);

    /*
   * PRE:-
   * POST: Retorna el número al que se hará referencia en el archivo de lecturas
   */
    bool newReference();


    /*
     * PRE: -
     * POST: Valida el ultimo escritor del archivo
     */
    void validateEOFAuthor(int count);


    /*
     * PRE:  -
     * POST: Reserva espacio de memoria para un tipo de dato Escritor
     */
    void newAuthor();

    /*
     * PRE: -
     * POST: da de alta en la lista Escritores un nuevo escritor
     */
    void addAuthor();

    /*
   * PRE:-
   * POST:  Valida que los datos asociados a un escritor no pase el número de referencia,
    *       si es valido, crea un nuevo escritor y da de alta.
   */
    void validateNewAuthor();

public:

    /*
     * PRE:
     * POST: construye un nuevo parserEscritor
     */
    AuthorsFileParser();


    /*
     * PRE:
     * POST: crea la lista con los datos de los Escritoes(AutoreS)
     */
    void getAuthor(List<Author*> *e);


    /*
     * PRE: -
     * POST: Destruye la lista de Escritores
     */
    ~AuthorsFileParser();

};

#endif //TP_FINAL_AUTHORS_FILE_PARSER_H
