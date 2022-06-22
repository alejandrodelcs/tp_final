#ifndef TP_2_CONSTANTS_H
#define TP_2_CONSTANTS_H

const int REFERENCE = 1;
const int EMPTY_LINE = 1;
const int DATO_DESCONOCIDO = -1;
const int GENRES_SIZE = 6;
const int ANIO_MINIMO = 900;
enum writer_data {ID,NOMBRE,NACIONALIDAD,ANIO_NACIMIENTO,ANIO_FALLECIMIENTO};
enum tipos_lectura {NOVEL='N',TALE='C',POEM='P'};
enum datos_lectura {TYPE,TITLE,MINUTES,PUBLISH_YEAR,READING_TYPES,ID_THEME,ID_HISTORIC};

#define WHITE "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"

#endif //TP_2_CONSTANTS_H
