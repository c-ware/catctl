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
 * @embed macro_function: CATCTL_MODE
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

/* Band indices. Strings, because some radios use letters. */
#define CAT_BAND_160 "00"
#define CAT_BAND_80 "01"
#define CAT_BAND_40 "03"
#define CAT_BAND_30 "04"
#define CAT_BAND_20 "05"
#define CAT_BAND_17 "06"
#define CAT_BAND_15 "07"
#define CAT_BAND_12 "08"
#define CAT_BAND_10 "09"
#define CAT_BAND_6 "10"
#define CAT_BAND_GENCOV "11"
#define CAT_BAND_MEDIUMWAVE "12"
#define CAT_BAND_VHFAIR "14"
#define CAT_BAND_2 "15"
#define CAT_BAND_70 "16"

/* FM Squelch Modes */
#define CAT_SQL_NONE 0
#define CAT_SQL_TENCDEC 1
#define CAT_SQL_TENC 2
#define CAT_SQL_DENCDEC 3
#define CAT_SQL_DENC 4

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
 * @type: char*
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
    char* band;
	int micgain;
	int power;
	int volume;
    int breakin;
    int rptshift;
    int ptt;
    int sqltype;
    int sqlcode;
};

/* Macro-functions */

/*
 * @docgen: macro_function
 * @brief: Convert mode text names to mode indices. 
 * @name: CATCTL_MODE
 *
 * @notes
 * @This is ONLY usable within the catctl_string_mode function.
 * @notes
 *
 * @param name: Mode name, like "lsb"
 * @param macro: The CATCTL_MODE_xyz macro that returns an integer.
*/
#define CATCTL_MODE(name, macro) \
    if(strcmp(mode, name) == 0) \
        return CAT_MODE_ ## macro;


/*
 * @docgen: macro_function
 * @brief: Convert band text names like "70cm" or "10m" into band numbers.
 * @name: CATCTL_BAND
 *
 * @notes
 * @This is ONLY usable within the catctl_string_band function.
 * @notes
 *
 * @param name: Band name, like "6m"
 * @param macro: The CATCTL_MODE_xyz macro that returns an integer.
*/
#define CATCTL_BAND(name, macro) \
    if(strcmp(band, name) == 0) \
        return CAT_BAND_ ## macro;

/* Change frequency
 * FA014250000; <-- 14.250
 * FA007272000; <-- 7.272
 * FA050125000; <-- 50.125
 */

/* 
 * @docgen: function
 * @name: catctl_change_freq
 * @brief: Change frequency
 * @param freq: The frequency structure.
 * @type: struct CatFrequency
 * @param status: The rig status structure.
 * @type: struct CatStatus
 * @param device: The output device.
 * @type: FILE*
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

/* 
 * @docgen: function
 * @name: catctl_change_mode
 * @brief: Change mode
 * @param mode: The new mode, as a string.
 * @type: char*
 * @param status: The rig status structure.
 * @type: struct CatStatus
 * @param device: The output device.
 * @type: FILE*
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

/* 
 * @docgen: function
 * @name: catctl_change_volume
 * @brief: Change output volume
 * @param volume: The new volume, 0-255.
 * @type: int
 * @param status: The rig status structure.
 * @type: struct CatStatus
 * @param device: The output device.
 * @type: FILE*
*/
void catctl_change_volume(int volume, struct CatStatus status, FILE* device);

/* Change band
 * BS10; <- 6 meters
 */

/* 
 * @docgen: function
 * @name: catctl_change_band
 * @brief: Change tuned band
 * @param volume: The new band number
 * @type: char*
 * @param status: The rig status structure.
 * @type: struct CatStatus
 * @param device: The output device.
 * @type: FILE*
*/
void catctl_change_band(char* band, struct CatStatus status, FILE* device);

/*
 * Increment to the next band.
 */
void catctl_change_band_up(struct CatStatus status, FILE* device);

/* Convert a string to a band number
 */
char* catctl_string_band(char* band);

/* Toggle the PTT operator */
void catctl_change_ptt(int whence, struct CatStatus status, FILE* device);


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

/*
 * Change/enable a PL or DPL repeater tone.
 *
 * @param type: 0 for CTCSS, 1 for DCS
 * @param code: DCS or PL code (see the macro table)
 */
void catctl_change_tone(int type, int code, struct CatStatus status,
    FILE* device);

/*
 * Set the squelch type in FM.
 *
 * @param type: the squelch type macro
 */
void catctl_change_squelch(int type, struct CatStatus status, FILE* device);

#endif
