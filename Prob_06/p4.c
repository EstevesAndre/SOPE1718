// PROGRAMA p03.c
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

void *PrintHello(void *threadnum)
{
        //sleep(1);
        printf("%d\n", *(int *) threadnum);
        return threadnum;
}

int main()
{
        pthread_t threads[NUM_THREADS];
        int t;
        int thread_number[NUM_THREADS];

        for(t=0; t< NUM_THREADS; t++) {
                thread_number[t] = t;
                pthread_create(&threads[t], NULL, PrintHello, (void *)&thread_number[t]);
        }

        //printf("%d %d %d %d \n", EDEADLK, EINVAL, EINVAL, ESRCH);
        for(t=0; t< NUM_THREADS; t++) {
                void* ret;
                int r = pthread_join(threads[t], &ret);
                printf("Main thread return: %d\n", *(int*)ret);
                //printf("%d\n",r);
        }


        pthread_exit(0);
}
