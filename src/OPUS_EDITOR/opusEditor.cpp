#include "opusEditor.h"
#include <iostream>
using namespace std;

int pow(int a, int b) {
    if (a != 0 && b == 0) return 1;
    int A = a;
    for (int i=0; i<b; i++) {
        A *= a;
    }
    return A;
}



////ONT_STAVE_PUTTING
//init_putting
int OpusEditor::get_path_to_key_bmp(const char chosen_key[2], char path_to_key_bmp[], int path_prefix_len, int hand) const {

    if (hand == 0) path_to_key_bmp[path_prefix_len] = 't';
    else path_to_key_bmp[path_prefix_len] = 'b';

    /*
     * For sharp keys
     */
    // G dur, a moll
    if ((chosen_key[0] == 'G' && chosen_key[1] == '\0') || (chosen_key[0] == 'e' && chosen_key[1] == '\0')) {
        path_to_key_bmp[path_prefix_len + 1] = '1';
        path_to_key_bmp[path_prefix_len + 2] = 's';
        return 0;
    }
    // D dur, h moll
    if ((chosen_key[0] == 'D' && chosen_key[1] == '\0') || (chosen_key[0] == 'h' && chosen_key[1] == '\0')) {
        path_to_key_bmp[path_prefix_len + 1] = '2';
        path_to_key_bmp[path_prefix_len + 2] = 's';
        return 0;
    }
    // A dur, fis moll
    if ((chosen_key[0] == 'A' && chosen_key[1] == '\0') || (chosen_key[0] == 'f' && chosen_key[1] == 'i')) {
        path_to_key_bmp[path_prefix_len + 1] = '3';
        path_to_key_bmp[path_prefix_len + 2] = 's';
        return 0;
    }
    // E dur, cis moll
    if ((chosen_key[0] == 'E' && chosen_key[1] == '\0') || (chosen_key[0] == 'c' && chosen_key[1] == 'i')) {
        path_to_key_bmp[path_prefix_len + 1] = '4';
        path_to_key_bmp[path_prefix_len + 2] = 's';
        return 0;
    }
    // H dur, gis moll
    if ((chosen_key[0] == 'H' && chosen_key[1] == '\0') || (chosen_key[0] == 'g' && chosen_key[1] == 'i')) {
        path_to_key_bmp[path_prefix_len + 1] = '5';
        path_to_key_bmp[path_prefix_len + 2] = 's';
        return 0;
    }
    // Fis dur, dis moll
    if ((chosen_key[0] == 'F' && chosen_key[1] == 'i') || (chosen_key[0] == 'd' && chosen_key[1] == 'i')) {
        path_to_key_bmp[path_prefix_len + 1] = '6';
        path_to_key_bmp[path_prefix_len + 2] = 's';
        return 0;
    }
    // Cis dur, ais moll
    if ((chosen_key[0] == 'C' && chosen_key[1] == 'i') || (chosen_key[0] == 'a' && chosen_key[1] == 'i')) {
        path_to_key_bmp[path_prefix_len + 1] = '7';
        path_to_key_bmp[path_prefix_len + 2] = 's';
        return 0;
    }
    //  C dur, a moll
    if ((chosen_key[0] == 'C' && chosen_key[1] == '\0') || (chosen_key[0] == 'a' && chosen_key[1] == '\0')) {
        return 0;
    }

    /*
     *For bmol keys
     */

    // F dur, d moll
    if ((chosen_key[0] == 'F' && chosen_key[1] == '\0') || (chosen_key[0] == 'd' && chosen_key[1] == '\0')) {
        path_to_key_bmp[path_prefix_len + 1] = '1';
        path_to_key_bmp[path_prefix_len + 2] = 'b';
        return 0;
    }
    // B dur, g moll
    if ((chosen_key[0] == 'B' && chosen_key[1] == '\0') || (chosen_key[0] == 'g' && chosen_key[1] == '\0')) {
        path_to_key_bmp[path_prefix_len + 1] = '2';
        path_to_key_bmp[path_prefix_len + 2] = 'b';
        return 0;
    }
    // Es dur, c moll
    if ((chosen_key[0] == 'E' && chosen_key[1] == 's') || (chosen_key[0] == 'c' && chosen_key[1] == '\0')) {
        path_to_key_bmp[path_prefix_len + 1] = '3';
        path_to_key_bmp[path_prefix_len + 2] = 'b';
        return 0;
    }
    // As dur, f moll
    if ((chosen_key[0] == 'A' && chosen_key[1] == 's') || (chosen_key[0] == 'f' && chosen_key[1] == '\0')) {
        path_to_key_bmp[path_prefix_len + 1] = '4';
        path_to_key_bmp[path_prefix_len + 2] = 'b';
        return 0;
    }
    // Des dur, b moll
    if ((chosen_key[0] == 'D' && chosen_key[1] == 'e') || (chosen_key[0] == 'b' && chosen_key[1] == '\0')) {
        path_to_key_bmp[path_prefix_len + 1] = '5';
        path_to_key_bmp[path_prefix_len + 2] = 'b';
        return 0;
    }
    // Ges dur, es moll
    if ((chosen_key[0] == 'G' && chosen_key[1] == 'e') || (chosen_key[0] == 'e' && chosen_key[1] == 's')) {
        path_to_key_bmp[path_prefix_len + 1] = '6';
        path_to_key_bmp[path_prefix_len + 2] = 'b';
        return 0;
    }
    // Ces dur, as moll
    if ((chosen_key[0] == 'C' && chosen_key[1] == 'e') || (chosen_key[0] == 'a' && chosen_key[1] == 's')) {
        path_to_key_bmp[path_prefix_len + 1] = '7';
        path_to_key_bmp[path_prefix_len + 2] = 'b';
        return 0;
    }

    return 1;
}
int OpusEditor::get_path_to_metre_bmp(const int chosen_metre[2], char path_to_metre_bmp[], int path_prefix_len) {

    for (int i=0; i<2; i++) {
        if (chosen_metre[i] < 10) {
            path_to_metre_bmp[path_prefix_len + i] = (char) (chosen_metre[i] + 48);
        } else {
            path_to_metre_bmp[path_prefix_len + i] = (char) ((int) ('g') + chosen_metre[i] - 16);
        }
    }
    return 0;
}

