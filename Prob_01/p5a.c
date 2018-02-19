/*
 * Prob_5.c
 *
 *  Created on: 14/02/2018
 *      Author: andre
 */

/*
 * gcc -o name filename.c	// compile
 *
 * ./name  					// to see output
 *
 * echo $?  				// to see the return of the function
 */

/*
 * input, more than 1 name (Andre Esteves)
 * 	./Prob_2 Andre\ Esteves   	// "\ " code for a space in a C-string
 *
 *
 */


#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	int n = 0;
	char *p = envp[0];
	while(p != NULL)
	{
		printf("%s\n", p);
		n++;
		p = envp[n];
	}
	return 0;
}
