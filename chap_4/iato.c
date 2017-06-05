#include <stdio.h>
#include <string.h>

void itoaa(int n, char s[]);


/* функция переводящая число в строку */
int main()
{

  int n = -123;
  char s[20];

  itoaa(n, s);
  printf("%s\n", s);

}

/*itob*/
void itoaa(int n, char s[])
{
    /* заводим статическую переменная, которая внутри функции будет служить буфером */
   static int i = 0;
   /* если число меньше ноля то заводим переменную со значением -1*/
   if(n < 0){
    n = -n;
    s[i++] = '-';
  }
    /* рекурсивно обращаемся к функции если число делится на 10*/
   if(n / 10)
    /* соответственно делим на 10 и аргумент*/
    itoaa(n / 10, s);
    /*сама функция, суть которой получить остаток от деления на десять последнего числа
    и добавить '0'*/
  s[i++] = n % 10 + '0';

  s[i] = '\0';

}


/*reverse
void reverse(char s[], int first, int last) {

int c = s[first];

s[first++] = s[last];

s[last--] = c;

if (first != last)

reverse(s, first, last);
}
*/
