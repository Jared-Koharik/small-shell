#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

#define SHELL_MAX_INPUT 100

bool getInput(char *restrict buff, int buffSize);
void flushInput(void);

#endif