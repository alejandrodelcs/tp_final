#ifndef TP_2_CONSTANTS_H
#define TP_2_CONSTANTS_H

const int REFERENCE = 1;
const int EMPTY_LINE = 1;
const int UNKNOWN_DATA = -1;
const int GENRES_SIZE = 6;
const int MINIMUM_YEAR = 900;

enum MENU {ONE = 1, TWO, THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN};
enum writerData {ISNI_ID,NAME_ID,NATIONALITY_ID,BIRTH_ID,DEATH_ID};
enum readingTypes {NOVEL='N',TALE='C',POEM='P'};
enum readingData {TYPE,TITLE,MINUTES,PUBLISH_YEAR,READING_TYPES,ID_THEME,ID_HISTORIC};
enum optionsReadingTypes{O_NOVEL=1,O_TALE,O_POEM};

#define WHITE "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define MAGENTA "\x1B[35m"

#endif
