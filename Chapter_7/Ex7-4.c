/*********************************************/
/* Ex7-4 Calculates the sales tax calculator */
/* 					     */
/* Author: David Ogor			     */
/* Date: 06-16-2015			     */
/*********************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int res = 0;
  char buf[BUFSIZ];
  float amt = 0.0;

  do {
    if (fgets(buf, BUFSIZ, stdin) == NULL) {
      perror("fgets");
      exit(1);
    }
    res = sscanf(buf, "%f", &amt);
  } while (res != 1);
 
  amt = amt + (amt * .08);
  printf("%.2f\n", amt);
  return 0;
}
