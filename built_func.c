#include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @var: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(vars_t *var))(vars_t *var)
{
	unsigned int i;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{NULL, NULL}};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmpr(var->av[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(var);
	return (check[i].f);
}

/**
 * new_exit - exit program
 * @var: variables
 * Return: void
 */
void new_exit(vars_t *var)
{
	int status;

	if (_strcmpr(var->av[0], "exit") == 0 && var->av[1] != NULL)
	{
		status = _atoi(var->av[1]);
		if (status == -1)
		{
			var->status = 2;
			print_error(var, ": Illegal number: ");
			_put2(var->av[1]);
			_put2("\n");
			free(var->commands);
			var->commands = NULL;
			return;
		}
		var->status = status;
	}
	free(var->buffer);
	free(var->av);
	free(var->commands);
	free_env(var->env);
	exit(var->status);
}

/**
 * _env - prints the current environment
 * @var: struct of variables
 * Return: void.
 */
void _env(vars_t *var)
{
	unsigned int i;

	for (i = 0; var->env[i]; i++)
	{
		_put(var->env[i]);
		_put("\n");
	}
	var->status = 0;
}

/**
 * new_setenv - create a new environment variable, or edit an existing variable
 * @var: pointer to struct of variables
 *
 * Return: void
 */
void new_setenv(vars_t *var)
{
	char **key;
	char *va;

	if (var->av[1] == NULL || var->av[2] == NULL)
	{
		print_error(var, ": Incorrect number of arguments\n");
		var->status = 2;
		return;
	}
	key = find_key(var->env, var->av[1]);
	if (key == NULL)
		add_key(var);
	else
	{
		va = add_value(var->av[1], var->av[2]);
		if (var == NULL)
		{
			print_error(var, NULL);
			free(var->buffer);
			free(var->commands);
			free(var->av);
			free_env(var->env);
			exit(127);
		}
		free(*key);
		*key = va;
	}
	var->status = 0;
}

/**
 * new_unsetenv - remove an environment variable
 * @var: pointer to a struct of variables
 *
 * Return: void
 */
void new_unsetenv(vars_t *var)
{
	char **key, **newenv;

	unsigned int i, j;

	if (var->av[1] == NULL)
	{
		print_error(var, ": Incorrect number of arguments\n");
		var->status = 2;
		return;
	}
	key = find_key(var->env, var->av[1]);
	if (key == NULL)
	{
		print_error(var, ": No variable to unset");
		return;
	}
	for (i = 0; var->env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * i);
	if (newenv == NULL)
	{
		print_error(var, NULL);
		var->status = 127;
		new_exit(var);
	}
	for (i = 0; var->env[i] != *key; i++)
		newenv[i] = var->env[i];
	for (j = i + 1; var->env[j] != NULL; j++, i++)
		newenv[i] = var->env[j];
	newenv[i] = NULL;
	free(*key);
	free(var->env);
	var->env = newenv;
	var->status = 0;
}
