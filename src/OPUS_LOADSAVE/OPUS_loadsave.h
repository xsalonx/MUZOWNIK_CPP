
#ifndef PI_PROJECTSDL2_PART_LIB_OPUS_LOADSAVE_H
#define PI_PROJECTSDL2_PART_LIB_OPUS_LOADSAVE_H

#include "../library.h"

int fscanf_note(FILE *opus_text_file, NOTE *n);
CHORD *fscanf_chord(FILE *opus_text_file);
BAR *fscanf_bar(FILE *opus_text_file);
OPUS *fscanf_opus(const char *path);


int fprint_note(FILE *opus_text_file, NOTE *n);
int fprint_chord(FILE *opus_text_file, CHORD *chord_to_print);
int fprint_bar(FILE *opus_text_file, BAR *bar_to_print);
int save_OPUS_as_TextFile(OPUS *OPUS_to_save);

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

#endif //PI_PROJECTSDL2_PART_LIB_OPUS_LOADSAVE_H
