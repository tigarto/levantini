#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char *voltear(char *str);
void voltear2(char *str); 

int main(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++) {
    fprintf(stdout, "%s ", voltear(argv[i]));  // printf("%s\n",voltear(argv[1]));    
  } 
  fprintf(stdout, "\n");
  return 0;
}

char *voltear(char *str) {
  int i, j, fin;
  char aux;
  
  if(strlen(str)%2 == 0) {
    fin = (strlen(str)-1)/2;
  }
  else {
    fin = strlen(str)/2;
  }
  for(i = 0, j = strlen(str) - 1; i < fin; i++, j--) {
    aux = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = aux;
  }  
  return str;  
}

void voltear2(char *str) {
  int i, j, fin;
  char aux;
  
  if(strlen(str)%2 == 0) {
    fin = (strlen(str)-1)/2;
  }
  else {
    fin = strlen(str)/2;
  }
  for(i = 0, j = strlen(str) - 1; i < fin; i++, j--) {
    aux = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = aux;
  } 
  printf("%s\n",str);  
}

