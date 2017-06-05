#include <stdio.h>
#include <ctype.h>

int matoi(char *a);
void mgetline(char *s);

main()
{

  char a[5];
  mgetline(a);
  printf("%d\n", matoi(a));

}
/* в очередной раз перевод из строки в число */
int matoi(char *a)
{
  int i = 0;
  int sign = 1;
  /* если минус то заводим переменную со значением -1 */
  if (*a == '-'){
    sign = -1;
    a++;
    }

  while(isdigit(*a) && *a != '\0')
  {
    /* умнажаем цифру на 10 и приавляем новую цифру которая перводится в исло методом
    вычитания '0' */ 
    i = i * 10 + (*a - '0');
    a++;
  }

  i *= sign;

  return i;
}
void mgetline(char *s)
{
  int i = 0;
  int c;
  while((c = getchar()) != EOF && c != '\n'){
  *s++ = c;
  }
}
