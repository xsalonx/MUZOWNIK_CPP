//
// Created by Luksz on 2021-06-12.
//

#include "putting.h"

int put_chord_on_treb_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start,
                                   int brace, const char serial_key[7], BARS_SPACE *b_space, struct current_OPUS_edits_ *COE) {

    int k, i, any_put = 0, j;
    int hand = 0;
    SDL_Rect blank_stave_rect;
    SDL_Rect line_rect;
    SDL_Rect insert_note_rect;
    SDL_Rect acci_rect;
    SDL_Rect dots_rect;

    blank_stave_rect.x = *X_start - WIDTH_NOTES_WITH_FLAGS / 2;
    blank_stave_rect.y = Y_FIRST_LINE + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                         brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES - 3 * DISTANCE_BETWEEN_LINES;
    blank_stave_rect.w = WIDTH_NOTES_WITH_FLAGS * 2;
    blank_stave_rect.h = DISTANCE_BETWEEN_LINES * 8;

    line_rect.w = WIDTH_NOTES_WITHOUT_FLAG * 2;
    line_rect.h = 1;
    line_rect.x = *X_start - WIDTH_NOTES_WITHOUT_FLAG / 2;

    insert_note_rect.x = *X_start;
    insert_note_rect.y = 0;

    acci_rect.x = *X_start - DISTANCE_BETWEEN_ACCI_AND_NOTE;

    SDL_Surface *note_without_flag = NULL;
    SDL_Surface *note_with_flag = NULL;
    SDL_Surface *note_to_put = NULL;
    SDL_Surface *sign_note_without_flag = NULL;
    SDL_Surface *sign_note_with_flag = NULL;

    SDL_Surface *acci_b = SDL_LoadBMP("obrazki/accidental/acci_b.bmp");
    SDL_Surface *acci_s = SDL_LoadBMP("obrazki/accidental/acci_s.bmp");
    SDL_Surface *acci_n = SDL_LoadBMP("obrazki/accidental/acci_n.bmp");
    SDL_Surface *acci_to_put = NULL;

    SDL_Surface *time_dot = SDL_LoadBMP("obrazki/notes/time_dot.bmp");

    //SDL_BlitSurface(blank_stave, &blank_stave_rect, stave, &blank_stave_rect);


    char path[28] = "obrazki/notes/note_00.bmp";
    int prefix_len = 19;
    path[prefix_len] = (char) (chord_to_put->time + 48);
    if (chord_to_put->time == 0) {
        path[prefix_len + 1] = 'n';
    } else {
        int lower_note_index = get_note_index(&chord_to_put->notes_[0]);
        int treb_sec_D_index = D_note + 5 * 12;

        if (lower_note_index >= treb_sec_D_index) {
            path[prefix_len + 1] = 'd';
        } else {
            path[prefix_len + 1] = 'u';
        }
    }


    if (chord_to_put->time <= 2) {
        note_without_flag = SDL_LoadBMP(path);
        note_with_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE->current_C){
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    } else {
        note_with_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE->current_C){
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            path[prefix_len - 2] = 'e';
        }
        path[prefix_len] = '2';
        note_without_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE->current_C){
            path[prefix_len - 2] = 'b';
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    }
    SDL_SetColorKey(acci_b, SDL_TRUE, SDL_MapRGB(acci_b->format, 255, 255, 255));
    SDL_SetColorKey(acci_n, SDL_TRUE, SDL_MapRGB(acci_n->format, 255, 255, 255));
    SDL_SetColorKey(acci_s, SDL_TRUE, SDL_MapRGB(acci_s->format, 255, 255, 255));
    SDL_SetColorKey(note_with_flag, SDL_TRUE, SDL_MapRGB(note_with_flag->format, 255, 255, 255));
    SDL_SetColorKey(note_without_flag, SDL_TRUE, SDL_MapRGB(note_without_flag->format, 255, 255, 255));
    if (chord_to_put == COE->current_C) {
        SDL_SetColorKey(sign_note_with_flag, SDL_TRUE, SDL_MapRGB(sign_note_with_flag->format, 255, 255, 255));
        SDL_SetColorKey(sign_note_without_flag, SDL_TRUE, SDL_MapRGB(sign_note_without_flag->format, 255, 255, 255));
    }
    SDL_SetColorKey(time_dot, SDL_TRUE, SDL_MapRGB(time_dot->format, 255, 255, 255));


    for (i = 0; i < chord_to_put->notes_number; i++) {

        if (path[prefix_len + 1] == 'u' || path[prefix_len + 1] == 'n') k = i;
        else k = chord_to_put->notes_number - 1 - i;
        note_to_put = note_without_flag;
        if (i == chord_to_put->notes_number - 1) note_to_put = note_with_flag;

        if (chord_to_put == COE->current_C && i == COE->current_note_index){
            note_to_put = sign_note_without_flag;
            if (i == chord_to_put->notes_number - 1) note_to_put = sign_note_with_flag;

        }


        switch (chord_to_put->notes_[k].name) {
            case 'C':
                if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);
                } else if (chord_to_put->notes_[k].height == 5) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 1 -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 6) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 1;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'D':
                if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 4 -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 5) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 6) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 3 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 1;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'E':
                if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 4 -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 5) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 6) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 3 -
                            Y_OF_ON_LINE_NOTES;
                    SDL_BlitSurface(note_to_put, NULL, stave, &insert_note_rect);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 1;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 3;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'F':
                if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 3 -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 5) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 6) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 4 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    SDL_BlitSurface(note_to_put, NULL, stave, &insert_note_rect);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 1;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 3;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'G':
                if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6;
                    SDL_FillRect(stave, &line_rect, 0x00);
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 3 -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 5) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES -
                            Y_OF_BETWEEN_LINE_NOTES;
                }
