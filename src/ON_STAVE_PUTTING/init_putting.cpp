//
// Created by Luksz on 2021-06-12.
//

#include "init_putting.h"

int get_path_to_key_bmp(const char chosen_key[2], char path_to_key_bmp[], int hand, int path_prefix_len) {

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
int get_path_to_metre_bmp(const int chosen_metre[2], char path_to_metre_bmp[], int path_prefix_len) {

    if (chosen_metre[0] < 10) {
        path_to_metre_bmp[path_prefix_len] = (char) (chosen_metre[0] + 48);
    } else {
        path_to_metre_bmp[path_prefix_len] = (char) ((int) ('g') + chosen_metre[0] - 16);
    }

    if (chosen_metre[1] < 10) {
        path_to_metre_bmp[path_prefix_len + 1] = (char) (chosen_metre[1] + 48);
    } else {
        path_to_metre_bmp[path_prefix_len + 1] = (char) ((int) ('g') + chosen_metre[1] - 16);
    }

    return 0;
}

int put_key(SDL_Surface *stave, const char chosen_key[2], OPUS *current_OPUS, int *X_star_on_line) {

    if (current_OPUS != NULL) {
        current_OPUS->key[0] = chosen_key[0];
        current_OPUS->key[1] = chosen_key[1];
    }

    if (chosen_key[0] == 'C' && chosen_key[1] == '\0') {
        return 0;
    }

    SDL_Surface *key_accidentals = NULL;
    SDL_Rect dst;
    dst.x = X_START_AFTER_KEY + 1;

    // Trzy zera ścieżki zostają podmienione na
    // znaki: ręka{t, b}, liczba znaków{1,..., 7}, typ znaku{s, b}
    char path_to_key_bmp[] = "obrazki/keys/000.bmp";
    const int path_prefix_len = 13;

    int hand, brace, diff_of_hights;

    for (hand = 0; hand < NUMBER_OF_HANDS; hand++) {

        if (get_path_to_key_bmp(chosen_key, path_to_key_bmp, hand, path_prefix_len)) {
            return 1;
        }
        if (key_accidentals != NULL) SDL_FreeSurface(key_accidentals);
        key_accidentals = SDL_LoadBMP(path_to_key_bmp);
        if (key_accidentals == NULL) {
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
            SDL_BlitSurface(key_accidentals, NULL, stave, &dst);

        }
    }

    SDL_FreeSurface(key_accidentals);
    return 0;
}
int put_metre(SDL_Surface *stave, const int chosen_metre[2], OPUS *current_OPUS, int *X_start_on_line, int brace) {

    if (current_OPUS != NULL) {
        current_OPUS->time_sign[0] = chosen_metre[0];
        current_OPUS->time_sign[1] = chosen_metre[1];
    }

    SDL_Surface *metre_sign = NULL;
    SDL_Rect dst;
    dst.x = *X_start_on_line + DISTANCE_BETWEEN_KEY_AND_METRE;
    dst.y = Y_FIRST_LINE;

    //// Two zeros are nunmerator and denomiantor metre.
    char path_to_metre_bmp[] = "obrazki/metre/metre_00.bmp";
    const int path_prefix_len = 20;
    get_path_to_metre_bmp(chosen_metre, path_to_metre_bmp, path_prefix_len);


    metre_sign = SDL_LoadBMP(path_to_metre_bmp);
    if (metre_sign == NULL) {
        return 1;
    }
    SDL_SetColorKey(metre_sign, SDL_TRUE, SDL_MapRGB(metre_sign->format, 255, 255, 255));

    int hands;
    for (hands = 0; hands < NUMBER_OF_HANDS; hands++) {

        dst.y = Y_FIRST_LINE + hands * DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES +
                brace * DISTANCE_BETWEEN_FIRST_LINE_BRACES;
        SDL_BlitSurface(metre_sign, NULL, stave, &dst);
    }

    *X_start_on_line = dst.x + metre_sign->w;
    SDL_FreeSurface(metre_sign);
    return 0;
}

