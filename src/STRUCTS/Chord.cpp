#include "Chord.h"


Chord::Chord(Chord *prev, Chord *next, int X_position, const char *serial_key):
            prev(prev), next(next), X_position(X_position) {
    int i;
    //// TODO change to c++ style
    for (i = 0; i < 7; i++) {
        this->local_serial_key[i] = serial_key[i];
    }
}

void Chord::swap_notes(int i, int j) {
    Note n = this->notes_[j];
    this->notes_[j] = this->notes_[i];
    this->notes_[i] = n;
}
int Chord::sort_uniq_notes() {
    if (this->notes_number <= 1) return 0;
    int is_sorted = 0, i, opt, j;

    while (!is_sorted) {
        is_sorted = 1;
        for (i = 0; i < this->notes_number - 1; i++) {
            opt = this->notes_[i].cmp_notes(this->notes_[i + 1]);
            if (opt == 1) {
                this->swap_notes(i, i+1);
                is_sorted = 0;
            } else if (opt == 0) {
                for (j = i + 1; j < this->notes_number - 1; j++) {
                    this->swap_notes(j, j+1);
                }
                is_sorted = 0;
                this->notes_number--;
            }
        }
    }
    return 0;
}
