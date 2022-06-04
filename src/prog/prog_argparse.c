#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <catctl.h> /* Library functions */
#include "prog_func.h" /* Program functions */

#include "libarg.h" /* Dependency headers */


/* A required libarg callback function */
int catctl_parameters(const char* option) {
    if(strcmp(option, "-h") == 0)
        return 0;
    else if(strcmp(option, "-l") == 0)
        return 2; 

    /* Default case */
    return LIBARG_UNKNOWN_OPTION;
}

void catctl_error(const char* option, int type, int expected, int got) {
    if(type == LIBARG_ERR_UNKNOWN_OPTION) {
        fprintf(stderr, "catctl: unknown option '%s'\n", option);
        fprintf(stderr, "Please run 'catctl -h' for more information!\n");
    }

    if(type == LIBARG_ERR_PARAM_COUNT) {
        fprintf(stderr, "catctl: not enough parameters provided for");
        fprintf(stderr, "'%s' -- requires %d, only got %d.\n", 
            option, expected, got);
        fprintf(stderr, "Please run 'catctl -h' for more information!\n");
    }

    if(type == LIBARG_ERR_HELP) {
        printf("Usage: catctl (command) (argument) (serial)\n");
        printf("    -h          Display this help text\n");
        printf("    -b (baud)   Change serial port baud rate\n");
        printf("    command     CatCtl command to run\n");
        printf("    argument    Argument to the CatCtl command\n");
        printf("    serial      UNIX-style TTY device file for your radio\n");
        printf("For more information, please run \"man cware catctl\"\n");
    }

    if(type == LIBARG_ERR_ARG_COUNT) {
        fprintf(stderr, "catctl: not enough arguments were supplied.\n");
        fprintf(stderr, "Requires at least %d, only got %d\n", expected, got);
    }

    exit(EXIT_FAILURE);
}

struct CatctlArguments parse_arguments(int argc, char* argv[]) {
    int index = 0;
    struct CatctlArguments arguments = {0};
    struct LibargCallbacks libarg_callbacks = {0};
    
    /* Use this function to see if an argv[] string is a valid option or not */
    libarg_callbacks.is_option = libarg_is_unix_option;
    /* Use this function to say how many parameters each argument expects */
    libarg_callbacks.parameters = catctl_parameters;
    /* Use this function to handle and check for errors */
    libarg_callbacks.error = catctl_error;

    /* Did the user ask for help? */
    if(libarg_find_option("-h") != LIBARG_UNKNOWN_OPTION) {
        /* Display the help text. */
        catctl_error(NULL, LIBARG_ERR_HELP, 0, 0);
    }

    /* Verify that any passed arguments have the correct number of parameters */
    libarg_options_check();

    /* Make sure the user provided at least 3 words */
    if(libarg_count_positionals() != 3) {
        catctl_error(NULL, LIBARG_ERR_ARG_COUNT, 3, libarg_count_positionals());
    }

    /* Get the two main arguments */
    for(index = 1; index < argc; index++) {
        char* current_arg = argv[index];

        /* Disregard options for now */
        if(libarg_callbacks.is_option(current_arg) == 1) {
            index += libarg_count_parameters(index);
            continue;
        }

        if(arguments.command == NULL) {
            arguments.command = current_arg;
        }
        else if(arguments.argument == NULL) {
            arguments.argument = current_arg;
        }
        else if(arguments.serial == NULL) {
            arguments.serial = current_arg;
        }
        
    }

    return arguments;
}

