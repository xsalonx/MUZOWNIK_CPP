#include "OPUS_loadsave.h"

int fscanf_note(FILE *opus_text_file, Note *n) {

    if (n == nullptr) {
        return 1;
    }
    n->name = (char)getc(opus_text_file);
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }
    n->acci = (char)getc(opus_text_file);
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }
    n->height = (int)(getc(opus_text_file) - 48);
    if (getc(opus_text_file) != ')') {
        printf("Opus is written incorrectly");
        exit(1);
    }

    return 0;
}
Chord *fscanf_chord(FILE *opus_text_file) {

    Chord *chord;
    int i;
    char c;
    chord = new Chord;

    chord->time = getc(opus_text_file) - 48;
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }
    chord->_time_dots_ = getc(opus_text_file) - 48;
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }
    chord->ssp_articulation = getc(opus_text_file) - 48;
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }
    chord->notes_number = getc(opus_text_file) - 48;
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }
    chord->X_position = 0;
    while ((c = (char)getc(opus_text_file)) != ':') {
        chord->X_position *= 10;
        chord->X_position += ((int)c - 48);
    }

    for (i = 0; i < 7; i++) {
        chord->local_serial_key[i] = (char)getc(opus_text_file);
    }
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }

    for (i = 0; i < chord->notes_number; i++) {
        if (getc(opus_text_file) != '(') {
            printf("Opus is written incorrectly");
            exit(1);
        }
        fscanf_note(opus_text_file, &chord->notes_[i]);
    }

    if (getc(opus_text_file) != ']') {
        printf("Opus is written incorrectly");
        exit(1);
    }

    return chord;
}
Bar *fscanf_bar(FILE *opus_text_file) {

    Bar *bar;
    bar = new Bar;
    char c;
    bar->X_of_start_bar = 0;
    while ((c = (char)getc(opus_text_file)) != ':') {
        bar->X_of_start_bar *= 10;
        bar->X_of_start_bar += ((int)c - 48);
    }
    bar->width_ = 0;
    while ((c = (char)getc(opus_text_file)) != ':') {
        bar->width_ *= 10;
        bar->width_ += ((int)c - 48);
    }
    bar->brace = (int)getc(opus_text_file) - 48;
    if (getc(opus_text_file) != ':') {
        printf("Opus is written incorrectly");
        exit(1);
    }

    Chord *help_chord;
    bar->prev = nullptr;
    bar->next = nullptr;

    if (getc(opus_text_file) != '[') {
        printf("Opus is written incorrectly");
        exit(1);
    }

    bar->first_chord_treb = fscanf_chord(opus_text_file);
    help_chord = bar->first_chord_treb;
    help_chord->prev = nullptr;
    help_chord->next = nullptr;

    while ((c = (char)getc(opus_text_file)) != '|') {

        help_chord->next = fscanf_chord(opus_text_file);
        help_chord->next->prev = help_chord;
        help_chord = help_chord->next;
    }
    help_chord->next = nullptr;

    if (getc(opus_text_file) != '[') {
        printf("Opus is written incorrectly");
        exit(1);
    }

    bar->first_chord_bass = fscanf_chord(opus_text_file);
    help_chord = bar->first_chord_bass;
    help_chord->prev = nullptr;
    help_chord->next = nullptr;
    while ((c = (char)getc(opus_text_file)) != '}') {
        help_chord->next = fscanf_chord(opus_text_file);
        help_chord->next->prev = help_chord;
        help_chord = help_chord->next;
    }
    help_chord->next = nullptr;


    return bar;
}
Opus *fscanf_opus(const char *path) {

    Opus *opus;
    opus = new Opus;
    char c;
    int i;

    FILE *opus_text_file;
    if (path != nullptr) {
        if ((opus_text_file = fopen(path, "r")) == nullptr) {
            printf("Opening error\n");
            exit(1);
        }
    } else {
        if ((opus_text_file = fopen("opus.txt", "r")) == nullptr) {
            printf("Opening error\n");
            exit(1);
        }
    }
    i = 0;
    while ((c = (char)getc(opus_text_file)) != ':') {
        opus->title[i] = c;
        i++;
    }
    opus->title[i] = '\0';
    i = 0;
    while ((c = (char)getc(opus_text_file)) != ':') {
        opus->author[i] = c;
        i++;
    }
    opus->author[i] = '\0';

    opus->key[0] = (char)getc(opus_text_file);
    if ((c = (char)getc(opus_text_file)) != ':') {
        opus->key[1] = c;
        getc(opus_text_file);
    } else {
        opus->key[1] = '\0';
    }

    for (i = 0; i < 7; i++) {
        opus->default_serial_key[i] = (char)getc(opus_text_file);
    }
    getc(opus_text_file);

    fscanf(opus_text_file, "%d", &(opus->metre[0]));
    getc(opus_text_file);
    fscanf(opus_text_file, "%d", &(opus->metre[1]));
    getc(opus_text_file);
    fscanf(opus_text_file, "%d", &(opus->temp));
    getc(opus_text_file);

    if (getc(opus_text_file) != '{') {
        printf("Opus is written incorrectly");
        exit(1);
    }

    Bar *help_bar;
    opus->first_bar = fscanf_bar(opus_text_file);
    opus->first_bar->prev = nullptr;
    opus->first_bar->next = nullptr;
    help_bar = opus->first_bar;

    while (getc(opus_text_file) == '{') {

        help_bar->next = fscanf_bar(opus_text_file);
        help_bar->next->prev = help_bar;
        help_bar = help_bar->next;
    }
    help_bar->next = nullptr;

    fclose(opus_text_file);
    return opus;
}


