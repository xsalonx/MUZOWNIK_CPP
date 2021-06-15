#ifndef MUZOWNIK_OPUS_H
#define MUZOWNIK_OPUS_H

#include "Bar.h"

class Opus{
private:
    void Opus_init() {}

public:
    char title[50]{};
    char author[50]{};
    char key[2]{};
    int metre[2]{};
    int temp{};
    char default_serial_key[7]{};
    Bar *first_bar{};

    Opus()=default;
    Opus(const char chosen_key[2], const int chosen_metre[2]);
    ~Opus();

};

class OnStaveObjects{
public:
    Opus *opus{};
    Bar *bar{};
    Chord *chord{};
    int note_idx{};
    int hand{};

};

#endif //MUZOWNIK_OPUS_H
