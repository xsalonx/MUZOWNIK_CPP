#include "library.h"


//#ifdef __cplusplus
//extern "C"
//#endif


int pow_int(int a, int b) {
    if (a == 0 || a == 1) return a;
    if (b == 0) return 1;
    int p = 1, i;
    for (i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

void sdl_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error\n");
        atexit(SDL_Quit);
        exit(1);
    }
}
void run() {
    char chosen_key[2];
    int chosen_metre[2];
    int opt;
    OPUS *current_OPUS = NULL, *prev_OPUS = NULL;
    while (1) {

        opt = menu_open(chosen_key, chosen_metre);
        if (opt == CREATING_WINDOW_CODE) {
            printf("Creating new opus\n");
            current_OPUS = create_new_OPUS(chosen_key, chosen_metre, NULL);
            printf("End of editing opus\n");
            printf("Saving opus as txt\n");
            save_OPUS_as_TextFile(current_OPUS);
            printf("Opus saved\n");
            printf("Try to free allocated memory of opus\n");
            delete current_OPUS;
            printf("Allocated memoty for opus freed\n");
        } else if (opt == MENU_LOAD_CODE) {
            printf("Loading opus\n");
            prev_OPUS = fscanf_opus(NULL);
            printf("Opus loaded\n");
            printf("Start editing loaded opus\n");
            current_OPUS = create_new_OPUS(prev_OPUS->key, prev_OPUS->time_sign, prev_OPUS);
            printf("End of editing loaded opus\n");
            printf("Saving edited opus\n");
            save_OPUS_as_TextFile(current_OPUS);
            printf("Edited opus saved\n");
            free_opus(current_OPUS); // also do free_opus(prev_OPUS); prev_OPUS == current_OPUS;
        } else if (opt == MENU_EXIT_CODE) {
            printf("Ending work\n");
            break;
        }
    }
}

