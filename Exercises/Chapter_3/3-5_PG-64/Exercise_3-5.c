#include <stdio.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
void almogs_reverse(char s[]);

int main(int argc, char const *argv[])
{
    int n = 186;
    char s[MAXLINE];
    int b = 17;
    itob(n,s,b);
    printf("n: %d\nn in base %d: %s\n", n, b, s);
    return 0;
}

/* itob: converts the integer n into a base b character representation in the string s */
void itob(int n, char s[], int b)
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do       /* generate digits in reverse order */
    {
        s[i++] = (n % b <= 9)?(n % b + '0'):((n % b) - 10 + 'A');  /* get next digit */
    } while ((n /= b) > 0);   /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    almogs_reverse(s);
}

/* reverse: reverse strnig s in place */
void almogs_reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
