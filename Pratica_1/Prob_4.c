/*
 * Prob_4.c
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
#include <stdlib.h> // for strtol

int main(int argc, char* argv[])
{
	int counter = 0;
	while(counter < strtol(argv[2], NULL, 10)){
		printf("Hello %s!\n", argv[1]);
		counter++;
	}
	return 0;
}
