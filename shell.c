#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

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

    int_mode = isatty(STDIN_FILENO);

    do{
        
        // fprintf(stderr, "$ ");
        write(STDOUT_FILENO, "$ ", 13);

        cmd = read_com;

        if (!cmd)
            perror("Error:");
            exit(EXIT_SUCCESS);
        
        if (cmd[0] == EOF || cmd == "\n")
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
        free(cmd);

    }while(int_mode);

    exit(EXIT_SUCCESS);
}
