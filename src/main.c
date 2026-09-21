#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
extern char **environ;

#define MAX_INPUT 100
#define MAX_ARGS 30

#define ANSI_RESET "\033[0m"
#define ANSI_RED_BOLD "\033[1;31m"

#define DELIMITER " "

static bool getInput(char *restrict buff, int buffSize);
static void errorMsg(const char *restrict mess, ...);
static void flushInput();

int main(int argc, char **argv) {

    char buff[MAX_INPUT] = { 0 };

    while(!getInput(buff, MAX_INPUT));

    char *token = strtok(buff, DELIMITER);
    while(token != NULL) {
        token = strtok(NULL, DELIMITER);
    }

    return EXIT_SUCCESS;

}

static bool getInput(char *restrict buff, int buffSize) {

    printf("> ");

    fgets(buff, buffSize, stdin);

    char *pnewline = strchr(buff, '\n');
    if( pnewline == NULL ) { 
        errorMsg("Input is too long, the max input is: %d\n", MAX_INPUT);
        flushInput(); 
        return false;
    } else {
        *pnewline = '\0';
    }

    return true;
}

static void errorMsg(const char *restrict mess, ...) {

    va_list ap;
    char *array[MAX_ARGS + 1];
    int argno = 0;

    printf(ANSI_RED_BOLD "  ERROR" ANSI_RESET ": ");

    va_start(ap, mess);

    vprintf(mess, ap);

    va_end(ap);

}

static void flushInput() {
    char c = '0';
    while( c != '\n' && c != EOF) {
        c = getc(stdin);
    }
}