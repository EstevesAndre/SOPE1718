#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[], char *envp[])
{
        pid_t pid;
        int file;

        if(argc != 3 && argc != 2)
        {
                printf("Usage: %s dirname\n", argv[0]);
                printf("Usage: %s dirname outputFile.txt\n\n", argv[0]);
                exit(1);
        }



        if(argc == 3)
        {
                file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if(file == -1)
                {
                        perror(argv[2]);
                        return 2;
                }
                dup2(file, STDOUT_FILENO);
        }

        pid = fork();

        if(pid > 0)   // parent
        {
                printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
        }
        else if(pid == 0)
        {
                execlp("ls", "ls", "-laR", argv[1], NULL);   // l -list , p - name of the executed file
        }

}
