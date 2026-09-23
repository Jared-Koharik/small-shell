#include "msg.h"

#include <stdarg.h>
#include <stdio.h>

#define ANSI_RESET "\033[0m"
#define ANSI_BOLD "\033[1m"
#define ANSI_RED_BOLD "\033[1;31m"

void errorMsg(const char *restrict mess, ...) {

    va_list ap;

    printf(ANSI_RED_BOLD "  ERROR" ANSI_RESET ": ");

    va_start(ap, mess);

    vprintf(mess, ap);

    va_end(ap);

    printf("\n");

}

void logMsg(const char *restrict mess, ...) {

    va_list ap;

    printf(ANSI_BOLD " LOG" ANSI_RESET ": ");

    va_start(ap, mess);

    vprintf(mess, ap);

    va_end(ap);

    printf("\n");

}
