#ifndef PI_PROJECTSDL2_PART_LIB_INIT_PUTTING_H
#define PI_PROJECTSDL2_PART_LIB_INIT_PUTTING_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "../structs.h"
#include "../geometry_def_codes.h"

int get_path_to_key_bmp(const char chosen_key[2], char path_to_key_bmp[], int hand, int path_prefix_len);
int get_path_to_metre_bmp(const int chosen_metre[2], char path_to_metre_bmp[], int path_prefix_len);

int put_key(SDL_Surface *stave, const char chosen_key[2], OPUS *current_OPUS, int *X_star_on_lines);
int put_metre(SDL_Surface *stave, const int chosen_metre[2], OPUS *current_OPUS, int *X_start_on_line, int brace);


#endif //PI_PROJECTSDL2_PART_LIB_INIT_PUTTING_H
