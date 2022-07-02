#ifndef TP_FINAL_READINGFILESPARSER_H
#define TP_FINAL_READINGFILESPARSER_H

#include <iostream>
#include <string>
#include "AuthorsFileParser.h"
#include "Graph.h"
#include "Constants.h"
#include "File.h"
#include "Reading.h"
#include "Tale.h"
#include "Novel.h"
#include "Historical.h"
#include "Poem.h"
#include "List.h"
#include "Mst.h"
#include "Validation.h"

class ReadingsFileParser {

private:
    File file;
    std::string fileLine;
    char type;
    std::string title;
    std::string book;
    Genres genre;
    char *theme;
    int id;
    unsigned int minutes;
    unsigned int publishYear;
    int verses;
    unsigned int totalMinDistance;
    unsigned int totalReading;;
    AuthorsFileParser pAuthors;
    HashTable<Author*>* authors;
    List<int>* insis;
    Validation validation;
    Reading *reading;
    List<Reading *> *readings;
    Graph<int> *graph;

    /*
     * PRE: fileLine should point to a line (of the file "lecturas.txt") with a valid reading genre
     * POST: Gets the genre (as a Genres object) of the current fileLine 
     */
    Genres validateGenre();

    /*
     * PRE: The file "lecturas.txt" should be processed allong, going through its lines.
     * POST: Validates fileLine (the current line of the file "lecturas.txt")
     */
    void validateReading(int count);

    /*
     * PRE: -
     * POST: Validates the existence of a new reference to the file "lecturas.txt"
     */
    bool newReference() const;

    /*
     * PRE:
     * POST: valida el tipo de Lectura del archivo lecturas.txt
     */
    void validateTypeReading();

    /*
     * PRE: -
     * POST: valida el numero de Referencia de la lectura
     *        respecto al tipo, si es la lectura es
     *        NOVELA guarda el tema.
     */
    void validateReference();

    /*
     * PRE: Recibe la cantidad de lineas leidas en el archivo
     *      hasta un '('
     * POST: Si contador = 6 entonces la novela es Historica
     *       y guarda el numero de referencia a la Lectura
     */
    void validateHistoricalReference();

    /*
     * PRE: Recibe la cantidad de lineas leidas en el archivo
     *      hasta un '('
     * POST: Si contador = 5 entonces estamos ante los
     *      demas generos de la Lectura y retorna True
     *      caso contrario False
     */
    bool validateNewReading(int count) const;

    /*
     * PRE: Recibe la cantidad de lineas leidas en el archivo
     *      hasta un '('
     * POST: Si contador = 6 y ademas el genero de la lectua es "HISTORICA" entonces
     *     la novela es Historica y retorna True, caso contrario False
     */
    bool validateHistoricalNovel(int contador) const;

    /*
     * PRE: Recibe la cantidad de lineas leidas en el archivo
     *      hasta un '('
     * POST: Una vez validado el metodo validaNuevaLectura,ValidaNovelaHistorica
     *      y devuelto True, valida el tipo de Lectura  crea una.
     */
    Reading *buildNewReading(int contador);

    /*
     * PRE: -
     * POST: Builds a new tale
     */
    Reading *buildNewTale();

    /*
     * PRE: -
     * POST: Builds a new poem
     */
    Reading *buildNewPoem();

    /*
     * PRE: -
     * POST: Builds a new novel
     */
    Reading *buildNewNovel();

    /*
     * PRE:
     * POST: Creates a new historical reading.
     */
    Reading *buildNewHistoricalNovel();

    /*
     * PRE: The current reading's genre should be historical
     * POST: Creates a new theme for the current reading.
     */
    void buildNewTheme();

    /*
     * PRE: The new reading's genre should be historical.
     * POST: Reserves memory space to store the theme of the new reading.
     */
    char *reserveThemeMemory(long unsigned int size);

    /*
     * PRE:
     * POST: Returns the reference number of the reading from the file lecturas.txt.
     */
    int getId() const;

    /*
     * PRE: 
     * POST: If the comparation returned -1, it will insert the object at the end of the list
     */
    void validateYearMinor();

    /*
     * PRE:
     * POST: If the comparation returned -1, it will validate the object through the previous positions in the list and insert it.
     */
    void validateYearSorted();

    /*
     * PRE:
     * POST: Creates the reading list in a descending order according to their published year.
     */
    void sortReadingList();

    /*
     * PRE:
     * POST: initializes the novel entered by the user
     */
    void setNewNovel();

    /*
     * PRE:
     * POST:  initializes the new tale entered by the user
     */
    void setNewTale();

    /*
     * PRE:
     * POST:initializes the new Poem entered by the user
     */
    void setNewPoem();

    /*
    * PRE:
    * POST: initializes the new title entered by the user
    */
    void setNewTitle();

    /*
    * PRE:
    * POST: initializes the new Genre entered by the user
    */
    void setNewGenres();

    /*
    * PRE:
    * POST: initializes the new theme entered by the user
    */
    void setNewTheme();

    /*
    * PRE:
    * POST: add the author with his reading
    */
    void setAuthorInReading();

    /*
    * PRE:
    * POST:  choose the type of reading
    */
    void setInputNewReading(int option);

    /*
    * PRE:-
    * POST: -
    */
    void displayTotalReading() const;


public:
    /*
     * PRE:
     * POST: Builds a new parser.
     */
    ReadingsFileParser();

    /*
     * PRE:
     * POST: Creates the list with the data of the readings.
     */
    List<Reading *> *getReadings();

    /*
    * PRE: List sent as parameter can be either empty or full.
    * POST: Initilizes the reading list
    */
    void setReadingList(List<Reading *> *&l);


    /*
     * PRE:
     * POST:-
     */
    void displayReadings();

    /*
     * PRE:
     * POST: Returns the cost of passing from the first Reading object to the second Reading object accordingly:
     *       cuento - cuento 8
     *       cuento - poema 0
     *       cuento - novela 10
     *       cuento - historica 15
     *       poema - cuento 0
     *
     *       poema - novela 5
     *       poema - historica 20
     *       novela - historica 60
     *       poema - poema 1
     *       novela - novela 30
     *       historica - historica 80
     */
    int getCost(Reading *initialReading, Reading *endingReading);

    /*
     * PRE:
     * POST:
     */
    int validateType(Reading *reading);

    /*
     * PRE
     * POST: add vertexes in graph
     */
    void setGraphVertex();

    /*
     * PRE
     * POST: add new Vertex in graph
     */
    void setGraphNewVertex();

    /*
     * PRE:
     * POST: get the Graph
     */
    Graph<int> *getGraph();

    /*
     * PRE:
     * POST: set the Graph
     */
    void setGraph(Graph<int> *&graph);

    /*
     * PRE:
     * POST: add Edges in the graph
     */
    void addGraphEdges();

    /*
     * PRE:
     * POST:
     */
    void displayMst(int option);

    /*
     * PRE:
     * POST: request reading for user
     */
    void requestReadingsInfo(int option);


    /*
     * PRE:
     * POST: set author in hash table
     */
    void setAuthors(HashTable<Author *>* &a);


    /*
     * PRE:
     * POST:
     */
    void displayMst();

    /*
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~ReadingsFileParser();
};

#endif
