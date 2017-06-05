#include <stdio.h>


#define MAX 25


void mgetline(char *s);
void mstrcat(char *s, char *m);
//int mstrlen(char *s);

main()
{

char s[MAX];
char m[MAX];

mgetline(s);
printf("%s\n", s);
mgetline(m);
printf("%s\n", m);
mstrcat(s, m);
printf("%s\n", s);


}

// Требуемая функция
void mstrcat(char *s, char *m)
{

  // доходим до конца массива
  while (*s)
    s++;
    // копируем из одного в другой
  while((*s++ = *m++))
    ;
}

void mgetline(char *s)
{
  int i = 0;
  int c;
  while((c = getchar()) != EOF && c != '\n'){
  *s++ = c;
  }
}
/*
int mstrlen(char *s)
{
  char *p = s;

  while (*p)
    p++;
  return p - s;
}
*/
