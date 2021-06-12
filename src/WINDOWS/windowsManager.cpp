//
// Created by Luksz on 2021-06-12.
//

#include "windowsManager.h"


int WindowsManager::help_window() {

    SDL_Event occurrence;
    int may_exit = 0, current_menu_opt = MENU_WINDOW_CODE;
    SDL_BlitSurface(instructions_, nullptr, screen, nullptr);
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
int WindowsManager::metre_choosing()  {

    chosen_metre[0] = 0;
    chosen_metre[1] = 0;
    SDL_Event occurrence;

    int may_exit = 0, tr = 0, key, current_opt = METRE_WINDOW_CODE;

    SDL_BlitSurface(metre_chose, nullptr, screen, nullptr);
    SDL_BlitSurface(stave, nullptr, screen, &RECT_STAVE_DST[0]);

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
                        SDL_BlitSurface(digits[chosen_metre[tr]], nullptr, screen, &RECT_DIGIT_DST[3 * tr + 1]);

                    } else if (chosen_metre[tr] >= 10) {

                        SDL_BlitSurface(digits[chosen_metre[tr] % 10], nullptr, screen, &RECT_DIGIT_DST[3 * tr + 2]);
                        SDL_BlitSurface(digits[chosen_metre[tr] / 10], nullptr, screen, &RECT_DIGIT_DST[3 * tr]);
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



    return current_opt;
}
////It returns option code
int WindowsManager::menu_window() {

    int may_exit = 0;
    int current_menu_opt = 0, prev_menu_opt = -1;
    SDL_Event occurrence;



    current_menu_opt = MENU_NEW_STAVE_CODE;
    prev_menu_opt = -1;

    SDL_BlitSurface(menu_background, nullptr, screen, nullptr);
    SDL_BlitSurface(title, nullptr, screen, &R_title_dst);
    SDL_BlitSurface(creating_option_highlighted, nullptr, screen, &R_new_dst);
    SDL_BlitSurface(loading_option, nullptr, screen, &R_load_dst);
    SDL_BlitSurface(exit_option, nullptr, screen, &R_exit_dst);
    SDL_BlitSurface(help_option, nullptr, screen, &R_help_dst);

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
                        SDL_BlitSurface(creating_option_highlighted, nullptr, screen, &R_new_dst);
                        prev_menu_opt = MENU_NEW_STAVE_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(creating_option, nullptr, screen, &R_new_dst);
                        current_menu_opt = MENU_LOAD_CODE;
                        prev_menu_opt = MENU_NEW_STAVE_CODE;
                    }
                    break;
                case MENU_LOAD_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(loading_option_highlighted, nullptr, screen, &R_load_dst);
                        prev_menu_opt = MENU_LOAD_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(loading_option, nullptr, screen, &R_load_dst);
                        current_menu_opt = MENU_NEW_STAVE_CODE;
                        prev_menu_opt = MENU_LOAD_CODE;
                    } else if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(loading_option, nullptr, screen, &R_load_dst);
                        current_menu_opt = MENU_EXIT_CODE;
                        prev_menu_opt = MENU_LOAD_CODE;
                    }
                    break;
                case MENU_EXIT_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(exit_option_highlighted, nullptr, screen, &R_exit_dst);
                        prev_menu_opt = MENU_EXIT_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(exit_option, nullptr, screen, &R_exit_dst);
                        current_menu_opt = MENU_LOAD_CODE;
                        prev_menu_opt = MENU_EXIT_CODE;
                    } else if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(exit_option, nullptr, screen, &R_exit_dst);
                        current_menu_opt = MENU_HELP_CODE;
                        prev_menu_opt = MENU_EXIT_CODE;
                    }
                    break;
                case MENU_HELP_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(help_option_highlighted, nullptr, screen, &R_help_dst);
                        prev_menu_opt = MENU_HELP_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(help_option, nullptr, screen, &R_help_dst);
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




    return current_menu_opt;
}
////It returns option code
int WindowsManager::fifths_choosing() {


    int current_fifths_opt = 0, prev_fifths_opt = -1, may_exit = 0, current_opt = 1;
    SDL_Event occurrence;


    SDL_BlitSurface(fifths_circle, nullptr, screen, nullptr);
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
            SDL_BlitSurface(dot, nullptr, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = current_fifths_opt;
        }
        if (occurrence.key.type == SDL_KEYDOWN &&
            (occurrence.key.keysym.sym == SDLK_DOWN || occurrence.key.keysym.sym == SDLK_RIGHT)) {
            SDL_BlitSurface(anty_dot, nullptr, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = current_fifths_opt;
            current_fifths_opt = (current_fifths_opt + 1) % 15;

        } else if (occurrence.key.type == SDL_KEYDOWN &&
                   (occurrence.key.keysym.sym == SDLK_UP || occurrence.key.keysym.sym == SDLK_LEFT)) {
            SDL_BlitSurface(anty_dot, nullptr, screen, &RECT_fifths_dots[current_fifths_opt]);
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


    return current_opt;
}
////It uses options codes
int WindowsManager::menu_open() {

    SDL_Event occurrence;
    int may_exit = 0, current_opt = MENU_WINDOW_CODE;



    while (!may_exit) {
        //////////////// Menu
        if (current_opt == MENU_WINDOW_CODE) {
            current_opt = this->menu_window();
        }
        ////// When creating new stave chosen
        if (current_opt == MENU_NEW_STAVE_CODE) {
            current_opt = this->fifths_choosing();

            if (current_opt == METRE_WINDOW_CODE) {
                current_opt = this->metre_choosing();
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
            current_opt = this->help_window();
        }
    }



    return current_opt;
}

char* WindowsManager::get_chosen_key() {
    return chosen_key;
}

int* WindowsManager::get_chosen_metre() {
    return chosen_metre;
}

