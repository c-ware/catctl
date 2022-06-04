#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>

struct CatFrequency catctl_string_freq(char* string) {
    struct CatFrequency freq;
    char* leftSide;
    char* rightSide;
    char* copy;

    copy = string;
    leftSide = strtok_r(string, ".", &string);
    rightSide = strtok_r(string, "\n", &string);

    freq.mhz = atoi(leftSide);
    freq.khz = atoi(rightSide);
    freq.hz = 0;
    
    return freq;
}


void catctl_change_freq(struct CatFrequency freq, struct CatStatus status, FILE* device) {
    char commandText[32];

    /* Shift the KHz value over to pad it */
    if((freq.khz > 0) && (freq.khz < 99))
        freq.khz *= 100;
    else if((freq.khz > 100) && (freq.khz < 999))
        freq.khz *= 10;

    /* Construct the command string */
    sprintf(commandText, "FA%03d%d%02d;", 
        freq.mhz, freq.khz, freq.hz);

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.frequency = freq;
}
