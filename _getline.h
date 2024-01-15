#ifndef _GETLINE_H
#define _GETLINE_H


/*	Macros	*/
	#define READ_SIZE 16


/*	Libraries		*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>


/*	Functions		*/

	/*
	*	reads from fd until the end or a new line whatever happens first
	*/
	char *_getline(const int fd);


	/*
	*	finds and returns the position where the '\0' or the '\n' is
	*/
	int end_line(char *str);


	/*
	*	joins two stings
	*	return behaviour:
	*		if at least one of them is NULL -> NULL
	*		else returns a copy of str1 and str2 into one single string, (str1 first)
	*/
	char *join_strings(char *str1, char *str2);


	/*
	*	returns a copy of the string given
	*/
	char *cpy_line(char *str);


#endif
