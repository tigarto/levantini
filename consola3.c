#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
http://www.sarathlakshman.com/2012/09/24/implementation-overview-of-redirection-and-pipe-operators-in-shell
*/

/*
1. Compilar y enlazar primero el codigo de voltear.c:

gcc -Wall solo.c -o solo

2. Compilar  y enlazar este codigo

gcc -Wall consola3.c -o consola

*/

int main(int argc, char *argv[])
{
    // Padre: Consola

    char *param[] = { 
                          NULL 
                        };
        
    char *param2[] = { 
                         ">",
                         "file.output",
                         NULL 
                     };
        

    int fd;   // file descriptor 
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {  
        // Hijo: Proceso que sera llamado (solo2)
        // Parametros de parsing con salida en pantalla         
        

        execv("./test1", param2);        
    } else {
        int rc_wait = wait(NULL);
    }
    return 0;
}
