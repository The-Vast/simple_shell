#include "shell.h"

/**
 * read_com - reads command from stdin
 * Return: the command typed
 */

char read_com(void)
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
