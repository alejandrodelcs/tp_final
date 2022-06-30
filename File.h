#ifndef TP_FINAL_FILE_H
#define TP_FINAL_FILE_H

#include <fstream>
#include <string>

class File {
    private:
    std::fstream file;
    std::string lines;
    public:
    /* Constructor
     * PRE: Recibe la ruta donde se ubica el archivo
     * POST: Construye un fichero
     */
    File();
    /*
     * PRE: -
     * POST: Abre el fichero
     */
    void open(std::string name);
    /*
     * PRE: -
     * POST: retorna linea del fichero
     */
    std::string read();
    /*
     * PRE: -
     * POST: Valida si llego al final del fichero
     */
    bool eof();
    /* Destructor
     * PRE:
     * POST: Closes the file opened.
     */
    ~File();
};

#endif
