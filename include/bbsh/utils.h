
#ifndef UTILS_H
#define UTILS_H

char *sh_prompt(char *buffer, char *directory);
char *get_dir(char *directory);
void free_tokens(char **tokens, uint16_t token_count);

#endif
