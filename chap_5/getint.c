#include <stdio.h>
#include <ctype.h>


#define SIZE 100

int getint(int *)
int getch(void);
void ungetch(int);

int main()
{
  int n, array[SIZE];

  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
      ;
}

int getint(int *pn)
{
  int c;
  int sign;
  // пропуск пробелов
  while (isspace(c = getch()))
      ;
  if (!isdigit(c) && c != EOF && != '+' && c != '-') {
    ungetch(c);
  //Не цыфра
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();

  for(*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  *pn *= sign;

  if (c != EOF)
    ungetch();
  return c;

}
