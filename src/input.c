#include "input.h"
#include "msg.h"

#include <stdio.h>
#include <string.h>


bool getInput(char *restrict buff, int buffSize) {

    printf("> ");

    fgets(buff, buffSize, stdin);

    char *pnewline = strchr(buff, '\n');
    if( pnewline == NULL ) { 
        errorMsg("Input is too long, the max input is: %d", SHELL_MAX_INPUT);
        flushInput(); 
        return false;
    } else {
        *pnewline = '\0';
    }

    return true;
}

void flushInput(void) {
    char c = '0';
    while( c != '\n' && c != EOF) {
        c = getc(stdin);
    }
}