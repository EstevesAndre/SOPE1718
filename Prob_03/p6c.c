#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
// em outro terminal usar o comando "ps u" para verificar a existencia de processos zombie

// tirando exit(0) o processo filho também vai continuar no ciclo for então vai criar filhos
// de forma exponencialmente, nao convém ter um numero elevado(>= 4) no ciclo.

int main(void)
{
        pid_t pid;
        int i,j;

        printf("I'm process %d. My parent is %d.\n", getpid(), getppid());

        for(i = 1; i <= 3; i++)
        {
                pid = fork();
                if(pid < 0)
                {
                        printf("fork error");
                        exit(1);
                }
                else if (pid == 0)
                {
                        printf("I'm process %d. My parent is %d. I'm going to work for 1 second ...\n", getpid(), getppid());

                        sleep(1); // simulado o trabalho do filho

                        printf("I'm process %d. My parent is %d. I finished my work\n",getpid(),getppid());
                        //exit(0); // a eliminar na alinea c)
                }
                else  // simulado o trabalho do pai
                {
                        waitpid(pid, NULL, WUNTRACED);
                        for(j = 1; j <= 10; j++)
                        {
                                sleep(1);
                                printf("father working ...\n");
                        }

                }
        }
        exit(0);
}
