#ifndef TP_2_CONSTANTES_H
#define TP_2_CONSTANTES_H

const int REFERENCE = 1;
const int LINEA_VACIA = 1;
const int DATO_DESCONOCIDO = -1;
const  int GENRES_SIZE = 6;
const int ANIO_MINIMO = 900;
enum datos_escritor {ID,NOMBRE,NACIONALIDAD,ANIO_NACIMIENTO,ANIO_FALLECIMIENTO};
enum tipos_lectura {NOVEL='N',TALE='C',POEM='P'};
enum datos_lectura {TYPE,TITLE,MINUTES,YEAR_PUBLICATION,READING_TYPES,ID_THEME,ID_HISTORIC};

#define BLANCO "\e[0m"
#define ROJO "\e[0;31m"
#define VERDE "\e[0;32m"
#define CIAN "\e[0;36m"



#endif //TP_2_CONSTANTES_H
