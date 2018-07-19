/*tomado de: https://cboard.cprogramming.com/linux-programming/101247-redirect-stdout-using-dup.html*/

#include <stdio.h>
#include <unistd.h>
 
int main(void)
{
  int sout = dup(1);
  close(1);
  close(2);
  int sin2 = dup(0);
  dup2(sout, 1);
  printf("dup(stdin): &#37;d\n", sin2);
  return 0;
}
