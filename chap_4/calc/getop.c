#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[])
{
  int i;
  static int c; /* используем статик и в результате значение с бцдет хранится от вызова к вызову*/
  /* getch - ungetch не нужен */
  while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  i = 0;

  if (c == '-')
    while (isdigit(s[++i] = c = getchar()))
        ;

  if (isdigit(c))
    while (isdigit(s[++i] = c = getchar()))
        ;

  if (c == '.')
    while (isdigit(s[++i] = c = getchar()))
        ;

  s[i] = '\0';

  if (s[--i] == '-')
    return '-';

    return NUMBER;
}
