#include <stdio.h>

#define MAXLINE 1000

void almogs_reverse(char s[]);
void almogs_itoa(int n, char s[], int w);

int main(int argc, char const *argv[])
{
    int n = 1;
    char s[MAXLINE];
    int w = 9;
    for (int i = 0; i < w; i++)
    {
        printf("%c", 222);
    }
    printf("\n");
    almogs_itoa(n, s, w);
    printf("%s", s);
    return 0;
}

/* itoa: conver n to characters in s */
void almogs_itoa(int n, char s[], int w)
{
    int i, j, sign, current_width;

    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do
    {                                     /* generate digits in reverse order */
        s[i++] = (unsigned)n % 10 + '0';  /* get next digit */
    } while ((n = (unsigned)n / 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    current_width = i;
    if (i < w)
    {
        // printf("i - %d\n",i);
        for (j = 0; j <= (w - current_width); j++)
            s[i++] = ' ';
        // printf("there were %d paddings\n", w - current_width);
    }
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