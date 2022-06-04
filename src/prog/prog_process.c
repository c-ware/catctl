#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <catctl.h> /* Library functions */
#include "prog_func.h" /* Program functions */

void catctl_process(struct CatctlArguments args) {
    FILE* device;
    struct CatStatus rigStatus;

    printf("Command: %s\n", args.command);
    device = fopen(args.serial, "wb");

    if(strcmp(args.command, "freq") == 0) {
        struct CatFrequency freq = catctl_string_freq(args.argument);
        catctl_change_freq(freq, rigStatus, device);
    }

    else if(strcmp(args.command, "mode") == 0) {
        char* mode = catctl_string_mode(args.argument);
        if(strcmp(mode, "?") == 0) {
            fprintf(stderr, "catctl: unknown mode '%s'\n", args.argument);
            exit(EXIT_FAILURE);
        }
        catctl_change_mode(mode, rigStatus, device);
    }


    else if(strcmp(args.command, "rptshift") == 0) {
        int mode = catctl_string_rptshift(args.argument);
        if(mode == -1) {
            fprintf(stderr, "catctl: unknown shift mode '%s'\n", args.argument);
            exit(EXIT_FAILURE);
        }
        catctl_change_rptshift(mode, rigStatus, device);
    }


    else if(strcmp(args.command, "band") == 0) {
        catctl_change_band(atoi(args.argument), rigStatus, device);
    }

    else {
        printf("catctl: unknown command '%s'\n", args.command);
    }

    printf("Done\n");
}
