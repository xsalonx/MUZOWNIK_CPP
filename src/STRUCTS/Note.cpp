#include "Note.h"

int Note::index() const {

    int index = 0;
    switch (this->name) {
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

    if (this->acci == 's') index = index + 1;
    if (this->acci == 'b') index = index - 1;

    index = index + this->height * 12;

    return index;
}

int Note::cmp_notes(const Note &other) const {

    int i1, i2;
    i1 = this->index();
    i2 = other.index();

    if (i1 > i2) return 1;
    if (i1 == i2) return 0;
    if (i1 < i2) return -1;

    return 0;
}
