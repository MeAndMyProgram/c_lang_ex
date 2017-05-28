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
   static int i = 0;
   if(n < 0){
    n = -n;
    s[i++] = '-';
  }
   if(n / 10)
    itoaa(n / 10, s);

  s[i++] = n % 10 +'0';

  s[i] = '\0';

}


/*reverse
void reverse(char s[])
{
   int i, j;
   char c;

   for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
   {
       c = s[i];
       s[i] = s[j];
       s[j] = c;
   }
}
*/
