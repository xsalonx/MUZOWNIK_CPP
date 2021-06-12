#ifndef PI_PROJECTSDL2_PART_LIB_STRUCTS_H
#define PI_PROJECTSDL2_PART_LIB_STRUCTS_H

#define NUMBER_OF_LINES 5
#define NUMBER_OF_HANDS 2
#define NUMBER_OF_BRACES 5
#define MAX_NOTES_IN_CHORD 7

#include "geometry_def_codes.h"

struct Note{
    char name;
    char acci;
    int height;
    int may_print_acci;
};

//// No sentinels when using those classes
class Chord{
public:
    int time{5};
    int _time_dots_{};
    int ssp_articulation{};
    int notes_number{};
    Note notes_[MAX_NOTES_IN_CHORD]{};
    Chord *prev{};
    Chord *next{};
    int X_position{};
    char local_serial_key[7]{};

    Chord()=default;
    Chord(Chord *prev, Chord *next, int X_position, const char *serial_key): prev(prev), next(next), X_position(X_position) {
        int i;
        //// TODO change to c++ style
        for (i = 0; i < 7; i++) {
            this->local_serial_key[i] = serial_key[i];
        }
    }
    ~Chord()=default;

};
struct BarsSpace{

    int widths_ni_[6][6];
};
class Bar{
public:
    Chord *first_chord_treb{};
    Chord *first_chord_bass{};
    Bar *prev{};
    Bar *next{};
    int X_of_start_bar{};
    int width_{};
    BarsSpace b_space{};
    int brace{};

    Bar()=default;
    Bar(Bar *prev, Bar *next, int X_of_start_bar, int width, int brace, const char *treb_serial_key,
        const char *bass_serial_key): prev(prev), next(next), brace(brace), X_of_start_bar(X_of_start_bar) {

        this->first_chord_bass = new Chord(nullptr, nullptr, X_of_start_bar + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE, bass_serial_key);
        this->first_chord_treb = new Chord(nullptr, nullptr, X_of_start_bar + DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE, treb_serial_key);
        if (X_of_start_bar + width > X_END_OF_STAVE) {
            this->width_ = (X_END_OF_STAVE - X_of_start_bar);
        } else {
            this->width_ = width;
        }
    }
    ~Bar() {
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
};
class Opus{
public:
    char title[50]{};
    char author[50]{};
    char key[2]{};
    int time_sign[2]{};
    int temp{};
    Bar *first_BAR{};
    char default_serial_key[7]{};

    Opus()=default;
    ~Opus() {
        Bar *help_bar = this->first_BAR;
        while (help_bar->next != nullptr) {
            help_bar = help_bar->next;
            delete help_bar->prev;
        }
        delete help_bar;
    }

};

typedef struct Note Note;

class CurrentOpusEdits{
public:
    Opus *current_O;
    Bar *current_B;
    Chord *current_C;
    int current_hand;
    int current_note_index;

};


#endif //PI_PROJECTSDL2_PART_LIB_STRUCTS_H
