#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>

void catctl_change_tone(int type, int code, struct CatStatus status, 
    FILE* device) {
    char commandText[32];

    /* Construct the command string to enable or disable the tone, and set it */
    sprintf(commandText, "CN0%d%03d;", type, code);

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.sqlcode = code;
}

void catctl_change_squelch(int type, struct CatStatus status, FILE* device) {
    char commandText[32];

    /* Construct the command that picks the squelch type */
    sprintf(commandText, "CT0%d;", type);

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.sqltype = type;
}
