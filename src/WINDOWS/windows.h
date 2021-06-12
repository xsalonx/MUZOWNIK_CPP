//
// Created by Luksz on 2021-06-12.
//

#ifndef PI_PROJECTSDL2_PART_LIB_WINDOWS_H
#define PI_PROJECTSDL2_PART_LIB_WINDOWS_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <SDL2/SDL.h>
#include "../geometry_def_codes.h"



class WindowsManager {
private:
    SDL_Surface *screen{};
    SDL_Window *window{};
    char chosen_key[2]{};
    int chosen_metre[2]{};
    int opt{};

    SDL_Surface *title{};
    SDL_Surface *creating_option{};
    SDL_Surface *loading_option{};
    SDL_Surface *exit_option{};
    SDL_Surface *creating_option_highlight{};
    SDL_Surface *loading_option_highlight{};
    SDL_Surface *exit_option_highlight{};
    SDL_Surface *menu_background{};
    SDL_Surface *help_option{};
    SDL_Surface *help_highlight_option{};

public:
    WindowsManager() {
       init_menu_images();
    }
    void init_menu_images() {
        window = SDL_CreateWindow("MUZOWNIK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MENU_SCREEN_WIDTH,
                                  SCREEN_HIGHT, SDL_WINDOW_SHOWN);
        screen = SDL_GetWindowSurface(window);

        menu_background = SDL_LoadBMP("obrazki/menu/menu_background.bmp");


        creating_option = SDL_LoadBMP("obrazki/menu/option_new.bmp");
        creating_option_highlight = SDL_LoadBMP("obrazki/menu/option_new_highlight.bmp");

        loading_option = SDL_LoadBMP("obrazki/menu/option_open.bmp");
        loading_option_highlight = SDL_LoadBMP("obrazki/menu/option_open_highlight.bmp");

        exit_option = SDL_LoadBMP("obrazki/menu/option_exit.bmp");
        exit_option_highlight = SDL_LoadBMP("obrazki/menu/option_exit_highlight.bmp");

        title = SDL_LoadBMP("obrazki/menu/title.bmp");

        help_option = SDL_LoadBMP("obrazki/menu/option_help.bmp");
        help_highlight_option = SDL_LoadBMP("obrazki/menu/option_help_highlight.bmp");

        SDL_SetColorKey(creating_option_highlight, SDL_TRUE, SDL_MapRGB(creating_option_highlight->format, 255, 255, 255));
        SDL_SetColorKey(creating_option, SDL_TRUE, SDL_MapRGB(creating_option->format, 255, 255, 255));

        SDL_SetColorKey(loading_option_highlight, SDL_TRUE, SDL_MapRGB(loading_option_highlight->format, 255, 255, 255));
        SDL_SetColorKey(loading_option, SDL_TRUE, SDL_MapRGB(loading_option->format, 255, 255, 255));

        SDL_SetColorKey(exit_option_highlight, SDL_TRUE, SDL_MapRGB(exit_option_highlight->format, 255, 255, 255));
        SDL_SetColorKey(exit_option, SDL_TRUE, SDL_MapRGB(exit_option->format, 255, 255, 255));

        SDL_SetColorKey(title, SDL_TRUE, SDL_MapRGB(title->format, 255, 255, 255));

        SDL_SetColorKey(help_option, SDL_TRUE, SDL_MapRGB(help_option->format, 255, 255, 255));
        SDL_SetColorKey(help_highlight_option, SDL_TRUE, SDL_MapRGB(help_highlight_option->format, 255, 255, 255));

    }

    ~WindowsManager() {
        SDL_FreeSurface(menu_background);
        SDL_FreeSurface(title);
        SDL_FreeSurface(creating_option);
        SDL_FreeSurface(loading_option);
        SDL_FreeSurface(exit_option);
        SDL_FreeSurface(creating_option_highlight);
        SDL_FreeSurface(loading_option_highlight);
        SDL_FreeSurface(exit_option_highlight);

        SDL_DestroyWindow(window);
        SDL_FreeSurface(screen);
    }
    int help_window();
    int fifths_choosing();
    int menu_window();
    int metre_choosing();

    int menu_open();


    char *get_chosen_key();
    int *get_chosen_metre();

};



#endif //PI_PROJECTSDL2_PART_LIB_WINDOWS_H


