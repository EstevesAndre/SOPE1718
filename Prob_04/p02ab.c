// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


// For each time we press CTRL+C the signal SIGINT is processed

//    But if we are processing a signal (while we wait the 5 sec (sleep(5)) )
// and then we type CTRL+C it doesn't do nothing

// So, the number of occurrences of SIGINT signal if the number of times that
//   printf("Entering SIGINT handler ...\n");
//   printf("Exiting SIGINT handler ...\n");
// appears in the terminal

//   b)  if we use kill -SIGTERM [PID program] while handler is executing
// the program closes

void sigint_handler(int signo)
{
        printf("Entering SIGINT handler ...\n");
        sleep(5);
        printf("Exiting SIGINT handler ...\n");
}

int main(void)
{

        struct sigaction action;

        action.sa_handler = sigint_handler;

        sigemptyset(&action.sa_mask);

        action.sa_flags = 0;


        if(sigaction(SIGINT,&action, NULL) < 0)
        {
                fprintf(stderr, "Unable to install SIGINT handler\n");
                exit(1);
        }

        printf("Try me with CTRL-C ...\n");

        while(1)
        {
                pause();
        }

        exit(0);
}
