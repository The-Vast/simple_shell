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
    // char *line = NULL;
    // ssize_t bufsize = 0;

    // if (getline(&line, &bufsize, stdin) == -1)
    // {
    //     if (feof(stdin))
    //     {
    //         exit(EXIT_SUCCESS);
    //     } else
    //     {
    //         perror("readline");
    //         exit(EXIT_FAILURE);
    //     }
    // }

    // return line;

    char buf[1024];
    char *ptr = NULL;
    char ptrlen = 0;

    while(fgets(buf, 1024, stdin))
    {
        int buflen = strlen(buf);

        if(!ptr)
        {
            ptr = malloc(buflen+1);
        }
        else
        {
            char *ptr2 = realloc(ptr, ptrlen+buflen+1);

            if(ptr2)
            {
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }
        if(!ptr)
        {
            fprintf(stderr, "error: failed to alloc buffer: %s\n", 
                    strerror(errno));
            return NULL;
        }
        strcpy(ptr+ptrlen, buf);

        if(buf[buflen-1] == '\n')
        {
            if(buflen == 1 || buf[buflen-2] != '\\')
            {
                return ptr;
            }

            ptr[ptrlen+buflen-2] = '\0';
            buflen -= 2;
            // print_prompt2();
            fprintf(stderr, "> ");
        }

        ptrlen += buflen;
    }

    return ptr;
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

    

    while(1){
        // int_mode = isatty(STDIN_FILENO);
        fprintf(stderr, "$ ");

        // if (int_mode == 1)
        // {
        //     write(STDOUT_FILENO, "#cisfun$ ", 13);
        // }

        cmd = read_com();

        if (!cmd)
            // perror("Error:");
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

        // token = strtok(buffer, delimiter);
        // while (token != NULL)
        // {
        //     toks[counter] = strdup(token);
        //     token = strtok(NULL, delimiter);
        //     Counter++;
        // }
        // toks[counter] = token;
        printf("%s\n", cmd);
        // write(STDOUT_FILENO, "cmd\n", 13);
        free(cmd);

    }

    exit(EXIT_SUCCESS);
}
