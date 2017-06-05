#include <stdio.h>
#include <ctype.h>
#include <math.h>


#define SIZE 15

int getint(int *);
/*
В данном случае я буду использовать статическую перменную, но можно использовать
getch / ungetch

int getch(void);
void ungetch(int);
*/

int main()
{
  int n;
  float array[SIZE];
  int o = 0;
  // цикл изменения элементов в массиве. Используется ссылка
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
      ;

  // выводим масив послеокончания файла через табуляцию
  printf("\n");
  while(array[o] != '\0' && o < SIZE)
    printf("%.2f\t", array[o++]);
  printf("\n");
  // int, нужно вернуть ноль
  return 0;
}

/* Версия для целых чисел

int getint(int *pn)
{
  // статическая переменная сохраняет значение в нутри функции
  static int c;
  int sign;
  // пропуск пробелов
  while (isspace(c = getchar()))
      ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
      ;
  //Не цыфра пропустить и записать в буфер(в данном случае сохраняется в статической переменной)
    return 0;
  }
  // определяем и сохроняем знак
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getchar();

  // применяем цикл к перменной - элементу массива через указатель
  for(*pn = 0; isdigit(c); c = getchar())
    *pn = 10 * *pn + (c - '0');

  *pn *= sign;

  return c;

}
*/

int getfloat(float *pn)
{
  // статическая переменная сохраняет значение в нутри функции
  static float c;
  int sign, point;


  // пропуск пробелов
  while (isspace(c = getchar()))
      ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
      ;
  //Не цыфра пропустить и записать в буфер(в данном случае сохраняется в статической переменной)
    return 0;
  }
  // определяем и сохроняем знак
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getchar();


  // применяем цикл к перменной - элементу массива через указатель
  for(*pn = 0.0, point = 0; isdigit(c) || c == '.'; c = getchar()){
    // есть точк или нет, если есть сразу возвращемся и увеличиваем разряд для деления на 10
    if (c == '.'){
      point = 1;
      continue;
    }
    else {
      *pn = 10.0 * *pn + (c - '0');
      if(point)
        point *= 10;
    }


}


/*
  for(power = 1; isdigit(c); c = getchar()){
    *pn = 10.0 * *pn + (c - '0');
    power *= 10;*/
if(point == 0)
    *pn *= sign;
else
    *pn = (*pn * sign)/point;


  return c;

}
