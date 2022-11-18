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

/* FM Squelch Tones (PL tones) */
#define CAT_PL_TONE_000 67.0
#define CAT_PL_TONE_001 69.3
#define CAT_PL_TONE_002 71.9
#define CAT_PL_TONE_003 74.4
#define CAT_PL_TONE_004 77.0
#define CAT_PL_TONE_005 79.7
#define CAT_PL_TONE_006 82.5
#define CAT_PL_TONE_007 85.4
#define CAT_PL_TONE_008 88.5
#define CAT_PL_TONE_009 91.5
#define CAT_PL_TONE_010 94.8
#define CAT_PL_TONE_011 97.4
#define CAT_PL_TONE_012 100.0
#define CAT_PL_TONE_013 103.5
#define CAT_PL_TONE_014 107.2
#define CAT_PL_TONE_015 110.9
#define CAT_PL_TONE_016 114.8
#define CAT_PL_TONE_017 118.8
#define CAT_PL_TONE_018 123.0
#define CAT_PL_TONE_019 127.3
#define CAT_PL_TONE_020 131.8
#define CAT_PL_TONE_021 136.5
#define CAT_PL_TONE_022 141.3
#define CAT_PL_TONE_023 146.2
#define CAT_PL_TONE_024 151.4
#define CAT_PL_TONE_025 156.7
#define CAT_PL_TONE_026 159.8
#define CAT_PL_TONE_027 162.2
#define CAT_PL_TONE_028 165.5
#define CAT_PL_TONE_029 167.9
#define CAT_PL_TONE_030 171.3
#define CAT_PL_TONE_031 173.8
#define CAT_PL_TONE_032 177.3
#define CAT_PL_TONE_033 179.9
#define CAT_PL_TONE_034 183.5
#define CAT_PL_TONE_035 186.2
#define CAT_PL_TONE_036 189.9
#define CAT_PL_TONE_037 192.8
#define CAT_PL_TONE_038 196.6
#define CAT_PL_TONE_039 199.5
#define CAT_PL_TONE_040 203.5
#define CAT_PL_TONE_041 206.5 
#define CAT_PL_TONE_042 210.7 
#define CAT_PL_TONE_043 218.1 
#define CAT_PL_TONE_044 225.7 
#define CAT_PL_TONE_045 229.1 
#define CAT_PL_TONE_046 233.6 
#define CAT_PL_TONE_047 241.8 
#define CAT_PL_TONE_048 250.3 
#define CAT_PL_TONE_049 254.1 

/* DPL/DCS codes */
#define CAT_DPL_CODE_000 023 
#define CAT_DPL_CODE_001 025
#define CAT_DPL_CODE_002 026 
#define CAT_DPL_CODE_003 031
#define CAT_DPL_CODE_004 032
#define CAT_DPL_CODE_005 036
#define CAT_DPL_CODE_006 043
#define CAT_DPL_CODE_007 047
#define CAT_DPL_CODE_008 051
#define CAT_DPL_CODE_009 053
#define CAT_DPL_CODE_010 054
#define CAT_DPL_CODE_011 065
#define CAT_DPL_CODE_012 071
#define CAT_DPL_CODE_013 072 
#define CAT_DPL_CODE_014 073 
#define CAT_DPL_CODE_015 074 
#define CAT_DPL_CODE_016 114
#define CAT_DPL_CODE_017 115
#define CAT_DPL_CODE_018 116
#define CAT_DPL_CODE_019 122
#define CAT_DPL_CODE_020 125
#define CAT_DPL_CODE_021 131
#define CAT_DPL_CODE_022 132
#define CAT_DPL_CODE_023 134
#define CAT_DPL_CODE_024 143
#define CAT_DPL_CODE_025 145
#define CAT_DPL_CODE_026 152
#define CAT_DPL_CODE_027 155
#define CAT_DPL_CODE_028 156
#define CAT_DPL_CODE_029 162
#define CAT_DPL_CODE_030 165 
#define CAT_DPL_CODE_031 172
#define CAT_DPL_CODE_032 174
#define CAT_DPL_CODE_033 205
#define CAT_DPL_CODE_034 212
#define CAT_DPL_CODE_035 223
#define CAT_DPL_CODE_036 225
#define CAT_DPL_CODE_037 226
#define CAT_DPL_CODE_038 243
#define CAT_DPL_CODE_039 244
#define CAT_DPL_CODE_040 245
#define CAT_DPL_CODE_041 246
#define CAT_DPL_CODE_042 251
#define CAT_DPL_CODE_043 252
#define CAT_DPL_CODE_044 255
#define CAT_DPL_CODE_045 261
#define CAT_DPL_CODE_046 263
#define CAT_DPL_CODE_047 265
#define CAT_DPL_CODE_048 266
#define CAT_DPL_CODE_049 271
#define CAT_DPL_CODE_050 274
#define CAT_DPL_CODE_051 306
#define CAT_DPL_CODE_052 311
#define CAT_DPL_CODE_053 315
#define CAT_DPL_CODE_054 325
#define CAT_DPL_CODE_055 331
#define CAT_DPL_CODE_056 332
#define CAT_DPL_CODE_057 343
#define CAT_DPL_CODE_058 346
#define CAT_DPL_CODE_059 351
#define CAT_DPL_CODE_060 356
#define CAT_DPL_CODE_061 364 
#define CAT_DPL_CODE_062 365
#define CAT_DPL_CODE_063 371
#define CAT_DPL_CODE_064 411
#define CAT_DPL_CODE_065 412
#define CAT_DPL_CODE_066 413
#define CAT_DPL_CODE_067 423
#define CAT_DPL_CODE_068 431
#define CAT_DPL_CODE_069 432
#define CAT_DPL_CODE_070 445
#define CAT_DPL_CODE_071 446
#define CAT_DPL_CODE_072 452
#define CAT_DPL_CODE_073 454
#define CAT_DPL_CODE_074 455
#define CAT_DPL_CODE_075 462
#define CAT_DPL_CODE_076 464
#define CAT_DPL_CODE_077 465
#define CAT_DPL_CODE_078 466
#define CAT_DPL_CODE_079 503
#define CAT_DPL_CODE_080 506
#define CAT_DPL_CODE_081 516
#define CAT_DPL_CODE_082 523
#define CAT_DPL_CODE_083 526
#define CAT_DPL_CODE_084 532
#define CAT_DPL_CODE_085 546
#define CAT_DPL_CODE_086 565
#define CAT_DPL_CODE_087 606
#define CAT_DPL_CODE_088 612
#define CAT_DPL_CODE_089 624
#define CAT_DPL_CODE_090 627
#define CAT_DPL_CODE_091 631
#define CAT_DPL_CODE_092 632
#define CAT_DPL_CODE_093 654
#define CAT_DPL_CODE_094 662
#define CAT_DPL_CODE_095 664
#define CAT_DPL_CODE_096 703
#define CAT_DPL_CODE_097 712
#define CAT_DPL_CODE_098 723
#define CAT_DPL_CODE_099 731
#define CAT_DPL_CODE_100 732
#define CAT_DPL_CODE_101 734
#define CAT_DPL_CODE_102 743
#define CAT_DPL_CODE_103 754

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
