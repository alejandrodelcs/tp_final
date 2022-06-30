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
     * PRE: 
     * POST: Retorna el genero de la Lectura
     */
    Genres validateGenre();

    /*
     * PRE: Recibe la cantidad de lineas leidas del archivo
     *      lecturas.txt hasta encontrar un parentesis '('
     * POST: Valida la linea del escritor
     */
    void validateReading(int count);

    /*
     * PRE: -
     * POST: Valida la existencia de una NUEVA
     *       referencia a la Lectura del archivo lecturas.txt
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
     * PRE: -
     * POST: Crea un nueva novela de genero Historica
     */
    Reading* buildNewHistoricalNovel();

    /*
     * PRE: -
     * POST: crea un nuevo tema para la lectura de genero Historica
     */
    void buildNewTheme();

    /*
     * PRE: -
     * POST: Reserva espacio en memoria para guardar el tema
     *      de la lectura de genero Historica
     */
    void reserveThemeMemory(char* &t);

    /*
     * PRE: -
     * POST: Retorna el numero de referencia de la lectura del archivo lecturas.txt
     */
    int getId() const;

    /*
     * PRE: -
     * POST: si comparar retorno 1 o 0 voy insertando en la ultima posicion de la lista
     */
    void validateYearMinor();

    /*
     * PRE: -
     * POST: Si comparar retorno -1, se valida en posiciones
     *       anteriores en la lista y se inserta.
     */
    void validateYearSorted();

    /*
     * PRE: -
     * POST: Crea la lista en orden descendente respecto al año de la publicacion
     */
    void sortReadingList();



public:

    /*
     * PRE: -
     * POST: Construye  un Parser
     */
    ReadingsFileParser();


    /*
     * PRE:
     * POST: crea la lista con los datos de las Lecturas
     */
    List<Reading*>* getReadings();

    /*
    * PRE: Recibe una lista vacia o llena
    * POST: Inicializa la lista
    */
    void setReadingList(List<Reading*>* &l);

    /*
     * PRE: -
     * POST: Busca el menor valor y lo ingresa
     */
    void addSortedReading(Reading* l);

    /*
     * PRE:
     * POST:
     */
    void displayReadings();

    /*
     * PRE: Recibe dos lecturas
     * POST: Retorna el costo de pasar de una lectura a otro considerando:
             * cuento - cuento 8
             * cuento - poema 0
             * cuento - novela 10
             * cuento - historica 15
             * poema - cuento 0
             *
             * poema - novela 5
             * poema - historica 20
             * novela - historica 60
             * poema - poema 1
             * novela - novela 30
             * historica - historica 80
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


    void _displayMst();

    /*
     * PRE:
     * POST: Destruye la lista de Lecturas
     */
    ~ReadingsFileParser();



};

#endif //TP_FINAL_READINGFILESPARSER_H
