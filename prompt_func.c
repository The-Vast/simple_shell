#include "shell.h"

/**
* get_path_args - get absolute path for program name
* @program: program token
* Return: absolute path
*/
char *get_path_args(char *program)
{
	char *prg;
	char *prg_env;
	char **prg_args;

	prg = _find_env_get_value("PATH");
	/* printf("%s\n", prg); */
	prg_env = _stralloc(1, prg);
	prg_args = tokeniser(&prg_env, ":");
	/* printf("[%s]\n", prg_args[1]); */
	prg = _find_x_path(prg_args, program);
	/* printf("prg[%s]a1[]a2[]\n", prg); */
	free(prg_env);
	free(prg_args);
	return (prg);
}
/**
* generate_prompt_line - display prompt
* @custom: custom prompt
* Return: prompt string in color
*/
char *generate_prompt_line(char *custom)
{
	char buffer[1024];

	if (custom == NULL)
		custom = "";

	return (_stralloc(21,
				_BOLD_, _COLOR_MAGENTA_, custom, _CLEAR_,
				" | ",
				_COLOR_MAGENTA_, "Raid55", _CLEAR_,
				_BOLD_, _COLOR_GREEN_, "@", _CLEAR_,
				_BOLD_, _COLOR_YELLOW_, _find_env_get_value("USER"), _CLEAR_,
				":",
				_COLOR_CYAN_, getcwd(buffer, 1024), _CLEAR_,
				"$ "));
}
