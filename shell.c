#include "shell.h"

/**
 * main - entry point
 * Return: Always 0 (success)
 */
int main(void)
{
	unsigned int start;

	do {
		start = _unix_shell();
		if (start == 3)
			start = 0;
	} while (stat);
	return (0);
}
