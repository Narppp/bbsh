
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>

int main(void)
{
        uint16_t token_amount = 0;
        char prompt[PROMPT_SIZE] = {0};
        char *buffer = NULL;
        char **tokens = NULL;

        while (1) {
                buffer = sh_prompt(prompt);
                tokens = tokenizer(buffer, &token_amount);

                if (tokens == NULL || tokens[0] == NULL) {
                        free(buffer);
                        free_tokens(tokens, token_amount);
                        continue;
                }

                free(buffer);
                free_tokens(tokens, token_amount);
        }

        return 0;
}
