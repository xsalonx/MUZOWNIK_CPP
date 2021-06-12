#include "opus_editing_utils.h"


void swap_notes(NOTE *n1, NOTE *n2) {
    int tmp;
    char c_tmp;
    tmp = n1->height;
    n1->height = n2->height;
    n2->height = tmp;

    c_tmp = n1->acci;
    n1->acci = n2->acci;
    n2->acci = c_tmp;

    c_tmp = n1->name;
    n1->name = n2->name;
    n2->name = c_tmp;

}
int get_note_index(NOTE *n) {

    int index = 0;
    switch (n->name) {
        case 'C':
            index = 0;
            break;
        case 'D':
            index = 2;
            break;
        case 'E':
            index = 4;
            break;
        case 'F':
            index = 5;
            break;
        case 'G':
            index = 7;
            break;
        case 'A':
            index = 9;
            break;
        case 'H':
            index = 11;
            break;
        default:
            break;
    }

    if (n->acci == 's') index = index + 1;
    if (n->acci == 'b') index = index - 1;

    index = index + n->height * 12;

    return index;
}
int compare_notes(NOTE *n1, NOTE *n2) {

    int i1, i2;
    i1 = get_note_index(n1);
    i2 = get_note_index(n2);

    if (i1 > i2) return 1;
    if (i1 == i2) return 0;
    if (i1 < i2) return -1;
}
int sort_uniq_notes(CHORD *chord_to_sort) {
    if (chord_to_sort->notes_number <= 1) return 0;
    int is_sorted = 0, i, opt, j;

    while (!is_sorted) {
        is_sorted = 1;
        for (i = 0; i < chord_to_sort->notes_number - 1; i++) {
            opt = compare_notes(&chord_to_sort->notes_[i], &chord_to_sort->notes_[i + 1]);
            if (opt == 1) {
                swap_notes(&chord_to_sort->notes_[i], &chord_to_sort->notes_[i + 1]);
                is_sorted = 0;
            } else if (opt == 0) {
                for (j = i + 1; j < chord_to_sort->notes_number - 1; j++) {
                    swap_notes(&chord_to_sort->notes_[j], &chord_to_sort->notes_[j + 1]);
                }
                is_sorted = 0;
                chord_to_sort->notes_number--;
            }
        }
    }
    return 0;
}
int get_serial_key(const char *chosen_key, char serial_key[7]) {

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
int is_acci_req(CHORD *chord_to_put, int k, const char *defauly_serial_key) {

    int i = 0;
    NOTE *n = &(chord_to_put->notes_[k]);
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
            (chord_to_put->prev == NULL && n->acci != defauly_serial_key[i]) ||
            (chord_to_put->prev != NULL && n->acci != chord_to_put->prev->local_serial_key[i])) {
        return 1;
    }

    return 0;
}
int get_space_for_chord(BAR *bar, BARS_SPACE *b_space, const int *metre) {

    int available_width = bar->width_ - DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE - DISTANCE_BEWTWEEN_LAST_NOTE_AND_BAR, i, j;
    double notes_periods[6][6], metre_quatient = (double)metre[0] / (double)metre[1];

    notes_periods[0][0] = 1;
    for (i = 1; i < 6; i++) {
        notes_periods[i][0] = notes_periods[i - 1][0] / 2;
        for (j = 1; j < 6; j++) {
            notes_periods[i][j] = notes_periods[i][0] * (2 - pow(2, -(double) j));
        }
    }


    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            b_space->widths_ni_[i][j] = (int) ((available_width * notes_periods[i][j]) / metre_quatient);
        }
    }
    return 0;
}
