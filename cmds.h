#ifndef CMDS_H
#define CMDS_H


/*	Macros	*/


/*	Libraries		*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>

	#include "_getline.h"


/*	Structures	*/


/*	Functions		*/

	/**/
	char **get_cmd(int fd);


	/**/
	char **cmd_maker(char **cmd, char *wrd);


	/**/
	void cmd_free(char **cmd);


	/**/
	char *wrd_maker(char *str, int *pos);


#endif
