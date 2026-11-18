
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>

char *get_dir(char *directory)
{
        if (getcwd(directory, PATH_MAX) == NULL) {
                perror("bbsh");
        }

        char *shortened_dir = strrchr(directory, '/');
        
        if (shortened_dir == NULL) {
                perror("what?");
        }

        shortened_dir++;

        return shortened_dir;
}

char *sh_prompt(char *buffer, char *curr_dir)
{
        char prompt[MAX_INPUT] = {0};

        snprintf(prompt, MAX_INPUT, "<nerpsh \033[0;32m[%s]\033[0m> ", curr_dir);
        printf("%s", prompt);
        fflush(stdout);
        
        return d_input(buffer);
}

void free_tokens(char **tokens, uint16_t token_count)
{
        if (tokens == NULL)
                return;

        for (uint16_t idx = 0; idx < token_count; idx++) {
                free(tokens[idx]);
        }

        free(tokens);
}

void bbsh_greeter(void)
{
        printf(" _    _          _    \n"
               "| |__ | |__  ___ | |__  \n"
               "| '_ \\| '_ \\/ __|| '_ \\ \n"
               "| |_) | |_) \\__ \\| | | |\n"
               "|_.__/|_.__/|___/|_| |_| v0.03\n\n");
        fflush(stdout);
}
