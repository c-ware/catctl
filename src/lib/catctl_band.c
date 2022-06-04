#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>


char* catctl_string_band(char* band) {
    CATCTL_BAND("160m", 160);
    CATCTL_BAND("80m", 80);
    CATCTL_BAND("40m", 40);
    CATCTL_BAND("30m", 30);
    CATCTL_BAND("20m", 20);
    CATCTL_BAND("17m", 17);
    CATCTL_BAND("15m", 15);
    CATCTL_BAND("12m", 12);
    CATCTL_BAND("10m", 10);
    CATCTL_BAND("6m", 6);
    CATCTL_BAND("2m", 2);
    CATCTL_BAND("70cm", 70);
    CATCTL_BAND("gen", GENCOV);
    CATCTL_BAND("mw", MEDIUMWAVE);
    CATCTL_BAND("air", VHFAIR);
    return "?";
}
    

void catctl_change_band(char* band, struct CatStatus status, FILE* device) {
    char commandText[32];


    /* Construct the command string */
    sprintf(commandText, "BS%s;", band);

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
