#include <stdio.h>
#include <stdlib.h>  /* функция atoi*/

#difine MAXOP 100
#difine NUMBER '0'

/* калькулятор с обратной записью */
main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) ! = EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+';
        push(pop() + pop());
        break;
      case '*';
        push(pop() * pop());
        break;
      case '-';
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 ! = 0.0)
          push(pop() / op2);
        break;
      case '\n':
        printf("\t%.8g\n", pop2);
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;

    }
  }
return 0;
}
