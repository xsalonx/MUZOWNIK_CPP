#include "Opus.h"

Opus::Opus(const char chosen_key[2], const int chosen_metre[2]) {
    this->key[0] = chosen_key[0];
    this->key[1] = chosen_key[1];
    this->metre[0] = chosen_metre[0];
    this->metre[1] = chosen_metre[1];

    for (int i = 0; i < 10; i++) {
        this->title[i] = 'x';
        this->author[i] = 'x';
    }
    this->title[10] = '\0';
    this->author[10] = '\0';
    this->temp = 60;

}

Opus::~Opus() {
    Bar *help_bar = this->first_bar;
    while (help_bar->next != nullptr) {
        help_bar = help_bar->next;
        delete help_bar->prev;
    }
    delete help_bar;
}