int fprint_note(FILE *opus_text_file, Note *n) {

    fprintf(opus_text_file, "%c", '(');
    fprintf(opus_text_file, "%c:", n->name);
    fprintf(opus_text_file, "%c:", n->acci);
    fprintf(opus_text_file, "%d", n->height);
    fprintf(opus_text_file, "%c", ')');

    return 0;
}
int fprint_chord(FILE *opus_text_file, Chord *chord_to_print) {

    int i;
    fprintf(opus_text_file, "%c", '[');
    ///
    fprintf(opus_text_file, "%d:", chord_to_print->time);
    fprintf(opus_text_file, "%d:", chord_to_print->_time_dots_);
    fprintf(opus_text_file, "%d:", chord_to_print->ssp_articulation);
    fprintf(opus_text_file, "%d:", chord_to_print->notes_number);
    fprintf(opus_text_file, "%d:", chord_to_print->X_position);
    for (i = 0; i < 7; i++) {
        fprintf(opus_text_file, "%c", chord_to_print->local_serial_key[i]);
    }
    fprintf(opus_text_file, "%c", ':');
    for (i = 0; i < chord_to_print->notes_number; i++) {
        fprint_note(opus_text_file, &(chord_to_print->notes_[i]));
    }
    ///
    fprintf(opus_text_file, "%c", ']');

    return 0;
}
int fprint_bar(FILE *opus_text_file, Bar *bar_to_print) {

    Chord *help_chord = nullptr;
    fprintf(opus_text_file, "%c", '{');
    fprintf(opus_text_file, "%d:", bar_to_print->X_of_start_bar);
    fprintf(opus_text_file, "%d:", bar_to_print->width_);
    fprintf(opus_text_file, "%d:", bar_to_print->brace);

    help_chord = bar_to_print->first_chord_treb;
    while (help_chord != nullptr) {
        fprint_chord(opus_text_file, help_chord);
        help_chord = help_chord->next;
    }
    fprintf(opus_text_file, "%c", '|');
    help_chord = bar_to_print->first_chord_bass;
    while (help_chord != nullptr) {
        fprint_chord(opus_text_file, help_chord);
        help_chord = help_chord->next;
    }
    fprintf(opus_text_file, "%c", '}');

    return 0;
}
int save_Opus_as_TextFile(Opus *OPUS_to_save) {

    int i;
    FILE *opus_text_file = nullptr;
    if ((opus_text_file = fopen("opus.txt", "w")) == nullptr) {
        printf("Nie mogę otworzyć pliku test.txt do zapisu!\n");
        exit(1);
    }

    fprintf(opus_text_file, "%s:", OPUS_to_save->title);
    fprintf(opus_text_file, "%s:", OPUS_to_save->author);
    fprintf(opus_text_file, "%c", OPUS_to_save->key[0]);
    if (OPUS_to_save->key[1] == '\0') {
        fprintf(opus_text_file, "%c", ':');
    } else {
        fprintf(opus_text_file, "%c%c", OPUS_to_save->key[1],':');
    }
    for (i = 0; i < 7; i++){
        fprintf(opus_text_file, "%c", OPUS_to_save->default_serial_key[i]);
    }
    fprintf(opus_text_file, "%c", ':');

    fprintf(opus_text_file, "%d,%d:", OPUS_to_save->metre[0], OPUS_to_save->metre[1]);
    fprintf(opus_text_file, "%d:", OPUS_to_save->temp);

    Bar *bar_to_put = OPUS_to_save->first_bar;

    while (bar_to_put != nullptr) {
        fprint_bar(opus_text_file, bar_to_put);
        bar_to_put = bar_to_put->next;
    }

    fclose (opus_text_file);
    return 0;
}


/*
    opus_text_file:

    title:author:key:serial_key:metre:temp:
    {X_of_start_bar:width_:brace:
        [time:_time_dots_:ssp_articulation:notes_number:X_positon:local_serial_key:
            (name:acci:height)(...)...(...)
        ][...
        ]...[...
        ]
        | // pipe, left hand above, right hand beneath
        [...
        ]...[...
        ]
    }{...
    }...{...
    }EOF
*/
