#include "input.h"
#include "command.h"

#include <dirent.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    CommandState *pcstate;
} AppState;

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    CommandState cstate = { 0 };
    AppState state = { .pcstate = &cstate };

    char *inputBuffer;

    while(!state.pcstate->requestQuit) {

        do { inputBuffer = getInput(); } while (inputBuffer == NULL);

        runCommand(state.pcstate, inputBuffer);

    }

    return EXIT_SUCCESS;

}

