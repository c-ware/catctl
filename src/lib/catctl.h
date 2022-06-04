/*
 * @docgen: project
 * @name: Catctl
 * @brief: control amateur radios using the CAT protocol
 *
 * @description
 * @This is the manual page for the catctl library. For information on the
 * @catctl program, please run "man 1 catctl" to display it. 
 * @description
 * 
 * @embed structure: CatFrequency
 * @embed structure: CatStatus
*/


#ifndef CATCTL_H
#define CATCTL_H 1

#include <stdio.h>

/* CAT control library for all systems */

/* Mode macros */
#define CAT_MODE_LSB "1"
#define CAT_MODE_USB "2"
#define CAT_MODE_CW_USB "3"
#define CAT_MODE_FM "4"
#define CAT_MODE_AM "5"
#define CAT_MODE_RTTY_LSB "6"
#define CAT_MODE_CW_LSB "7"
#define CAT_MODE_DATA_LSB "8"
#define CAT_MODE_RTTY_USB "9"
#define CAT_MODE_DATA_FM "A"
#define CAT_MODE_FM_NAR "B"
#define CAT_MODE_DATA_USB "C"
#define CAT_MODE_AM_NAR "D"
#define CAT_MODE_C4FM "E"


/* Repeater shift macros */
#define CAT_SHIFT_SIMPLEX 0
#define CAT_SHIFT_UP 0
#define CAT_SHIFT_DOWN 0

/* Structures */

/*
 * @docgen: structure
 * @name: CatFrequency
 * @brief: The radio's current frequency
 * @field mhz: frequency MHz position
 * @type: int
 * @field khz: frequency KHz position
 * @type: int
 * @field hz: frequency hz position
 * @type: int
*/

struct CatFrequency {
	int mhz;
	int khz;
	int hz;
};


/*
 * @docgen: structure
 * @name: CatStatus
 * @brief: The status of the connected radio
 * @field frequency: radio frequency
 * @type: struct CatFrequency
 * @field mode: current mode letter
 * @type: char* 
 * @field band: current band number
 * @type: int
 * @field micgain: current microphone gain
 * @type: int
 * @field power: current RF output power
 * @type: int
 * @field volume: current AF volume
 * @type: int
 * @field rptshift: current repeater shift mode
 * @type: int
*/

struct CatStatus {
	struct CatFrequency frequency;
	char* mode;
    int band;
	int micgain;
	int power;
	int volume;
    int breakin;
    int rptshift;
};

/* Change frequency
 * FA014250000; <-- 14.250
 * FA007272000; <-- 7.272
 * FA050125000; <-- 50.125
 */
void catctl_change_freq(struct CatFrequency freq, struct CatStatus status,
    FILE* device);

/* Convert a string to a frequency
 */
struct CatFrequency catctl_string_freq(char* string);

/* Change Mode (the mode parm is NOT am/fm/whatnot)
 * MD01; <-- LSB
 * MD02; <-- USB
 * MD04; <-- FM
 */
void catctl_change_mode(char* mode, struct CatStatus status, FILE* device);

/* Read Mode (and update status)
 * 
 * MD0; <-- returns MD04; for FM
 */
int catctl_read_mode(struct CatStatus status, FILE* device);

/* Convert a mode name in plaintext to a mode character.
 */
char* catctl_string_mode(char* mode);

/* Set AF gain (volume) (returns a command string)
 * AG0070; <-- volume to 50
 */

void catctl_change_volume(int volume, struct CatStatus status, FILE* device);

/* Change band
 * BS10; <- 6 meters
 */
void catctl_change_band(int band, struct CatStatus status, FILE* device);

/*
 * Increment to the next band.
 */
void catctl_change_band_up(struct CatStatus status, FILE* device);

/* Convert a string to a band number
 */
int catctl_string_band(char* mode);


/* Control CW break-in
 * BI1; <--- enable
 */
void catctl_change_breakin(int selector, struct CatStatus status, FILE* device);

/* Change repeater shift
 * OS02; <--- negative shift
 */
void catctl_change_rptshift(int type, struct CatStatus status, FILE* device);

/* Convert +, -, or S to a shift macro
 */
int catctl_string_rptshift(char* string);

#endif
