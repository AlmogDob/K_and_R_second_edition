#include <string.h>
#include <stdio.h>

void almogs_reverse(char s[]);

int main(int argc, char const *argv[])
{
    char s[] = "almog";
    printf("s: %s\n",s);
    almogs_reverse(s);
    printf("reverse s - %s\n",s);
    return 0;
}

/* reverse: reverse strnig s in place */
void almogs_reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}