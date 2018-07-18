#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
STATUS --> levantini
*/

/*
1. Compilar y enlazar primero el codigo de voltear.c:

gcc -Wall voltear.c -o voltear.out

2. Compilar  y enlazar este codigo

gcc -Wall voltear.c -o voltear.out

*/


int main(int argc, char *argv[])
{
    // Supongamos que esta es la consola
    printf("prompt > ./voltear.out casa carro beca > reves.output\n");   
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // Supontamos que para este caso se empleo un comando con redireccion y despues de hacer el parsing se llego a lo siguiente
        char *args[] = {  "./voltear.out"
                          "casa",
                          "carro",
                          "beca",
                          ">",
                          "./reves.output",
                          NULL 
                        }; 
        if(strcmp(args[0],">")==0) {
           // Redireccion a la salida -> child: redirect standard output to a file
           close(STDOUT_FILENO);
           open(args[5], O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
           // now exec "voltear.out"...
           char *myargs[5];
           myargs[0] = strdup(args[0]);   // program: "./voltear.out" (aplicacion para voltear)
           myargs[1] = strdup(args[1]);   // "casa": cadena de entrada 
           myargs[2] = strdup(args[2]);   // "carro": cadena de entrada 
           myargs[3] = strdup(args[3]);   // "beca": cadena de entrada 
           myargs[4] = NULL;  
           execvp(myargs[0], myargs); // runs word count
        }
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("prompt > \n");   
    }
    return 0;
}

/*
Conclusion a la que se llego:
Es necesario la implementacion de algun mecanismo para la salida redireccionada en el comando indicado.
Para el caso dado. La aplicacion no dio porque es probable que el ejecutable voltear.out no tenga nada asociado
*/

