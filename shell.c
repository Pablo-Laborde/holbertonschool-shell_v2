#include "shell.h"


/*	Global Variables	*/
char*	path = NULL;
int		len = 0;


/**
* main- function
* @ac: int
* @av: char**
* @env: char**
* Return: int
*/
int main(int ac, char** av, char** env)
{
	int mode = 0;
	char **cmd = NULL;

	(void)ac;
	(void)av;
	(void)env;
	/*
	*	Mode value is set by isatty, which will determine if usage is
	*	in interactive or non-interactive mode.
	*/
	mode = isatty(STDIN_FILENO);
	if (mode) {
		set_path();
	}
	do {
		if (mode)
			write(STDIN_FILENO, path, len);
		cmd = get_cmd(STDIN_FILENO);
		for (int i = 0; cmd[i]; i++)
			printf("%s\n", cmd[i]);
		cmd_free(cmd);
		cmd = NULL;
	} while (mode);
	free(path);
	return (0);
}
