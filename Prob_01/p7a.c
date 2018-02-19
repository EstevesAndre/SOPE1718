#include <stdio.h>
#include <stdlib.h>

// Os handlers feitos usando atexit() são executados por ordem inversa, portanto o output será em ordem iversa de leitura, como se fosse uma stack.

// output:
//  Main done!
//  Executing exit handler 2
//  Executing exit handler 1


void exit_handler_1()
{
        printf("Executing exit handler 1\n");
}

void exit_handler_2()
{
        printf("Executing exit handler 2\n");
}

int main()
{
        atexit(exit_handler_1);
        atexit(exit_handler_2);

        printf("Main done!\n");

}
