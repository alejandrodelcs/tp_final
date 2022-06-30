#ifndef TP_FINAL_AUTHORSFILEPARSER_H
#define TP_FINAL_AUTHORSFILEPARSER_H
#include <string>
#include "Constants.h"
#include "File.h"
#include "Author.h"
#include "List.h"
#include "Hash.h"
#include "Reading.h"
#include "Validations.h"

class AuthorsFileParser {

private:
    File file;
    std::string fileLine;
    HashTable<Author*>* authors;
    List<Reading*> *readings;
    Author* author;
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
     * PRE: -
     * POST: Retorna la tabla de hash con los autores
     */
    HashTable<Author *>* getAuthors();

    /*
     * PRE:
     * POST: Agrega el autor a su lectura
     */
    void addReadingAuthor();

    /*
     * PRE:
     * POST: Setea la lista lecturas en Readings File Parser
     */
    void setReadings(List<Reading*>* &l);

    /*
     * PRE:
     * POST: Setea la tabla de hash  en Readings File Parser
     */
    void setAuthors(HashTable<Author*>* &a);

    /*
     * PRE:
     * POST:
     */
    void displayAuthors();

    void requestAuthorsInfo();

    /*
     * PRE:
     * POST:
     */
    List<int>* displayNameAuthors();


    /* Destructor
     * PRE:
     * POST: Destruye la lista de Escritores
     */
    ~AuthorsFileParser();

};

#endif //TP_FINAL_AUTHORSFILEPARSER_H
