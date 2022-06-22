#include "AuthorsFileParser.h"

ParserEscritor::ParserEscritor() {
    datos.open("escritores.txt");
    this->escritor = nullptr;
}

void ParserEscritor::obtenerDatosEscritor(List<Author*> *e) {
    int contador = 0;
    this->escritores = e;
    while (!datos.endOfFile()) {
        lineaFichero = datos.read();
        if (nuevaReferencia())
            contador = 0;
        procesarLineaEscritor(contador);
        if (contador == 4) {
            validaNuevoEscritor();
        }
        validaFinFicheroEscritor(contador);
        contador++;
    }
}

void ParserEscritor::validaNuevoEscritor() {
    nuevoEscritor();
    altaNuevoEscritor();
}


void ParserEscritor::validaFinFicheroEscritor(int contador) {
    if (datos.endOfFile() && contador<4) {
        contador += 1;
        lineaFichero = " ";
        while (contador <= 4) {
            procesarLineaEscritor(contador);
            contador += 1;
        }
        validaNuevoEscritor();
    }
}

void ParserEscritor::procesarLineaEscritor(int contador) {
    switch (contador) {
        case ID:
            id = devuelveId();
            break;
        case NOMBRE:
            nombre = validarLineaFichero() ? " " : lineaFichero;
            break;
        case NACIONALIDAD:
            nacionalidad = validarLineaFichero() ? " " : lineaFichero;
            break;
        case ANIO_NACIMIENTO:
            anioNacimiento = validarLineaFichero() ? DATO_DESCONOCIDO : std::stoi(lineaFichero);
            break;
        case ANIO_FALLECIMIENTO:
            anioFallecimiento = validarLineaFichero() ? DATO_DESCONOCIDO : std::stoi(lineaFichero);
            break;
        default:
            std::cout<<std::endl;
            break;
    }
}

void ParserEscritor::altaNuevoEscritor() {
    escritores->alta(this->escritor);
}

void ParserEscritor::nuevoEscritor() {
    escritor = new Author(this->id, this->nombre, this->nacionalidad,
                            this->anioNacimiento, this->anioFallecimiento);
}


bool ParserEscritor::nuevaReferencia() {
    return (this->lineaFichero[0] == '(');
}

int ParserEscritor::devuelveId() {
    return std::stoi(this->lineaFichero.substr(REFERENCIA, lineaFichero.find(')')));
}

bool ParserEscritor::validarLineaFichero() {
    return (this->lineaFichero.length() <= LINEA_VACIA);
}

ParserEscritor::~ParserEscritor() {
    escritores->iniciarCursor();
    while (escritores->avanzarCursor())
        delete escritores->obtenerCursor();
    delete escritores;
    escritores = nullptr;
}