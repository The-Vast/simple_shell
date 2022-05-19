#include "shell.h"

/**
 * _tokount - counts number of tokens
 * @str: input string
 * @delim: delimiter string
 * Return: delimiter count
 */
int _tokount(char *str, char *delim)
{
	int i = 0, j = 0;
	int k = 0;

	while (delim[i])
	{
		while (str[j])
			if (str[j++] == delim[i] && str[j] != delim[i])
				k++;
		j = 0;
		i++;
	}
	return (k);
}
/**
 * _is_arg_run_ready - tests for file access
 * @arg: path to check
 * Return: 1 on success, 0 on failure
 */
unsigned int _is_arg_run_ready(char *arg)
{
	if (access(arg, X_OK) == -1)
		return (0);
	else
		return (1);
}
/**
 * _stralloc - concatenate count strings
 * @count: string count
 * Return: concatenated strings
 */
char *_stralloc(int count, ...)
{
	va_list valist;
	char *prg_arg;
	char *prg_ptr;
	char *prg_ret;
	int sLen;
	int aLen;

	va_start(valist, count);

	prg_arg = va_arg(valist, char *), count--;
	aLen = _strlen(prg_arg);

	prg_ret = malloc(sizeof(char) * aLen + 1);
	if (prg_ret == NULL)
		perror("big segfult: "), exit(EXIT_FAILURE);

	_strcpy(prg_ret, prg_arg);
	while (count != 0)
	{
		prg_arg = va_arg(valist, char *), count--;
		sLen = _strlen(prg_ret), aLen = _strlen(prg_arg);

		prg_ptr = malloc(sizeof(char) * (sLen + aLen) + 1);
		if (prg_ptr == NULL)
			perror("gros gros segfult: "), exit(EXIT_FAILURE);

		if (prg_ret != NULL)
			_strcpy(prg_ptr, prg_ret), free(prg_ret);
		_strcat(prg_ptr, prg_arg), prg_ret = prg_ptr;
	}

	va_end(valist);
	return (prg_ret);
}
/**
 * _find_env_get_value - get value of key
 * @key: key is key
 * Return: pointer to first letter env value
 */
char *_find_env_get_value(char *key)
{
	int i = 0;
	char *prg;

	while (_strstr(environ[i], key) == NULL && environ[i] != NULL)
		i++;

	if (environ[i] == NULL)
		return (NULL);
	prg = _strstr(environ[i], "="), prg++;
	return (prg);
}
/**
 * _find_x_path - find path of program
 * @env_paths: path token array
 * @program: program string
 * Return: absolute path of program
 */
char *_find_x_path(char **env_paths, char *program)
{
	int i = 1;
	char *prg;

	prg = _stralloc(3, env_paths[0], "/", program);
	while (access(prg, X_OK) == -1 && env_paths[i] != NULL)
	{
		free(prg);
		prg = _stralloc(3, env_paths[i], "/", program);
		i++;
	}
	if (env_paths[i] == NULL)
		return (NULL);
	else
		return (prg);
}
