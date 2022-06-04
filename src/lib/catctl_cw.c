#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>


void catctl_change_breakin(int selector, struct CatStatus status, FILE* device) {
    char commandText[32];

    /* Construct the command string */
    sprintf(commandText, "BI%d;", selector);

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.breakin = selector;
}
