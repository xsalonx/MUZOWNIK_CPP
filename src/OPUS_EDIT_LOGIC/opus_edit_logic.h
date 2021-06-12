

#include "opus_editing_utils.h"

#ifndef PI_PROJECTSDL2_PART_LIB_OPUS_EDIT_LOGIC_H
#define PI_PROJECTSDL2_PART_LIB_OPUS_EDIT_LOGIC_H


int change_bar_width(int pressed_key, int *any_change, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, int X_after_key);
int change_chord_len(int pressed_key, int *any_change, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE);
int change_hand(struct current_OPUS_edits_ *COE);
int change_note(int pressed_key, struct current_OPUS_edits_ *COE);
int change_chord_or_bar(int pressed_key, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE);
int put_note_or_pause(int pressed_key, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, const char *serial_key);
int del_note_chord_bar(struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, int X_after_key);
int create_new_chord_bar(struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, int X_after_key, const char *default_serial_key);
int put_acci(int pressed_key, struct current_OPUS_edits_ *COE, const Uint8 *KEY_STATE, const char *default_serial_key);



#endif //PI_PROJECTSDL2_PART_LIB_OPUS_EDIT_LOGIC_H
