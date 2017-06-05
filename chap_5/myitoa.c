#include <stdio.h>
#include <string.h>

void itoaa(int n, char *s);
void mreverse(char *s);
int mstrlen(char *s);



/* функция переводящая число в строку */
int main()
{

  int n = -123;
  char s[20];
  itoaa(n, s);
  mreverse(s);
  printf("%s\n", s);

}


void itoaa(int n, char *s)
{
  int sign = 1;

  if (n < 0){
    n = -n;
    sign = -1;
  }

  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);

  if(sign < 0)
    *s++ = '-';

  *s = '\0';
// почему то не работает..
  mreverse(s);
}

void mreverse(char *s)
{
  int i,j,c;

  for(i = 0, j = mstrlen(s) - 1; i < j; i++, j--){

    c = *(s+i);
    *(s+i) = *(s+j);
    *(s+j) = c;
  }
}

int mstrlen(char *s)
{
  char *p = s;

  while (*p != '\0')
    p++;

  return p - s;
}
/*
void itoaa(int n, char *s)
{
  int i = 0;
  ++i;
  if (n < 0){
    *s = '-';
    n = -n;
    }
  if(n / 10)
    itoaa(n / 10, s);

  *(s+i) = n % 10 + '0';

  *s++ = '\0';
}
*/
