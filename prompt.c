#include "prompt.h"


void set_path(void) {
	int		i = 0,
				j = 0,
				k = 0,
				flag = 0,
				len_h = 0,
				len_p = 0,
				pos_h = 5,
				pos_p = 4;
	char*	h_aux = NULL,
			*	p_aux = NULL,
			*	new_path = NULL;

	while (environ[i]) {
		if (strc(environ[i], "HOME", 0))
			break;
		i++;
	}
	h_aux = &environ[i][pos_h];
	while (environ[j]) {
		if (strc(environ[j], "PWD", 0))
			break;
		j++;
	}
	p_aux = &environ[j][pos_p];
	flag = strc(h_aux, p_aux, 0);
	if (flag) {
		while (h_aux[len_h])
			len_h++;
		len++;
		p_aux += len_h;
	}
	while (p_aux[len_p])
		len_p++;
	len += len_p + 3;
	new_path = malloc(len);
	if (new_path) {
		free(path);
		if (flag)
			new_path[0] = '~';
		while (p_aux[k]) {
			new_path[k + flag] = p_aux[k];
			k++;
		}
		new_path[k + flag] = '$';
		new_path[k + flag + 1] = ' ';
		new_path[k + flag + 2] = '\0';
		path = new_path;
	}
}


int strc(char* so, char* st, int chn) {
	int   eq = 1,
				i = 0;

	if (so && st) {
		eq = 1;
		while (eq && so[i] && st[i]) {
			if (so[i] != st[i])
				eq = 0;
			i++;
		}
		if (chn && ((!so[i] && st[i]) || (so[i] && !st[i])))
			eq = 0;
	}
	return (eq);
}
