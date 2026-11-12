
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
                        free(buffer);
                        free_tokens(tokens, token_amount);
                        continue;
                }

                exec_commands(tokens);

                free(buffer);
                free_tokens(tokens, token_amount);
        }

        return 0;
}
