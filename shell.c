#include "shell.h"

/*	Global Variables	*/
char*	path = NULL;
int		len = 0;

int main(int ac, char** av, char** env) {
	hsh(ac, av);
	return (0);
}


int hsh(int ac, char** av) {
	int
		mode = 0;
	char
		**cmd = NULL;

	/*
		Mode value is set by isatty, which will determine if usage is
		in interactive or non-interactive mode.
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
		free(path);
	} while (mode);
}
