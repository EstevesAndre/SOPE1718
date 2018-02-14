/*
 * Prob_5-b.c
 *
 *  Created on: 14/02/2018
 *      Author: andre
 */

/*
 * input, more than 1 name (Andre Esteves)
 * 	./Prob_2 Andre\ Esteves   	// "\ " code for a space in a C-string
 *
 *
 */


#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])
{

	if(argc == 1){
		int n = 0;
		char *p = envp[0];

		while(p != NULL)
		{
			if( strncmp("USER=",p, 5) == 0)
				break;
			n++;
			p = envp[n];

		}
		printf("Hello %s!\n",&p[5]); // endereço da sexta posição
	}
	else{
		printf("Hello %s!\n", argv[1]);
	}

	return 0;
}