void scroll_updown(SDL_Surface *screen, SDL_Surface *stave, SDL_Rect *current, SDL_Event *occurrence) {

    int y = current->y;
    int s = occurrence->wheel.y;

    y -= s * 10;

    if (y > stave->h - screen->h) y = stave->h - screen->h;
    if (y < 0) y = 0;

    current->y = y;
    //SDL_BlitSurface(stave, current, screen, NULL);

}
OPUS *create_new_OPUS(char chosen_key[2], int chosen_metre[2], OPUS *prev_opus) {

    int i;

    OPUS *current_OPUS = NULL;
    if (prev_opus == NULL) {
        current_OPUS = new OPUS;
        current_OPUS->key[0] = chosen_key[0];
        current_OPUS->key[1] = chosen_key[1];
        current_OPUS->time_sign[0] = chosen_metre[0];
        current_OPUS->time_sign[1] = chosen_metre[1];

        ///////
        for (i = 0; i < 10; i++) {
            current_OPUS->title[i] = 'x';
            current_OPUS->author[i] = 'x';
        }
        current_OPUS->title[10] = '\0';
        current_OPUS->author[10] = '\0';
        current_OPUS->temp = 60;
        //////
    } else {
        current_OPUS = prev_opus;
    }

    SDL_Event occurrence;
    int may_exit = 0, is_instruction_open = 0, page_number = 0;
    char default_serial_key[7];
    get_serial_key(chosen_key, default_serial_key);

    int X_start_on_treb = X_START_AFTER_KEY;
    int X_start_on_bass = X_START_AFTER_KEY;
    int X_after_key;

    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL;
    SDL_Surface *stave = NULL;
    SDL_Surface *blank_stave = NULL;
    SDL_Surface *stave_with_key_and_metre = NULL;

    stave = SDL_LoadBMP("obrazki/wiolbas.bmp");
    blank_stave = SDL_LoadBMP("obrazki/wiolbas.bmp");
    stave_with_key_and_metre = SDL_LoadBMP("obrazki/wiolbas.bmp");
    window = SDL_CreateWindow("MUZOWNIK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, stave->w,
                              SCREEN_HIGHT, SDL_WINDOW_SHOWN);
    screen = SDL_GetWindowSurface(window);

    SDL_Rect Rect_current_view;
    Rect_current_view.x = 0;
    Rect_current_view.y = 0;
    Rect_current_view.w = stave->w;
    Rect_current_view.h = SCREEN_HIGHT;

    SDL_Surface *instructions_[3];
    instructions_[0] = SDL_LoadBMP("obrazki/menu/stave_instructions_str1.bmp");
    instructions_[1] = SDL_LoadBMP("obrazki/menu/stave_instructions_str2.bmp");
    instructions_[2] = SDL_LoadBMP("obrazki/menu/stave_instructions_str3.bmp");


    put_key(stave, chosen_key, NULL, &X_start_on_treb);
    X_after_key = X_start_on_treb;
    put_metre(stave, chosen_metre, NULL, &X_start_on_treb, 0);
    SDL_BlitSurface(stave, NULL, stave_with_key_and_metre, NULL);
    X_start_on_treb += 5;
    X_start_on_bass = X_start_on_treb;

    //// Alokowanie pierwszego bar-u

    struct current_OPUS_edits_ COE;

    COE.current_O = current_OPUS;
    if (prev_opus == NULL) {
        COE.current_O->first_BAR = malloc_new_bar(NULL, NULL, X_start_on_treb, DEFAULT_BAR_WIDTH, 0, default_serial_key,
                                                  default_serial_key);
    }
    COE.current_B = COE.current_O->first_BAR;
    COE.current_B->X_of_start_bar = X_start_on_treb;
    COE.current_C = COE.current_B->first_chord_treb;



    COE.current_note_index = COE.current_C->notes_number - 1;
    COE.current_hand = 0;

    for (i = 0; i < 7; i++){
        COE.current_O->default_serial_key[i] = default_serial_key[i];
    }

    int pressed_key, any_change;
    const Uint8 *KEY_STATE = SDL_GetKeyboardState(NULL);
    put_all_bars_on_stave(COE.current_B, stave, stave_with_key_and_metre, default_serial_key, chosen_metre, &COE);
    SDL_BlitSurface(stave, &Rect_current_view, screen, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5);
    SDL_UpdateWindowSurface(window);

    while (!may_exit) {
        while (SDL_PollEvent(&occurrence)) {
            if (occurrence.type == SDL_QUIT) {
                may_exit = 1;
            }
            any_change = 0;

            if (!is_instruction_open && occurrence.type == SDL_MOUSEWHEEL) {
                any_change = 1;
                scroll_updown(screen, stave, &Rect_current_view, &occurrence);
            }

            if ((KEY_STATE[SDL_SCANCODE_LCTRL] && occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_h)) {
                is_instruction_open += 1;
                is_instruction_open %= 2;
                page_number = 0;
                SDL_Delay(300);
            }

            if (occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_ESCAPE) {
                may_exit = 1;
                SDL_Delay(200);
            }

            if (is_instruction_open) {
                if (occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_RIGHT) {
                    page_number = __min(page_number + 1, 2);
                    SDL_Delay(200);
                } else if (occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_LEFT) {
                    page_number = __max(page_number - 1, 0);
                    SDL_Delay(200);
                }
                SDL_BlitSurface(instructions_[page_number], NULL, screen, NULL);
                SDL_UpdateWindowSurface(window);
            }

            if (!is_instruction_open && occurrence.type == SDL_KEYDOWN) {
                any_change = 1;

                SDL_Delay(75);

                pressed_key = occurrence.key.keysym.sym;
                /////////// Zmiana szerokości aktualnego taktu
                if (pressed_key == SDLK_j || pressed_key == SDLK_m) {
                    change_bar_width(pressed_key, &any_change, &COE, KEY_STATE, X_after_key);

                }
                ////////// Zmiana długości chord-u
                if (pressed_key == SDLK_k || pressed_key == SDLK_l) {
                    change_chord_len(pressed_key, &any_change, &COE, KEY_STATE);
                }
                ///////// Zmiana ręki
                if (pressed_key == SDLK_LALT) {
                    change_hand(&COE);
                }
                //////// Zmiana edytowanej nuty
                if ((pressed_key == SDLK_UP || pressed_key == SDLK_DOWN)) {
                    change_note(pressed_key, &COE);
                }
                //////// Zmiana chord-u lub bar-u
                if (pressed_key == SDLK_LEFT || pressed_key == SDLK_RIGHT) {
                    change_chord_or_bar(pressed_key, &COE, KEY_STATE);
                }
                /////// Odkładanie nuty lub pauzy
                if (pressed_key == SDLK_a || pressed_key == SDLK_p ||
                    (SDLK_c <= pressed_key && pressed_key <= SDLK_h)) {
                    put_note_or_pause(pressed_key, &COE, KEY_STATE, COE.current_C->local_serial_key);
                }
                /////// Odkładanie znaku chromatycznego
                if ((pressed_key == SDLK_s || pressed_key == SDLK_b || pressed_key == SDLK_n ||
                     pressed_key == SDLK_x) && COE.current_C->notes_number > 0) {
                    put_acci(pressed_key, &COE, KEY_STATE, COE.current_C->local_serial_key);
                }
                /////// Usuwanie nut i chord-ów
                if (pressed_key == SDLK_BACKSPACE) {
                    del_note_chord_bar(&COE, KEY_STATE, X_after_key);
                }
                ////// Tworzenie noewgo chord-u lub bar-u
                if (pressed_key == SDLK_SPACE) {
                    create_new_chord_bar(&COE, KEY_STATE, X_after_key, default_serial_key);
                }

            }
            if (any_change && !is_instruction_open) {
                put_all_bars_on_stave(COE.current_O->first_BAR, stave, stave_with_key_and_metre, default_serial_key,
                                      chosen_metre, &COE);
                SDL_BlitSurface(stave, &Rect_current_view, screen, NULL);
                SDL_UpdateWindowSurface(window);
                SDL_Delay(10);
            }
        }
    }

    COE.current_C = NULL;
    put_all_bars_on_stave(COE.current_O->first_BAR, stave, stave_with_key_and_metre, default_serial_key, chosen_metre, &COE);
    SDL_SaveBMP(stave, "wynik.bmp");
    SDL_DestroyWindow(window);
    //SDL_FreeSurface(screen);

    return current_OPUS;
}


