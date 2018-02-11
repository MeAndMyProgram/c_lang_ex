#include <stdio.h>

main()
{
    int ch, nl;

    nl = 0;

    while ((ch = getchar()) != EOF){
        if (ch == '\t' || ch == ' ' || ch == '\\')
            nl++;
    }
    printf("%d\n", nl);
}