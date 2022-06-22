#ifndef TP_2_FICHERO_H
#define TP_2_FICHERO_H

#include <fstream>
#include <string>

class File {
private:
    std::fstream file;
    std::string lines;

public:
    /*
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

    /*
     * PRE: -
     * POST: Cierra el archivo
     */
    ~File();
};

#endif //TP_2_FICHERO_H
