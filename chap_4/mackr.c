#include <stdio.h>
#include <string.h>
#include <ctype.h>
// требуемый макрос
#define swap(t, x, y) t temp = x; x = y; y = temp

/* считает колличество int в массиве */
int getarr(int array[]);

main()
{
  int array[10];
  // переменные для  подсчета и подстановки в макрос
  int i, first, second, col, m;
  // набираем массив
  col = getarr(array);

  // выводим массив
  for (i = 0; i < col; i++)
    printf("%d", array[i]);
  printf("\n");
  // вводим номера которые надо поменять местами
  scanf("%d\n", &first);
  first--;
  scanf("%d\n", &second);
  second--;

  // меняем
  swap(int, array[first], array[second]);
  // выводим
  for (i = 0; i < col; i++)
    printf("%d", array[i]);

  printf("\n");
}

/* колличество цифр в массиве */
int getarr(int array[])
{
  int c, i;
  i = 0;
  while ((c = getchar()) != EOF && c != '\n'){
      array[i] = c -'0';
      i++;
  }
  if (c == '\n')
    ;
  array[i] = '\0';
  return i;
}
