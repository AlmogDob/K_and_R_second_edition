#include <stdio.h>

#define lim 100

int main()
{
    int c;
    char s[lim];
    for (int i = 0; i < lim-1; ++i)
    {
        if ((c = getchar()) != '\n')
        {
            if (c != EOF)
                s[i] = c;
            else
                break;
        }
    }
    printf("the string is: %s\n",s);
    return 0;
}