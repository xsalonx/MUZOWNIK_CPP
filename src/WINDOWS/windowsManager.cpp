#include "windowsManager.h"


void WindowsManager::init_menu_() {
    menu_background_surf = SDL_LoadBMP("pictures/menu/menu_background.bmp");


    creating_option_surf = SDL_LoadBMP("pictures/menu/option_new.bmp");
    creating_option_highlighted_surf = SDL_LoadBMP("pictures/menu/option_new_highlight.bmp");

    loading_option_surf = SDL_LoadBMP("pictures/menu/option_open.bmp");
    loading_option_highlighted_surf = SDL_LoadBMP("pictures/menu/option_open_highlight.bmp");

    exit_option_surf = SDL_LoadBMP("pictures/menu/option_exit.bmp");
    exit_option_highlighted_surf = SDL_LoadBMP("pictures/menu/option_exit_highlight.bmp");

    title_surf = SDL_LoadBMP("pictures/menu/title.bmp");

    help_option_surf = SDL_LoadBMP("pictures/menu/option_help.bmp");
    help_option_highlighted_surf = SDL_LoadBMP("pictures/menu/option_help_highlight.bmp");

    SDL_SetColorKey(creating_option_highlighted_surf, SDL_TRUE, SDL_MapRGB(creating_option_highlighted_surf->format, 255, 255, 255));
    SDL_SetColorKey(creating_option_surf, SDL_TRUE, SDL_MapRGB(creating_option_surf->format, 255, 255, 255));

    SDL_SetColorKey(loading_option_highlighted_surf, SDL_TRUE, SDL_MapRGB(loading_option_highlighted_surf->format, 255, 255, 255));
    SDL_SetColorKey(loading_option_surf, SDL_TRUE, SDL_MapRGB(loading_option_surf->format, 255, 255, 255));

    SDL_SetColorKey(exit_option_highlighted_surf, SDL_TRUE, SDL_MapRGB(exit_option_highlighted_surf->format, 255, 255, 255));
    SDL_SetColorKey(exit_option_surf, SDL_TRUE, SDL_MapRGB(exit_option_surf->format, 255, 255, 255));

    SDL_SetColorKey(title_surf, SDL_TRUE, SDL_MapRGB(title_surf->format, 255, 255, 255));

    SDL_SetColorKey(help_option_surf, SDL_TRUE, SDL_MapRGB(help_option_surf->format, 255, 255, 255));
    SDL_SetColorKey(help_option_highlighted_surf, SDL_TRUE, SDL_MapRGB(help_option_highlighted_surf->format, 255, 255, 255));


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
void WindowsManager::init_fifths_choosing_() {
    fifths_circle_surf = SDL_LoadBMP("pictures/fifths_circle/fifths_circle_large.bmp");
    dot_surf = SDL_LoadBMP("pictures/fifths_circle/dot.bmp");
    anty_dot_surf = SDL_LoadBMP("pictures/fifths_circle/anty_dot.bmp");
    SDL_SetColorKey(dot_surf, SDL_TRUE, SDL_MapRGB(dot_surf->format, 255, 255, 255));

    RECT_fifths_dots[C_dur_key].x = 390;
    RECT_fifths_dots[C_dur_key].y = 4;

    RECT_fifths_dots[G_dur_key].x = 559;
    RECT_fifths_dots[G_dur_key].y = 50;

    RECT_fifths_dots[D_dur_key].x = 680;
    RECT_fifths_dots[D_dur_key].y = 173;

    RECT_fifths_dots[A_dur_key].x = 723;
    RECT_fifths_dots[A_dur_key].y = 338;

    RECT_fifths_dots[E_dur_key].x = 684;
    RECT_fifths_dots[E_dur_key].y = 509;

    RECT_fifths_dots[Ces_dur_key].x = 564;
    RECT_fifths_dots[Ces_dur_key].y = 628;

    RECT_fifths_dots[H_dur_key].x = 590;
    RECT_fifths_dots[H_dur_key].y = 722;

    RECT_fifths_dots[Ges_dur_key].x = 392;
    RECT_fifths_dots[Ges_dur_key].y = 679;

    RECT_fifths_dots[Fis_dur_key].x = 407;
    RECT_fifths_dots[Fis_dur_key].y = 761;

    RECT_fifths_dots[Des_dur_key].x = 215;
    RECT_fifths_dots[Des_dur_key].y = 632;

    RECT_fifths_dots[Cis_dur_key].x = 156;
    RECT_fifths_dots[Cis_dur_key].y = 712;

    RECT_fifths_dots[As_dur_key].x = 98;
    RECT_fifths_dots[As_dur_key].y = 513;

    RECT_fifths_dots[Es_dur_key].x = 59;
    RECT_fifths_dots[Es_dur_key].y = 340;

    RECT_fifths_dots[B_dur_key].x = 100;
    RECT_fifths_dots[B_dur_key].y = 160;

    RECT_fifths_dots[F_dur_key].x = 224;
    RECT_fifths_dots[F_dur_key].y = 51;
}
void WindowsManager::init_metre_choosing_() {
    char path[50] = "pictures/metre_choose/digit_0.bmp";
    int pos = 28;
    for (int i = 0; i < 10; i++) {
        path[pos] = (char) (i + 48);
        digits_surf[i] = SDL_LoadBMP(path);
        SDL_SetColorKey(digits_surf[i], SDL_TRUE, SDL_MapRGB(digits_surf[i]->format, 255, 255, 255));

    }
    metre_chose_surf = SDL_LoadBMP("pictures/metre_choose/metre_chosing.bmp");
    stave_surf = SDL_LoadBMP("pictures/metre_choose/stave.bmp");


    RECT_STAVE_SRC[0].x = 0;
    RECT_STAVE_SRC[0].y = 0;
    RECT_STAVE_SRC[0].w = stave_surf->w;
    RECT_STAVE_SRC[0].h = stave_surf->h / 2;
    RECT_STAVE_SRC[1].x = 0;
    RECT_STAVE_SRC[1].y = stave_surf->h / 2;
    RECT_STAVE_SRC[1].w = stave_surf->w;
    RECT_STAVE_SRC[1].h = stave_surf->h / 2;

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
void WindowsManager::init_instructions_() {
    instructions_surf = SDL_LoadBMP("pictures/menu/instructions.bmp");
}


WindowsManager::WindowsManager() {
    init_menu_();
    init_fifths_choosing_();
    init_metre_choosing_();
    init_instructions_();
}
WindowsManager::~WindowsManager() {
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);

    //// For menu;
    SDL_FreeSurface(menu_background_surf);
    SDL_FreeSurface(title_surf);
    SDL_FreeSurface(creating_option_surf);
    SDL_FreeSurface(loading_option_surf);
    SDL_FreeSurface(exit_option_surf);
    SDL_FreeSurface(creating_option_highlighted_surf);
    SDL_FreeSurface(loading_option_highlighted_surf);
    SDL_FreeSurface(exit_option_highlighted_surf);

    //// For fifths_choosing_window
    SDL_FreeSurface(fifths_circle_surf);
    SDL_FreeSurface(dot_surf);
    SDL_FreeSurface(anty_dot_surf);

    //// For mertre_choosing;
    SDL_FreeSurface(stave_surf);
    SDL_FreeSurface(metre_chose_surf);
    for (auto & digit : digits_surf) {
        SDL_FreeSurface(digit);
    }
}

int WindowsManager::help_window() {

    SDL_Event occurrence;
    int may_exit = 0, current_menu_opt = MENU_WINDOW_CODE;
    SDL_BlitSurface(instructions_surf, nullptr, screen, nullptr);
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
int WindowsManager::metre_choosing_window()  {

    chosen_metre[0] = 0;
    chosen_metre[1] = 0;
    SDL_Event occurrence;

    int may_exit = 0, tr = 0, key, current_opt = METRE_WINDOW_CODE;

    SDL_BlitSurface(metre_chose_surf, nullptr, screen, nullptr);
    SDL_BlitSurface(stave_surf, nullptr, screen, &RECT_STAVE_DST[0]);

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

            SDL_Delay(60);
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

                    SDL_BlitSurface(stave_surf, &RECT_STAVE_SRC[tr], screen, &RECT_STAVE_DST[tr]);


                    //// When numerator or denominator is single digit it
                    //// is placed at the middle of top or button of stave,

                    //// or it built with two digits, then at left and right.
                    if (0 < chosen_metre[tr] && chosen_metre[tr] < 10) {
                        SDL_BlitSurface(digits_surf[chosen_metre[tr]], nullptr, screen, &RECT_DIGIT_DST[3 * tr + 1]);

                    } else if (chosen_metre[tr] >= 10) {

                        SDL_BlitSurface(digits_surf[chosen_metre[tr] % 10], nullptr, screen, &RECT_DIGIT_DST[3 * tr + 2]);
                        SDL_BlitSurface(digits_surf[chosen_metre[tr] / 10], nullptr, screen, &RECT_DIGIT_DST[3 * tr]);
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
int WindowsManager::menu_window() {

    int may_exit = 0;
    int current_menu_opt = 0, prev_menu_opt = -1;
    SDL_Event occurrence;



    current_menu_opt = MENU_NEW_STAVE_CODE;
    prev_menu_opt = -1;

    SDL_BlitSurface(menu_background_surf, nullptr, screen, nullptr);
    SDL_BlitSurface(title_surf, nullptr, screen, &R_title_dst);
    SDL_BlitSurface(creating_option_highlighted_surf, nullptr, screen, &R_new_dst);
    SDL_BlitSurface(loading_option_surf, nullptr, screen, &R_load_dst);
    SDL_BlitSurface(exit_option_surf, nullptr, screen, &R_exit_dst);
    SDL_BlitSurface(help_option_surf, nullptr, screen, &R_help_dst);

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
                        SDL_BlitSurface(creating_option_highlighted_surf, nullptr, screen, &R_new_dst);
                        prev_menu_opt = MENU_NEW_STAVE_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(creating_option_surf, nullptr, screen, &R_new_dst);
                        current_menu_opt = MENU_LOAD_CODE;
                        prev_menu_opt = MENU_NEW_STAVE_CODE;
                    }
                    break;
                case MENU_LOAD_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(loading_option_highlighted_surf, nullptr, screen, &R_load_dst);
                        prev_menu_opt = MENU_LOAD_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(loading_option_surf, nullptr, screen, &R_load_dst);
                        current_menu_opt = MENU_NEW_STAVE_CODE;
                        prev_menu_opt = MENU_LOAD_CODE;
                    } else if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(loading_option_surf, nullptr, screen, &R_load_dst);
                        current_menu_opt = MENU_EXIT_CODE;
                        prev_menu_opt = MENU_LOAD_CODE;
                    }
                    break;
                case MENU_EXIT_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(exit_option_highlighted_surf, nullptr, screen, &R_exit_dst);
                        prev_menu_opt = MENU_EXIT_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(exit_option_surf, nullptr, screen, &R_exit_dst);
                        current_menu_opt = MENU_LOAD_CODE;
                        prev_menu_opt = MENU_EXIT_CODE;
                    } else if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_DOWN) {
                        SDL_BlitSurface(exit_option_surf, nullptr, screen, &R_exit_dst);
                        current_menu_opt = MENU_HELP_CODE;
                        prev_menu_opt = MENU_EXIT_CODE;
                    }
                    break;
                case MENU_HELP_CODE:
                    if (prev_menu_opt != current_menu_opt) {
                        SDL_BlitSurface(help_option_highlighted_surf, nullptr, screen, &R_help_dst);
                        prev_menu_opt = MENU_HELP_CODE;
                    }
                    if (occurrence.key.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_UP) {
                        SDL_BlitSurface(help_option_surf, nullptr, screen, &R_help_dst);
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
int WindowsManager::fifths_choosing_window() {


    int current_fifths_opt = 0, prev_fifths_opt = -1, end = 0, current_opt = 1;
    SDL_Event occurrence;


    SDL_BlitSurface(fifths_circle_surf, nullptr, screen, nullptr);
    if (occurrence.key.type != SDL_KEYUP) {
        SDL_Delay(50);
    }

    while (!end) {
        while (SDL_PollEvent(&occurrence)) {
            if (occurrence.type == SDL_QUIT) {
                end = 1;
                current_opt = MENU_EXIT_CODE;
            }
        }

        if (current_fifths_opt != prev_fifths_opt) {
            SDL_BlitSurface(dot_surf, nullptr, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = current_fifths_opt;
        }
        if (occurrence.key.type == SDL_KEYDOWN &&
            (occurrence.key.keysym.sym == SDLK_DOWN || occurrence.key.keysym.sym == SDLK_RIGHT)) {
            SDL_BlitSurface(anty_dot_surf, nullptr, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = current_fifths_opt;
            current_fifths_opt = (current_fifths_opt + 1) % 15;

        } else if (occurrence.key.type == SDL_KEYDOWN &&
                   (occurrence.key.keysym.sym == SDLK_UP || occurrence.key.keysym.sym == SDLK_LEFT)) {
            SDL_BlitSurface(anty_dot_surf, nullptr, screen, &RECT_fifths_dots[current_fifths_opt]);
            prev_fifths_opt = current_fifths_opt;
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
            end = 1;

        }

        SDL_UpdateWindowSurface(window);
        if (occurrence.key.type != SDL_KEYUP) {
            SDL_Delay(60);
        }
        if (occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_ESCAPE) {
            end = 1;
            current_opt = MENU_WINDOW_CODE;
        }
        SDL_Delay(80);

    }

    return current_opt;
}

int WindowsManager::open() {
    this->open_window_();

    int end = 0, current_opt = MENU_WINDOW_CODE;

    while (!end) {
        //////////////// Menu
        if (current_opt == MENU_WINDOW_CODE) {
            current_opt = this->menu_window();
        }
        ////// When creating new stave chosen
        if (current_opt == MENU_NEW_STAVE_CODE) {
            current_opt = this->fifths_choosing_window();

            if (current_opt == METRE_WINDOW_CODE) {
                current_opt = this->metre_choosing_window();
                if (current_opt == CREATING_WINDOW_CODE) {
                    end = 1;
                }
            }
        }
        ////// When opening existing stave
        if (current_opt == MENU_LOAD_CODE) {
            end = 1;
        }
        ////// When go exit
        if (current_opt == MENU_EXIT_CODE) {
            end = 1;

            SDL_Quit();
            exit(0);
        }
        ////// When need help
        if (current_opt == MENU_HELP_CODE) {
            current_opt = this->help_window();
        }
    }

    this->close_window_();
    return current_opt;

}


char* WindowsManager::get_chosen_key() {
    return chosen_key;
}
int* WindowsManager::get_chosen_metre() {
    return chosen_metre;
}

