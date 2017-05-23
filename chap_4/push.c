#include "stdio.h"

#define MAXOP 100

int sp = 0;
double val[MAXOP];


void push(double f)
{
  if (sp < MAXOP)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}
/* возвращает значение из стека */

double pop(void)
{
  if(sp >  0)
    return val[--sp];
  else
    printf("error: stack empty\n");
    return 0.0;
}
