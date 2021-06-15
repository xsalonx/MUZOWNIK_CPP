#ifndef PI_PROJECTSDL2_PART_LIB_WINDOWS_H
#define PI_PROJECTSDL2_PART_LIB_WINDOWS_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <SDL2/SDL.h>
#include "../geometry_defCodes.h"



class WindowsManager {
private:
    SDL_Surface *screen{};
    SDL_Window *window{};
    char chosen_key[2]{};
    int chosen_metre[2]{};

    //// For menu;
    SDL_Surface *title_surf{};
    SDL_Surface *menu_background_surf{};
    SDL_Surface *creating_option_surf{};
    SDL_Surface *creating_option_highlighted_surf{};
    SDL_Surface *loading_option_surf{};
    SDL_Surface *loading_option_highlighted_surf{};
    SDL_Surface *exit_option_surf{};
    SDL_Surface *exit_option_highlighted_surf{};
    SDL_Surface *help_option_surf{};
    SDL_Surface *help_option_highlighted_surf{};

    SDL_Rect R_load_dst{}, R_new_dst{}, R_exit_dst{}, R_title_dst{}, R_help_dst{};


    //// For fifths_choosing_window;
    SDL_Surface *fifths_circle_surf{};
    SDL_Surface *dot_surf{};
    SDL_Surface *anty_dot_surf{};

    SDL_Rect RECT_fifths_dots[15]{};

    //// For metre_choosing_window;
    SDL_Surface *metre_chose_surf{};
    SDL_Surface *stave_surf{};
    SDL_Surface *digits_surf[10]{};

    SDL_Rect RECT_STAVE_SRC[2]{}, RECT_STAVE_DST[2]{}, RECT_DIGIT_DST[8]{};

    //// For instructions_
    SDL_Surface *instructions_surf{};


    //// constructor help methods
    void init_menu_();
    void init_fifths_choosing_();
    void init_metre_choosing_();
    void init_instructions_();

    int help_window();
    int fifths_choosing_window();
    int menu_window();
    int metre_choosing_window();

    void open_window_() {
        window = SDL_CreateWindow("MUZOWNIK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MENU_SCREEN_WIDTH,
                                  SCREEN_HIGHT, SDL_WINDOW_SHOWN);
        screen = SDL_GetWindowSurface(window);
    }
    void close_window_() {
        SDL_FreeSurface(screen);
        SDL_DestroyWindow(window);
    }
public:
    WindowsManager();
    ~WindowsManager();

    int open();

    char *get_chosen_key();
    int *get_chosen_metre();

};



#endif //PI_PROJECTSDL2_PART_LIB_WINDOWS_H


