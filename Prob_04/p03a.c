// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

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

        struct sigaction action;

        action.sa_handler = sigusr_handler;

        sigemptyset(&action.sa_mask);

        action.sa_flags = 0;


        if(sigaction(SIGUSR2,&action, NULL) < 0)
        {
                fprintf(stderr, "Unable to install SIGUSR2 handler\n");
                exit(1);
        }
        if(sigaction(SIGUSR1,&action, NULL) < 0)
        {
                fprintf(stderr, "Unable to install SIGUSR1 handler\n");
                exit(1);
        }

        while(1)
        {
                printf("Value = %d\n", global_value);
                global_value += global_direction;
                sleep(1);
        }

        exit(0);
}
