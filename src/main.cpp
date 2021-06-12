#include "library.h"
//author: Lukasz Dubiel
#define SDL_main main



int main(int argc, char *argv[]) {

    sdl_init();
    run();
    SDL_Quit();

    return 0;
}
