
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/commands.h>

void exec_commands(char **tokens)
{
        if (tokens[0] == NULL)
                return;

        pid_t id = fork();

        if (id < 0) {
                perror("Fork");
                exit(1);
        }

        if (id == 0) {
                if (execvp(tokens[0], tokens) < 0)
                        perror("bbsh");
                exit(1);
        }
        else {
                pid_t status = 0;
                waitpid(id, &status, 0);
        }
}

int16_t custom_commands(char **tokens, char *curr_dir)
{
        /* return values:
         * no error = 0 | exit code = -1 | valid command = 1 | error and invalid = -2
         */

        if (tokens == NULL || tokens[0] == NULL)
                return 0;

        if (strcmp(tokens[0], "help") == 0 && tokens[1] == NULL) {
                printf("Help Command:\n");
                printf("help: help [command]: used to understand commands\n");
                printf("jmp: jmp [dir]: change directories (no flags yet)\n");
                printf("exit: exit: exit the shell program.\n");
                return 1;
        } else if (strcmp(tokens[0], "help") == 0 && tokens[1] != NULL) {
                if (strcmp(tokens[1], "help") == 0) {
                        printf("help: help [command]\n");
                        printf("\tThis displays information about commands.\n");
                        return 1;
                } else if (strcmp(tokens[1], "jmp") == 0) {
                        printf("jmp: jmp [path]\n");
                        printf("\tJumps to a specific directory/folder. Replacement of cd\n");
                        return 1;
                } else if (strcmp(tokens[1], "exit") == 0) {
                        printf("exit: exit\n");
                        printf("\tExits the shell.\n");
                        return 1;
                }
        } 

        if (strcmp(tokens[0], "exit") == 0 && tokens[1] == NULL) {
                printf("bye bye\n");
                return -1;
        } 

        if (strcmp(tokens[0], "jmp") == 0) {
                if (tokens[1] == NULL || strcmp(tokens[1], "~") == 0) {
                        char *target_dir = NULL;

                        if ((target_dir = getenv("HOME")) == NULL) {
                                perror("bbsh: home");
                                return -2;
                        }

                        snprintf(curr_dir, CURR_DIR, "%s", target_dir);

                        if (chdir(curr_dir) < 0)
                                return -2;

                        return 1;  
                } else {
                        if (chdir(tokens[1]) < 0)
                                return -2;

                        return 1;
                }
        }

        return 0; 
}