/////                    if (chord_to_put->notes_[k].height == 6)...
                break;
            case 'A':
                if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6;
                    SDL_FillRect(stave, &line_rect, 0x00);
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_BETWEEN_LINE_NOTES;

                } else if (chord_to_put->notes_[k].height == 5) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 1;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
/////                    if (chord_to_put->notes_[k].height == 6) {

                break;
            case 'H':
                if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 5) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 1;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
/////                    if (chord_to_put->notes_[k].height == 6)...
                break;
            default:
                break;
        }
        ///// Kropki przedłużające nute
        if (chord_to_put->_time_dots_){
            dots_rect.y = insert_note_rect.y;
            dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG;
            for (j = 0; j < chord_to_put->_time_dots_; j++){
                SDL_BlitSurface(time_dot, NULL, stave, &dots_rect);
                dots_rect.x += time_dot->w;
            }
        }
        ///// Znaki artykulacji
        if (chord_to_put->ssp_articulation) {

            if (chord_to_put->ssp_articulation == 1) {
                if (path[prefix_len + 1] == 'u' && k == 0) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y + 15;
                    SDL_BlitSurface(time_dot, NULL, stave, &dots_rect);
                }  else if (path[prefix_len + 1] == 'd' && k == chord_to_put->notes_number - 1) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y - 15;
                    SDL_BlitSurface(time_dot, NULL, stave, &dots_rect);
                }
            }
        }

        if (insert_note_rect.y != 0) {
            SDL_BlitSurface(note_to_put, NULL, stave, &insert_note_rect);
            any_put = 1;
            if (is_acci_req(chord_to_put, k, COE->current_O->default_serial_key) || chord_to_put->notes_[k].may_print_acci) {
                acci_rect.y = insert_note_rect.y + Y_OF_ACCI_S_ON_LINE + 10;
                switch (chord_to_put->notes_[i].acci) {
                    case 's':
                        acci_to_put = acci_s;
                        break;
                    case 'b':
                        acci_to_put = acci_b;
                        break;
                    case 'n':
                        acci_to_put = acci_n;
                        break;
                    default:
                        break;
                }

                if (chord_to_put->notes_[i].acci == 'b') {
                    acci_rect.y -= DISTANCE_BETWEEN_LINES / 2;
                }

                SDL_BlitSurface(acci_to_put, NULL, stave, &acci_rect);
            }
        }
    }
    if (!any_put) {
        insert_note_rect.y = Y_FIRST_LINE + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES;
        insert_note_rect.h = 4 * DISTANCE_BETWEEN_LINES;
        insert_note_rect.w = WIDTH_NOTES_WITHOUT_FLAG;
        if (chord_to_put == COE->current_C){
            SDL_FillRect(stave, &insert_note_rect, 0x0f);

        } else {
            SDL_FillRect(stave, &insert_note_rect, 0x05);
        }
    }

    chord_to_put->X_position = *X_start;
    *X_start += b_space->widths_ni_[chord_to_put->time][chord_to_put->_time_dots_];



