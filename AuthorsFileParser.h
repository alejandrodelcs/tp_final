#ifndef TP_FINAL_AUTHORSFILEPARSER_H
#define TP_FINAL_AUTHORSFILEPARSER_H
#include <iostream>
#include <string>
#include "Constants.h"
#include "File.h"
#include "Author.h"
#include "List.h"

class AuthorsFileParser {

private:

    File file;
    std::string fileLine;
    List<Author*> *authors;
    int isni;
    int birth;
    int death;
    std::string name;
    std::string nationality;

    /*
     * PRE:
     * POST: retorna el ID (numero de referencia) de la linea del fichero
     */
    int getISNI();

    /*
     * PRE:
     * POST: retorna el nombre de la linea del fichero
     */
    bool validateFileLine();

    /*
     * PRE:
     * POST: Inicializa los datos traidos del archivos escritores
     */
    void validateAuthorFile(int count);

    /*
     * PRE:
     * POST: Retorna el número al que se hará referencia en el archivo de lecturas
     */
    bool newReference();

    /*
     * PRE:
     * POST: Valida el ultimo escritor del archivo
     */
    void validateEOFAuthor(int count);

    /*
     * PRE:-
     * POST: Adds the new author to the main list of authors.
     */
    void addNewAuthor();

public:

    /* Constructor
     * PRE:
     * POST: construye un nuevo parserEscritor
     */
    AuthorsFileParser();

    /*
     * PRE:
     * POST: crea la lista con los datos de los Escritoes(AutoreS)
     */
    void getAuthor(List<Author*> *e);

    /* Destructor
     * PRE:
     * POST: Destruye la lista de Escritores
     */
    ~AuthorsFileParser();

};

#endif //TP_FINALAUTHORSFILEPARSER_H
