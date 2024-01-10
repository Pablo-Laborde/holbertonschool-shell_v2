#include "cmds.h"


char **get_cmd(int fd) {
	int
		pos = 0;
	char
		*line = NULL,
		*aux = NULL,
		**cmd = NULL;

	/* cleans static variables */
	_getline(-1);
	cmd_maker(NULL, NULL);
	/* read input, converts it into arguments, and return the command */
	line = _getline(fd);
	if (line)
		while (aux = wrd_maker(&line[pos], &pos))
			cmd = cmd_maker(cmd, aux);
	free(line);
	return (cmd);
}


char **cmd_maker(char **cmd, char *wrd) {
	static int
		len;
	int
		i = 0;
	char
		**new_cmd = cmd;

	if (!cmd & !wrd)
		len = 0;
	if (wrd) {
		len++;
		/* creates a char** that can hold one argument more */
		new_cmd = malloc(sizeof(char*) * (len + 1));
		if (new_cmd) {
			if (cmd) {
				/* copies all the arguments & frees old cmd */
				for (;i < (len - 1); i++)
					new_cmd[i] = cmd[i];
				free(cmd);
			}
			/* adds the new word */
			new_cmd[i] = wrd;
			/* NULL terminating */
			new_cmd[len] = NULL;
		}
	}
	return (new_cmd);
}


void cmd_free(char **cmd) {
	int
		i = 0;

	if (cmd) {
		/* frees each argument inthe cmd */
		for (; cmd[i]; i++)
			free(cmd[i]);
		/* frees the cmd */
		free(cmd);
	}
}


char *wrd_maker(char *str, int *pos) {
	int
		i = 0,
		j = 0,
		k = 0;
	char
		*wrd = NULL;

	if (str && str[i]) {
		/* skip space char and tabs */
		while ((str[i] == ' ') || (str[i] == '\t'))
			i++;
		j = i;
		/* find the next space, tab or end of str */
		while (str[j] && (str[j] != ' ') && (str[j] != '\t'))
			j++;
		wrd = malloc(j - i + 1);
		if (wrd) {
			/* copies the word and adjusts the position */
			for (; (i + k) < j; k++)
				wrd[k] = str[i + k];
			wrd[k] = '\0';
		}
		*pos += j;
	}
	return (wrd);
}
