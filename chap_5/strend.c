#include <stdio.h>
#include "mystdio.h"

main()
{
char s[MAX];
char m[MAX];

mgetline(s);
printf("%s\n", s);
mgetline(m);
printf("%s\n", m);
mstrend(s, m);
printf("%d\n", mstrend(s, m));
}
