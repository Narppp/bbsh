
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>

char *get_dir(char *prompt, char *curr_dir)
{
        if (getcwd(curr_dir, CURR_DIR) == NULL) {
                perror("bbsh");
        }

        char *shortened_dir = strrchr(curr_dir, '/');
        
        if (shortened_dir == NULL) {
                perror("what?");
        }

        shortened_dir++;

        snprintf(prompt, PROMPT_SIZE, "<nerpsh \033[0;32m[%s]\033[0m> ", shortened_dir);
        return prompt;
}

char *sh_prompt(char *prompt, char *curr_dir)
{
        get_dir(prompt, curr_dir);
        printf("%s", prompt);
        fflush(stdout);
        char *temp_buf = malloc(MAX_BUF * sizeof(char));

        if (temp_buf == NULL) {
                perror("Temporary Buffer");
                exit(1);
        }
        
        temp_buf = d_input(temp_buf);

        return temp_buf;
}

void free_tokens(char **tokens, uint16_t token_count)
{
        for (uint16_t idx = 0; idx < token_count; idx++) {
                free(tokens[idx]);
        }

        free(tokens);
}
