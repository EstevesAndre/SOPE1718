// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/*
    Using 2 CLI's
    One to compiple and run the program
    The other is to send the signal

    ex:t1->   gcc -o p p01a.c -Wall
          .   /p

       t2->   ps u
              kill -SIGUSR1 [PID do /p]  // or -SIGINT
 */

void sigint_handler(int signo)
{
        printf("In SIGINT handler ...\n");
}

int main(void)
{
        if(signal(SIGUSR1,sigint_handler) < 0)
        {
                fprintf(stderr, "Unable to install SIGINT handler\n");
                exit(1);
        }

        printf("Sleeping for 30 seconds ...\n");
        sleep(30);
        printf("Waking up ...\n");

        exit(0);
}
