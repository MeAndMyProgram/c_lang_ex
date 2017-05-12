#difine MAXOP 100

int sp = 0;
double val[MAXOP];


void push(double f)
{
  if (sp < MAXOP)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}
