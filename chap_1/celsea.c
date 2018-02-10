#include <stdio.h>

main()
{
    int step, max, min;
    float farin, celsea;

    step = 10;
    max = 100;
    min = 0;

    celsea = 0;

    while(farin <= max){
        farin = celsea + 32.8;
        printf("%4.2f\t%4.2f\n", celsea, farin);
        celsea += step;
    }
}