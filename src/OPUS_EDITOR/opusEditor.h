#ifndef MUZOWNIK_OPUSEDITOR_H
#define MUZOWNIK_OPUSEDITOR_H

#include "../STRUCTS/Opus.h"
#include <SDL2/SDL.h>

#define RIGHT_HAND 0
#define LEFT_HAND 1

#define BUTTONS_DELAY 50

class OpusEditor{
private:
    Opus *current_opus{};

    SDL_Window *window{};
    SDL_Surface *screen{};
    SDL_Renderer *renderer{};
    SDL_Texture *texture{};

    SDL_Surface *stave{};
    SDL_Surface *blank_stave{};
    SDL_Surface *stave_with_key_and_metre{};

    SDL_Rect Rect_current_view{};
    SDL_Surface *instructions_[3]{};

    OnStaveObjects OSO{};

    void resize_window();

    int any_change{};

    //// ON_STAVE_PUTTING
    //init_putting
    int get_path_to_key_bmp(const char chosen_key[2], char path_to_key_bmp[], int path_prefix_len, int hand) const;
    int get_path_to_metre_bmp(const int chosen_metre[2], char path_to_metre_bmp[], int path_prefix_len);

    int put_key(const char *chosen_key, int *X_star_on_lines);
    int put_metre(const int *chosen_metre, int *X_start_on_line, int brace);

    //putting
    int put_chord_on_treb_without_beam(Chord *chord_to_put, int *X_start, int brace, BarsSpace *b_space);
    int put_chord_on_bass_without_beam(Chord *chord_to_put, int *X_start, int brace, BarsSpace *b_space);
    int put_pause_on_stave_without_beam(Chord *chord_to_put, int *X_start, int brace, int hand, BarsSpace *b_space);
    int put_chord_on_stave_without_beam(Chord *chord_to_put, int *X_start, int hand, int brace, BarsSpace *b_space);
    int put_bar_on_stave(Bar *bar_to_put, int hand, int brace, const int chosen_metre[2]);
    int put_all_bars_on_stave(Bar *first_bar_to_put, const int chosen_metre[2]);

    //opus_editing_utils;
    int get_serial_key(const char *chosen_key, char serial_key[7]);
    int is_acci_req(Chord *chord_to_put, int k, const char *defauly_serial_key);
    int get_space_for_chord(Bar *bar, BarsSpace *b_space, const int *metre);



    //opus_edit_logic;
    int change_bar_width(int pressed_key, const Uint8 *KEY_STATE, int X_after_key);
    int change_chord_len(int pressed_key, const Uint8 *KEY_STATE);
    int change_hand();
    int change_note(int pressed_key);
    int change_chord_or_bar(int pressed_key, const Uint8 *KEY_STATE);
    int put_note_or_pause(int pressed_key, const Uint8 *KEY_STATE, const char *serial_key);
    int del_note_chord_bar(const Uint8 *KEY_STATE, int X_after_key);
    int create_new_chord_bar(const Uint8 *KEY_STATE, int X_after_key);
    int put_accidental(int pressed_key, const Uint8 *KEY_STATE);



    ////
    void open_window();
    void close_window();
    void init();
    void scroll_vertically(SDL_Event *occurrence);

public:
    OpusEditor() {
        init();
    }
    Opus *run(char chosen_key[2], int chosen_metre[2], Opus *prev_opus);
};




#endif //MUZOWNIK_OPUSEDITOR_H