//    SDL_FreeSurface(note_without_flag);
//    SDL_FreeSurface(note_with_flag);
//    SDL_FreeSurface(note_to_put);
//    SDL_FreeSurface(acci_b);
//    SDL_FreeSurface(acci_s);
//    SDL_FreeSurface(acci_n);
//    SDL_FreeSurface(acci_to_put);



    return 0;
}
int put_chord_on_bass_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start,
                                   int brace, const char serial_key[7], BARS_SPACE *b_space, struct current_OPUS_edits_ *COE) {

    int k, i, any_put = 0, j;
    int hand = 1;
    SDL_Rect blank_stave_rect;
    SDL_Rect line_rect;
    SDL_Rect insert_note_rect;
    SDL_Rect acci_rect;
    SDL_Rect dots_rect;

    blank_stave_rect.x = *X_start - WIDTH_NOTES_WITH_FLAGS / 2;
    blank_stave_rect.y = Y_FIRST_LINE + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                         brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES - 3 * DISTANCE_BETWEEN_LINES;
    blank_stave_rect.w = WIDTH_NOTES_WITH_FLAGS * 2;
    blank_stave_rect.h = DISTANCE_BETWEEN_LINES * 8;

    line_rect.w = WIDTH_NOTES_WITHOUT_FLAG * 2;
    line_rect.h = 1;
    line_rect.x = *X_start - WIDTH_NOTES_WITHOUT_FLAG / 2;

    insert_note_rect.x = *X_start;
    insert_note_rect.y = 0;

    acci_rect.x = *X_start - DISTANCE_BETWEEN_ACCI_AND_NOTE;

    SDL_Surface *note_without_flag = NULL;
    SDL_Surface *note_with_flag = NULL;
    SDL_Surface *note_to_put = NULL;
    SDL_Surface *sign_note_without_flag = NULL;
    SDL_Surface *sign_note_with_flag = NULL;

    SDL_Surface *acci_b = SDL_LoadBMP("obrazki/accidental/acci_b.bmp");
    SDL_Surface *acci_s = SDL_LoadBMP("obrazki/accidental/acci_s.bmp");
    SDL_Surface *acci_n = SDL_LoadBMP("obrazki/accidental/acci_n.bmp");
    SDL_Surface *acci_to_put = NULL;

    SDL_Surface *time_dot = SDL_LoadBMP("obrazki/notes/time_dot.bmp");

    //SDL_BlitSurface(blank_stave, &blank_stave_rect, stave, &blank_stave_rect);

    char path[28] = "obrazki/notes/note_00.bmp";
    int prefix_len = 19;
    path[prefix_len] = (char) (chord_to_put->time + 48);
    if (chord_to_put->time == 0) {
        path[prefix_len + 1] = 'n';
    } else {
        int lower_note_index = get_note_index(&chord_to_put->notes_[0]);
        int treb_sec_D_index = H_note + 3 * 12;

        if (lower_note_index >= treb_sec_D_index) {
            path[prefix_len + 1] = 'd';
        } else {
            path[prefix_len + 1] = 'u';
        }
    }


    if (chord_to_put->time <= 2) {
        note_without_flag = SDL_LoadBMP(path);
        note_with_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE->current_C) {
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    } else {
        note_with_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE->current_C) {
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            path[prefix_len - 2] = 'e';
        }
        path[prefix_len] = '2';
        note_without_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE->current_C) {
            path[prefix_len - 2] = 'b';
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    }

    SDL_SetColorKey(acci_b, SDL_TRUE, SDL_MapRGB(acci_b->format, 255, 255, 255));
    SDL_SetColorKey(acci_n, SDL_TRUE, SDL_MapRGB(acci_n->format, 255, 255, 255));
    SDL_SetColorKey(acci_s, SDL_TRUE, SDL_MapRGB(acci_s->format, 255, 255, 255));
    SDL_SetColorKey(note_with_flag, SDL_TRUE, SDL_MapRGB(note_with_flag->format, 255, 255, 255));
    SDL_SetColorKey(note_without_flag, SDL_TRUE, SDL_MapRGB(note_without_flag->format, 255, 255, 255));
    if (chord_to_put == COE->current_C) {
        SDL_SetColorKey(sign_note_with_flag, SDL_TRUE, SDL_MapRGB(sign_note_with_flag->format, 255, 255, 255));
        SDL_SetColorKey(sign_note_without_flag, SDL_TRUE, SDL_MapRGB(sign_note_without_flag->format, 255, 255, 255));
    }
    SDL_SetColorKey(time_dot, SDL_TRUE, SDL_MapRGB(time_dot->format, 255, 255, 255));



    for (i = 0; i < chord_to_put->notes_number; i++) {
        if (path[prefix_len + 1] == 'u' || path[prefix_len + 1] == 'n') k = i;
        else k = chord_to_put->notes_number - 1 - i;
        note_to_put = note_without_flag;
        if (i == chord_to_put->notes_number - 1) note_to_put = note_with_flag;

        if (chord_to_put == COE->current_C && i == COE->current_note_index) {
            note_to_put = sign_note_without_flag;
            if (i == chord_to_put->notes_number - 1) note_to_put = sign_note_with_flag;

        }


        switch (chord_to_put->notes_[k].name) {
            case 'C':
                if (chord_to_put->notes_[k].height == 2) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);

                } else if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'D':
                if (chord_to_put->notes_[k].height == 2) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);

                } else if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'E':
                if (chord_to_put->notes_[k].height == 2) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);

                } else if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 1 -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'F':
                if (chord_to_put->notes_[k].height == 1) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 8 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 8;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 7;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);

                } else if (chord_to_put->notes_[k].height == 2) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 4 -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 1 -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 3 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'G':
                if (chord_to_put->notes_[k].height == 1) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 7 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 7;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);
                } else if (chord_to_put->notes_[k].height == 2) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 4 -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 4) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 4 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 2;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES * 3;
                    SDL_FillRect(stave, &line_rect, 0x00);
                }
                break;
            case 'A':
                if (chord_to_put->notes_[k].height == 1) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 7 -
                            Y_OF_ON_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 7;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);
                } else if (chord_to_put->notes_[k].height == 2) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 3 -
                            Y_OF_BETWEEN_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace -
                            Y_OF_ON_LINE_NOTES;
                }
                break;
            case 'H':
                if (chord_to_put->notes_[k].height == 1) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6 -
                            Y_OF_BETWEEN_LINE_NOTES;
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 6;
                    SDL_FillRect(stave, &line_rect, 0x00);
                    line_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 5;
                    SDL_FillRect(stave, &line_rect, 0x00);
                } else if (chord_to_put->notes_[k].height == 2) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace + DISTANCE_BETWEEN_LINES * 3 -
                            Y_OF_ON_LINE_NOTES;
                } else if (chord_to_put->notes_[k].height == 3) {
                    insert_note_rect.y =
                            Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                            DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace - DISTANCE_BETWEEN_LINES -
                            Y_OF_BETWEEN_LINE_NOTES;
                }
                break;
            default:
                break;
        }

        ///// Kropki przedłużające nute
        if (chord_to_put->_time_dots_) {
            dots_rect.y = insert_note_rect.y;
            dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG;
            for (j = 0; j < chord_to_put->_time_dots_; j++) {
                SDL_BlitSurface(time_dot, NULL, stave, &dots_rect);
                dots_rect.x += time_dot->w;
            }
        }
        ///// Znaki artykulacji
        if (chord_to_put->ssp_articulation) {

            if (chord_to_put->ssp_articulation == 1) {
                if (path[prefix_len + 1] == 'u' && k == 0) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y + 15;
                    SDL_BlitSurface(time_dot, NULL, stave, &dots_rect);
                }  else if (path[prefix_len + 1] == 'd' && k == chord_to_put->notes_number - 1) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y - 15;
                    SDL_BlitSurface(time_dot, NULL, stave, &dots_rect);
                }
            }
        }

        if (insert_note_rect.y != 0) {
            SDL_BlitSurface(note_to_put, NULL, stave, &insert_note_rect);
            any_put = 1;
            ////// Znaki chromatyczne
            if (is_acci_req(chord_to_put, k, COE->current_O->default_serial_key) || chord_to_put->notes_[k].may_print_acci) {
                acci_rect.y = insert_note_rect.y + Y_OF_ACCI_S_ON_LINE + 10;
                switch (chord_to_put->notes_[i].acci) {
                    case 's':
                        acci_to_put = acci_s;
                        break;
                    case 'b':
                        acci_to_put = acci_b;
                        acci_rect.y -= DISTANCE_BETWEEN_LINES / 2;
                        break;
                    case 'n':
                        acci_to_put = acci_n;
                        break;
                    default:
                        break;
                }

                SDL_BlitSurface(acci_to_put, NULL, stave, &acci_rect);
            }
        }
    }

    ///// Jescze się przyda funkcja odległości od (CHORDS->time)

    if (!any_put) {
        insert_note_rect.y = Y_FIRST_LINE + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES;
        insert_note_rect.h = 4 * DISTANCE_BETWEEN_LINES;
        insert_note_rect.w = WIDTH_NOTES_WITHOUT_FLAG;
        if (chord_to_put == COE->current_C){
            SDL_FillRect(stave, &insert_note_rect, 0x0f);

        } else {
            SDL_FillRect(stave, &insert_note_rect, 0x05);
        }
    }

    chord_to_put->X_position = *X_start;
    *X_start += b_space->widths_ni_[chord_to_put->time][chord_to_put->_time_dots_];


