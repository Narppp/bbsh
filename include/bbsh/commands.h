
#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdint.h>

// real commands that is executed by execvp
void exec_commands(char **tokens);

// custom command functions
int16_t bbsh_help(char **tokens);
int16_t bbsh_jmp(char **tokens, char *curr_dir);
int16_t bbsh_exit(char **tokens);

// command checker if their my own commands
int16_t custom_commands(char **tokens, char *curr_dir);
int16_t bbsh_redir(char **tokens);

#endif
