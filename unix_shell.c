#include "shell.h"
/**
 * _unix_shell - an instance of the shell
 * Return: status code
 */
int _unix_shell(void)
{
	/* char *welcome = generate_prompt_line("BIT.SH"); */
	char *buffer = NULL, *pPath = NULL;
	char **t_args = NULL;
	ssize_t EOFCheck;
	unsigned int start = 1;
	size_t getLineSize = 0;

	write(STDOUT_FILENO, "$ ", 2);
	/* signal(SIGINT, SIG_IGN); */
	EOFCheck = getline(&buffer, &getLineSize, stdin);

	if (EOFCheck == -1)
		start = _SHELL_END_, write(STDOUT_FILENO, "\n", 1);
	if (EOFCheck == 1)
		start = _SKIP_;

	if (start == _NORMAL_)
		t_args = tokeniser(&buffer, "' '\n\t");
	/* printf("LOLOLO[%s]\n", t_args[0]); */
	if (start == _NORMAL_)
		start = run_built_in(t_args);

	if (start == _NORMAL_ && (t_args[0][0] != '.' && t_args[0][1] != '/'))
		pPath = get_path_args(t_args[0]);
	if (start == _NORMAL_)
		exec_process(pPath ? pPath : t_args[0], t_args), wait(NULL);

	free(buffer);
	free(t_args);
	free(pPath);

	return (start);
}
