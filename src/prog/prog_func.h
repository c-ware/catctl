#ifndef PROG_FUNC
#define PROG_FUNC 1

struct CatctlArguments {
    char* command;
    char* argument;
    char* serial;
    int opt_list;
};


int catctl_parameters(const char* option);
void catctl_error(const char* option, int type, int expected, int got);
struct CatctlArguments parse_arguments(int argc, char* argv[]);

void catctl_process(struct CatctlArguments args);

#endif
