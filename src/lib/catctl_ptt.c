#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>

void catctl_change_ptt(int whence, struct CatStatus status, FILE* device) {
    char commandText[32];

    /* Construct the command string */
    if(whence == 1) {
        sprintf(commandText, "TX2;");
        status.ptt = 1;
    }
    else if(whence == 0) {
        sprintf(commandText, "TX0;");
        status.ptt = 0;
    }

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);
}
