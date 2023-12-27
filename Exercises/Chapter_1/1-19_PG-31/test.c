#include <stdio.h>

#define MAXLINE 1000

char reverse_s[MAXLINE];
char s[MAXLINE];

int main()
{
    int i, len;
    s[0] = 'a';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = 'd';
    s[4] = '\n';
    s[5] = '\0';

    len = 5;
    for (i = 0; i < len-1; ++i)
    {
         reverse_s[i] = s[len-2-i];   
    } 
    printf("s - %srevese_s - %s",s,reverse_s);
}