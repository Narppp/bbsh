
#ifndef UTILS_H
#define UTILS_H

char *sh_prompt(char *prompt);
char *get_dir(char *buffer);
void free_tokens(char **tokens, uint16_t token_count);

#endif
