#include <stdio.h>

int binsearch(int x, int v[],int n);

  main()
{
  int x, n, d;
  int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  x = 3;
  n = 9;
  
  d = binsearch(x, v, n);
  printf("%d\n", d);
}
    
int binsearch(int x, int v[],int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
  // нет соответствий

}


