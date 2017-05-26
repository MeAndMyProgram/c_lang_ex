#include <stdio.h>
#include <ctype.h>
void forbit(int);

int main()
{
  int c, i;

  while((c = getchar()) != EOF){
      if (isdigit(c)){
        i = c;
      forbit(i);
    } else if(c == '\n')
      printf("%o\n", i);
    }


}


void forbit(int a)
{
    a & 077;
}
