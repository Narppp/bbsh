
#include <bbsh/shlib.h>
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
