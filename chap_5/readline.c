#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* максимальное колличество встроенных строк */
#define MAXLEN 1000 /*максимальная длинна входной строки */
#include "mystdio.h" /*  использую собственные переписанные функции */

char *lineptr[MAXLINES]; /* указатели на строки */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void maqsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);


/* сортировка строк входного потока */
main()
{
  int nlines; /*колличество введенных строк */

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    maqsort(lineptr, 0, nlines-1);

    writelines(lineptr, nlines);

    return 0;

  } else {

    printf("error: input too big to sort\n");
    return 1;

  }
}




int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  static char linestore[MAXLINES];
  p = linestore + strlen(linestore);

  nlines = 0;
  while ((len = mgetline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || len + strlen(linestore) >= MAXLINES)
      return -1;
    else {
      line[len-1] = '\0'; /* удаление конца строки */
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
    printf("%d\n", nlines);
    return nlines;
}

/* writelines: ввывод строк в выходной поток */
void writelines(char *lineptr[], int nlines)
{
  /* вариант без учета что lineptr - массив укахателей

  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);

  */
  while (nlines-- > 0)
    printf("\t%s\n", *lineptr++);
}

void maqsort(char *v[], int left, int right)
{
  int i, last;
  /*void swap(char *v[], int i, int j);*/

  if (left >= right)
    return;

  swap(v, left, (left + right)/2);
  /* едем в серидину и меняем местами элемениы*/
  last = left;
  /* назначаем последний элемент равным сомому левому */
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
    /*функция strcmp сравнивает две строки */
      swap (v, ++last, i);
    /* если функци я вернула отрицательное число, двигаем последний элемент
    как указатель направо и меняем  местами текущий и последний */
  swap(v, left, last);
  maqsort(v, left, last - 1);
  maqsort(v, last + 1, right);

}

void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
