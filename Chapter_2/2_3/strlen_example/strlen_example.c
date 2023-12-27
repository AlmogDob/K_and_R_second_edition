#include <stdio.h>

/* strlen: return length of s */
int strlen(char s[])
{
    int i = 0;

    while (s[i] != '\0')
        ++i;
    return i;
}

int main()
{
    printf("%d",strlen("hello wolrd"));
    return 0;
}