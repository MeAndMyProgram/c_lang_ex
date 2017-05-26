#include <stdio.h>
#include <stdlib.h>  /* функция atoi*/
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100


/* калькулятор с обратной записью */
main()
{
  int type;
  double op2;

  double a, b, c, d, e;
  double var;

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
      case '^':
        push(pow(pop(), pop()));
        break;
      case '@':
        show();
        break;
      case '#':
        clear();
        break;
      case '$':
        copysp();
        break;
      case '!':
        repleace();
        break;
/* Итак перменная. Тупая реализация */
      case '=':
        while ((var = getchar()) != '\n'){
          if(var == 'a')
            a = pop();
          if(var == 'b')
            b = pop();
          else
            printf("error: unknown command\n");
          }
          break;
      case 'a':
        if (a)
            push(a);

        break;
      case 'b':
        if (b)
            push(b);
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
