
#include "opus_edit_logic.h"

int change_bar_width(int pressed_key, int *any_change, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, int X_after_key) {

    int i;
    struct current_OPUS_edits_ COE_HELP;
    if (KEY_STATE != NULL && !KEY_STATE[SDL_SCANCODE_LSHIFT] && !KEY_STATE[SDL_SCANCODE_RSHIFT]) {
        i = STEP_IN_BAR_WIDTH_CHANGING_WITHOUT_SHIFT;
    } else {
        i = STEP_IN_BAR_WIDTH_CHANGING_WITH_SHIFT;
    }
    if (pressed_key == SDLK_j) {
        COE->current_B->width_ -= i;
        if (COE->current_B->width_ < WIDTH_NOTES_WITH_FLAGS) {
            COE->current_B->width_ = WIDTH_NOTES_WITH_FLAGS;
            if (any_change != NULL) *any_change = 0;
        }
    } else if (pressed_key == SDLK_m) {
        COE->current_B->width_ += i;
        if (COE->current_B->X_of_start_bar + COE->current_B->width_ > X_END_OF_STAVE) {
            COE->current_B->width_ = X_END_OF_STAVE - COE->current_B->X_of_start_bar;
            if (any_change != NULL) *any_change = 0;
        }
    }

    COE_HELP.current_B = COE->current_B->next;
    if (any_change == NULL || *any_change) {
        while (COE_HELP.current_B != NULL) {

            COE_HELP.current_B->X_of_start_bar =
                    COE_HELP.current_B->prev->width_ + COE_HELP.current_B->prev->X_of_start_bar + 3;
            COE_HELP.current_B->width_ = __min(X_END_OF_STAVE - COE_HELP.current_B->X_of_start_bar,
                                               COE_HELP.current_B->width_);
            //COE_HELP.current_B->width_ = __min(DEFAULT_BAR_WIDTH, COE_HELP.current_B->width_);

            COE_HELP.current_B->brace = COE_HELP.current_B->prev->brace;
            if (COE_HELP.current_B->width_ < MIN_BAR_WIDTH) {
                if (COE_HELP.current_B->brace < 4) {
                    COE_HELP.current_B->brace += 1;
                    COE_HELP.current_B->X_of_start_bar = X_after_key;
                    COE_HELP.current_B->width_ = DEFAULT_BAR_WIDTH;
                } else {
                    COE_HELP.current_B->prev->next = NULL;
                    free_bar(COE_HELP.current_B);
                    COE_HELP.current_B = NULL;
                }
            }
            COE_HELP.current_B = COE_HELP.current_B->next;
        }
    }

    return 0;
}
int change_chord_len(int pressed_key, int *any_change, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE){
    int help_tmp_1, help_tmp_2;
    if (!KEY_STATE[SDL_SCANCODE_RSHIFT] && !KEY_STATE[SDL_SCANCODE_LSHIFT]) {
        help_tmp_1 = COE->current_C->time;
        if (pressed_key == SDLK_k) {
            COE->current_C->time--;
            if (COE->current_C->time < 0) {
                COE->current_C->time = 0;
            }
        } else {
            COE->current_C->time++;
            if (COE->current_C->time > 5) {
                COE->current_C->time = 5;
            }
        }
        if (help_tmp_1 == COE->current_C->time) {
            *any_change = 0;
        }
    } else {
        help_tmp_1 = COE->current_C->_time_dots_;
        help_tmp_2 = COE->current_C->ssp_articulation;
        if (pressed_key == SDLK_l) {
            if (COE->current_C->_time_dots_ > 0) {
                COE->current_C->_time_dots_--;
            } else {
                if (COE->current_C->ssp_articulation < 3) {
                    COE->current_C->ssp_articulation++;
                }
            }

        } else {
            if (COE->current_C->ssp_articulation > 0) {
                COE->current_C->ssp_articulation--;
            } else {
                if (COE->current_C->_time_dots_ < 5) {
                    COE->current_C->_time_dots_++;
                }
            }
        }
        if (!(help_tmp_1 != COE->current_C->_time_dots_ ||
              help_tmp_2 != COE->current_C->ssp_articulation)) {
            *any_change = 0;
        }
    }
    return 0;
}
int change_hand(struct current_OPUS_edits_ *COE) {

    if (COE->current_hand == 0) {
        COE->current_C = COE->current_B->first_chord_bass;
        COE->current_hand = 1;
        COE->current_note_index = COE->current_C->notes_number - 1;

    } else {
        COE->current_C = COE->current_B->first_chord_treb;
        COE->current_hand = 0;
        COE->current_note_index = COE->current_C->notes_number - 1;
    }
    return 0;
}
int change_note(int pressed_key, struct current_OPUS_edits_ *COE) {
    if (COE->current_C->notes_number > 0) {

        if (pressed_key == SDLK_UP) {
            COE->current_note_index++;
            if (COE->current_note_index >= COE->current_C->notes_number) {
                COE->current_note_index--;
            }
        } else {
            COE->current_note_index--;
            if (COE->current_note_index < 0) {
                COE->current_note_index++;
            }
        }
    } else {
        COE->current_note_index = -1;
    }
    return 0;
}
int change_chord_or_bar(int pressed_key, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE) {

    struct current_OPUS_edits_ COE_HELP;

    if (pressed_key == SDLK_RIGHT) {
        if (!KEY_STATE[SDL_SCANCODE_LSHIFT]) {
            if (COE->current_C->next != NULL) {
                COE->current_C = COE->current_C->next;
            } else if (COE->current_B->next != NULL) {
                COE->current_B = COE->current_B->next;
                if (COE->current_hand == 0) {
                    COE->current_C = COE->current_B->first_chord_treb;
                } else {
                    COE->current_C = COE->current_B->first_chord_bass;
                }

            }
        } else {
            if (COE->current_B->next != NULL) {
                COE->current_B = COE->current_B->next;
                if (COE->current_hand == 0) {
                    COE->current_C = COE->current_B->first_chord_treb;
                } else {
                    COE->current_C = COE->current_B->first_chord_bass;
                }

            } else {
                COE_HELP.current_C = COE->current_C;
                while (COE_HELP.current_C->next != NULL) {
                    COE_HELP.current_C = COE_HELP.current_C->next;
                }
                COE->current_C = COE_HELP.current_C;
            }
        }
    }
    if (pressed_key == SDLK_LEFT) {
        if (!KEY_STATE[SDL_SCANCODE_LSHIFT]) {
            if (COE->current_C->prev != NULL) {
                COE->current_C = COE->current_C->prev;
            } else if (COE->current_B->prev != NULL) {
                COE->current_B = COE->current_B->prev;

                if (COE->current_hand == 0) {
                    COE->current_C = COE->current_B->first_chord_treb;
                } else {
                    COE->current_C = COE->current_B->first_chord_bass;
                }
                COE_HELP.current_C = COE->current_C;
                while (COE_HELP.current_C->next != NULL) {
                    COE_HELP.current_C = COE_HELP.current_C->next;
                }
                COE->current_C = COE_HELP.current_C;
            }
        } else {
            if (COE->current_B->prev != NULL) {
                COE->current_B = COE->current_B->prev;

                if (COE->current_hand == 0) {
                    COE->current_C = COE->current_B->first_chord_treb;
                } else {
                    COE->current_C = COE->current_B->first_chord_bass;
                }
                COE_HELP.current_C = COE->current_C;
                while (COE_HELP.current_C->next != NULL) {
                    COE_HELP.current_C = COE_HELP.current_C->next;
                }
                COE->current_C = COE_HELP.current_C;
            } else {
                if (COE->current_hand == 0) {
                    COE->current_C = COE->current_B->first_chord_treb;
                } else {
                    COE->current_C = COE->current_B->first_chord_bass;
                }
            }
        }
    }

    COE->current_note_index = COE->current_C->notes_number - 1;
    return 0;
}
int put_note_or_pause(int pressed_key, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, const char *serial_key) {

    int help_tmp_1, i;
    if (COE->current_C->notes_number < MAX_NOTES_IN_CHORD) {
        COE->current_C->notes_number++;
        COE->current_note_index = COE->current_C->notes_number - 1;
    }

    help_tmp_1 = -1;
    for (i = SDL_SCANCODE_1; i <= SDL_SCANCODE_7; i++) {
        if (KEY_STATE[i]) {
            help_tmp_1 = i + 1 - SDL_SCANCODE_1;
            break;
        }
    }

    if (help_tmp_1 > -1 || pressed_key == SDLK_p) {
        if (pressed_key != SDLK_p) {
            char name, acci;
            name = (char) (pressed_key - 32);
            COE->current_C->notes_[COE->current_note_index].name = name;
            COE->current_C->notes_[COE->current_note_index].height = help_tmp_1;
            COE->current_C->notes_[COE->current_note_index].may_print_acci = 0;
            switch (name) {
                case 'C':
                    acci = serial_key[0];
                    break;
                case 'D':
                    acci = serial_key[1];
                    break;
                case 'E':
                    acci = serial_key[2];
                    break;
                case 'F':
                    acci = serial_key[3];
                    break;
                case 'G':
                    acci = serial_key[4];
                    break;
                case 'A':
                    acci = serial_key[5];
                    break;
                case 'H':
                    acci = serial_key[6];
                    break;
                default:
                    acci = '\0';
                    break;
            }
            COE->current_C->notes_[COE->current_note_index].acci = acci;
            sort_uniq_notes(COE->current_C);
        } else {
            COE->current_C->notes_[0].name = 'P';
            COE->current_C->notes_[0].acci = 's';            COE->current_C->notes_[0].height = 4;
            COE->current_C->notes_number = 1;
            COE->current_note_index = 0;
        }
    }
    return 0;
}
int del_note_chord_bar(struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, int X_after_key) {

    int i;
    struct current_OPUS_edits_ COE_HELP;

    if (!KEY_STATE[SDL_SCANCODE_LSHIFT] && !KEY_STATE[SDL_SCANCODE_RSHIFT]) {
        if (COE->current_C->notes_number > 0) {
            if (COE->current_note_index == COE->current_C->notes_number - 1) {
                COE->current_C->notes_number--;
                COE->current_note_index--;
            } else {
                for (i = COE->current_note_index; i < COE->current_C->notes_number - 1; i++) {
                    swap_notes(&(COE->current_C->notes_[i]), &(COE->current_C->notes_[i + 1]));
                }
                COE->current_C->notes_number--;
            }
        }
    } else {
        // Usuwanie pojedynczego chord-u
        if (COE->current_C->prev != NULL) {
            COE_HELP.current_C = COE->current_C;
            COE->current_C = COE->current_C->prev;
            COE->current_C->next = COE->current_C->next->next;
            if (COE->current_C->next != NULL) {
                COE->current_C->next->prev = COE->current_C;
            }
            free(COE_HELP.current_C);
            // jeżeli jest pierwszy i nie jest jedyny
        } else if (COE->current_C->next != NULL) {
            COE->current_C = COE->current_C->next;
            free(COE->current_C->prev);
            COE->current_C->prev = NULL;
            if (COE->current_hand == 0) {
                COE->current_B->first_chord_treb = COE->current_C;
            } else {
                COE->current_B->first_chord_bass = COE->current_C;
            }

            // jeśli jest on pierwszym i jedynym chord-em w bar-rze, to jeśli nie jest to jedyny bar
        } else {
            if (COE->current_B->prev != NULL) {
                COE->current_B = COE->current_B->prev;

                COE_HELP.current_B = COE->current_B->next;
                COE->current_B->next = COE->current_B->next->next;
                if (COE->current_B->next != NULL) {
                    COE->current_B->next->prev = COE->current_B;
                }
                free_bar(COE_HELP.current_B);
                if (COE->current_hand == 0) {
                    COE->current_C = COE->current_B->first_chord_treb;
                } else {
                    COE->current_C = COE->current_B->first_chord_bass;
                }

                // Jesli bar jest pierwszy ale nie jest jedyny
            } else if (COE->current_B->next != NULL) {
                COE->current_B = COE->current_B->next;
                COE->current_B->X_of_start_bar = COE->current_B->prev->X_of_start_bar;
                free_bar(COE->current_B->prev);
                COE->current_B->prev = NULL;
                COE->current_O->first_BAR = COE->current_B;
                if (COE->current_hand == 0) {
                    COE->current_C = COE->current_B->first_chord_treb;
                } else {
                    COE->current_C = COE->current_B->first_chord_bass;
                }
            }
        }
        COE->current_note_index = COE->current_C->notes_number - 1;
    }
    change_bar_width(0, NULL, COE, NULL, X_after_key);
    return 0;
}
int create_new_chord_bar(struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, int X_after_key, const char *default_serial_key) {

    int brace_help, X_st_help, width_help;
    if (!KEY_STATE[SDL_SCANCODE_LSHIFT] && !KEY_STATE[SDL_SCANCODE_RSHIFT]) {
        if (COE->current_C->next == NULL) {
            COE->current_C->next = malloc_new_chord(COE->current_C, NULL,
                                                    COE->current_C->X_position + WIDTH_NOTES_WITH_FLAGS, COE->current_C->local_serial_key);
        } else {
            COE->current_C->next = malloc_new_chord(COE->current_C, COE->current_C->next,
                                                    COE->current_C->X_position + WIDTH_NOTES_WITH_FLAGS, COE->current_C->local_serial_key);
            COE->current_C->next->prev = COE->current_C;
            COE->current_C->next->next->prev = COE->current_C->next;
        }
        COE->current_C = COE->current_C->next;
        COE->current_note_index = -1;
    } else {

        brace_help = COE->current_B->brace;
        X_st_help = COE->current_B->X_of_start_bar + COE->current_B->width_ + 2;
        width_help = __min(X_END_OF_STAVE - (COE->current_B->X_of_start_bar + COE->current_B->width_),
                           DEFAULT_BAR_WIDTH);
        if (width_help < MIN_BAR_WIDTH) {
            brace_help++;
            width_help = DEFAULT_BAR_WIDTH;
            X_st_help = X_after_key;
        }

        COE->current_B->next = malloc_new_bar(COE->current_B, COE->current_B->next, X_st_help, width_help, brace_help,
                                              default_serial_key, default_serial_key);
        COE->current_B = COE->current_B->next;
        if (COE->current_B->next != NULL) {
            COE->current_B->next->prev = COE->current_B;
        }
        if (COE->current_hand == 0) {
            COE->current_C = COE->current_B->first_chord_treb;
        } else {
            COE->current_C = COE->current_B->first_chord_bass;
        }
    }

    COE->current_note_index = -1;
    change_bar_width(0, NULL, COE, NULL, X_after_key);

    return 0;
}
int put_acci(int pressed_key, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, const char *default_serial_key) {


    if (pressed_key == SDLK_x) {
        COE->current_C->notes_[COE->current_note_index].may_print_acci += 1;
        COE->current_C->notes_[COE->current_note_index].may_print_acci %= 2;
    } else if (COE->current_C->notes_[COE->current_note_index].name != 'p') {
        int i = 0;
        COE->current_C->notes_[COE->current_note_index].acci = (char) pressed_key;
        sort_uniq_notes(COE->current_C);
        switch (COE->current_C->notes_[COE->current_note_index].name) {
            case 'C':
                i = 0;
                break;
            case 'D':
                i = 1;
                break;
            case 'E':
                i = 2;
                break;
            case 'F':
                i = 3;
                break;
            case 'G':
                i = 4;
                break;
            case 'A':
                i = 5;
                break;
            case 'H':
                i = 6;
                break;
            default:
                break;
        }
        COE->current_C->local_serial_key[i] = (char) pressed_key;
        CHORD *help_chord = COE->current_C->next;
        while (help_chord != NULL) {

            if (help_chord->local_serial_key[i] == default_serial_key[i]) {
                help_chord->local_serial_key[i] = help_chord->prev->local_serial_key[i];
            } else {
                break;
            }
            help_chord = help_chord->next;
        }
    }

    return 0;
}
