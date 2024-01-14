#ifndef PROMPT_H
#define PROMPT_H


/*	Macros	*/


/*	Libraries		*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>


/*	Structures	*/


/*	Variables		*/
	extern char **environ, *path;
	extern int len;


/*	Functions		*/

	/**/
	void set_path(void);


	/**/
	int strc(char* so, char* st, int chn);

#endif
