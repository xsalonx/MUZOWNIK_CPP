#ifndef MUZOWNIK_NOTE_H
#define MUZOWNIK_NOTE_H


#include "../geometry_defCodes.h"
#include <utility>


#define NUMBER_OF_LINES 5
#define NUMBER_OF_HANDS 2
#define NUMBER_OF_BRACES 5
#define MAX_NOTES_IN_CHORD 7

class Note{
public:
    char name;
    char acci;
    int height;
    int may_print_acci;
};


#endif //MUZOWNIK_NOTE_H
