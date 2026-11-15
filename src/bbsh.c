
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>
#include <bbsh/commands.h>

int main(void)
{
        uint16_t token_amount = 0;
        char directory[PATH_MAX] = {0};
        char prompt[MAX_INPUT] = {0};
        char *buffer = NULL;
        char **tokens = NULL;

        while (1) {
                buffer = sh_prompt(prompt, directory);
                tokens = tokenizer(buffer, &token_amount);

                if (tokens == NULL) {
                        printf("command didn't end properly.\n");
                        goto clean_all;
                        continue;
                }

                int16_t is_custom_command = custom_commands(tokens, directory);

                // exit command
                if (is_custom_command == -1)
                        goto clean_all;
                // working command
                if (is_custom_command == 1)
                        goto clean_all;

                exec_commands(tokens);

                goto clean_all;

                clean_all:
                        free(buffer);
                        free_tokens(tokens, token_amount);
                        buffer = NULL;
                        token_amount = 0;
                        
                        if (is_custom_command == -1)
                                exit(0);
        }
        return 0;
}
