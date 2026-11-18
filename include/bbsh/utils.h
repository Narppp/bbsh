
#ifndef UTILS_H
#define UTILS_H

void free_tokens(char **tokens, uint16_t token_count);
void bbsh_greeter(void);

char *sh_prompt(char *buffer, char *directory);
char *get_dir(char *directory);

int16_t check_tokens(char **tokens, uint16_t token_amount);

#endif
