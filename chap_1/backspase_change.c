#include <stdio.h>

main() 
{
    int ch, backspase_count;
    
    backspase_count = 0;

    while ((ch = getchar()) != 'EOF') {
        if (ch == ' '){ 
            backspase_count++;
            putchar('\b');
        }  
        putchar(ch);
        backspase_count = 0;
        
    }
}