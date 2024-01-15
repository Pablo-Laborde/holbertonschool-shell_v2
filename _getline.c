#include "_getline.h"


/**
* _getline- function
* @fd: int
* Return: char*
*/
char *_getline(const int fd)
{
	static char buff[READ_SIZE];
	static int pos;
	static ssize_t ar;
	int x = 0, m_read = 1, com_line = 1;
	char *str = NULL, *aux = NULL;

	if (fd == -1)
	{
		pos = 0;
		ar = 0;
	}
	else
		do {
			if (m_read)
			{
				for (x = 0; x < READ_SIZE; x++)
					buff[x] = '\0';
				ar = read(fd, buff, READ_SIZE);
				com_line = end_line(buff);
				if (com_line)
					m_read = 0;
			}
			if (ar && (ar != -1))
			{
				aux = cpy_line(&buff[pos]);
				str = (str) ? (join_strings(str, aux)) : aux;
				aux = NULL;
			}
		} while (!com_line);
	return (str);
}


/**
* end_line- function
* @str: char*
* Return: int
*/
int end_line(char *str)
{
	static int lp = READ_SIZE - 1;

	return ((!str[lp] || (str[lp] == '\n')) ? (1) : (0));
}


/**
* join_strings- function
* @str1: char*
* @str2: char*
* Return: char*
*/
char *join_strings(char *str1, char *str2)
{
	int i = 0, len1 = 0, len2 = 0;
	char *new_str = NULL;

	if (str1 && str2)
	{
		while (str1[len1])
			len1++;
		while (str2[len2])
			len2++;
		new_str = malloc(len1 + len2 + 1);
		if (new_str)
		{
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


/**
* cpy_line- function
* @str: char*
* Return: char*
*/
char *cpy_line(char *str)
{
	int i = 0, len = 0;
	char *new_str = NULL;

	if (str)
	{
		while (str[len] && (str[len] != '\n'))
			len++;
		new_str = malloc(len + 1);
		if (new_str)
		{
			for (; i < len; i++)
				new_str[i] = str[i];
			new_str[i] = '\0';
		}
	}
	return (new_str);
}