//    SDL_FreeSurface(note_without_flag);
//    SDL_FreeSurface(note_with_flag);
//    SDL_FreeSurface(note_to_put);
//    SDL_FreeSurface(acci_b);
//    SDL_FreeSurface(acci_s);
//    SDL_FreeSurface(acci_n);
//    SDL_FreeSurface(acci_to_put);

    return 0;
}
int put_pause_on_stave_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start,
                                    int brace, int hand, BARS_SPACE *b_space, struct current_OPUS_edits_ *COE){


    SDL_Rect blank_stave_rect;

    blank_stave_rect.x = *X_start - WIDTH_NOTES_WITH_FLAGS / 2;
    blank_stave_rect.y = Y_FIRST_LINE + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                         brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES - 3 * DISTANCE_BETWEEN_LINES;
    blank_stave_rect.w = WIDTH_NOTES_WITH_FLAGS * 2;
    blank_stave_rect.h = DISTANCE_BETWEEN_LINES * 8;
    //SDL_BlitSurface(blank_stave, &blank_stave_rect, stave, &blank_stave_rect);

    SDL_Rect pause_rect;
    pause_rect.x = *X_start;
    pause_rect.y = Y_FIRST_LINE + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES;
    SDL_Surface *pause = NULL;
    char path[26] = "obrazki/notes/paus_0n.bmp";
    int prefix_len = 19;
    path[prefix_len] = (char)(chord_to_put->time + 48);

    if (chord_to_put == COE->current_C){
        path[prefix_len - 2] = 'b';
    }

    pause = SDL_LoadBMP(path);

    SDL_BlitSurface(pause, NULL, stave, &pause_rect);

    chord_to_put->X_position = *X_start;
    *X_start += b_space->widths_ni_[chord_to_put->time][chord_to_put->_time_dots_];

    SDL_FreeSurface(pause);
    return 0;
}
int put_chord_on_stave_without_beam(CHORD *chord_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int *X_start,
                                    int hand, int brace, const char *serial_key, BARS_SPACE *b_space, struct current_OPUS_edits_ *COE) {

    if (chord_to_put->notes_[0].name == 'P') {
        put_pause_on_stave_without_beam(chord_to_put, stave, blank_stave, X_start, brace, hand, b_space, COE);
    } else {

        if (hand == 0) {
            put_chord_on_treb_without_beam(chord_to_put, stave, blank_stave, X_start, brace, serial_key, b_space, COE);
        } else {
            put_chord_on_bass_without_beam(chord_to_put, stave, blank_stave, X_start, brace, serial_key, b_space, COE);
        }
    }
    return 0;
}


