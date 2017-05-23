#include <stdio.h>
#include <stdlib.h>  /* функция atoi*/
#include <ctype.h>
#include <math.h>


#define MAXOP 100
#define NUMBER '0'


int getop();
void push(double);
double pop(void);
int celi(double);
void show(void);
void repleace(void);
void clear(void);
void copysp(void);

int sp = 0;
double val[MAXOP];

/* калькулятор с обратной записью */
main()
{
  int type;
  double op2;
  int op3;


  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        break;
      case '%':
        op3 = celi(pop());

        if(op3 != 0)
          push(celi(pop()) % op3);
        break;
      case 's':
        show();
        break;
      case 'd':
        clear();
        break;
      case 'c':
        copysp();
        break;
      case 'r':
        repleace();
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;


    }
  }
return 0;
}

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
int celi(double m)
{
  int i;

  for(i = 0; i <= m; i++)
      ;
  return i;

}

void show(void)
{
    printf("\t%.8g\n", val[sp]);
}

void copysp(void)
{
      double i = val[sp] = val[++sp];
      printf("\t%.8g\n", val[sp]);
      printf("\t%.8g\n", val[--sp]);
      sp++;
}
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
void clear(void)
{
      while(sp >  0)
            val[--sp] = 0;

}
