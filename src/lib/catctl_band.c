#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>


int catctl_string_band(char* mode) {
    return -1;
}
    

void catctl_change_band(int band, struct CatStatus status, FILE* device) {
    char commandText[32];


    /* Construct the command string */
    sprintf(commandText, "BS%02d;", band);

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.band = band;
}


void catctl_change_band_up(struct CatStatus status, FILE* device) {
    char commandText[32];

    /* Construct the command string */
    sprintf(commandText, "BU0;");

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.band++;
}
