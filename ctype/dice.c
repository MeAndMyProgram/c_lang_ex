#include <stdio.h>
#include <stdlib.h>


/* $  gcc -shared -Wl,-soname,<file> -o <file>.so -fPIC <file>.c */

int d6(void);
int d6(void)
{
  int c = (rand() % 5) + 1;
  return c;
}
