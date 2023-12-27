#include <stdio.h>

main()
{
    int c;
    while ((c = getchar()) != 'q')
    {
        if (c)
            printf("1\n");
        else
            printf("0\n");
    }
    
}