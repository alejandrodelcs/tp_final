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
     * PRE: The file's route should be set
     * POST: Builds a new File object
     */
    File();
    /*
     * PRE:
     * POST: Opens the file
     */
    void open(std::string name);
    /*
     * PRE:
     * POST: Returns the next line of the file
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
