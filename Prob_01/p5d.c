/*
 * Prob_5-d.c
 *
 *  Created on: 14/02/2018
 *      Author: andre
 */

/*
 * input, more than 1 name (Andre Esteves)
 * 	./Prob_2 Andre\ Esteves   	// "\ " code for a space in a C-string
 *
 *	char * getenv(char * name); 	// gets the info on the environment
 *
 *	$ export USER_NAME="complete name" 	//
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])
{
	printf("Hello %s !\n", getenv("USER_NAME"));

	return 0;
}
