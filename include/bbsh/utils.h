
#ifndef UTILS_H
#define UTILS_H

char *sh_prompt(char *prompt, char *curr_dir);
char *get_dir(char *prompt, char *curr_dir);
void free_tokens(char **tokens, uint16_t token_count);

#endif
