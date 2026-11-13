
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>
#include <bbsh/commands.h>

int main(void)
{
        uint16_t token_amount = 0;
        char prompt[PROMPT_SIZE] = {0};
        char *buffer = NULL;
        char **tokens = NULL;

        while (1) {
                buffer = sh_prompt(prompt);
                tokens = tokenizer(buffer, &token_amount);

                if (tokens == NULL) {
                        printf("command didn't end properly.\n");
                        goto clean_all;
                        continue;
                }

                exec_commands(tokens);

                goto clean_all;

                clean_all:
                        free(buffer);
                        free_tokens(tokens, token_amount);
                        buffer = NULL;
                        token_amount = 0;
        }
        return 0;
}
