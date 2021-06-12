//
// Created by Luksz on 2021-06-12.
//

#ifndef PI_PROJECTSDL2_PART_LIB_PUTTING_H
#define PI_PROJECTSDL2_PART_LIB_PUTTING_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "../structs.h"
#include "../geometry_def_codes.h"
#include "../OPUS_EDIT_LOGIC/opus_editing_utils.h"


int put_chord_on_treb_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int brace, const char serial_key[7], BARS_SPACE *b_space, struct current_OPUS_edits_ *COE);
int put_chord_on_bass_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int brace, const char serial_key[7], BARS_SPACE *b_space, struct current_OPUS_edits_ *COE);
int put_pause_on_stave_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int brace, int hand, BARS_SPACE *b_space, struct current_OPUS_edits_ *COE);
int put_chord_on_stave_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int hand, int brace, const char *serial_key, BARS_SPACE *b_space, struct current_OPUS_edits_ *COE);
int put_bar_on_stave(BAR *bar_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int hand, int brace, const char serial_key[7], const int chosen_metre[2], struct current_OPUS_edits_ *COE);
int put_all_bars_on_stave(BAR *first_bar_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, const char serial_key[7], const int chosen_metre[2], struct current_OPUS_edits_ *COE);


#endif //PI_PROJECTSDL2_PART_LIB_PUTTING_H
