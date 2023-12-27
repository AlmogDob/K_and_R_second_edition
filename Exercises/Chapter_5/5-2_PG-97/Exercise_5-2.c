#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define dprintDOUBLE(expr) printf(#expr " = %g\n", expr)
#define SIZE 3
#define BUFSIZE 100
#define SKIP -2

int getfloat(double *);
int getch(void);
void ungetch(int);

char buf[BUFSIZ]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */

int main(int argc, char const *argv[])
{
    int n, j;
    double array[SIZE];

    for (n = 0; n < SIZE && (j = getfloat(&array[n])) != -1; n++)
    {
        if (j == SKIP)
            --n;
    }
    printf("inputed numbers are:\n");
    for (int i = 0; i < n; i++){
        printf("%d. ", i+1);
        dprintDOUBLE(array[i]);
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getfloat(double *pn)
{
    double val, power, scientific_power;
    int i, c, sign, scientific_sign;
    
    scientific_power = 1;
    scientific_sign = 1;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c); /* it's not a number */
        return SKIP;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        if (!isdigit(c = getch()))
            return SKIP;
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
        power *= 10.0;
    }
    if (c == 'e' || c == 'E')
    {
        c = getch();
        scientific_sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
            c = getch();
        for (scientific_power = 0.0; isdigit(c); c = getch())
            scientific_power = 10.0 * scientific_power + (c - '0');
        scientific_power = pow(10, scientific_power * scientific_sign);
    }
    // *pn = sign * *pn * scientific_power / power;
    *pn *= sign * scientific_power / power;
    if (c != EOF)
        ungetch(c);
    return (int)c;
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
