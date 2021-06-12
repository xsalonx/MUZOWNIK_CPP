//
// Created by Luksz on 2021-06-11.
//

#ifndef PI_PROJECTSDL2_PART_LIB_OPUS_EDITING_UTILS_H
#define PI_PROJECTSDL2_PART_LIB_OPUS_EDITING_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <time.h>
#include "../geometry_def_codes.h"
#include "../structs.h"
#include "../STRUCTS_MALLFREE/structs_mallfree.h"

void swap_notes(NOTE *n1, NOTE *n2);
int get_note_index(NOTE *n);
int compare_notes(NOTE *n1, NOTE *n2);
int sort_uniq_notes(CHORD *chord_to_sort);
int get_serial_key(const char *chosen_key, char serial_key[7]);
int is_acci_req(CHORD *chord_to_put, int k, const char *defauly_serial_key);
int get_space_for_chord(BAR *bar, BARS_SPACE *b_space, const int *metre);


#endif //PI_PROJECTSDL2_PART_LIB_OPUS_EDITING_UTILS_H
