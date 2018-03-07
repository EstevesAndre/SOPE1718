#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// pathname of the command "ls"
// $ which ls
// /bin/ls

//using mc

// $ ./mc p8a.c  - compiles p8a.c file and creates p8a (same name)

// to see output
// $ ./p8a

int main(int argc, char *argv[], char *envp[])
{
        pid_t pid;

        if(argc != 2)
        {
                printf("Usage: %s dirname\n", argv[0]);
                exit(1);
        }
        pid = fork();

        if(pid > 0) // parent
        {
                printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
        }
        else if(pid == 0)
        {
                char * arguments[] = {"ls", "-laR", argv[1], NULL};
                execvp("ls", arguments); // v - argument - vector
        }
}
