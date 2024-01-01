#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(int argc, char const *argv[])
{
    char s[] = "123456789";
    printf("s before: %s\n",s);
    reverse(s);
    printf("s after: %s\n",s);
    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
