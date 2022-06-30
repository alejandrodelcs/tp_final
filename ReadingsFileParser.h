#ifndef TP_FINAL_READINGFILESPARSER_H
#define TP_FINAL_READINGFILESPARSER_H
#include <iostream>
#include <string>
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

class ReadingsFileParser {
    private:
    File file;
    std::string fileLine;
    char type;
    std::string title;
    std::string book;
    Genres genre;
    char* theme;
    int id;
    unsigned int minutes;
    unsigned int publishYear;
    int verses;
    Reading *reading;
    List<Reading*> *readings;
    Graph<int>* graph;
    /*
     * PRE: fileLine should point to a line (of the file "lecturas.txt") with a valid reading genre
     * POST: Get the genre (as a Genres object) of the current fileLine 
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
    Reading* buildNewReading(int contador);
    /*
     * PRE: -
     * POST: Builds a new tale
     */
    Reading* buildNewTale();
    /*
     * PRE: -
     * POST: Builds a new poem
     */
    Reading* buildNewPoem();
    /*
     * PRE: -
     * POST: Builds a new novel
     */
    Reading* buildNewNovel();
    /*
     * PRE:
     * POST: Creates a new historical reading.
     */
    Reading* buildNewHistoricalNovel();
    /*
     * PRE: The current reading's genre should be historical
     * POST: Creates a new theme for the current reading.
     */
    void buildNewTheme();
    /*
     * PRE: The new reading's genre should be historical.
     * POST: Reserves memory space to store the theme of the new reading.
     */
    void reserveThemeMemory(char* &t);
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
    List<Reading*>* getReadings();
    /*
    * PRE: List sent as parameter can be either empty or full.
    * POST: Initilizes the reading list
    */
    void setReadingList(List<Reading*>* &l);
    /*
     * PRE:
     * POST: Seeks the lowest values and inputs it.
     */
    void addSortedReading(Reading* l);
    /*
     * PRE:
     * POST:
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
    int getCost(Reading* initialReading, Reading* endingReading);
    /*
     * PRE:
     * POST:
     */
    int validateType(Reading* reading);
    /*
     * PRE
     * POST:
     */
    void setGraphVertex();
    /*
     * PRE:
     * POST:
     */
    Graph<int>* getGraph();
    /*
     * PRE:
     * POST:
     */
    void setGraph(Graph<int>* &graph);
    /*
     * PRE:
     * POST:
     */
    void addGraphEdges();
    /*
     * PRE:
     * POST:
     */
    void displayMst();
    /*
     * PRE:
     * POST:
     */
    void _displayMst();
    /*
     * PRE:
     * POST: Dealocates the memory used
     */
    ~ReadingsFileParser();
};

#endif
