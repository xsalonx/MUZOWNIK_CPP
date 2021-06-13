#include "Bar.h"

Bar::Bar(Bar *prev, Bar *next, int X_of_start_bar, int width, int brace, const char *treb_serial_key,
const char *bass_serial_key): prev(prev), next(next), brace(brace), X_of_start_bar(X_of_start_bar) {

    this->first_chord_bass = new Chord(nullptr, nullptr, X_of_start_bar + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE, bass_serial_key);
    this->first_chord_treb = new Chord(nullptr, nullptr, X_of_start_bar + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE, treb_serial_key);
    if (X_of_start_bar + width > X_END_OF_STAVE) {
        this->width_ = (X_END_OF_STAVE - X_of_start_bar);
    } else {
        this->width_ = width;
    }
}

Bar::~Bar() {
    Chord *help_chord = this->first_chord_treb;
    while (help_chord->next != nullptr) {
        help_chord = help_chord->next;
        delete help_chord->prev;
    } delete help_chord;

    help_chord = this->first_chord_bass;
    while (help_chord->next != nullptr) {
        help_chord = help_chord->next;
        delete help_chord->prev;
    } delete help_chord;

}