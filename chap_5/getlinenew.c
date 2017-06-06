#include <stdio.h>
#include <ctype.h>

/* функция записи строки */
int mgetline(char *s, int lim)
{
  int i;
  int c;
  for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
/* длинна стоки с указателями */
int mstrlen(char *s)
{
  char *p = s;

  while (*p != '\0')
    p++;
  /* s - содежит адрес массива, отнять его и получим длинну */
  return p - s;
}

/* функция записи строки */
int mstrend(char *s, char *m)
{
  // создаем указатель который подвинут на разницу размеров массивов
  char *i = m + (mstrlen(m) - mstrlen(s));

  // если цикл лойдет до  \О  то значит строки совпадают
  for(; *i == *s; s++, i++)
    if (*i =='\0')
      return 1;
  return 0;
}

/* функция записи строки */
void mstrcat(char *s, char *m, int n)
{
  int i = 0;
  // доходим до конца массива
  while (*s)
    s++;
    // копируем из одного в другой
  while(*s++ = *m++ && i < n)
    i++;
}

/* функция записи строки */
void mstrncpy(char *s, char *m/* int n*/)
{
  /*int i = 0;*/
    // копируем из одного в другой
  while(*s++ = *m++/*&& i < n*/)
    /*i++*/;
}

/* функция возвращает 1 если находит строку s  в начале строки m */
int mstrcmp(char *s, char *m, int n)
{
  int i = 0;
  // если цикл лойдет до  \О  то значит строки совпадают
  for(; *m == *s && i != n ; s++, i++, m++)
    if (*m =='\0')
      return 1;
  return 0;
}
