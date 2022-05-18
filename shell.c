#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * read_com - reads command from stdin
 * Return: the command typed
 */

char *read_com(void)
{
    char *line = NULL;
    ssize_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        } else
        {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 *
 * Return: exits on success
 */

int main(int argc, char **argv)
{
    char *cmd;
    int int_mode;

    int_mode = isatty(STDIN_FILENO);

    do{
        
        // fprintf(stderr, "$ ");
        write(STDOUT_FILENO, "#cisfun$ ", 13);

        cmd = read_com();

        if (!cmd)
            perror("Error:");
            exit(EXIT_SUCCESS);
        
        if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
        {
            free(cmd);
            continue;
        }

        if (strcmp(cmd, "exit\n") == 0)
        {
            free(cmd);
            break;
        }

        printf("%s\n", cmd);
        // write(STDOUT_FILENO, "cmd\n", 13);
        free(cmd);

    }while(int_mode);

    exit(EXIT_SUCCESS);
}
