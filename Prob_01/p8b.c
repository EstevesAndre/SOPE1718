#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[] )
{
        struct rusage usage;
        // timer in system mode
        struct timeval init_sys_time, end_sys_time;
        // timer in user mode
        struct timeval init_user_time, end_user_time;
        // real time
        struct timespec init_t, end_t;

        // gets and sets the real time
        clock_gettime(CLOCK_REALTIME, &init_t);

        // gets and sets the current time
        getrusage(RUSAGE_SELF, &usage);
        init_sys_time = usage.ru_stime;
        init_user_time = usage.ru_utime;


        if(argc != 3)
        {
                printf("Error. Invalid number of arguments! Usage: %s <n1> <n2>\n", argv[0]);
                return 1;
        }

        // convert char* (string) to int (decimal)
        int n1 = strtol(argv[1], NULL, 10);
        int n2 = strtol(argv[2], NULL, 10);

        if(n2 >= n1)
        {
                printf("n2 can't be greater than or equal to n1.\n");
                return 2;
        }

        /* Intializes random number generator */
        srand(time(NULL));

        // ensure that val != n2
        int val = n2 + 2;
        int i = 1;

        while(val != n2)
        {
                val = rand() % n1;
                printf("i: %d\tval: %d\n", i, val);
                i++;
        }

        // gets and sets the real time, at the end
        clock_gettime(CLOCK_REALTIME, &end_t);

        // gets and sets the current time
        getrusage(RUSAGE_SELF, &usage);
        end_sys_time = usage.ru_stime;
        end_user_time = usage.ru_utime;

        printf("\nReal time (ms): %f", (end_t.tv_sec - init_t.tv_sec)* 1000.0 + (end_t.tv_nsec - init_t.tv_nsec) / 1000000.0);
        printf("\n\nUser time (ms): %f", (end_user_time.tv_sec - init_user_time.tv_sec) * 1000.0 + (end_user_time.tv_usec - init_user_time.tv_usec) / 1000.0);
        printf("\n\nSystem time (ms): %f\n\n", (end_sys_time.tv_sec - init_sys_time.tv_sec) * 1000.0 + (end_sys_time.tv_usec - init_sys_time.tv_usec) / 1000.0);


        return 0;
}
