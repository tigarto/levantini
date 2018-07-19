#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

/*
http://pubs.opengroup.org/onlinepubs/9699919799/functions/dup.html

*/

int main(int argc, char *argv[]) {
  int fid;
  printf("solo escribe\n");
  /*redirection of I/O*/
  //fid = open("archivo1.txt", O_WRONLY | O_CREAT);
  fid = open(argv[1], O_WRONLY | O_CREAT); 
  close(1);
  dup(fid);
  close(fid);
  /* stdout is now redirected */
  printf("solo escribe en el archivo\n");
  return 0;
}

