#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>

#define CATCTL_MODE(name, retMacName) \
    if(strcmp(mode, name) == 0) \
        return CAT_MODE_ ## retMacName;

char* catctl_string_mode(char* mode) {
    CATCTL_MODE("fm", FM)
    CATCTL_MODE("am", AM)
    CATCTL_MODE("lsb", LSB)
    CATCTL_MODE("usb", USB)
    CATCTL_MODE("cw", CW_USB)
    CATCTL_MODE("cw-usb", CW_USB)
    CATCTL_MODE("cw-lsb", CW_LSB)
    CATCTL_MODE("rtty", RTTY_USB)
    CATCTL_MODE("rtty-usb", RTTY_USB)
    CATCTL_MODE("rtty-lsb", RTTY_LSB)
    CATCTL_MODE("data", DATA_USB)
    CATCTL_MODE("data-lsb", DATA_LSB)
    CATCTL_MODE("data-usb", DATA_USB)
    CATCTL_MODE("am-nar", AM_NAR)
    CATCTL_MODE("fm-nar", FM_NAR)
    CATCTL_MODE("c4fm", C4FM)
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