int put_bar_on_stave(BAR *bar_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, int hand, int brace,
                     const char serial_key[7], const int chosen_metre[2],
                     struct current_OPUS_edits_ *COE) {

    int X_start = bar_to_put->X_of_start_bar;
    int i, j, may_edit_whole_bar = 0, was_chord_deleted = 0;
    int X_start_hands[2];
    X_start_hands[0] = X_start + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE;
    X_start_hands[1] = X_start + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE;


    SDL_Rect start_bar_rect;
    start_bar_rect.x = X_start + bar_to_put->width_;
    start_bar_rect.y = Y_FIRST_LINE + DISTANCE_BETWEEN_FIRST_LINE_BRACES * brace;
    start_bar_rect.w = WIDTH_BAR_LINE;
    start_bar_rect.h = DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES + 4 * DISTANCE_BETWEEN_LINES;

    SDL_Rect whole_bar_rect;
    whole_bar_rect.x = X_start;
    whole_bar_rect.y = Y_FIRST_LINE + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES - 4 * DISTANCE_BETWEEN_LINES;
    whole_bar_rect.w = bar_to_put->width_ + STEP_IN_BAR_WIDTH_CHANGING_WITH_SHIFT + WIDTH_BAR_LINE;
    whole_bar_rect.h =
            DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES + 4 * DISTANCE_BETWEEN_LINES + 11 * DISTANCE_BETWEEN_LINES;

    SDL_Rect treb_bar_rect;
    treb_bar_rect.x = X_start;
    treb_bar_rect.y = Y_FIRST_LINE + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES - 4 * DISTANCE_BETWEEN_LINES;
    treb_bar_rect.w = bar_to_put->width_ + STEP_IN_BAR_WIDTH_CHANGING_WITH_SHIFT + WIDTH_BAR_LINE;
    treb_bar_rect.h = 4 * DISTANCE_BETWEEN_LINES + 11 * DISTANCE_BETWEEN_LINES;

    SDL_Rect bass_bar_rect;
    bass_bar_rect.x = X_start;
    bass_bar_rect.y =
            Y_FIRST_LINE + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES + DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES -
            4 * DISTANCE_BETWEEN_LINES;
    bass_bar_rect.w = bar_to_put->width_ + STEP_IN_BAR_WIDTH_CHANGING_WITH_SHIFT + WIDTH_BAR_LINE;
    bass_bar_rect.h = 4 * DISTANCE_BETWEEN_LINES + 12 * DISTANCE_BETWEEN_LINES;


    CHORD *help_chord = NULL;
    double chords_periods[6][6], max_metre_sum, metre_sum = 0;
    max_metre_sum = (double) chosen_metre[0] / (double) chosen_metre[1];
    chords_periods[0][0] = 1;
    for (i = 1; i < 6; i++) {
        chords_periods[i][0] = chords_periods[i - 1][0] / 2;
        for (j = 1; j < 6; j++) {
            chords_periods[i][j] = chords_periods[i][0] * (2 - pow(2, -(double)j));
        }
    }
    //////Trzeba usunąć nadmiarowe chord-y dla treb
    help_chord = bar_to_put->first_chord_treb;


    while (help_chord != NULL) {
        metre_sum += chords_periods[help_chord->time][help_chord->_time_dots_];
        help_chord = help_chord->next;
    }

    while (metre_sum > max_metre_sum) {
        was_chord_deleted = 1;
        help_chord = bar_to_put->first_chord_treb;
        while (help_chord->next != NULL) {
            help_chord = help_chord->next;
        }
        if (help_chord->prev != NULL) {
            help_chord->prev->next = NULL;
            free(help_chord);
        } else {
            help_chord->time++;
        }

        help_chord = bar_to_put->first_chord_treb;
        metre_sum = 0;
        while (help_chord != NULL) {
            metre_sum += chords_periods[help_chord->time][help_chord->_time_dots_];
            help_chord = help_chord->next;
        }
    }


    //////Trzeba usunąć nadmiarowe chord-y dla bass
    metre_sum = 0;
    help_chord = bar_to_put->first_chord_bass;

    while (help_chord != NULL) {
        metre_sum += chords_periods[help_chord->time][help_chord->_time_dots_];
        help_chord = help_chord->next;
    }

    while (metre_sum > max_metre_sum) {
        was_chord_deleted = 1;
        help_chord = bar_to_put->first_chord_bass;
        while (help_chord->next != NULL) {
            help_chord = help_chord->next;
        }

        if (help_chord->prev != NULL) {
            help_chord->prev->next = NULL;
            free(help_chord);
        } else {
            help_chord->time++;
        }

        help_chord = bar_to_put->first_chord_bass;
        metre_sum = 0;
        while (help_chord != NULL) {
            metre_sum += chords_periods[help_chord->time][help_chord->_time_dots_];
            help_chord = help_chord->next;
        }
    }
    if (was_chord_deleted) {
        if (COE->current_hand == 0) {
            help_chord = bar_to_put->first_chord_treb;
            while (help_chord->next != NULL) {
                help_chord = help_chord->next;
            }
            COE->current_C = help_chord;
        } else {
            help_chord = bar_to_put->first_chord_bass;
            while (help_chord->next != NULL) {
                help_chord = help_chord->next;
            }
            COE->current_C = help_chord;
        }
        COE->current_note_index = COE->current_C->notes_number - 1;
    }

    //////////////////////////////
    BARS_SPACE b_space;

    get_space_for_chord(bar_to_put, &b_space, chosen_metre);

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (bar_to_put->b_space.widths_ni_[i][j] != b_space.widths_ni_[i][j]) {
                bar_to_put->b_space.widths_ni_[i][j] = b_space.widths_ni_[i][j];
                may_edit_whole_bar = 1;
            }
        }
    }

    if (may_edit_whole_bar || hand == 2) {
        SDL_BlitSurface(blank_stave, &whole_bar_rect, stave, &whole_bar_rect);
    } else {
        if (hand == 0) {
            SDL_BlitSurface(blank_stave, &treb_bar_rect, stave, &treb_bar_rect);
        } else if (hand == 1) {
            SDL_BlitSurface(blank_stave, &bass_bar_rect, stave, &bass_bar_rect);
        }
    }
    SDL_FillRect(stave, &start_bar_rect, 0x00);

    ///Odkładanie chord-ów
    if (may_edit_whole_bar || hand == 2) {
        help_chord = bar_to_put->first_chord_treb;
        while (help_chord != NULL) {
            put_chord_on_stave_without_beam(help_chord, stave, blank_stave, &X_start_hands[0], 0, brace, serial_key,
                                            &b_space, COE);
            help_chord = help_chord->next;
        }
        help_chord = bar_to_put->first_chord_bass;
        while (help_chord != NULL) {
            put_chord_on_stave_without_beam(help_chord, stave, blank_stave, &X_start_hands[1], 1, brace, serial_key,
                                            &b_space, COE);
            help_chord = help_chord->next;
        }
    } else {
        if (hand == 0) {
            help_chord = bar_to_put->first_chord_treb;
            while (help_chord != NULL) {
                put_chord_on_stave_without_beam(help_chord, stave, blank_stave, &X_start_hands[0], 0, brace, serial_key,
                                                &b_space, COE);
                help_chord = help_chord->next;
            }
        } else if (hand == 1) {
            help_chord = bar_to_put->first_chord_bass;
            while (help_chord != NULL) {
                put_chord_on_stave_without_beam(help_chord, stave, blank_stave, &X_start_hands[1], 1, brace, serial_key,
                                                &b_space, COE);
                help_chord = help_chord->next;
            }
        }
    }


    return 0;
}
int put_all_bars_on_stave(BAR *first_bar_to_put, SDL_Surface *stave, SDL_Surface *blank_stave, const char serial_key[7],
                          const int chosen_metre[2],
                          struct current_OPUS_edits_ *COE){
    SDL_BlitSurface(blank_stave, NULL, stave, NULL);

    while (first_bar_to_put != NULL){
        put_bar_on_stave(first_bar_to_put, stave, blank_stave, 2, first_bar_to_put->brace, serial_key, chosen_metre, COE);
        first_bar_to_put = first_bar_to_put->next;
    }
    return 0;
}

