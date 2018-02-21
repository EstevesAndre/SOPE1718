//FOLHA 2 - p2b.c
//FILE COPY
//USAGE: copy source destination

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

/*
      If <source> file doesn't exit, return 2 (main function : echo $?)
      If <destination> file already exists, the flag O_EXCL return -1 (error)
      Writes the content of the source file in destination file
 */

// alinea c) execute twice with different inputs to see the execution time

int main(int argc, char *argv[])
{
        int fd1, fd2, nr, nw;
        unsigned char buffer[BUFFER_SIZE];

        if (argc != 3) {
                printf("Usage: %s <source> <destination>\n", argv[0]);
                return 1;
        }
        fd1 = open(argv[1], O_RDONLY);
        if (fd1 == -1) {
                perror(argv[1]);
                return 2;
        }
        fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
        if (fd2 == -1) {
                perror(argv[2]);
                close(fd1);
                return 3;
        }
        while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0)
                if ((nw = write(fd2, buffer, nr)) <= 0 || nw != nr) { // ou se nao escreveu nada (nw <= 0)
                        perror(argv[2]);                              // verifica  se o que escreveu foi igual ao que tinha para escrever
                        close(fd1);                                   // exemplo: falta de memoria no disco
                        close(fd2);
                        return 4;
                }
        close(fd1);
        close(fd2);
        return 0;
}
