#include "structs_mallfree.h"


CHORD *malloc_new_chord(CHORD *prev, CHORD *next, int X_position, const char *serial_key){

    int i;
    CHORD *new_chord = new CHORD;
    new_chord->prev = prev;
    new_chord->next = next;
    new_chord->notes_number = 0;
    new_chord->X_position = X_position;
    new_chord->time = 5;
    new_chord->_time_dots_ = 0;
    new_chord->ssp_articulation = 0;
    for (i = 0; i < 7; i++) {
        new_chord->local_serial_key[i] = serial_key[i];
    }


    return new_chord;
}
BAR *malloc_new_bar(BAR *prev, BAR *next, int X_of_start_bar, int width, int brace, const char *treb_serial_key,
                    const char *bass_serial_key) {

    BAR *new_bar = new BAR;
    new_bar->prev = prev;
    new_bar->next = next;
    new_bar->brace = brace;
    new_bar->X_of_start_bar = X_of_start_bar;
    new_bar->first_chord_bass = malloc_new_chord(NULL, NULL, X_of_start_bar + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE, bass_serial_key);
    new_bar->first_chord_treb = malloc_new_chord(NULL, NULL, X_of_start_bar + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE, treb_serial_key);
    if (X_of_start_bar + width > X_END_OF_STAVE) {
        new_bar->width_ = (X_END_OF_STAVE - X_of_start_bar);
    } else {
        new_bar->width_ = width;
    }
    new_bar->brace = brace;

    return new_bar;
}
int free_bar(BAR *bar_to_del) {

    if (bar_to_del == NULL) {
        return 1;
    }
    CHORD *help_chord = bar_to_del->first_chord_treb;
    while (help_chord->next != NULL) {
        help_chord = help_chord->next;
        free(help_chord->prev);
    } free(help_chord);

    help_chord = bar_to_del->first_chord_bass;
    while (help_chord->next != NULL) {
        help_chord = help_chord->next;
        free(help_chord->prev);
    } free(help_chord);

    return 0;
}
int free_opus(OPUS *opus_to_del) {

    BAR *help_bar = opus_to_del->first_BAR;
    while (help_bar->next != NULL) {
        help_bar = help_bar->next;
        free_bar(help_bar->prev);
    }
    free_bar(help_bar);
    free(opus_to_del);
    return 0;
}