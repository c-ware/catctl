#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <catctl.h> /* Library functions */
#include "prog_func.h" /* Program functions */


int main(int argc, char* argv[]) {
    struct CatctlArguments arguments = parse_arguments(argc, argv);

    catctl_process(arguments);

    return 0;
}


