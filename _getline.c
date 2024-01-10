#include "_getline.h"


char *_getline(const int fd) {
	static char
		buff[READ_SIZE];
	static int
		pos;
	static ssize_t
		ar;
	int
		i = pos,
		len = 0,
		cl = 0;
	char
		*str = NULL,
		*aux = NULL;

	if (fd == -1) {
		pos = 0;
		ar = 0;
	}
	while ((pos < ar) || ((ar = read(fd, buff, READ_SIZE)) && (ar > -1))) {
		if (!(pos < ar))
			pos = 0;
		i = pos;
		pos = end_line(buff, pos, ar);
		len = pos - i + 1;
		if (!(pos < ar))
			len--;
		else {
			pos++;
			cl = 1;
		}
		aux = cpy_string(&buff[i], len);
		if (aux) {
			str = (str) ? join_strings(str, aux) : aux;
			aux = NULL;
		}
		if (cl)
			break;
	}
	return (str);
}


int end_line(char *str, int pos, int ar) {
	int
		i = pos;

	while (str[i] && (str[i] != '\n') && (i < ar))
		i++;
	return (i);
}


char *join_strings(char *str1, char *str2) {
	int
		i = 0,
		len1 = 0,
		len2 = 0;
	char
		*new_str = NULL;

	if (str1 && str2) {
		while (str1[len1])
			len1++;
		while (str2[len2])
			len2++;
		new_str = malloc(len1 + len2 + 1);
		if (new_str) {
			for (; i < len1; i++)
				new_str[i] = str1[i];
			for (i = 0; i < len2; i++)
				new_str[i + len1] = str2[i];
			new_str[len1 + len2] = '\0';
			free(str1);
			free(str2);
		}
	}
	return (new_str);
}


char *cpy_string(char *str, int amt) {
	int
		i = 0;
	char
		*new_str = NULL;

	if (str) {
		new_str = malloc(amt + 1);
		if (new_str) {
			for (; i < amt; i++)
				new_str[i] = str[i];
			new_str[i] = '\0';
			if (new_str[i - 1] == '\n')
				new_str[i - 1] = '\0';
		}
	}
	return (new_str);
}