int OpusEditor::put_key(const char *chosen_key, int *X_star_on_line) {

    if (current_OPUS != nullptr) {
        current_OPUS->key[0] = chosen_key[0];
        current_OPUS->key[1] = chosen_key[1];
    }

    if (chosen_key[0] == 'C' && chosen_key[1] == '\0') {
        return 0;
    }

    SDL_Surface *key_accidentals = nullptr;
    SDL_Rect dst;
    dst.x = X_START_AFTER_KEY + 1;

    // Trzy zera ścieżki zostają podmienione na
    // znaki: ręka{t, b}, liczba znaków{1,..., 7}, typ znaku{s, b}
    char path_to_key_bmp[] = "pictures/keys/000.bmp";
    const int path_prefix_len = 14;

    int brace, diff_of_hights;

    for (int hand = 0; hand < NUMBER_OF_HANDS; hand++) {

        if (get_path_to_key_bmp(chosen_key, path_to_key_bmp, path_prefix_len, hand)) {
            return 1;
        }
        if (key_accidentals != nullptr) SDL_FreeSurface(key_accidentals);
        key_accidentals = SDL_LoadBMP(path_to_key_bmp);
        if (key_accidentals == nullptr) {
            return 1;
        }

        SDL_SetColorKey(key_accidentals, SDL_TRUE, SDL_MapRGB(key_accidentals->format, 255, 255, 255));

        if (*X_star_on_line < X_START_AFTER_KEY + key_accidentals->w) {
            *X_star_on_line = X_START_AFTER_KEY + key_accidentals->w;
        }

        if (hand == 0) {
            if (path_to_key_bmp[path_prefix_len + 2] == 's') diff_of_hights = Y_OF_FIRST_LINE_TREB_SHARP_KEY;
            else diff_of_hights = Y_OF_FIRST_LINE_TREB_BMOL_KEY;

        } else {
            if (path_to_key_bmp[path_prefix_len + 2] == 's') diff_of_hights = Y_OF_FIRST_LINE_BASS_SHARP_KEY;
            else diff_of_hights = Y_OF_FIRST_LINE_BASS_BMOL_KEY;
        }

        for (brace = 0; brace < NUMBER_OF_BRACES; brace++) {

            dst.y = Y_FIRST_LINE + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                    brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES - diff_of_hights;
            SDL_BlitSurface(key_accidentals, nullptr, stave, &dst);

        }
    }

    SDL_FreeSurface(key_accidentals);
    return 0;
}
int OpusEditor::put_metre(const int *chosen_metre, int *X_start_on_line, int brace) {

    if (current_OPUS != nullptr) {
        current_OPUS->metre[0] = chosen_metre[0];
        current_OPUS->metre[1] = chosen_metre[1];
    }

    SDL_Surface *metre_sign = nullptr;
    SDL_Rect dst;
    dst.x = *X_start_on_line + DISTANCE_BETWEEN_KEY_AND_METRE;
    dst.y = Y_FIRST_LINE;

    //// Two zeros are nunmerator and denomiantor metre.
    char path_to_metre_bmp[] = "pictures/metre/metre_00.bmp";
    const int path_prefix_len = 21;
    get_path_to_metre_bmp(chosen_metre, path_to_metre_bmp, path_prefix_len);


    metre_sign = SDL_LoadBMP(path_to_metre_bmp);
    if (metre_sign == nullptr) {
        return 1;
    }
    SDL_SetColorKey(metre_sign, SDL_TRUE, SDL_MapRGB(metre_sign->format, 255, 255, 255));

    int hands;
    for (hands = 0; hands < NUMBER_OF_HANDS; hands++) {

        dst.y = Y_FIRST_LINE + hands * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES;
        SDL_BlitSurface(metre_sign, nullptr, stave, &dst);
    }

    *X_start_on_line = dst.x + metre_sign->w;
    SDL_FreeSurface(metre_sign);
    return 0;
}

