#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 512

typedef struct {
        char name [BUFFER_SIZE];
        int score;
}score;

int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                printf("Wrong number of arguments!\nUsage; %s <destination>\n", argv[0]);
                return 1;
        }

        int file, nr;

        file = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
        if(file == -1)
        {
                perror(argv[1]);
                return 2;
        }

        printf("Enter the name of the student and the respective score.\nEmpty input to exit.\n\n");

        score student;

        while( (nr = read(STDIN_FILENO, &student,sizeof(student))) > 1)
        {
                write(file,&student,nr);
        }

        close(file);
        return 0;
}
