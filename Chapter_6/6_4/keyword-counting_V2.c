#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof keytab / sizeof keytab[0])
#define MAXWORD 100
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define BUFSIZE 100

struct key
{
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0};

int getword(char *, int);
struct key *binsearch(char *word, struct key *tab, int n);
int getch(void);
void ungetch(int);

char buf[BUFSIZ]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */
int there_was_underscore_before = 0;
int there_was_underscore_after = 0;

/* count c keyword; pointer version */
int main(int argc, char const *argv[])
{
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            // dprintINT(there_was_underscore_before);
            // dprintINT(there_was_underscore_after);
            if (there_was_underscore_before || there_was_underscore_after)
            {
                there_was_underscore_before = 0;
                there_was_underscore_after = 0;
                continue;
            }
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
            {
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++)
    {
        if (p->count > 0)
        {
            printf("%4d %s\n", p->count, p->word);
        }
    }
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high)
    {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
        {
            high = mid;
        }
        else if (cond > 0)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return NULL;
}

/* getword: get next word ro character from input */
int getword(char *word, int lim)
{
    /*test*/
    // printf("enterd getword\n");
    /*test*/
    int c, c1;
    char *w = word;

    while (isspace(c = getch()))
    {
        ;
    }
    /*test*/
    // dprintCHAR(c);
    // dprintCHAR(*(w-1));
    /*test*/

    if (c == '/')
    {
        /*test*/
        // printf("c = /\n");
        // dprintCHAR(c);
        /*test*/
        switch (c = getch())
        {
        case '*':
            /*test*/
            // printf("c = *\n");
            /*test*/
            while ((c = getch()) != EOF)
            {
                if (c == '*' && (c1 = getch()) == '/')
                {
                    break;
                }
            }
            if (c == EOF)
            {
                return EOF;
            }
            break;
        case '/':
            while ((c = getch()) != EOF && c != '\n')
            {
                ;
            }
            if (c == EOF)
            {
                return EOF;
            }
            break;
        default:
            break;
        }
    }

    if (c == '\"')
    {
        while ((c = getch()) != EOF && c != '\"')
        {
            ;
        }
        if (c == EOF)
        {
            return EOF;
        }
    }

    if (c == '#')
    {
        while ((c = getch()) != EOF && c != '\n')
        {
            ;
        }
        if (c == EOF)
        {
            return EOF;
        }
    }

    if (!isalpha(c))
    {
        /*test*/
        // printf("c is not alpha\n");
        /*test*/
        if (c == '_')
        {
            there_was_underscore_before = 1;
        }

        *w = '\0';
        return c;
    }
    if (c != EOF)
    {
        *w++ = c;
    }
    for (; --lim > 0; w++)
    {
        /*test*/
        // printf("enterd for loop\n");
        /*test*/
        if (!isalnum(*w = getch()))
        {
            /*test*/
            // dprintSTRING(w-2);
            // printf("c(%c) is not alunm\n", *(w));
            /*test*/
            if (*w == '_')
            {
                there_was_underscore_after = 1;
            }
            else
            {
                ungetch(*w);
            }
            break;
        }
    }
    *w = '\0';
    return word[0];
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
