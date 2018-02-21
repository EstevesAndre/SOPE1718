#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
        int file, nr, nw;

        unsigned char buffer[BUFFER_SIZE];

        if(argc != 2)
        {
                printf("Usage; %s <destination>\n", argv[0]);
                return 1;
        }

        file = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
        if(file == -1)
        {
                perror(argv[1]);
                return 2;
        }

        while( (nr = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 1)
        {
                if( (nw = write(file,buffer,nr)) <= 0 || nw != nr)
                {
                        perror(argv[1]);
                        close(file);
                        return 3;
                }
        }

        close(file);
        return 0;
}
