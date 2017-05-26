#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double);
double pop(void);
int celi(double);
double show(void);
void repleace(void);
void clear(void);
void copysp(void);

/* функция для помещения в стек чисел*/
void push(double f)
{
  if (sp < MAXVAL)
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

/* переведение из double в int для modulo */
int celi(double m)
{
  int i;
  for(i = 0; i <= m; i++)
      ;
  return i;
}

/* функция показывает верхнюю позицию в стеке без его удаления */
double show(void)
{
    printf("\t%.8g\n", val[sp]);
}

/* скопировать топ стека еще один раз */
void copysp(void)
{
      double i = val[sp] = val[++sp];
      printf("\t%.8g\n", val[sp]);
      printf("\t%.8g\n", val[--sp]);
      sp++;
}

/* поинеять последние числа из стека местами */
void repleace(void)
{
      double i = val[sp];
      double n = val[--sp];
      val[sp] = i;
      val[++sp] = n;
      printf("\t%.8g\n", val[sp]);
      printf("\t%.8g\n", val[--sp]);
      sp++;
}

/* очистиеть стек */
void clear(void)
{
      while(sp >  0)
            val[--sp] = 0;

}
