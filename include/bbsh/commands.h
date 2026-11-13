
#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdint.h>

void exec_commands(char **tokens);
int16_t custom_commands(char **tokens, char *curr_dir);

#endif
