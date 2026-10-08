#include "command.h"
#include "msg.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define DELIMITER_SPACE " "
#define DELIMITER_DASH "-"

static void commandQuit(CommandState *restrict pcstate, const char *restrict options, ...);
static void commandShow(CommandState *restrict pcstate, const char *restrict options, ...);
static void commandList(CommandState *restrict pcstate, const char *restrict options, ...);
static void commandHelp(CommandState *restrict pcstate, const char *restrict options, ...);

typedef void (*CommandFunc)(CommandState *restrict pcstate, const char *restrict options, ...);
static CommandFunc commandFuncs[COMMANDS_SIZE] = {
    commandQuit,
    commandShow,
    commandHelp,
    commandList,
};

static char *commandStrings[COMMANDS_SIZE] = {
    "quit",
    "show",
    "help",
    "list",
};

void runCommand(CommandState *restrict pcstate, char* restrict buffer) {

    // Look for the first set of characters ending with DELIMITER_STR

    const char *command = strtok(buffer, DELIMITER_SPACE);
    if(command == NULL) {
        errorMsg("No input was entered");
        return;
    }

    // Get pointer to options ending with null character

    const char *options = strtok(NULL, DELIMITER_DASH);
    if(options != NULL) {
        logMsg(options);
    }
    
    for(uint8_t i = 0; i < COMMANDS_SIZE; i++) {
        if(strcmp(command, commandStrings[i]) == 0 ) {
            commandFuncs[i](pcstate, options);
            return;
        }
    }

    errorMsg("Command was not recognized, type 'help' for a list of commands");

}

static void commandQuit(CommandState *restrict pcstate, const char *restrict options, ...) {
    (void)options;
    pcstate->requestQuit = true;
}
static void commandShow(CommandState *restrict pcstate, const char *restrict options, ...) {
    (void)pcstate;

    va_list ap;

    va_start(ap, options);

    vprintf(options, ap);

    printf("\n");

    va_end(ap);

}
static void commandList(CommandState *restrict pcstate, const char *restrict options, ...) {
    (void)pcstate;
    (void)options;

    DIR *directory = opendir(".");

    struct dirent *dirent = readdir(directory);

    while(dirent != NULL) {
        printf("    %s\n", dirent->d_name);
        dirent = readdir(directory);
    }

}
static void commandHelp(CommandState *restrict pcstate, const char *restrict options, ...) {
    (void)pcstate;
    (void)options;
    for(int i = 0; i < COMMANDS_SIZE; i++) {
        printf("    %s\n", commandStrings[i]);
    }
}