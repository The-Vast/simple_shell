#include "shell.h"

/**
 * print_error - prints error messages to standard error
 * @var: pointer to struct of variables
 * @msg: message to print
 *
 * Return: void
 */
void print_error(vars_t *var, char *msg)
{
	char *count;

	_put2(var->argv[0]);
	_put2(": ");
	count = _uitoa(var->count);
	_put2(count);
	free(count);
	_put2(": ");
	_put2(var->av[0]);
	if (msg)
	{
		_put2(msg);
	}
	else
		perror("");
}

/**
 * _put2 - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _put2(char *str)
{
	ssize_t fig, len;

	fig = _strlen(str);
	len = write(STDERR_FILENO, str, fig);
	if (len != fig)
	{
		perror("Fatal Error");
		exit(1);
	}
}

/**
 * _uitoa - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
