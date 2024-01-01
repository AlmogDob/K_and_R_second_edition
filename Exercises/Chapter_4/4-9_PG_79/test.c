#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

char buf[BUFSIZ];  
int bufp = 0;

int main(int argc, char const *argv[])
{
    char s[] = "almog";
    int i;
    
    for (i = 0; i <= 5; i++)
    {
        ungetch(s[i]);
        printf("%c",getch());
    }

    return 0;
}

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
