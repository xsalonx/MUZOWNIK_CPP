//
// Created by Luksz on 2021-06-11.
//

#ifndef PI_PROJECTSDL2_PART_LIB_GEOMETRY_DEF_CODES_H
#define PI_PROJECTSDL2_PART_LIB_GEOMETRY_DEF_CODES_H


#ifndef __min
#define __min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef __max
#define __max(a, b) (((a) < (b)) ? (b) : (a))
#endif





#define SCREEN_HIGHT 860
#define MENU_SCREEN_WIDTH 810

#define X_TO_INSERT_OPTION_NEW 269
#define Y_TO_INSERT_OPTION_NEW 335
#define X_TO_INSERT_OPTION_OPEN 238
#define Y_TO_INSERT_OPTION_OPEN 450
#define X_TO_INSERT_OPTION_EXIT 295
#define Y_TO_INSERT_OPTION_EXIT 570
#define X_TO_INSERT_OPTION_TITLE 158
#define Y_TO_INSERT_OPTION_TITLE 105
#define X_TO_INSERT_OPTION_HELP 247
#define Y_TO_INSERT_OPTION_HELP 730


///Options codes: 0 - 7
///MENU OPTIONS CODES
#define MENU_EXIT_CODE 2
#define MENU_NEW_STAVE_CODE 0
#define MENU_LOAD_CODE 1
#define MENU_HELP_CODE 3
///WINDOW CODES
#define MENU_WINDOW_CODE 4
#define METRE_WINDOW_CODE 5
#define CREATING_WINDOW_CODE 6
#define LOADING_WINDOW_CODE 7
/////////////////////////////////

///Creating states modes:


#define X_STAVE_METRE_CHOOSING 135
#define FIRST_Y_METRE_CHOOSE 309
#define SECOND_Y_METRE_CHOOSE 432
#define FIRST_X_METRE_CHOOSE 297
#define SECOND_X_METRE_CHOOSE 357
#define THIRD_X_METRE_CHOOSE 397


#define X_START_AFTER_KEY 131
#define Y_FIRST_LINE 267
#define DISTANCE_BETWEEN_LINES 14
#define DISTANCE_BETWEEN_FIRST_LINE_HANDS_STAVES 180
#define DISTANCE_BETWEEN_FIRST_LINE_BRACES 382
#define DISTANCE_BETWEEN_KEY_AND_METRE 10
#define X_END_OF_STAVE 1634

#define DISTANCE_BETWEEN_ACCI_AND_NOTE 13
#define DISTANCE_BETWEEN_BAR_AND_FIRST_NOTE 15
#define DISTANCE_BEWTWEEN_LAST_NOTE_AND_BAR 6



#define Y_OF_FIRST_LINE_TREB_SHARP_KEY 28
#define Y_OF_FIRST_LINE_BASS_SHARP_KEY 27
#define Y_OF_FIRST_LINE_TREB_BMOL_KEY 19
#define Y_OF_FIRST_LINE_BASS_BMOL_KEY 5

#define WIDTH_TIME_DOTS 5
#define DEFAULT_BAR_WIDTH 450
#define WIDTH_BAR_LINE 2
#define WIDTH_NOTES_WITH_FLAGS 31
#define WIDTH_NOTES_WITHOUT_FLAG 19
#define Y_OF_BETWEEN_LINE_NOTES 43
#define Y_OF_ON_LINE_NOTES 51
#define X_OF_NOTES_WITH_FLAG 11
#define Y_OF_METRE 0
#define Y_OF_PAUSE 0
#define MIN_BAR_WIDTH 40

#define STEP_IN_BAR_WIDTH_CHANGING_WITHOUT_SHIFT 1
#define STEP_IN_BAR_WIDTH_CHANGING_WITH_SHIFT 10

#define Y_OF_ACCI_B_ON_LINE 26
#define Y_OF_ACCI_S_ON_LINE 21
#define Y_OF_ACCI_N_ON_LINE 21
#define Y_OF_ACCI_B_BETWEEN_LINE 19
#define Y_OF_ACCI_S_BETWEEEN_LINE 15
#define Y_OF_ACCI_N_BETWEEEN_LINE 15


/// Sounds maping:
#define C_note 0
#define Cis_note 1 //Des
#define D_note 2
#define Dis_note 3 //Es
#define E_note 4 //Fes
#define F_note 5 //Eis
#define Fis_note 6 //Ges
#define G_note 7
#define Gis_note 8 //As
#define A_note 9
#define B_note 10 //Ais
#define H_note 11 //Ces

/// Sounds maping to serial_key:
#define C_in_serial_key 0
#define D_in_serial_key 1
#define E_in_serial_key 2
#define F_in_serial_key 3
#define G_in_serial_key 4
#define A_in_serial_key 5
#define H_in_serial_key 6

#endif //PI_PROJECTSDL2_PART_LIB_GEOMETRY_DEF_CODES_H
