//
// Created by Luksz on 2021-06-12.
//

#include "windows.h"


int help_window(SDL_Surface *screen, SDL_Window *window) {

    SDL_Surface *instructions_ = NULL;
    instructions_ = SDL_LoadBMP("obrazki/menu/instructions.bmp");
    SDL_Event occurrence;
    int may_exit = 0, current_menu_opt = MENU_WINDOW_CODE;
    SDL_BlitSurface(instructions_, NULL, screen, NULL);
    SDL_UpdateWindowSurface(window);

    while (may_exit == 0) {
        while (SDL_PollEvent(&occurrence)) {
            if (occurrence.type == SDL_QUIT) {
                may_exit = 1;
                current_menu_opt = MENU_EXIT_CODE;
            }
            if (occurrence.key.type != SDL_KEYUP) {
                SDL_Delay(80);
            }
            if (occurrence.key.type != SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_ESCAPE) {
                may_exit = 1;
                current_menu_opt = MENU_WINDOW_CODE;
            }

            SDL_UpdateWindowSurface(window);
            SDL_Delay(20);
        }
    }
    return current_menu_opt;
}
////It returns option code
int metre_choosing(SDL_Surface *screen, SDL_Window *window, int chosen_metre[2])  {

    chosen_metre[0] = 0;
    chosen_metre[1] = 0;
    SDL_Event occurrence;
    SDL_Surface *metre_chose = NULL;
    SDL_Surface *stave = NULL;
    SDL_Surface *digits[10];
    char path[33] = "obrazki/metre_choose/digit_0.bmp";
    int pos = 27, i, may_exit = 0, tr = 0, key, current_opt = METRE_WINDOW_CODE;
    for (i = 0; i < 10; i++) {
        path[pos] = (char) (i + 48);
        digits[i] = SDL_LoadBMP(path);
        SDL_SetColorKey(digits[i], SDL_TRUE, SDL_MapRGB(digits[i]->format, 255, 255, 255));

    }
    metre_chose = SDL_LoadBMP("obrazki/metre_choose/metre_chosing.bmp");
    stave = SDL_LoadBMP("obrazki/metre_choose/stave.bmp");


    SDL_Rect RECT_STAVE_SRC[2], RECT_STAVE_DST[2], RECT_DIGIT_DST[8];
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

    SDL_BlitSurface(metre_chose, NULL, screen, NULL);
    SDL_BlitSurface(stave, NULL, screen, &RECT_STAVE_DST[0]);

    while (!may_exit) {
        while (SDL_PollEvent(&occurrence)) {
            if (occurrence.type == SDL_QUIT) {
                may_exit = 1;
                current_opt = MENU_EXIT_CODE;
            }


            if (tr == 0 && occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                tr = 1;
            } else if (tr == 1 && occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                tr = 0;
            }

            if (occurrence.key.type != SDL_KEYUP) {
                SDL_Delay(60);
            }

            if (occurrence.key.type == SDL_KEYDOWN) {
                key = occurrence.key.keysym.sym;
                if ((SDLK_0 <= key && key <= SDLK_9) || key == SDLK_BACKSPACE) {

                    if (SDLK_0 <= key && key <= SDLK_9) {
                        if (chosen_metre[tr] < 10) {
                            chosen_metre[tr] = chosen_metre[tr] * 10 + (key - 48);
                        }
                    } else {
                        chosen_metre[tr] /= 10;
                    }

                    SDL_BlitSurface(stave, &RECT_STAVE_SRC[tr], screen, &RECT_STAVE_DST[tr]);


                    //// When numerator or denominator is single digit it
                    //// is placed at the middle of top or button of stave,

                    //// or it built with two digits, then at left and right.
                    if (0 < chosen_metre[tr] && chosen_metre[tr] < 10) {
                        SDL_BlitSurface(digits[chosen_metre[tr]], NULL, screen, &RECT_DIGIT_DST[3 * tr + 1]);

                    } else if (chosen_metre[tr] >= 10) {

                        SDL_BlitSurface(digits[chosen_metre[tr] % 10], NULL, screen, &RECT_DIGIT_DST[3 * tr + 2]);
                        SDL_BlitSurface(digits[chosen_metre[tr] / 10], NULL, screen, &RECT_DIGIT_DST[3 * tr]);
                    }
                }
            }


            if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_ESCAPE) {
                may_exit = 1;
                current_opt = MENU_NEW_STAVE_CODE;
            }
            if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_RETURN) {
                if (chosen_metre[0] * chosen_metre[1] > 0) {
                    may_exit = 1;
                    current_opt = CREATING_WINDOW_CODE;
                } else {
                    fprintf(stderr, "You didn't choose metre\n");
                }
            }

            SDL_UpdateWindowSurface(window);
        }
    }

