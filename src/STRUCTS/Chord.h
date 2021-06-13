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
    Chord(Chord *prev, Chord *next, int X_position, const char *serial_key): prev(prev), next(next), X_position(X_position) {
        int i;
        //// TODO change to c++ style
        for (i = 0; i < 7; i++) {
            this->local_serial_key[i] = serial_key[i];
        }
    }
    ~Chord()=default;

};
#endif //MUZOWNIK_CHORD_H
