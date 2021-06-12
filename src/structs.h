#ifndef PI_PROJECTSDL2_PART_LIB_STRUCTS_H
#define PI_PROJECTSDL2_PART_LIB_STRUCTS_H

#define NUMBER_OF_LINES 5
#define NUMBER_OF_HANDS 2
#define NUMBER_OF_BRACES 5
#define MAX_NOTES_IN_CHORD 7

struct note{

    char name;
    char acci;
    int height;
    int may_print_acci;
};

////W przypadku poniższych struktur nie używa się wartowników
struct chord{

    int time;
    int _time_dots_;
    int ssp_articulation;
    int notes_number;
    struct note notes_[MAX_NOTES_IN_CHORD];
    struct chord *prev;
    struct chord *next;
    int X_position;
    char local_serial_key[7];
};
struct bars_space{

    int widths_ni_[6][6];
};
struct bar{

    struct chord *first_chord_treb;
    struct chord *first_chord_bass;
    struct bar *prev;
    struct bar *next;
    int X_of_start_bar;
    int width_;
    struct bars_space b_space;
    int brace;
};
struct OPUS{

    char title[50];
    char author[50];
    char key[2];
    int time_sign[2];
    int temp;
    struct bar *first_BAR;
    char default_serial_key[7];
};

typedef struct note NOTE;
typedef struct chord CHORD;
typedef struct bar BAR;
typedef struct OPUS OPUS;
typedef struct bars_space BARS_SPACE;

struct current_OPUS_edits_{

    OPUS *current_O;
    BAR *current_B;
    CHORD *current_C;
    int current_hand;
    int current_note_index;

};


#endif //PI_PROJECTSDL2_PART_LIB_STRUCTS_H
