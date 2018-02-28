#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
        pid_t pid;

        pid = fork();

        switch (pid) {
        case -1:
                perror("fork");
                break;
        case 0: // filho
                printf("Hello");
                break;
        default: // pai
                printf("World!");
        }

        printf("\n\n");
        return 0;
}
