
#ifndef INPUTS_H
#define INPUTS_H

char *parse_normal_words(const char **input);
char *parse_quoted_words(const char **input);
char **tokenizer(const char *string, uint16_t *token_amount);
char *d_input(char *buffer);

#endif