//    SDL_FreeSurface(stav);
//    SDL_FreeSurface(metre_chose);
//    for (i = 0; i < 10; i++) {
//        SDL_FreeSurface(digits[i]);
//    }

    return current_opt;
}
////It returns option code
int menu_window(SDL_Surface *screen, SDL_Window *window) {

    int may_exit = 0;
    int current_menu_opt = 0, prev_menu_opt = -1;
    SDL_Event occurrence;

    SDL_Surface *title = NULL;
    SDL_Surface *creating_option = NULL;
    SDL_Surface *loading_option = NULL;
    SDL_Surface *exit_option = NULL;
    SDL_Surface *creating_option_highlight = NULL;
    SDL_Surface *loading_option_highlight = NULL;
    SDL_Surface *exit_option_highlight = NULL;
    SDL_Surface *menu_background = NULL;
    SDL_Surface *help_option = NULL;
    SDL_Surface *help_highlight_option = NULL;

    menu_background = SDL_LoadBMP("obrazki/menu/menu_background.bmp");
    creating_option = SDL_LoadBMP("obrazki/menu/option_new.bmp");
    loading_option = SDL_LoadBMP("obrazki/menu/option_open.bmp");
    exit_option = SDL_LoadBMP("obrazki/menu/option_exit.bmp");
    creating_option_highlight = SDL_LoadBMP("obrazki/menu/option_new_highlight.bmp");
    loading_option_highlight = SDL_LoadBMP("obrazki/menu/option_open_highlight.bmp");
    exit_option_highlight = SDL_LoadBMP("obrazki/menu/option_exit_highlight.bmp");
    title = SDL_LoadBMP("obrazki/menu/title.bmp");
    help_option = SDL_LoadBMP("obrazki/menu/option_help.bmp");
    help_highlight_option = SDL_LoadBMP("obrazki/menu/option_help_highlight.bmp");

    SDL_SetColorKey(help_option, SDL_TRUE, SDL_MapRGB(help_option->format, 255, 255, 255));
    SDL_SetColorKey(help_highlight_option, SDL_TRUE, SDL_MapRGB(help_highlight_option->format, 255, 255, 255));
    SDL_SetColorKey(title, SDL_TRUE, SDL_MapRGB(title->format, 255, 255, 255));
    SDL_SetColorKey(exit_option_highlight, SDL_TRUE, SDL_MapRGB(exit_option_highlight->format, 255, 255, 255));
    SDL_SetColorKey(exit_option, SDL_TRUE, SDL_MapRGB(exit_option->format, 255, 255, 255));
    SDL_SetColorKey(loading_option_highlight, SDL_TRUE, SDL_MapRGB(loading_option_highlight->format, 255, 255, 255));
    SDL_SetColorKey(loading_option, SDL_TRUE, SDL_MapRGB(loading_option->format, 255, 255, 255));
    SDL_SetColorKey(creating_option_highlight, SDL_TRUE, SDL_MapRGB(creating_option_highlight->format, 255, 255, 255));
    SDL_SetColorKey(creating_option, SDL_TRUE, SDL_MapRGB(creating_option->format, 255, 255, 255));

    SDL_Rect R_load_dst, R_new_dst, R_exit_dst, R_title_dst, R_help_dst;
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

    current_menu_opt = MENU_NEW_STAVE_CODE;
    prev_menu_opt = -1;

    SDL_BlitSurface(menu_background, NULL, screen, NULL);
    SDL_BlitSurface(title, NULL, screen, &R_title_dst);
    SDL_BlitSurface(creating_option_highlight, NULL, screen, &R_new_dst);
    SDL_BlitSurface(loading_option, NULL, screen, &R_load_dst);
    SDL_BlitSurface(exit_option, NULL, screen, &R_exit_dst);
    SDL_BlitSurface(help_option, NULL, screen, &R_help_dst);

    SDL_UpdateWindowSurface(window);


    while (may_exit == 0) {
        while (SDL_PollEvent(&occurrence)) {
            if (occurrence.type == SDL_QUIT) {
                may_exit = 1;
                current_menu_opt = 2;
            }


            if (occurrence.key.type != SDL_KEYUP) {
                SDL_Delay(80);
            }
            switch (current_menu_opt) {

                case MENU_NEW_STAVE_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(creating_option_highlight, NULL, screen, &R_new_dst);
                        prev_menu_opt = MENU_NEW_STAVE_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(creating_option, NULL, screen, &R_new_dst);
                        current_menu_opt = MENU_LOAD_CODE;
                        prev_menu_opt = MENU_NEW_STAVE_CODE;
                    }
                    break;
                case MENU_LOAD_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(loading_option_highlight, NULL, screen, &R_load_dst);
                        prev_menu_opt = MENU_LOAD_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(loading_option, NULL, screen, &R_load_dst);
                        current_menu_opt = MENU_NEW_STAVE_CODE;
                        prev_menu_opt = MENU_LOAD_CODE;
                    } else if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(loading_option, NULL, screen, &R_load_dst);
                        current_menu_opt = MENU_EXIT_CODE;
                        prev_menu_opt = MENU_LOAD_CODE;
                    }
                    break;
                case MENU_EXIT_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(exit_option_highlight, NULL, screen, &R_exit_dst);
                        prev_menu_opt = MENU_EXIT_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(exit_option, NULL, screen, &R_exit_dst);
                        current_menu_opt = MENU_LOAD_CODE;
                        prev_menu_opt = MENU_EXIT_CODE;
                    } else if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(exit_option, NULL, screen, &R_exit_dst);
                        current_menu_opt = MENU_HELP_CODE;
                        prev_menu_opt = MENU_EXIT_CODE;
                    }
                    break;
                case MENU_HELP_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(help_highlight_option, NULL, screen, &R_help_dst);
                        prev_menu_opt = MENU_HELP_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(help_option, NULL, screen, &R_help_dst);
                        current_menu_opt = MENU_EXIT_CODE;
                        prev_menu_opt = MENU_HELP_CODE;
                    }
                    break;
                default:
                    break;
            }


            if (prev_menu_opt == current_menu_opt && occurrence.key.keysym.sym == SDLK_RETURN) {
                may_exit = 1;
            }

            SDL_UpdateWindowSurface(window);
            SDL_Delay(20);
        }
    }

    SDL_FreeSurface(menu_background);
    SDL_FreeSurface(title);
    SDL_FreeSurface(creating_option);
    SDL_FreeSurface(loading_option);
    SDL_FreeSurface(exit_option);
    SDL_FreeSurface(creating_option_highlight);
    SDL_FreeSurface(loading_option_highlight);
    SDL_FreeSurface(exit_option_highlight);

    return current_menu_opt;
}
////It returns option code
int fifths_choosing(SDL_Surface *screen, SDL_Window *window, char chosen_key[2]) {

    SDL_Rect RECT_fifths_dots[15];
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


    int current_fifths_opt = 0, prev_fifths_opt = -1, may_exit = 0, current_opt = 1;
    SDL_Surface *fifths_circle = NULL;
    SDL_Surface *dot = NULL;
    SDL_Surface *anty_dot = NULL;
    SDL_Event occurrence;

    fifths_circle = SDL_LoadBMP("obrazki/fifths_circle/fifths_circle_large.bmp");
    dot = SDL_LoadBMP("obrazki/fifths_circle/dot.bmp");
    anty_dot = SDL_LoadBMP("obrazki/fifths_circle/anty_dot.bmp");
    SDL_SetColorKey(dot, SDL_TRUE, SDL_MapRGB(dot->format, 255, 255, 255));


    SDL_BlitSurface(fifths_circle, NULL, screen, NULL);
    if (occurrence.key.type != SDL_KEYUP) {
        SDL_Delay(50);
    }
    while (may_exit == 0) {
        while (SDL_PollEvent(&occurrence)) {
            if (occurrence.type == SDL_QUIT) {
                may_exit = 1;
                current_opt = MENU_EXIT_CODE;
            }
        }

        if (current_fifths_opt != prev_fifths_opt) {
            SDL_BlitSurface(dot, NULL, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = current_fifths_opt;
        }
        if (occurrence.key.type == SDL_KEYDOWN &&
            (occurrence.key.keysym.sym == SDLK_DOWN || occurrence.key.keysym.sym == SDLK_RIGHT)) {
            SDL_BlitSurface(anty_dot, NULL, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = current_fifths_opt;
            current_fifths_opt = (current_fifths_opt + 1) % 15;

        } else if (occurrence.key.type == SDL_KEYDOWN &&
                   (occurrence.key.keysym.sym == SDLK_UP || occurrence.key.keysym.sym == SDLK_LEFT)) {
            SDL_BlitSurface(anty_dot, NULL, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = 0;
            current_fifths_opt = (current_fifths_opt + 14) % 15;
        }

        if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_RETURN) {
            chosen_key[1] = '\0';
            switch (current_fifths_opt) {

                case 0:
                    chosen_key[0] = 'C';
                    break;
                case 1:
                    chosen_key[0] = 'G';
                    break;
                case 2:
                    chosen_key[0] = 'D';
                    break;
                case 3:
                    chosen_key[0] = 'A';
                    break;
                case 4:
                    chosen_key[0] = 'E';
                    break;
                case 5:
                    chosen_key[0] = 'C';
                    chosen_key[1] = 'e';
                    break;
                case 6:
                    chosen_key[0] = 'H';
                    break;
                case 7:
                    chosen_key[0] = 'G';
                    chosen_key[1] = 'e';
                    break;
                case 8:
                    chosen_key[0] = 'F';
                    chosen_key[1] = 'i';
                    break;
                case 9:
                    chosen_key[0] = 'D';
                    chosen_key[1] = 'e';
                    break;
                case 10:
                    chosen_key[0] = 'C';
                    chosen_key[1] = 'i';
                    break;
                case 11:
                    chosen_key[0] = 'A';
                    chosen_key[1] = 's';
                    break;
                case 12:
                    chosen_key[0] = 'E';
                    chosen_key[1] = 's';
                    break;
                case 13:
                    chosen_key[0] = 'B';
                    break;
                case 14:
                    chosen_key[0] = 'F';
                    break;
                default:
                    break;
            }

            current_opt = METRE_WINDOW_CODE;
            may_exit = 1;

        }

        SDL_UpdateWindowSurface(window);
        if (occurrence.key.type != SDL_KEYUP) {
            SDL_Delay(60);
        }
        if (occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_ESCAPE) {
            may_exit = 1;
            current_opt = MENU_WINDOW_CODE;
        }
        SDL_Delay(20);

    }

//    SDL_FreeSurface(fifths_circle);
//    SDL_FreeSurface(dot);
//    SDL_FreeSurface(anty_dot);

    return current_opt;
}
////It uses options codes
int menu_open(char chosen_key[2], int chosen_metre[2]) {

    SDL_Event occurrence;
    int may_exit = 0, current_opt = MENU_WINDOW_CODE;

    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL;

    window = SDL_CreateWindow("MUZOWNIK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MENU_SCREEN_WIDTH,
                              SCREEN_HIGHT, SDL_WINDOW_SHOWN);
    screen = SDL_GetWindowSurface(window);

    while (!may_exit) {
        //////////////// Menu
        if (current_opt == MENU_WINDOW_CODE) {
            current_opt = menu_window(screen, window);
        }
        ////// When creating new stave chosen
        if (current_opt == MENU_NEW_STAVE_CODE) {
            current_opt = fifths_choosing(screen, window, chosen_key);

            if (current_opt == METRE_WINDOW_CODE) {
                current_opt = metre_choosing(screen, window, chosen_metre);
                if (current_opt == CREATING_WINDOW_CODE) {
                    may_exit = 1;
                }
            }
        }
        ////// When opening existing stave
        if (current_opt == MENU_LOAD_CODE) {
            may_exit = 1;
        }
        ////// When go exit
        if (current_opt == MENU_EXIT_CODE) {
            may_exit = 1;

            SDL_FreeSurface(screen);
            SDL_DestroyWindow(window);

            SDL_Quit();
            exit(0);
        }
        ////// When need help
        if (current_opt == MENU_HELP_CODE) {
            current_opt = help_window(screen, window);
        }
    }

    SDL_DestroyWindow(window);
    //SDL_FreeSurface(screen);

    return current_opt;
}

