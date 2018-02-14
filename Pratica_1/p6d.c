/*
 * p6d.c
 *
 *  Created on: 14/02/2018
 *      Author: andre
 */

// PROGRAMA p6a.c

/*
 * 	b) "infile.txt" doesn't exist , so the program exists ..
 * 	c) $ echo $? // output = 1
 * 	d)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LENGTH 256

int main(void)
{
	FILE *src, *dst;
	char buf [BUF_LENGTH];

	if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )
	{
		perror("infile.txt doesn't exist");

		exit(1);
	}

	if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL )
	{
		perror("Read only file, directory doesn't have permission to WRITE");

		exit(2);
	}

	while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
	{
		fputs( buf, dst );
	}
	fclose( src );
	fclose( dst );


	exit(0);  // zero é geralmente indicativo de "sucesso"
}
