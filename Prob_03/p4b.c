#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/*
      O processo de fork consome algum tempo
      Já o printf é rapdido.. Ou seja tanto na alinea a) ou b) o processo pai
    acaba primeiro que o processo filho.

      Em casos em que o programa é extenso o processo filho pode acabar mais depressa
    que o processo pai.
 */

int main(void)
{
        pid_t pid;

        pid = fork();

        switch (pid) {
        case -1:
                perror("fork");
                break;
        case 0: // filho
                printf("World!");
                break;
        default: // pai
                printf("Hello");
        }

        printf("\n\n");
        return 0;
}
