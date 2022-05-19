#include "shell.h"

/**
 * _exit_bin - exit shell
 * @args: argument array
 * Return: _SHELL_END_ code on success
 */
int _exit_bin(__attribute__((unused)) char **args)
{
    return (3);
}
/**
 * _bin_cd - change directory
 * @args: argument array
 * Return: _SKIP_ code on success
 */
int _bin_cd(char **args)
{
    int stat;

    if (args[1] == NULL)
        stat = chdir(_find_env_get_value("HOME"));
    else if (_strcmp(args[1], "-") == 0)
        stat = chdir(_find_env_get_value("OLDPWD"));
    else
        stat = chdir(args[1]);
    if (stat == -1)
        perror("cd had an error");
    return (2);
}