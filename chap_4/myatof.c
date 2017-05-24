#include <ctype.h>
#include <stdio.h>
#include <math.h>

double matof(char s[]);
int gettline(char s[]);

main()
{
  double sum;
  #define MAXLINE 100
  char s[MAXLINE];

  sum = 0;
  while (gettline(s) > 0)
      printf("\t%g\n", sum += matof(s));
}

int gettline(char s[])
{
  int i, c;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
  return i;
}

double matof(char s[])
{
double val, power, st;
int i, sing;

for (i = 0; isspace(s[i]); i++)
      ;

for (val = 0.0; isdigit(s[i]); i++)
      val = 10.0 * val + (s[i] - '0');

if (s[i] == '.')
    i++;

for (power = 1.0;  isdigit(s[i]); i++) {
  val = 10.0 * val + (s[i] - '0');
  power *= 10;
}
if (s[i] == 'e' || s[i] == 'E')
    i++;

sing = (s[i] == '-') ? -1: 1;

if (s[i] == '-' || s[i] == '+')
    i++;
for (st = 0.0;  isdigit(s[i]); i++) 
  st = 10.0 * st + (s[i] - '0');
st *= sing;

return  val / power * pow(10, st);
}
