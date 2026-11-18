
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>
#include <bbsh/commands.h>

int main(void)
{
        struct Shell bbsh = {0};

        bbsh_greeter();
        while (1) {
                char *shortened_dir = get_dir(bbsh.directory);
                bbsh.buffer = sh_prompt(bbsh.buffer, shortened_dir);
                bbsh.tokens = tokenizer(bbsh.buffer, &bbsh.token_amount);

                if (bbsh.tokens == NULL) {
                        printf("command didn't end properly.\n");
                        goto clean_all;
                        continue;
                }

                int16_t is_custom_command = custom_commands(bbsh.tokens, bbsh.directory);

                // exit command
                if (is_custom_command == -1)
                        goto clean_all;
                // working command
                if (is_custom_command == 1)
                        goto clean_all;

                exec_commands(bbsh.tokens);

                goto clean_all;

                clean_all:
                        free(bbsh.buffer);
                        free_tokens(bbsh.tokens, bbsh.token_amount);
                        bbsh.buffer = NULL;
                        bbsh.token_amount = 0;
                        
                        if (is_custom_command == -1)
                                exit(0);

        }
        return 0;
}
