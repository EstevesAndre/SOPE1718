#include <stdio.h>
#include <stdlib.h>

// Os handlers feitos usando atexit() são executados por ordem inversa, portanto o output será em ordem iversa de leitura, como se fosse uma stack.

// a)output:
//  Main done!
//  Executing exit handler 2
//  Executing exit handler 1

// b)output:
//    handler with exit()
//    nao tem qualquer alteração, executa como na alíena a), como se fosse uma stack

//    abort antes do "Main done!"
//    Se a função abort() for chamada, nenhum dos handlers são executados pelas funçoes atexit() nem o printf da função main, "Main done!\n" é executado.


void exit_handler_1()
{
        printf("Executing exit handler 1\n");
}

void exit_handler_2()
{
        printf("Executing exit handler 2\n");
}

void exit_handler_3()
{
        printf("Executing exit handler 3\n");
        //  exit(0);
}

int main()
{
        if(atexit(exit_handler_1) != 0)
        {
                printf("Error registering handler 1\n");
        }

        if(atexit(exit_handler_2) != 0)
        {
                printf("Error registering handler 1\n");
        }

        if(atexit(exit_handler_3) != 0)
        {
                printf("Error registering handler 3 (with exit)\n");
        }

        if(atexit(exit_handler_1) != 0)
        {
                printf("Error registering handler 1\n");
        }

        abort();

        printf("Main done!\n");

}
