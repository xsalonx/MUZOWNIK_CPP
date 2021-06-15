#ifndef MUZOWNIK_CHORD_H
#define MUZOWNIK_CHORD_H


#include "Note.h"

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
    Chord(Chord *prev, Chord *next, int X_position, const char *serial_key);
    ~Chord()=default;

    void swap_notes(int i, int j);
    int sort_uniq_notes();

};
#endif //MUZOWNIK_CHORD_H
