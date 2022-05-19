#include "shell.h"

/**
 * str_exec - tokenizes a buffer with a delimiter
 * @buffer: buffer to str_exec
 * @delimiter: delimiter to str_exec along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **str_exec(char *buffer, char *delimiter)
{
	char **tokn = NULL;
	size_t i = 0, count = 10;

	if (buffer == NULL)
		return (NULL);
	tokn = malloc(sizeof(char *) * count);
	if (tokn == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokn[i] = new_strtokn(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == count)
		{
			tokn = _realoc(tokn, &count);
			if (tokn == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokn);
}
