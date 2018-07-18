#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
1. Compilar y enlazar primero el codigo de voltear.c:

gcc -Wall voltear.c -o voltear.out

2. Compilar  y enlazar este codigo

gcc -Wall voltear.c -o voltear.out

*/

int main(int argc, char *argv[])
{
    //printf("-> P(*)\n");
    printf("prompt >");    
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // printf("-> H\n");
        // child (new process)
        char *param[] = { "casa",
                          "carro",
                          "beca",
                          NULL 
                        };
        execv("./voltear.out", param);
        
    } else {
        // printf("-> P(**)\n");
        int rc_wait = wait(NULL);
        // printf("-> P(**)\n");
        printf("prompt >");    
    }
    return 0;
}
