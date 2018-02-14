/*
 * p6h.c
 *
 *  Created on: 14/02/2018
 *      Author: andre
 */


// PROGRAMA p6a.c

/*
 * 	b) "infile.txt" doesn't exist , so the program exists ..
 * 	c) $ echo $? // output = 1
 *
 *	f) created the infile.txt file and run the program, outfile.txt file was created with the same content
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(int argc, char * argv[])
{
	if(argc == 3){

		FILE *src, *dst;
		char buf [BUF_LENGTH];

		if ( ( src = fopen( argv[1], "r" ) ) == NULL )
		{
			printf("%d\n", errno);

			exit(1);
		}

		if ( ( dst = fopen( argv[2], "w" ) ) == NULL )
		{
			printf("%d\n", errno);

			exit(2);
		}

		while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
		{
			fputs( buf, dst );
		}
		fclose( src );
		fclose( dst );
	}
	else{
		printf("usage: nome_do_executável file1 file2\n");
	}

	exit(0);  // zero é geralmente indicativo de "sucesso"
}
