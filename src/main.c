#include "input.h"
#include "msg.h"

#include <dirent.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 30

#define DELIMITER " "

#define COMMANDS_SIZE 4

static bool quit = false;

static char *commands[COMMANDS_SIZE] = {
    "quit",
    "show",
    "list",
    "help",
};

static void commandQuit(char *options, ...);
static void commandShow(char *options, ...);
static void commandList(char *options, ...);
static void commandHelp(char *options, ...);

typedef void (*CommandFunc)(char *options, ...);
static CommandFunc commandFuncs[COMMANDS_SIZE] = {
    commandQuit,
    commandShow,
    commandList,
    commandHelp,
};

int main(int argc, char **argv) {

    char buff[SHELL_MAX_INPUT] = { 0 };

    while(!quit) {

        while(!getInput(buff, SHELL_MAX_INPUT));

        char *command = strtok(buff, DELIMITER);

        uint8_t i;
        for(i = 0; i < COMMANDS_SIZE; i++) {
            if(strcmp(command, commands[i]) == 0 ) {
                commandFuncs[i](strchr(buff, '\0') + 1);
                break;
            }
        }
        if(i == COMMANDS_SIZE) {
            errorMsg("Command is not recognized");
        }

    }

    return EXIT_SUCCESS;

}

static void commandQuit(char *options, ...) {
    quit = true;
}
static void commandShow(char *options, ...) {

    va_list ap;

    va_start(ap, options);

    vprintf(options, ap);

    printf("\n");

    va_end(ap);

}
static void commandList(char *options, ...) {

}
static void commandHelp(char *options, ...) {
    for(int i = 0; i < COMMANDS_SIZE; i++) {
        printf("  %s\n", commands[i]);
    }
}