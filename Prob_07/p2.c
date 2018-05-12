// PROGRAMA p02.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define STDERR 2

int global = 50000;

pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;  // mutex p/a sec.critica

void *thr_func(void *nr)
{
        while(1)
        {
                pthread_mutex_lock(&mut);
                global--;
                if(global < 0)
                {
                        pthread_mutex_unlock(&mut);
                        return NULL;
                }
                pthread_mutex_unlock(&mut);

                *(int *)nr+=1;
        }

}

int main(void)
{
        pthread_t tid1,tid2;
        int k1 = 0;
        int k2 = 0;

        pthread_create(&tid1, NULL, thr_func, &k1);
        pthread_create(&tid2, NULL, thr_func, &k2);

        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

        printf("Thread 1: %d\n", k1);
        printf("Thread 2: %d\n", k2);
        printf("Total: %d\n", k1+k2);

        return 0;
}
