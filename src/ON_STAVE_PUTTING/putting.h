//
// Created by Luksz on 2021-06-12.
//

#ifndef PI_PROJECTSDL2_PART_LIB_PUTTING_H
#define PI_PROJECTSDL2_PART_LIB_PUTTING_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <SDL2/SDL.h>
#include "../structs.h"
#include "../geometry_def_codes.h"
#include "../OPUS_EDIT_LOGIC/opus_editing_utils.h"
#include "init_putting.h"

int put_chord_on_treb_without_beam(Chord *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int brace, const char serial_key[7], BarsSpace *b_space, struct CurrentOpusEdits *COE);
int put_chord_on_bass_without_beam(Chord *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int brace, const char serial_key[7], BarsSpace *b_space, struct CurrentOpusEdits *COE);
int put_pause_on_stave_without_beam(Chord *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int brace, int hand, BarsSpace *b_space, struct CurrentOpusEdits *COE);
int put_chord_on_stave_without_beam(Chord *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start, int hand, int brace, const char *serial_key, BarsSpace *b_space, struct CurrentOpusEdits *COE);
int put_bar_on_stave(Bar *bar_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int hand, int brace, const char serial_key[7], const int chosen_metre[2], struct CurrentOpusEdits *COE);
int put_all_bars_on_stave(Bar *first_bar_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, const char serial_key[7], const int chosen_metre[2], struct CurrentOpusEdits *COE);


#endif //PI_PROJECTSDL2_PART_LIB_PUTTING_H