//putting
int OpusEditor::put_chord_on_treb_without_beam(Chord *chord_to_put, int *X_start, int brace, BarsSpace *b_space) {

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

    SDL_Surface *note_without_flag = nullptr;
    SDL_Surface *note_with_flag = nullptr;
    SDL_Surface *note_to_put = nullptr;
    SDL_Surface *sign_note_without_flag = nullptr;
    SDL_Surface *sign_note_with_flag = nullptr;

    SDL_Surface *acci_b = SDL_LoadBMP("pictures/accidental/acci_b.bmp");
    SDL_Surface *acci_s = SDL_LoadBMP("pictures/accidental/acci_s.bmp");
    SDL_Surface *acci_n = SDL_LoadBMP("pictures/accidental/acci_n.bmp");
    SDL_Surface *acci_to_put = nullptr;

    SDL_Surface *time_dot = SDL_LoadBMP("pictures/notes/time_dot.bmp");


    char path[28] = "pictures/notes/note_00.bmp";
    int prefix_len = 20;
    path[prefix_len] = (char) (chord_to_put->time + 48);
    if (chord_to_put->time == 0) {
        path[prefix_len + 1] = 'n';
    } else {
        int lower_note_index = chord_to_put->notes_[0].index();
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
        if (chord_to_put == COE.current_C){
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    } else {
        note_with_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE.current_C){
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            path[prefix_len - 2] = 'e';
        }
        path[prefix_len] = '2';
        note_without_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE.current_C){
            path[prefix_len - 2] = 'b';
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    }
    SDL_SetColorKey(acci_b, SDL_TRUE, SDL_MapRGB(acci_b->format, 255, 255, 255));
    SDL_SetColorKey(acci_n, SDL_TRUE, SDL_MapRGB(acci_n->format, 255, 255, 255));
    SDL_SetColorKey(acci_s, SDL_TRUE, SDL_MapRGB(acci_s->format, 255, 255, 255));
    SDL_SetColorKey(note_with_flag, SDL_TRUE, SDL_MapRGB(note_with_flag->format, 255, 255, 255));
    SDL_SetColorKey(note_without_flag, SDL_TRUE, SDL_MapRGB(note_without_flag->format, 255, 255, 255));
    if (chord_to_put == COE.current_C) {
        SDL_SetColorKey(sign_note_with_flag, SDL_TRUE, SDL_MapRGB(sign_note_with_flag->format, 255, 255, 255));
        SDL_SetColorKey(sign_note_without_flag, SDL_TRUE, SDL_MapRGB(sign_note_without_flag->format, 255, 255, 255));
    }
    SDL_SetColorKey(time_dot, SDL_TRUE, SDL_MapRGB(time_dot->format, 255, 255, 255));

    for (i = 0; i < chord_to_put->notes_number; i++) {

        if (path[prefix_len + 1] == 'u' || path[prefix_len + 1] == 'n') k = i;
        else k = chord_to_put->notes_number - 1 - i;
        note_to_put = note_without_flag;
        if (i == chord_to_put->notes_number - 1) note_to_put = note_with_flag;

        if (chord_to_put == COE.current_C && i == COE.current_note_index){
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
                    SDL_BlitSurface(note_to_put, nullptr, stave, &insert_note_rect);
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
                    SDL_BlitSurface(note_to_put, nullptr, stave, &insert_note_rect);
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
                SDL_BlitSurface(time_dot, nullptr, stave, &dots_rect);
                dots_rect.x += time_dot->w;
            }
        }
        ///// Znaki artykulacji
        if (chord_to_put->ssp_articulation) {

            if (chord_to_put->ssp_articulation == 1) {
                if (path[prefix_len + 1] == 'u' && k == 0) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y + 15;
                    SDL_BlitSurface(time_dot, nullptr, stave, &dots_rect);
                }  else if (path[prefix_len + 1] == 'd' && k == chord_to_put->notes_number - 1) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y - 15;
                    SDL_BlitSurface(time_dot, nullptr, stave, &dots_rect);
                }
            }
        }

        if (insert_note_rect.y != 0) {
            SDL_BlitSurface(note_to_put, nullptr, stave, &insert_note_rect);
            any_put = 1;
            if (is_acci_req(chord_to_put, k, COE.current_O->default_serial_key) || chord_to_put->notes_[k].may_print_acci) {
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

                SDL_BlitSurface(acci_to_put, nullptr, stave, &acci_rect);
            }
        }
    }
    if (!any_put) {
        insert_note_rect.y = Y_FIRST_LINE + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES;
        insert_note_rect.h = 4 * DISTANCE_BETWEEN_LINES;
        insert_note_rect.w = WIDTH_NOTES_WITHOUT_FLAG;
        if (chord_to_put == COE.current_C){
            SDL_FillRect(stave, &insert_note_rect, 0x0f);

        } else {
            SDL_FillRect(stave, &insert_note_rect, 0x05);
        }
    }

    chord_to_put->X_position = *X_start;
    *X_start += b_space->widths_ni_[chord_to_put->time][chord_to_put->_time_dots_];

    return 0;
}
int OpusEditor::put_chord_on_bass_without_beam(Chord *chord_to_put, int *X_start, int brace, BarsSpace *b_space) {

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

    SDL_Surface *note_without_flag = nullptr;
    SDL_Surface *note_with_flag = nullptr;
    SDL_Surface *note_to_put = nullptr;
    SDL_Surface *sign_note_without_flag = nullptr;
    SDL_Surface *sign_note_with_flag = nullptr;

    SDL_Surface *acci_b = SDL_LoadBMP("pictures/accidental/acci_b.bmp");
    SDL_Surface *acci_s = SDL_LoadBMP("pictures/accidental/acci_s.bmp");
    SDL_Surface *acci_n = SDL_LoadBMP("pictures/accidental/acci_n.bmp");
    SDL_Surface *acci_to_put = nullptr;

    SDL_Surface *time_dot = SDL_LoadBMP("pictures/notes/time_dot.bmp");


    char path[28] = "pictures/notes/note_00.bmp";
    int prefix_len = 20;
    path[prefix_len] = (char) (chord_to_put->time + 48);
    if (chord_to_put->time == 0) {
        path[prefix_len + 1] = 'n';
    } else {
        int lower_note_index = chord_to_put->notes_[0].index();
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
        if (chord_to_put == COE.current_C) {
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    } else {
        note_with_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE.current_C) {
            path[prefix_len - 2] = 'b';
            sign_note_with_flag = SDL_LoadBMP(path);
            path[prefix_len - 2] = 'e';
        }
        path[prefix_len] = '2';
        note_without_flag = SDL_LoadBMP(path);
        if (chord_to_put == COE.current_C) {
            path[prefix_len - 2] = 'b';
            sign_note_without_flag = SDL_LoadBMP(path);
        }
    }

    SDL_SetColorKey(acci_b, SDL_TRUE, SDL_MapRGB(acci_b->format, 255, 255, 255));
    SDL_SetColorKey(acci_n, SDL_TRUE, SDL_MapRGB(acci_n->format, 255, 255, 255));
    SDL_SetColorKey(acci_s, SDL_TRUE, SDL_MapRGB(acci_s->format, 255, 255, 255));
    SDL_SetColorKey(note_with_flag, SDL_TRUE, SDL_MapRGB(note_with_flag->format, 255, 255, 255));
    SDL_SetColorKey(note_without_flag, SDL_TRUE, SDL_MapRGB(note_without_flag->format, 255, 255, 255));
    if (chord_to_put == COE.current_C) {
        SDL_SetColorKey(sign_note_with_flag, SDL_TRUE, SDL_MapRGB(sign_note_with_flag->format, 255, 255, 255));
        SDL_SetColorKey(sign_note_without_flag, SDL_TRUE, SDL_MapRGB(sign_note_without_flag->format, 255, 255, 255));
    }
    SDL_SetColorKey(time_dot, SDL_TRUE, SDL_MapRGB(time_dot->format, 255, 255, 255));



    for (i = 0; i < chord_to_put->notes_number; i++) {
        if (path[prefix_len + 1] == 'u' || path[prefix_len + 1] == 'n') k = i;
        else k = chord_to_put->notes_number - 1 - i;
        note_to_put = note_without_flag;
        if (i == chord_to_put->notes_number - 1) note_to_put = note_with_flag;

        if (chord_to_put == COE.current_C && i == COE.current_note_index) {
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
                SDL_BlitSurface(time_dot, nullptr, stave, &dots_rect);
                dots_rect.x += time_dot->w;
            }
        }
        ///// Znaki artykulacji
        if (chord_to_put->ssp_articulation) {

            if (chord_to_put->ssp_articulation == 1) {
                if (path[prefix_len + 1] == 'u' && k == 0) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y + 15;
                    SDL_BlitSurface(time_dot, nullptr, stave, &dots_rect);
                }  else if (path[prefix_len + 1] == 'd' && k == chord_to_put->notes_number - 1) {
                    dots_rect.x = insert_note_rect.x + WIDTH_NOTES_WITHOUT_FLAG / 3;
                    dots_rect.y = insert_note_rect.y - 15;
                    SDL_BlitSurface(time_dot, nullptr, stave, &dots_rect);
                }
            }
        }

        if (insert_note_rect.y != 0) {
            SDL_BlitSurface(note_to_put, nullptr, stave, &insert_note_rect);
            any_put = 1;
            ////// Znaki chromatyczne
            if (is_acci_req(chord_to_put, k, COE.current_O->default_serial_key) || chord_to_put->notes_[k].may_print_acci) {
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

                SDL_BlitSurface(acci_to_put, nullptr, stave, &acci_rect);
            }
        }
    }

    ///// Jescze się przyda funkcja odległości od (CHORDS->time)

    if (!any_put) {
        insert_note_rect.y = Y_FIRST_LINE + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES;
        insert_note_rect.h = 4 * DISTANCE_BETWEEN_LINES;
        insert_note_rect.w = WIDTH_NOTES_WITHOUT_FLAG;
        if (chord_to_put == COE.current_C){
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
int OpusEditor::put_pause_on_stave_without_beam(Chord *chord_to_put, int *X_start, int brace, int hand, BarsSpace *b_space){


    SDL_Rect blank_stave_rect;

    blank_stave_rect.x = *X_start - WIDTH_NOTES_WITH_FLAGS / 2;
    blank_stave_rect.y = Y_FIRST_LINE + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                         brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES - 3 * DISTANCE_BETWEEN_LINES;
    blank_stave_rect.w = WIDTH_NOTES_WITH_FLAGS * 2;
    blank_stave_rect.h = DISTANCE_BETWEEN_LINES * 8;

    SDL_Rect pause_rect;
    pause_rect.x = *X_start;
    pause_rect.y = Y_FIRST_LINE + hand * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES + brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES;
    SDL_Surface *pause = nullptr;
    char path[40] = "pictures/notes/paus_0n.bmp";
    int prefix_len = 20;
    path[prefix_len] = (char)(chord_to_put->time + 48);

    if (chord_to_put == COE.current_C) {
        path[prefix_len - 2] = 'b';
    }

    pause = SDL_LoadBMP(path);

    SDL_BlitSurface(pause, nullptr, stave, &pause_rect);

    chord_to_put->X_position = *X_start;
    *X_start += b_space->widths_ni_[chord_to_put->time][chord_to_put->_time_dots_];

    SDL_FreeSurface(pause);
    return 0;
}
int OpusEditor::put_chord_on_stave_without_beam(Chord *chord_to_put, int *X_start, int hand, int brace, BarsSpace *b_space) {

    if (chord_to_put->notes_[0].name == 'P') {
        put_pause_on_stave_without_beam(chord_to_put, X_start, brace, hand, b_space);
    } else {

        if (hand == 0) {
            put_chord_on_treb_without_beam(chord_to_put, X_start, brace, b_space);
        } else {
            put_chord_on_bass_without_beam(chord_to_put, X_start, brace, b_space);
        }
    }
    return 0;
}

int OpusEditor::put_bar_on_stave(Bar *bar_to_put, int hand, int brace, const int chosen_metre[2]) {

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


    Chord *help_chord = nullptr;
    double max_metre_sum, metre_sum = 0;
    max_metre_sum = (double) chosen_metre[0] / (double) chosen_metre[1];

    //////Trzeba usunąć nadmiarowe chord-y dla treb
    help_chord = bar_to_put->first_chord_treb;


    metre_sum = bar_to_put->get_current_time_taken(RIGHT_HAND);

    while (metre_sum > max_metre_sum) {
        was_chord_deleted = 1;
        help_chord = bar_to_put->first_chord_treb;
        while (help_chord->next != nullptr) {
            help_chord = help_chord->next;
        }
        if (help_chord->prev != nullptr) {
            help_chord->prev->next = nullptr;
            delete help_chord;
        } else {
            help_chord->time++;
        }

        help_chord = bar_to_put->first_chord_treb;
        metre_sum = 0;
        while (help_chord != nullptr) {
            metre_sum += Bar::chords_periods[help_chord->time][help_chord->_time_dots_];
            help_chord = help_chord->next;
        }
    }


    //////Trzeba usunąć nadmiarowe chord-y dla bass
    metre_sum = 0;
    help_chord = bar_to_put->first_chord_bass;

    metre_sum = bar_to_put->get_current_time_taken(LEFT_HAND);

    while (metre_sum > max_metre_sum) {
        was_chord_deleted = 1;
        help_chord = bar_to_put->first_chord_bass;
        while (help_chord->next != nullptr) {
            help_chord = help_chord->next;
        }

        if (help_chord->prev != nullptr) {
            help_chord->prev->next = nullptr;
            delete help_chord;
        } else {
            help_chord->time++;
        }

        help_chord = bar_to_put->first_chord_bass;
        metre_sum = 0;
        while (help_chord != nullptr) {
            metre_sum += Bar::chords_periods[help_chord->time][help_chord->_time_dots_];
            help_chord = help_chord->next;
        }
    }
    if (was_chord_deleted) {
        if (COE.current_hand == 0) {
            help_chord = bar_to_put->first_chord_treb;
            while (help_chord->next != nullptr) {
                help_chord = help_chord->next;
            }
            COE.current_C = help_chord;
        } else {
            help_chord = bar_to_put->first_chord_bass;
            while (help_chord->next != nullptr) {
                help_chord = help_chord->next;
            }
            COE.current_C = help_chord;
        }
        COE.current_note_index = COE.current_C->notes_number - 1;
    }

    //////////////////////////////
    BarsSpace b_space;

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
        SDL_BlitSurface(stave_with_key_and_metre, &whole_bar_rect, stave, &whole_bar_rect);
    } else {
        if (hand == 0) {
            SDL_BlitSurface(stave_with_key_and_metre, &treb_bar_rect, stave, &treb_bar_rect);
        } else if (hand == 1) {
            SDL_BlitSurface(stave_with_key_and_metre, &bass_bar_rect, stave, &bass_bar_rect);
        }
    }
    SDL_FillRect(stave, &start_bar_rect, 0x00);

    ///Odkładanie chord-ów
    if (may_edit_whole_bar || hand == 2) {
        help_chord = bar_to_put->first_chord_treb;
        while (help_chord != nullptr) {
            put_chord_on_stave_without_beam(help_chord, &X_start_hands[0], 0, brace,
                                            &b_space);
            help_chord = help_chord->next;
        }
        help_chord = bar_to_put->first_chord_bass;
        while (help_chord != nullptr) {
            put_chord_on_stave_without_beam(help_chord, &X_start_hands[1], 1, brace,
                                            &b_space);
            help_chord = help_chord->next;
        }
    } else {
        if (hand == 0) {
            help_chord = bar_to_put->first_chord_treb;
            while (help_chord != nullptr) {
                put_chord_on_stave_without_beam(help_chord, &X_start_hands[0], 0, brace,
                                                &b_space);
                help_chord = help_chord->next;
            }
        } else if (hand == 1) {
            help_chord = bar_to_put->first_chord_bass;
            while (help_chord != nullptr) {
                put_chord_on_stave_without_beam(help_chord, &X_start_hands[1], 1, brace,
                                                &b_space);
                help_chord = help_chord->next;
            }
        }
    }


    return 0;
}
int OpusEditor::put_all_bars_on_stave(Bar *first_bar_to_put, const int chosen_metre[2]) {
    SDL_BlitSurface(stave_with_key_and_metre, nullptr, stave, nullptr);

    while (first_bar_to_put != nullptr){
        put_bar_on_stave(first_bar_to_put, 2, first_bar_to_put->brace, chosen_metre);
        first_bar_to_put = first_bar_to_put->next;
    }
    return 0;
}



//opus_editing_utils;
int OpusEditor::get_serial_key(const char *chosen_key, char *serial_key) {

    int i;
    for (i = 0; i < 7; i++) {
        serial_key[i] = 'n';
    }

    switch (chosen_key[0]) {
        case 'C':
            switch (chosen_key[1]) {
                case '\0':
                    break;
                case 'i':
                    for (i = 0; i < 7; i++) {
                        serial_key[i] = 's';
                    }
                    break;
                case 'e':
                    for (i = 0; i < 7; i++) {
                        serial_key[i] = 'b';
                    }
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case 'D':
            switch (chosen_key[1]) {
                case '\0':
                    serial_key[0] = 's';
                    serial_key[3] = 's';
                    break;
                case 'e':
                    for (i = 0; i < 7; i++) {
                        serial_key[i] = 'b';
                    }
                    serial_key[0] = 'n';
                    serial_key[3] = 'n';
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case 'E':
            switch (chosen_key[1]) {
                case '\0':
                    serial_key[0] = 's';
                    serial_key[3] = 's';
                    serial_key[4] = 's';
                    serial_key[1] = 's';
                    break;
                case 'e':
                    serial_key[2] = 'b';
                    serial_key[5] = 'b';
                    serial_key[6] = 'b';
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case 'F':
            switch (chosen_key[1]) {
                case '\0':
                    serial_key[6] = 'b';
                    break;
                case 'i':
                    for (i = 0; i < 6; i++) {
                        serial_key[i] = 's';
                    }
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case 'G':
            switch (chosen_key[1]) {
                case '\0':
                    serial_key[3] = 's';
                    break;
                case 'e':
                    for (i = 0; i < 7; i++) {
                        serial_key[i] = 'b';
                    }
                    serial_key[3] = 'n';
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case 'A':
            switch (chosen_key[1]) {
                case '\0':
                    serial_key[3] = 's';
                    serial_key[0] = 's';
                    serial_key[4] = 's';
                    break;
                case 's':
                    serial_key[6] = 'b';
                    serial_key[2] = 'b';
                    serial_key[5] = 'b';
                    serial_key[1] = 'b';
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case 'H':
            for (i = 0; i < 6; i++) {
                serial_key[i] = 's';
            }
            serial_key[2] = 'n';
            break;
        case 'B':
            serial_key[6] = 'b';
            serial_key[2] = 'b';
            break;
        default:
            return 1;
            break;
    }

    return 0;
}
int OpusEditor::is_acci_req(Chord *chord_to_put, int k, const char *defauly_serial_key) {

    int i = 0;
    Note *n = &(chord_to_put->notes_[k]);
    switch (n->name) {
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
    if (//n->acci != chord_to_put->local_serial_key[i] ||
            (chord_to_put->prev == nullptr && n->acci != defauly_serial_key[i]) ||
            (chord_to_put->prev != nullptr && n->acci != chord_to_put->prev->local_serial_key[i])) {
        return 1;
    }

    return 0;
}
int OpusEditor::get_space_for_chord(Bar *bar, BarsSpace *b_space, const int *metre) {

    int available_width = bar->width_ - DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE - DISTANCE_BEWTWEEN_LAST_NOTE_AND_BAR, i, j;
    double notes_periods[6][6], metre_quotient = (double)metre[0] / (double)metre[1];

    notes_periods[0][0] = 1;
    for (i = 1; i < 6; i++) {
        notes_periods[i][0] = notes_periods[i - 1][0] / 2;
        for (j = 1; j < 6; j++) {
            notes_periods[i][j] = notes_periods[i][0] * (2 - pow(2, -j));
        }
    }


    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            b_space->widths_ni_[i][j] = (int) ((available_width * notes_periods[i][j]) / metre_quotient);
        }
    }
    return 0;
}



//opus_edit_logic;
int OpusEditor::change_bar_width(int pressed_key, const Uint8 *KEY_STATE, int X_after_key) {

    int i;
    CurrentOpusEdits COE_HELP;
    if (KEY_STATE != nullptr && !KEY_STATE[SDL_SCANCODE_LSHIFT] && !KEY_STATE[SDL_SCANCODE_RSHIFT]) {
        i = STEP_IN_BAR_WIDTH_CHANGING_WITHOUT_SHIFT;
    } else {
        i = STEP_IN_BAR_WIDTH_CHANGING_WITH_SHIFT;
    }

    if (pressed_key == SDLK_j) {
        COE.current_B->width_ -= i;
        if (COE.current_B->width_ < WIDTH_NOTES_WITH_FLAGS) {
            COE.current_B->width_ = WIDTH_NOTES_WITH_FLAGS;
            any_change = 0;
        }
    } else if (pressed_key == SDLK_m) {
        COE.current_B->width_ += i;
        if (COE.current_B->X_of_start_bar + COE.current_B->width_ > X_END_OF_STAVE) {
            COE.current_B->width_ = X_END_OF_STAVE - COE.current_B->X_of_start_bar;
            any_change = 0;
        }
    }

    COE_HELP.current_B = COE.current_B->next;
    if (any_change) {
        while (COE_HELP.current_B != nullptr) {

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
                    COE_HELP.current_B->prev->next = nullptr;
                    delete COE_HELP.current_B;
                    COE_HELP.current_B = nullptr;
                }
            }
            COE_HELP.current_B = COE_HELP.current_B->next;
        }
    }

    return 0;
}
int OpusEditor::change_chord_len(int pressed_key, const Uint8 *KEY_STATE) {
    int tmp1, tmp2;
    Chord *help_chord = nullptr;
    double max_time_taken, metre_sum = 0;
    max_time_taken = (double) COE.current_O->metre[0] / (double) COE.current_O->metre[1];

    if (!KEY_STATE[SDL_SCANCODE_RSHIFT] && !KEY_STATE[SDL_SCANCODE_LSHIFT]) {
        tmp1 = COE.current_C->time;
        if (pressed_key == SDLK_k) {
            if (COE.current_C->time > 0) {
                COE.current_C->time--;
                if (COE.current_B->get_current_time_taken(COE.current_hand) > max_time_taken)
                    COE.current_C->time++;
            }
        } else {
            if (COE.current_C->time < 5) {
                COE.current_C->time++;
            }
        }
        if (tmp1 == COE.current_C->time) {
            any_change = 0;
        }
    } else {
        tmp1 = COE.current_C->_time_dots_;
        tmp2 = COE.current_C->ssp_articulation;
        if (pressed_key == SDLK_l) {
            if (COE.current_C->_time_dots_ > 0) {
                COE.current_C->_time_dots_--;
                if (COE.current_B->get_current_time_taken(COE.current_hand) > max_time_taken)
                    COE.current_C->_time_dots_++;

            } else {
                if (COE.current_C->ssp_articulation < 3) {
                    COE.current_C->ssp_articulation++;
                }
            }

        } else {
            if (COE.current_C->ssp_articulation > 0) {
                COE.current_C->ssp_articulation--;

            } else {
                if (COE.current_C->_time_dots_ < 5) {
                    COE.current_C->_time_dots_++;
                }
            }
        }
        if (!(tmp1 != COE.current_C->_time_dots_ ||
              tmp2 != COE.current_C->ssp_articulation)) {
            any_change = 0;
        }
    }

    return 0;
}
int OpusEditor::change_hand() {

    if (COE.current_hand == RIGHT_HAND) {
        COE.current_C = COE.current_B->first_chord_bass;
        COE.current_hand = LEFT_HAND;
        COE.current_note_index = COE.current_C->notes_number - 1;

    } else {
        COE.current_C = COE.current_B->first_chord_treb;
        COE.current_hand = RIGHT_HAND;
        COE.current_note_index = COE.current_C->notes_number - 1;
    }
    return 0;
}
int OpusEditor::change_note(int pressed_key) {
    if (COE.current_C->notes_number > 0) {

        if (pressed_key == SDLK_UP) {
            COE.current_note_index++;
            if (COE.current_note_index >= COE.current_C->notes_number) {
                COE.current_note_index--;
            }
        } else {
            COE.current_note_index--;
            if (COE.current_note_index < 0) {
                COE.current_note_index++;
            }
        }
    } else {
        COE.current_note_index = -1;
    }
    return 0;
}
int OpusEditor::change_chord_or_bar(int pressed_key, const Uint8 *KEY_STATE) {

    struct CurrentOpusEdits COE_HELP;

    if (pressed_key == SDLK_RIGHT) {
        if (!KEY_STATE[SDL_SCANCODE_LSHIFT]) {
            if (COE.current_C->next != nullptr) {
                COE.current_C = COE.current_C->next;
            } else if (COE.current_B->next != nullptr) {
                COE.current_B = COE.current_B->next;
                if (COE.current_hand == 0) {
                    COE.current_C = COE.current_B->first_chord_treb;
                } else {
                    COE.current_C = COE.current_B->first_chord_bass;
                }

            }
        } else {
            if (COE.current_B->next != nullptr) {
                COE.current_B = COE.current_B->next;
                if (COE.current_hand == 0) {
                    COE.current_C = COE.current_B->first_chord_treb;
                } else {
                    COE.current_C = COE.current_B->first_chord_bass;
                }

            } else {
                COE_HELP.current_C = COE.current_C;
                while (COE_HELP.current_C->next != nullptr) {
                    COE_HELP.current_C = COE_HELP.current_C->next;
                }
                COE.current_C = COE_HELP.current_C;
            }
        }
    }
    if (pressed_key == SDLK_LEFT) {
        if (!KEY_STATE[SDL_SCANCODE_LSHIFT]) {
            if (COE.current_C->prev != nullptr) {
                COE.current_C = COE.current_C->prev;
            } else if (COE.current_B->prev != nullptr) {
                COE.current_B = COE.current_B->prev;

                if (COE.current_hand == 0) {
                    COE.current_C = COE.current_B->first_chord_treb;
                } else {
                    COE.current_C = COE.current_B->first_chord_bass;
                }
                COE_HELP.current_C = COE.current_C;
                while (COE_HELP.current_C->next != nullptr) {
                    COE_HELP.current_C = COE_HELP.current_C->next;
                }
                COE.current_C = COE_HELP.current_C;
            }
        } else {
            if (COE.current_B->prev != nullptr) {
                COE.current_B = COE.current_B->prev;

                if (COE.current_hand == 0) {
                    COE.current_C = COE.current_B->first_chord_treb;
                } else {
                    COE.current_C = COE.current_B->first_chord_bass;
                }
                COE_HELP.current_C = COE.current_C;
                while (COE_HELP.current_C->next != nullptr) {
                    COE_HELP.current_C = COE_HELP.current_C->next;
                }
                COE.current_C = COE_HELP.current_C;
            } else {
                if (COE.current_hand == 0) {
                    COE.current_C = COE.current_B->first_chord_treb;
                } else {
                    COE.current_C = COE.current_B->first_chord_bass;
                }
            }
        }
    }

    COE.current_note_index = COE.current_C->notes_number - 1;
    return 0;
}
int OpusEditor::put_note_or_pause(int pressed_key, const Uint8 *KEY_STATE, const char *serial_key) {

    int help_tmp_1, i;
    if (COE.current_C->notes_number < MAX_NOTES_IN_CHORD) {
        COE.current_C->notes_number++;
        COE.current_note_index = COE.current_C->notes_number - 1;
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
            COE.current_C->notes_[COE.current_note_index].name = name;
            COE.current_C->notes_[COE.current_note_index].height = help_tmp_1;
            COE.current_C->notes_[COE.current_note_index].may_print_acci = 0;
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
            COE.current_C->notes_[COE.current_note_index].acci = acci;
            COE.current_C->sort_uniq_notes();
        } else {
            COE.current_C->notes_[0].name = 'P';
            COE.current_C->notes_[0].acci = 's';
            COE.current_C->notes_[0].height = 4;
            COE.current_C->notes_number = 1;
            COE.current_note_index = 0;
        }
    }
    return 0;
}
int OpusEditor::del_note_chord_bar(const Uint8 *KEY_STATE, int X_after_key) {

    int i;
    CurrentOpusEdits COE_HELP;

    if (!KEY_STATE[SDL_SCANCODE_LSHIFT] && !KEY_STATE[SDL_SCANCODE_RSHIFT]) {
        if (COE.current_C->notes_number > 0) {
            if (COE.current_note_index == COE.current_C->notes_number - 1) {
                COE.current_C->notes_number--;
                COE.current_note_index--;
            } else {
                for (i = COE.current_note_index; i < COE.current_C->notes_number - 1; i++) {
                    COE.current_C->swap_notes(i, i+1);
                }
                COE.current_C->notes_number--;
            }
        }
    } else {
        // Usuwanie pojedynczego chord-u
        if (COE.current_C->prev != nullptr) {
            COE_HELP.current_C = COE.current_C;
            COE.current_C = COE.current_C->prev;
            COE.current_C->next = COE.current_C->next->next;
            if (COE.current_C->next != nullptr) {
                COE.current_C->next->prev = COE.current_C;
            }
            delete COE_HELP.current_C;
            // jeżeli jest pierwszy i nie jest jedyny
        } else if (COE.current_C->next != nullptr) {
            COE.current_C = COE.current_C->next;
            delete COE.current_C->prev;
            COE.current_C->prev = nullptr;
            if (COE.current_hand == 0) {
                COE.current_B->first_chord_treb = COE.current_C;
            } else {
                COE.current_B->first_chord_bass = COE.current_C;
            }

            // jeśli jest on pierwszym i jedynym chord-em w bar-rze, to jeśli nie jest to jedyny bar
        } else {
            if (COE.current_B->prev != nullptr) {
                COE.current_B = COE.current_B->prev;

                COE_HELP.current_B = COE.current_B->next;
                COE.current_B->next = COE.current_B->next->next;
                if (COE.current_B->next != nullptr) {
                    COE.current_B->next->prev = COE.current_B;
                }
                delete COE_HELP.current_B;
                if (COE.current_hand == 0) {
                    COE.current_C = COE.current_B->first_chord_treb;
                } else {
                    COE.current_C = COE.current_B->first_chord_bass;
                }

                // Jesli bar jest pierwszy ale nie jest jedyny
            } else if (COE.current_B->next != nullptr) {
                COE.current_B = COE.current_B->next;
                COE.current_B->X_of_start_bar = COE.current_B->prev->X_of_start_bar;
                delete COE.current_B->prev;
                COE.current_B->prev = nullptr;
                COE.current_O->first_BAR = COE.current_B;
                if (COE.current_hand == 0) {
                    COE.current_C = COE.current_B->first_chord_treb;
                } else {
                    COE.current_C = COE.current_B->first_chord_bass;
                }
            }
        }
        COE.current_note_index = COE.current_C->notes_number - 1;
    }
    change_bar_width(0, nullptr, X_after_key);
    return 0;
}
int OpusEditor::create_new_chord_bar(const Uint8 *KEY_STATE, int X_after_key) {

    int brace_help, X_st_help, width_help;
    if (!KEY_STATE[SDL_SCANCODE_LSHIFT] && !KEY_STATE[SDL_SCANCODE_RSHIFT]) {
        if (COE.current_C->next == nullptr) {
            COE.current_C->next = new Chord(COE.current_C, nullptr,
                                             COE.current_C->X_position + WIDTH_NOTES_WITH_FLAGS, COE.current_C->local_serial_key);
        } else {
            COE.current_C->next = new Chord(COE.current_C, COE.current_C->next,
                                             COE.current_C->X_position + WIDTH_NOTES_WITH_FLAGS, COE.current_C->local_serial_key);
            COE.current_C->next->prev = COE.current_C;
            COE.current_C->next->next->prev = COE.current_C->next;
        }
        COE.current_C = COE.current_C->next;
        COE.current_note_index = -1;
    } else {

        brace_help = COE.current_B->brace;
        X_st_help = COE.current_B->X_of_start_bar + COE.current_B->width_ + 2;
        width_help = __min(X_END_OF_STAVE - (COE.current_B->X_of_start_bar + COE.current_B->width_),
                           DEFAULT_BAR_WIDTH);
        if (width_help < MIN_BAR_WIDTH) {
            brace_help++;
            width_help = DEFAULT_BAR_WIDTH;
            X_st_help = X_after_key;
        }

        COE.current_B->next = new Bar(COE.current_B, COE.current_B->next, X_st_help, width_help, brace_help,
                                      COE.current_O->default_serial_key, COE.current_O->default_serial_key);
        COE.current_B = COE.current_B->next;
        if (COE.current_B->next != nullptr) {
            COE.current_B->next->prev = COE.current_B;
        }
        if (COE.current_hand == 0) {
            COE.current_C = COE.current_B->first_chord_treb;
        } else {
            COE.current_C = COE.current_B->first_chord_bass;
        }
    }

    COE.current_note_index = -1;
    change_bar_width(0, nullptr, X_after_key);

    return 0;
}
int OpusEditor::put_accidental(int pressed_key, const Uint8 *KEY_STATE) {


    if (pressed_key == SDLK_x) {
        COE.current_C->notes_[COE.current_note_index].may_print_acci += 1;
        COE.current_C->notes_[COE.current_note_index].may_print_acci %= 2;
    } else if (COE.current_C->notes_[COE.current_note_index].name != 'p') {
        int i = 0;
        COE.current_C->notes_[COE.current_note_index].acci = (char) pressed_key;
        COE.current_C->sort_uniq_notes();
        switch (COE.current_C->notes_[COE.current_note_index].name) {
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
        COE.current_C->local_serial_key[i] = (char) pressed_key;
        Chord *help_chord = COE.current_C->next;
        while (help_chord != nullptr) {

            if (help_chord->local_serial_key[i] == COE.current_O->default_serial_key[i]) {
                help_chord->local_serial_key[i] = help_chord->prev->local_serial_key[i];
            } else {
                break;
            }
            help_chord = help_chord->next;
        }
    }

    return 0;
}


void OpusEditor::open_window() {
    window = SDL_CreateWindow("Nutownik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, stave->w, SCREEN_HIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    screen = SDL_GetWindowSurface(window);
    SDL_BlitSurface(blank_stave, nullptr, stave, nullptr);

}
void OpusEditor::close_window(){
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
}
void OpusEditor::init() {
    stave = SDL_LoadBMP("pictures/wiolbas.bmp");
    blank_stave = SDL_LoadBMP("pictures/wiolbas.bmp");
    stave_with_key_and_metre = SDL_LoadBMP("pictures/wiolbas.bmp");


    Rect_current_view.x = 0;
    Rect_current_view.y = 0;
    Rect_current_view.w = stave->w;
    Rect_current_view.h = SCREEN_HIGHT;

    instructions_[0] = SDL_LoadBMP("pictures/menu/stave_instructions_str1.bmp");
    instructions_[1] = SDL_LoadBMP("pictures/menu/stave_instructions_str2.bmp");
    instructions_[2] = SDL_LoadBMP("pictures/menu/stave_instructions_str3.bmp");
}


void OpusEditor::scroll_vertically(SDL_Event *occurrence) {

    int y = Rect_current_view.y;
    int s = occurrence->wheel.y;

    y -= s * 10;

    if (y > stave->h - screen->h) y = stave->h - screen->h;
    if (y < 0) y = 0;

    Rect_current_view.y = y;
}
Opus* OpusEditor::run(char chosen_key[2], int chosen_metre[2], Opus *prev_opus) {
    open_window();
    if (prev_opus == nullptr) {
        current_OPUS = new Opus(chosen_key, chosen_metre);
    } else {
        current_OPUS = prev_opus;
    }

    SDL_Event occurrence;
    int end = 0, is_instruction_open = 0, page_number = 0;

    int X_start_on_treb = X_START_AFTER_KEY;
    int X_start_on_bass = X_START_AFTER_KEY;
    int X_after_key;



    this->put_key(chosen_key, &X_start_on_treb);
    X_after_key = X_start_on_treb;
    this->put_metre(chosen_metre, &X_start_on_treb, 0);
    SDL_BlitSurface(stave, nullptr, stave_with_key_and_metre, nullptr);
    X_start_on_treb += 5;
    X_start_on_bass = X_start_on_treb;

    //// Alokowanie pierwszego bar-u


    COE.current_O = current_OPUS;
    if (prev_opus == nullptr) {
        COE.current_O->first_BAR = new Bar(nullptr, nullptr, X_start_on_treb, DEFAULT_BAR_WIDTH, 0, COE.current_O->default_serial_key,
                                           COE.current_O->default_serial_key);
    }
    COE.current_B = COE.current_O->first_BAR;
    COE.current_B->X_of_start_bar = X_start_on_treb;
    COE.current_C = COE.current_B->first_chord_treb;

    get_serial_key(chosen_key, COE.current_O->default_serial_key);



    COE.current_note_index = COE.current_C->notes_number - 1;
    COE.current_hand = 0;

    int pressed_key;

    const Uint8 *KEY_STATE = SDL_GetKeyboardState(nullptr);
    put_all_bars_on_stave(COE.current_B, chosen_metre);
    SDL_BlitSurface(stave, &Rect_current_view, screen, nullptr);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5);

    while (!end) {
        while (SDL_PollEvent(&occurrence)) {
            if (occurrence.type == SDL_QUIT) {
                end = 1;
            }
            any_change = 0;

            if (!is_instruction_open && occurrence.type == SDL_MOUSEWHEEL) {
                any_change = 1;
                scroll_vertically(&occurrence);
            }

            if ((KEY_STATE[SDL_SCANCODE_LCTRL] && occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_h)) {
                is_instruction_open += 1;
                is_instruction_open %= 2;
                page_number = 0;
                SDL_Delay(300);
            }

            if (occurrence.type == SDL_KEYDOWN && occurrence.key.keysym.sym == SDLK_ESCAPE) {
                end = 1;
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
                SDL_BlitSurface(instructions_[page_number], nullptr, screen, nullptr);
                SDL_UpdateWindowSurface(window);
            }

            if (!is_instruction_open && occurrence.type == SDL_KEYDOWN) {
                any_change = 1;

                SDL_Delay(75);

                pressed_key = occurrence.key.keysym.sym;
                /////////// Zmiana szerokości aktualnego taktu
                if (pressed_key == SDLK_j || pressed_key == SDLK_m) {
                    change_bar_width(pressed_key, KEY_STATE, X_after_key);

                }
                ////////// Zmiana długości chord-u
                if (pressed_key == SDLK_k || pressed_key == SDLK_l) {
                    change_chord_len(pressed_key, KEY_STATE);
                }
                ///////// Zmiana ręki
                if (pressed_key == SDLK_LALT) {
                    change_hand();
                }
                //////// Zmiana edytowanej nuty
                if ((pressed_key == SDLK_UP || pressed_key == SDLK_DOWN)) {
                    change_note(pressed_key);
                }
                //////// Zmiana chord-u lub bar-u
                if (pressed_key == SDLK_LEFT || pressed_key == SDLK_RIGHT) {
                    change_chord_or_bar(pressed_key, KEY_STATE);
                }
                /////// Odkładanie nuty lub pauzy
                if (pressed_key == SDLK_a || pressed_key == SDLK_p ||
                    (SDLK_c <= pressed_key && pressed_key <= SDLK_h)) {
                    put_note_or_pause(pressed_key, KEY_STATE, COE.current_C->local_serial_key);
                }
                /////// Odkładanie znaku chromatycznego
                if ((pressed_key == SDLK_s || pressed_key == SDLK_b || pressed_key == SDLK_n ||
                     pressed_key == SDLK_x) && COE.current_C->notes_number > 0) {
                    put_accidental(pressed_key, KEY_STATE);
                }
                /////// Usuwanie nut i chord-ów
                if (pressed_key == SDLK_BACKSPACE) {
                    del_note_chord_bar(KEY_STATE, X_after_key);
                }
                ////// Tworzenie noewgo chord-u lub bar-u
                if (pressed_key == SDLK_SPACE) {
                    create_new_chord_bar(KEY_STATE, X_after_key);
                }

            }
            if (any_change && !is_instruction_open) {
                put_all_bars_on_stave(COE.current_O->first_BAR, chosen_metre);
                SDL_BlitSurface(stave, &Rect_current_view, screen, nullptr);
                SDL_UpdateWindowSurface(window);
                SDL_Delay(10);
            }

            if (occurrence.type == SDL_WINDOWEVENT && occurrence.window.event == SDL_WINDOWEVENT_RESIZED) {
                cout << "resizing event\n";
                this->resize_window();

            }

        }
    }

    COE.current_C = nullptr;
    put_all_bars_on_stave(COE.current_O->first_BAR, chosen_metre);
    SDL_SaveBMP(stave, "wynik.bmp");

    close_window();
    return current_OPUS;
}

void OpusEditor::resize_window() {
    SDL_FreeSurface(screen);
    screen = SDL_GetWindowSurface(window);
    SDL_BlitSurface(stave, nullptr, screen, nullptr);
    SDL_UpdateWindowSurface(window);
}
