#ifndef MUZOWNIK_OPUSEDITOR_H
#define MUZOWNIK_OPUSEDITOR_H

#include "../ON_STAVE_PUTTING/putting.h"
#include "../OPUS_EDIT_LOGIC/opus_edit_logic.h"



class OpusEditor{
private:
    Opus *current_OPUS{};

    SDL_Window *window{};
    SDL_Surface *screen{};
    SDL_Surface *stave{};
    SDL_Surface *blank_stave{};
    SDL_Surface *stave_with_key_and_metre{};

    SDL_Rect Rect_current_view{};
    SDL_Surface *instructions_[3]{};

    int hand{};
    //// ON_STAVE_PUTTING
    //init_putting
    int get_path_to_key_bmp(const char chosen_key[2], char path_to_key_bmp[], int path_prefix_len) const;
    int get_path_to_metre_bmp(const int chosen_metre[2], char path_to_metre_bmp[], int path_prefix_len);

    int put_key(const char chosen_key[2], int *X_star_on_lines);
    int put_metre(const int chosen_metre[2], int *X_start_on_line, int brace);

    //putting
    int put_chord_on_treb_without_beam(Chord *chord_to_put, int *X_start, int brace, const char serial_key[7], BarsSpace *b_space, struct CurrentOpusEdits *COE);
    int put_chord_on_bass_without_beam(Chord *chord_to_put, int *X_start, int brace, const char serial_key[7], BarsSpace *b_space, struct CurrentOpusEdits *COE);
    int put_pause_on_stave_without_beam(Chord *chord_to_put, int *X_start, int brace, int hand, BarsSpace *b_space, struct CurrentOpusEdits *COE);
    int put_chord_on_stave_without_beam(Chord *chord_to_put, int *X_start, int hand, int brace, const char *serial_key, BarsSpace *b_space, struct CurrentOpusEdits *COE);
    int put_bar_on_stave(Bar *bar_to_put, int hand, int brace, const char serial_key[7], const int chosen_metre[2], struct CurrentOpusEdits *COE);
    int put_all_bars_on_stave(Bar *first_bar_to_put, const char serial_key[7], const int chosen_metre[2], struct CurrentOpusEdits *COE);


    ////
    void open_window();
    void close_window();
    void init();
    void scroll_vertically(SDL_Rect *current, SDL_Event *occurrence);

public:
    OpusEditor() {
        init();
    }
    Opus *run(char chosen_key[2], int chosen_metre[2], Opus *prev_opus);
};




#endif //MUZOWNIK_OPUSEDITOR_H
