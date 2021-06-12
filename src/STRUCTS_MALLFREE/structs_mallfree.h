#ifndef PI_PROJECTSDL2_PART_LIB_STRUCTS_MALLFREE_H
#define PI_PROJECTSDL2_PART_LIB_STRUCTS_MALLFREE_H

#include <stdlib.h>
#include <stdio.h>
#include "../structs.h"
#include "../geometry_def_codes.h"


CHORD *malloc_new_chord(CHORD *prev, CHORD *next, int X_position, const char *serial_key);
BAR *malloc_new_bar(BAR *prev, BAR *next, int X_of_start_bar, int width, int brace, const char *treb_serial_key, const char *bass_serial_key);
int free_bar(BAR *bar_to_del);
int free_opus(OPUS *opus_to_del);


#endif //PI_PROJECTSDL2_PART_LIB_STRUCTS_MALLFREE_H
