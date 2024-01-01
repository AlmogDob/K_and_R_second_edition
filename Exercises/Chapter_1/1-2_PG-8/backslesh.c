#include <stdio.h>

main()
{

    char charaters[28] = "qwertyuiopasdfghjklzxcvbnm/\\";
    for (int i=0;i<28;++i)
    {
        putchar(charaters[i]);
        printf("\n");
    }

}