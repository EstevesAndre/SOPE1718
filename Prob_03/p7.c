#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        char prog[20];

        sprintf(prog,"%s.c",argv[1]);

        execlp("tdc","gcc",prog,"-Wall","-o",argv[1],NULL);

        printf("Command not executed !\n");
        exit(1);
}
