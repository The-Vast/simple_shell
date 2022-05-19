#include "shell.h"
/**
 * run_built_in - run built-in function if found
 * @args: argument array
 * Return: shell instance status code
 */
int run_built_in(char **args)
{
	int i = 0;

	b_ins binsarr[] = {
		{"env", _bin_env},
		{"exit", _exit_bin},
		{"cd", _bin_cd},
		{NULL, NULL}};
	while (binsarr[i].command != NULL){
		if (_strcmp(args[0], binsarr[i].command) == 0)
			return (binsarr[i].func(args));
		i++;
	}
	return (1);
}
/**
 * _bin_env - print environment
 * @args: argument array
 * Return: _SKIP_ code on success
 */
int _bin_env(__attribute__((unused)) char **args)
{
	int i = 0, len;
	
	while (environ[i] != NULL){
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (2);
}
