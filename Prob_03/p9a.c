#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
        pid_t pid, pidSon;

        if(argc != 2)
        {
                printf("Usage: %s dirname\n", argv[0]);
                exit(1);
        }
        pid = fork();
        int status;

        if(pid > 0) // parent
        {
                pidSon = wait(&status);
                printf("I'm the parent (PID=%d)\n\n", getpid());
                printf("My son %d exited with exit code %d\n", pidSon,WEXITSTATUS(status));

        }
        else if(pid == 0)
        {
                execlp("ls", "ls", "-laR", argv[1], NULL); // l -list , p - name of the executed file
        }
}
