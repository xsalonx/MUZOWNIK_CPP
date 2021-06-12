//
// Created by Luksz on 2021-06-12.
//

#ifndef PI_PROJECTSDL2_PART_LIB_WINDOWS_H
#define PI_PROJECTSDL2_PART_LIB_WINDOWS_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "../geometry_def_codes.h"

int help_window(SDL_Surface *screen, SDL_Window *window);
int menu_open(char chosen_key[2], int chosen_metre[2]);
int fifths_choosing(SDL_Surface *screen, SDL_Window *window, char chosen_key[2]);
int menu_window(SDL_Surface *screen, SDL_Window *window);
int metre_choosing(SDL_Surface *screen, SDL_Window *window, int chosen_metre[2]);


#endif //PI_PROJECTSDL2_PART_LIB_WINDOWS_H


