
#ifndef SHLIB_H
#define SHLIB_H

/*
* This header file only has c libraries necessary to build the shell and some macros
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF 64
#define CURR_DIR 1024

#endif
