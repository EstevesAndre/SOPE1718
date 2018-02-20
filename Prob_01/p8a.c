#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[] )
{

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

        return 0;
}
