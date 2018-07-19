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
    int fd;   // file descriptor 
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {  
        printf("%s\n", argv[1]);      
        fd = open("./test1", O_WRONLY | O_CREAT);        
        /* stdout is now redirected */        
        char *param[] = { argv[1],
                          NULL };
        printf("%s\n", param[0]);      
        execv("./test1", param);        
    } else {
        // printf("-> P(**)\n");
        int rc_wait = wait(NULL);
    }
    return 0;
}
