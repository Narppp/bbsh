
#ifndef SHLIB_H
#define SHLIB_H

/*
* This header file only has c libraries necessary to build the shell and some macros
*/
#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

#define CURR_DIR 1024
#define PROMPT_SIZE 128

#endif
