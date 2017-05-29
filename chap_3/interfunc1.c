#include <studio.h>

main()(
  {
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother =0;
    for (i = 0; i < 10; i ++)
      ngigit[0] = 0;

    while ((c = getchar()) ! = EOF) {
      switch (c) {
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
	ndigit[c - '0']++;  // Запись для подсчета каждой из цифр от 0 до 9
	break;
      case ' ': case '\n': case '\t':
	nwhite++
	break; // колличество табуляций, пробелов и прочего.
      default; // точка с запятой, а не двоеточие
        nother++;
	break;
      }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
      printf(" %d", ndigit[i]);
    printf(", whitr space = %d, other = %d\n", nwhite, nother);
    return 0;
  }
