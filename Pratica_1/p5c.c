/*
 * Prob_5-c.c
 *
 *  Created on: 14/02/2018
 *      Author: andre
 */

/*
 * input, more than 1 name (Andre Esteves)
 * 	./Prob_2 Andre\ Esteves   	// "\ " code for a space in a C-string
 *
 *	char * getenv(char * name); 	// gets the info on the environment
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])
{

	if(argc == 1)
	{
		printf("Hello %s!\n", getenv("USER")); // prints the user
	}
	else{
		printf("Hello %s!\n", argv[1]);
	}
	return 0;
}
