
#include <stdio.h>
#define LEN 500

void expand(char s1[], char s2[]);

int main()
{
    char s1[LEN], s2[LEN];
    int c, i;

    for(i = 0; (c = getchar()) != EOF; i++)//заполняем массив знаками
        s1[i] = c;
    s1[i] = '\0';
    expand(s1, s2);
    printf("%s", s2);
    printf("\n");
    return 0;
}

/*expand*/
void expand(char s1[], char s2[])
{
    int i, j;
    char c;

    for(i=j=0; (c=s1[i++]) != '\0';)
    {
        /*если '-'встречается внутри
         * строки( a-z -a-z) после пробела*/
        if(c == ' ' && s1[i] == '-')
            s2[j++] = c;
        else if(s1[i] =='-' && s1[i+1] >=c)
        {
            i++;
            while(c < s1[i])//печатаем полный список
                s2[j++] = c++;
        }
        else
            s2[j++] = c;

    }
    s2[j] = '\0';
}
