// PROGRAMA p01.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define STDERR 2

int global = 50000;

void *thr_func(void *arg)
{
        void *ret;
        int value;
        value = *(int *) arg;
        printf("Starting thread %s\n", (char *) arg);

        for(; global > 0; global--)
        {
                value++;
                write(STDERR,"1",1);
        }
        ret = malloc(sizeof(int));
        *(int *)ret = value;
        return ret;
}

int main(void)
{
        pthread_t tid1,tid2;
        int k = 10;
        void *r1;
        void *r2;

        pthread_create(&tid1, NULL, thr_func, &k);
        pthread_create(&tid2, NULL, thr_func, &k);
        pthread_join(tid1, &r1);
        pthread_join(tid2, &r2);

        printf("\n\nMain thread: %d\n", *(int *)r1);
        printf("Main thread: %d\n", *(int *)r2);
        printf("Total: %d\n", *(int *)r1 + *(int*)r2);

        free(r1);
        free(r2);

        return 0;
}
