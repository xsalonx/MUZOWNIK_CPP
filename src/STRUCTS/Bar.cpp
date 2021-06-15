#include "Bar.h"

const double Bar::chords_spaces[6][6] = {
        {1.0, 1.5, 1.75, 1.875, 1.9375, 1.96875},
        {0.5, 0.75, 0.875, 0.9375, 0.96875, 0.984375},
        {0.25, 0.375, 0.4375, 0.46875, 0.484375, 0.4921875},
        {0.125, 0.1875, 0.21875, 0.234375, 0.2421875, 0.24609375},
        {0.0625, 0.09375, 0.109375, 0.1171875, 0.12109375, 0.123046875},
        {0.03125, 0.046875, 0.0546875, 0.05859375, 0.060546875, 0.0615234375}
};

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

double Bar::get_current_time_taken(int hand) const {
    Chord *help_chord;
    if (hand == 0) help_chord = this->first_chord_treb;
    else help_chord = this->first_chord_bass;
    double time_taken = 0;
    while (help_chord != nullptr) {
        time_taken += Bar::chords_spaces[help_chord->time][help_chord->_time_dots_];
        help_chord = help_chord->next;
    }
    return time_taken;
}
