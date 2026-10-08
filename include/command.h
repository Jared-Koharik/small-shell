#ifndef COMMAND_h
#define COMMAND_h

#include <stdbool.h>

#define COMMANDS_SIZE 4

typedef struct {
    bool requestQuit;
} CommandState;

void runCommand(CommandState *restrict pcstate, char* restrict buffer);

void getCommandState(void);

#endif