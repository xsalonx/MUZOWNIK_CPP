//
// Created by Luksz on 2021-06-11.
//

#ifndef PI_PROJECTSDL2_PART_LIB_OPUS_EDITING_UTILS_H
#define PI_PROJECTSDL2_PART_LIB_OPUS_EDITING_UTILS_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <SDL2/SDL.h>
#include <ctime>
#include "../geometry_defCodes.h"
#include "../STRUCTS/Opus.h"

void swap_notes(Note *n1, Note *n2);
int get_note_index(Note *n);
int compare_notes(Note *n1, Note *n2);
int sort_uniq_notes(Chord *chord_to_sort);
int get_serial_key(const char *chosen_key, char serial_key[7]);
int is_acci_req(Chord *chord_to_put, int k, const char *defauly_serial_key);
int get_space_for_chord(Bar *bar, BarsSpace *b_space, const int *metre);


#endif //PI_PROJECTSDL2_PART_LIB_OPUS_EDITING_UTILS_H
