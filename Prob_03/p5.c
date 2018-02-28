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
                pid = fork();
                switch(pid) {
                case -1:
                        perror("fork");
                        break;
                case 0: // filho do filho (neto)
                        write(STDOUT_FILENO,"friends!\n",10);
                        break;
                default: // filho (pai)
                        write(STDOUT_FILENO," my ",4);
                }
                break;
        default: // pai (granpa)
                write(STDOUT_FILENO,"Hello",5);
        }

        return 0;
}
