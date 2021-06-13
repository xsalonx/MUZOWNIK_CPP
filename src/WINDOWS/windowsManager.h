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
    SDL_Surface *title{};
    SDL_Surface *menu_background{};
    SDL_Surface *creating_option{};
    SDL_Surface *creating_option_highlighted{};
    SDL_Surface *loading_option{};
    SDL_Surface *loading_option_highlighted{};
    SDL_Surface *exit_option{};
    SDL_Surface *exit_option_highlighted{};
    SDL_Surface *help_option{};
    SDL_Surface *help_option_highlighted{};

    SDL_Rect R_load_dst{}, R_new_dst{}, R_exit_dst{}, R_title_dst{}, R_help_dst{};


    //// For fifths_choosing;
    SDL_Surface *fifths_circle{};
    SDL_Surface *dot{};
    SDL_Surface *anty_dot{};

    SDL_Rect RECT_fifths_dots[15]{};

    //// For metre_choosing_window;
    SDL_Surface *metre_chose{};
    SDL_Surface *stave{};
    SDL_Surface *digits[10]{};

    SDL_Rect RECT_STAVE_SRC[2]{}, RECT_STAVE_DST[2]{}, RECT_DIGIT_DST[8]{};

    //// For instructions_
    SDL_Surface *instructions_{};


    //// constructor help methods
    void init_menu_();
    void init_fifths_choosing_();
    void init_metre_choosing_();
    void init_instructions_();

    int help_window();
    int fifths_choosing();
    int menu_window();
    int metre_choosing_window();

public:
    WindowsManager();
    ~WindowsManager();



    int menu_open();


    char *get_chosen_key();
    int *get_chosen_metre();

};



#endif //PI_PROJECTSDL2_PART_LIB_WINDOWS_H


