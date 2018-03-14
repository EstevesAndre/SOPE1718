// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int global_direction = 1;
int global_value = 0;

void sigusr_handler(int signo)
{
        if(signo == SIGUSR1)
        {
                global_direction = 1;
        }
        else if(signo == SIGUSR2)
        {
                global_direction = -1;
        }

}


int main(void)
{

        pid_t pid;
        struct sigaction action;
        srand(time(NULL));

        action.sa_handler = sigusr_handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;

        if(sigaction(SIGUSR2,&action, NULL) < 0)
        {
                fprintf(stderr, "Unable to install SIGINT handler\n");
                exit(1);
        }
        if(sigaction(SIGUSR1,&action, NULL) < 0)
        {
                fprintf(stderr, "Unable to install SIGINT handler\n");
                exit(1);
        }

        int counter = 0;

        pid = fork();

        if(pid == 0) // son
        {
                while(counter<50)
                {
                        printf("Value = %d\n", global_value);
                        global_value += global_direction;
                        counter++;
                        sleep(2);
                }
        }
        else if(pid > 0) // parent
        {
                int random = rand() % 2;
                if(random)
                {
                        raise(SIGUSR1);
                }
                // MUDAR PARA KILL (PID, SIGUSR#);
                else
                {
                        raise(SIGUSR2);
                }
                sleep(1);
        }
        exit(0);
}
