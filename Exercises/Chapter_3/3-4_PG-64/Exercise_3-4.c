#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void almogs_reverse(char s[]);
void almogs_itoa(int n, char s[]);

int main(int argc, char const *argv[])
{
    printf("int min: %d\n", INT_MIN);
    int n = INT_MIN;
    char s[MAXLINE];
    almogs_itoa(n, s);
    printf("n: %d\nstr: %s", n, s);
    return 0;
}

/* itoa: conver n to characters in s */
void almogs_itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do
    {                                     /* generate digits in reverse order */
        s[i++] = (unsigned)n % 10 + '0';  /* get next digit */
    } while ((n = (unsigned)n / 10) > 0); /* delete it */
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