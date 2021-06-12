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

    //// For metre_choosing;
    SDL_Surface *metre_chose{};
    SDL_Surface *stave{};
    SDL_Surface *digits[10]{};

    SDL_Rect RECT_STAVE_SRC[2]{}, RECT_STAVE_DST[2]{}, RECT_DIGIT_DST[8]{};

    //// For instructions_
    SDL_Surface *instructions_{};


    //// constructor help methods
    void init_menu_() {
        window = SDL_CreateWindow("MUZOWNIK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MENU_SCREEN_WIDTH,
                                  SCREEN_HIGHT, SDL_WINDOW_SHOWN);
        screen = SDL_GetWindowSurface(window);

        menu_background = SDL_LoadBMP("obrazki/menu/menu_background.bmp");


        creating_option = SDL_LoadBMP("obrazki/menu/option_new.bmp");
        creating_option_highlighted = SDL_LoadBMP("obrazki/menu/option_new_highlight.bmp");

        loading_option = SDL_LoadBMP("obrazki/menu/option_open.bmp");
        loading_option_highlighted = SDL_LoadBMP("obrazki/menu/option_open_highlight.bmp");

        exit_option = SDL_LoadBMP("obrazki/menu/option_exit.bmp");
        exit_option_highlighted = SDL_LoadBMP("obrazki/menu/option_exit_highlight.bmp");

        title = SDL_LoadBMP("obrazki/menu/title.bmp");

        help_option = SDL_LoadBMP("obrazki/menu/option_help.bmp");
        help_option_highlighted = SDL_LoadBMP("obrazki/menu/option_help_highlight.bmp");

        SDL_SetColorKey(creating_option_highlighted, SDL_TRUE, SDL_MapRGB(creating_option_highlighted->format, 255, 255, 255));
        SDL_SetColorKey(creating_option, SDL_TRUE, SDL_MapRGB(creating_option->format, 255, 255, 255));

        SDL_SetColorKey(loading_option_highlighted, SDL_TRUE, SDL_MapRGB(loading_option_highlighted->format, 255, 255, 255));
        SDL_SetColorKey(loading_option, SDL_TRUE, SDL_MapRGB(loading_option->format, 255, 255, 255));

        SDL_SetColorKey(exit_option_highlighted, SDL_TRUE, SDL_MapRGB(exit_option_highlighted->format, 255, 255, 255));
        SDL_SetColorKey(exit_option, SDL_TRUE, SDL_MapRGB(exit_option->format, 255, 255, 255));

        SDL_SetColorKey(title, SDL_TRUE, SDL_MapRGB(title->format, 255, 255, 255));

        SDL_SetColorKey(help_option, SDL_TRUE, SDL_MapRGB(help_option->format, 255, 255, 255));
        SDL_SetColorKey(help_option_highlighted, SDL_TRUE, SDL_MapRGB(help_option_highlighted->format, 255, 255, 255));


        R_title_dst.x = X_TO_INSERT_OPTION_TITLE;
        R_title_dst.y = Y_TO_INSERT_OPTION_TITLE;
        R_new_dst.x = X_TO_INSERT_OPTION_NEW;
        R_new_dst.y = Y_TO_INSERT_OPTION_NEW;
        R_load_dst.x = X_TO_INSERT_OPTION_OPEN;
        R_load_dst.y = Y_TO_INSERT_OPTION_OPEN;
        R_exit_dst.x = X_TO_INSERT_OPTION_EXIT;
        R_exit_dst.y = Y_TO_INSERT_OPTION_EXIT;
        R_help_dst.x = X_TO_INSERT_OPTION_HELP;
        R_help_dst.y = Y_TO_INSERT_OPTION_HELP;
    }
    void init_fifths_choosing_() {
        fifths_circle = SDL_LoadBMP("obrazki/fifths_circle/fifths_circle_large.bmp");
        dot = SDL_LoadBMP("obrazki/fifths_circle/dot.bmp");
        anty_dot = SDL_LoadBMP("obrazki/fifths_circle/anty_dot.bmp");
        SDL_SetColorKey(dot, SDL_TRUE, SDL_MapRGB(dot->format, 255, 255, 255));

        RECT_fifths_dots[0].x = 390;
        RECT_fifths_dots[0].y = 4;

        RECT_fifths_dots[1].x = 559;
        RECT_fifths_dots[1].y = 50;

        RECT_fifths_dots[2].x = 680;
        RECT_fifths_dots[2].y = 173;

        RECT_fifths_dots[3].x = 723;
        RECT_fifths_dots[3].y = 338;

        RECT_fifths_dots[4].x = 684;
        RECT_fifths_dots[4].y = 509;

        RECT_fifths_dots[5].x = 564;
        RECT_fifths_dots[5].y = 628;

        RECT_fifths_dots[6].x = 590;
        RECT_fifths_dots[6].y = 722;

        RECT_fifths_dots[7].x = 392;
        RECT_fifths_dots[7].y = 679;

        RECT_fifths_dots[8].x = 407;
        RECT_fifths_dots[8].y = 761;

        RECT_fifths_dots[9].x = 215;
        RECT_fifths_dots[9].y = 632;

        RECT_fifths_dots[10].x = 156;
        RECT_fifths_dots[10].y = 712;

        RECT_fifths_dots[11].x = 98;
        RECT_fifths_dots[11].y = 513;

        RECT_fifths_dots[12].x = 59;
        RECT_fifths_dots[12].y = 340;

        RECT_fifths_dots[13].x = 100;
        RECT_fifths_dots[13].y = 160;

        RECT_fifths_dots[14].x = 224;
        RECT_fifths_dots[14].y = 51;
    }
    void init_metre_choosing_() {
        char path[33] = "obrazki/metre_choose/digit_0.bmp";
        int pos = 27;
        for (int i = 0; i < 10; i++) {
            path[pos] = (char) (i + 48);
            digits[i] = SDL_LoadBMP(path);
            SDL_SetColorKey(digits[i], SDL_TRUE, SDL_MapRGB(digits[i]->format, 255, 255, 255));

        }
        metre_chose = SDL_LoadBMP("obrazki/metre_choose/metre_chosing.bmp");
        stave = SDL_LoadBMP("obrazki/metre_choose/stave.bmp");


        RECT_STAVE_SRC[0].x = 0;
        RECT_STAVE_SRC[0].y = 0;
        RECT_STAVE_SRC[0].w = stave->w;
        RECT_STAVE_SRC[0].h = stave->h / 2;
        RECT_STAVE_SRC[1].x = 0;
        RECT_STAVE_SRC[1].y = stave->h / 2;
        RECT_STAVE_SRC[1].w = stave->w;
        RECT_STAVE_SRC[1].h = stave->h / 2;

        RECT_STAVE_DST[0].x = X_STAVE_METRE_CHOOSING;
        RECT_STAVE_DST[0].y = FIRST_Y_METRE_CHOOSE - 2;
        RECT_STAVE_DST[1].x = X_STAVE_METRE_CHOOSING;
        RECT_STAVE_DST[1].y = SECOND_Y_METRE_CHOOSE - 1;

        RECT_DIGIT_DST[0].x = FIRST_X_METRE_CHOOSE;
        RECT_DIGIT_DST[0].y = FIRST_Y_METRE_CHOOSE;
        RECT_DIGIT_DST[1].x = SECOND_X_METRE_CHOOSE;
        RECT_DIGIT_DST[1].y = FIRST_Y_METRE_CHOOSE;
        RECT_DIGIT_DST[2].x = THIRD_X_METRE_CHOOSE;
        RECT_DIGIT_DST[2].y = FIRST_Y_METRE_CHOOSE;
        RECT_DIGIT_DST[3].x = FIRST_X_METRE_CHOOSE;
        RECT_DIGIT_DST[3].y = SECOND_Y_METRE_CHOOSE;
        RECT_DIGIT_DST[4].x = SECOND_X_METRE_CHOOSE;
        RECT_DIGIT_DST[4].y = SECOND_Y_METRE_CHOOSE;
        RECT_DIGIT_DST[5].x = THIRD_X_METRE_CHOOSE;
        RECT_DIGIT_DST[5].y = SECOND_Y_METRE_CHOOSE;
    }
    void init_instructions_() {
        instructions_ = SDL_LoadBMP("obrazki/menu/instructions.bmp");
    }

public:
    WindowsManager() {
       init_menu_();
       init_fifths_choosing_();
       init_metre_choosing_();
       init_instructions_();
    }
    ~WindowsManager() {
        SDL_DestroyWindow(window);
        SDL_FreeSurface(screen);

        //// For menu;
        SDL_FreeSurface(menu_background);
        SDL_FreeSurface(title);
        SDL_FreeSurface(creating_option);
        SDL_FreeSurface(loading_option);
        SDL_FreeSurface(exit_option);
        SDL_FreeSurface(creating_option_highlighted);
        SDL_FreeSurface(loading_option_highlighted);
        SDL_FreeSurface(exit_option_highlighted);

        //// For fifths_choosing
        SDL_FreeSurface(fifths_circle);
        SDL_FreeSurface(dot);
        SDL_FreeSurface(anty_dot);

        //// For mertre_choosing;
        SDL_FreeSurface(stave);
        SDL_FreeSurface(metre_chose);
        for (auto & digit : digits) {
            SDL_FreeSurface(digit);
        }
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


