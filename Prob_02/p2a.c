#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LENGTH 256

int main(void)
{
        FILE *src, *dst;
        char buf [BUF_LENGTH];

        if( (src = fopen("infile.txt","r")) == NULL)
        {
                exit(1);
        }

        if( (dst = fopen("outfile.txt","w")) == NULL)
        {
                exit(2);
        }
        size_t n;

        while( (n = fread(buf,1, BUF_LENGTH, src)) > 0) // gets n(length) of the bytes (limit BUF_LENGTH) of the file src
        {
                fwrite(buf, 1, n, dst); //overwrite in the fie dst
        }

        fclose(src);
        fclose(dst);

        exit(0); // success
}
