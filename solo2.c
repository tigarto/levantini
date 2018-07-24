#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>



int main(int argc, char *argv[]) {
  /* Nota: Vamos a suponer que no hay validacion de que los parametros se encuenetren bien colocados*/
  if(argc == 3) &&strcmp(argv[1],">") == 0) {
    // Se empleara redireccion a un archivo
    int fid;
    /*redirection of I/O*/
    fid = open(argv[2], O_WRONLY | O_CREAT); // argv2 es el nombre del archivo
    close(1);
    dup(fid);
    close(fid);
    /* stdout is now redirected */
    printf("solo escribe en el archivo\n");
  }
  else {
    // Se empleo la salida estandar
    printf("solo escribe\n");
  }
  return 0;
}
