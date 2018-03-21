#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main()
{
        int fd[2];

        pid_t pid;

        if( pipe(fd) < 0)
        {
                fprintf(stderr, "pipe error\n" );
                exit(1);
        }
        if( (pid = fork())  < 0)
        {
                fprintf(stderr, "fork error\n");
                exit(2);
        }

        if(pid > 0) // father
        {
                int a[2];
                printf("PARENT:\nx y ? ");
                scanf("%d %d",&a[0],&a[1]);
                close(fd[READ]);
                write(fd[WRITE], a, 2*sizeof(int));
                close(fd[WRITE]);
        }
        else // son
        {
                int b[2];
                close(fd[WRITE]);
                read(fd[READ],b,2*sizeof(int));
                printf("\nSON:\nx + y = %d\n",b[0]+b[1]);
                close(fd[READ]);
        }

        return 0;
}
