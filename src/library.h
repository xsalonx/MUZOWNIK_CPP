#ifndef LIBS_PI_PROJECTSDL2_LIBRARY_H
#define LIBS_PI_PROJECTSDL2_LIBRARY_H



#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <SDL2/SDL.h>
#include <ctime>

#include "OPUS_EDIT_LOGIC/opus_edit_logic.h"
#include "ON_STAVE_PUTTING/putting.h"
#include "ON_STAVE_PUTTING/init_putting.h"

#include "OPUS_LOADSAVE/OPUS_loadsave.h"
#include "WINDOWS/windowsManager.h"

int pow_int(int a, int b);


void sdl_init();
void run();

void scroll_updown(SDL_Surface *screen, SDL_Surface *stave, SDL_Rect *current, SDL_Event *occurrence);
Opus *create_new_OPUS(char chosen_key[2], int chosen_metre[2], Opus *prev_opus);




#endif //LIBS_PI_PROJECTSDL2_LIBRARY_H
