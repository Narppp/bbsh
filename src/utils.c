
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>

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

int16_t check_tokens(char **tokens)
{
        /* Return Values:
         * invalid syntax = -1
         * no redirection symbol = 0
         * > symbol = 1
         * < symbol = 2
         * >> symbol = 3
         */

        for (uint16_t idx = 0; tokens[idx] != NULL; idx++) {
                if ((strcmp(tokens[idx], ">") == 0 && tokens[idx + 1] == NULL) || 
                        (strcmp(tokens[idx], "<") == 0 && tokens[idx + 1] == NULL) ||
                        (strcmp(tokens[idx], ">>") == 0 && tokens[idx + 1] == NULL))
                        return -1;
                if (strcmp(tokens[idx], ">") == 0 && tokens[idx + 1] != NULL)
                        tokens[idx] = NULL;
                        return 1;
                if (strcmp(tokens[idx], "<") == 0 && tokens[idx + 1] != NULL)
                        tokens[idx] = NULL;
                        return 2;
                if (strcmp(tokens[idx], ">>") == 0 && tokens[idx + 1] != NULL)
                        tokens[idx] = NULL;
                        return 3;
        }

        return 0;
}
