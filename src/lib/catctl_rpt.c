#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catctl.h>

int catctl_string_rptshift(char* string) {
    if(strcmp(string, "+") == 0)
        return CAT_SHIFT_UP;
    else if(strcmp(string, "-") == 0) 
        return CAT_SHIFT_DOWN;
    else if(strcmp(string, "s") == 0) 
        return CAT_SHIFT_SIMPLEX;
    
    return -1;
}

void catctl_change_rptshift(int type, struct CatStatus status, FILE* device) {
    char commandText[32];

    /* Construct the command string */
    sprintf(commandText, "OS0%d;", type);

    /* Write the command string */
    fwrite(commandText, 1, strlen(commandText), device);

    status.rptshift = type;
}
