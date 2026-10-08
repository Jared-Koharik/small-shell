#include "input.h"
#include "msg.h"

#include <stdio.h>
#include <string.h>

#define SHELL_MAX_INPUT 100

static char inputBuffer[SHELL_MAX_INPUT] = { 0 };

static void flushInput(void);

char *getInput(void) {

    printf("> ");

    fgets(inputBuffer, SHELL_MAX_INPUT, stdin);

    char *pnewline = strchr(inputBuffer, '\n');
    if( pnewline == NULL ) { 
        errorMsg("Input is too long, the max input is: %d", SHELL_MAX_INPUT);
        flushInput(); 
        return NULL;
    } else {
        *pnewline = '\0';
    }

    return inputBuffer;
}

static void flushInput(void) {
    char c = '0';
    while( c != '\n' && c != EOF) {
        c = getc(stdin);
    }
}