#define ALLOCSIZE 10000 // объем имеющейся памяти

static char allocbuf[ALLOCSIZE]; // буфер памяти для alloc
static char *allocp = allocbuf;  // следующая свободная ячейка

char *alloc(int n) // возвращает указатль на n символов
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {  //  есть место
/* итак чтобы понять позицию нужно к allocbuf, это адрес первого элемента
прибвить ALLOCSIZE (длинну) получим последний эдемент масива и отнять соответственно
нынешний, получим колличество свободной памяти */
    allocp += n;
    return allocp - n; // старый p
  } else  // недостаточно места в буфере
    return 0;
}

void afree(char *p) // освобождает память по адресу "p"
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
