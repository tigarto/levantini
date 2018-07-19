#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
1. Compilar y enlazar primero el codigo de voltear.c:

gcc -Wall solo.c -o solo

2. Compilar  y enlazar este codigo

gcc -Wall consola3.c -o consola

*/

int main(int argc, char *argv[])
{
    //printf("-> P(*)\n");
    printf("prompt > ./solo");   
    int fd;   // file descriptor 
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // printf("-> H\n");
        // child (new process)
        /**redirection of I/O*/
        fd = open("solo.output", O_WRONLY | O_CREAT);
        close(stdout);  //stdout => 1
        dup(fd);
        close(fd);
        /* stdout is now redirected */        
        char *param[] = { NULL };
        execv("./solo", param);        
    } else {
        // printf("-> P(**)\n");
        int rc_wait = wait(NULL);
        // printf("-> P(**)\n");
        printf("\nprompt >\n");    
    }
    return 0;
}
