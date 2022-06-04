#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>


char* catctl_string_mode(char* mode) {
    if(strcmp(mode, "fm") == 0) 
        return CAT_MODE_FM;
    else if(strcmp(mode, "am") == 0)
        return CAT_MODE_AM;
    else if(strcmp(mode, "lsb") == 0)
        return CAT_MODE_LSB;
    else if(strcmp(mode, "usb") == 0)
        return CAT_MODE_USB;
    else if(strcmp(mode, "cw") == 0)
        return CAT_MODE_CW_LSB;
    else if(strcmp(mode, "cw-lsb") == 0)
        return CAT_MODE_CW_LSB;
    else if(strcmp(mode, "cw-usb") == 0)
        return CAT_MODE_CW_USB;
    else if(strcmp(mode, "rtty") == 0)
        return CAT_MODE_RTTY_USB;
    else if(strcmp(mode, "rtty-usb") == 0)
        return CAT_MODE_RTTY_USB;
    else if(strcmp(mode, "rtty-lsb") == 0)
        return CAT_MODE_RTTY_LSB;
    else if(strcmp(mode, "am-nar") == 0)
        return CAT_MODE_AM_NAR;
    else if(strcmp(mode, "fm-nar") == 0)
        return CAT_MODE_FM_NAR;
    else if(strcmp(mode, "c4fm") == 0)
        return CAT_MODE_C4FM;

    return "?";
}
    

void catctl_change_mode(char* mode, struct CatStatus status, FILE* device) {
    char commandText[32];

    /* Construct the command string */
    sprintf(commandText, "MD0%s;", mode);

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.mode = mode;
}
