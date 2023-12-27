#include <stdio.h>
#include <ctype.h>

#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define SIZE 5
#define BUFSIZE 100

int getint(int *);
int getch(void);
void ungetch(int);

char buf[BUFSIZ]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */

int main(int argc, char const *argv[])
{
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != 0; n++)
    {
        ;
    }
    printf("inputed numbers are:\n");
    for (int i = 0; i < n; i++){
        printf("%d. ", i+1);
        dprintINT(array[i]);
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

/* get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
