#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100
#define UNDCL 1
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int);

int tokentype;           /* type of last token */
char token[MAXTOKEN];    /* last toke string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, intm etc. */
char out[1000];          /* output string */
enum
{
    NAME,
    PARENS,
    BRACKETS
};

char buf[BUFSIZ]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */

#if !UNDCL
/* convert declaration to words */
int main()
{
    while (gettoken() != EOF) /* 1st token on line */
    {
        strcpy(datatype, token); /* is the datatype */
        out[0] = '\0';
        dcl(); /* parse rest of line */
        if (tokentype != '\n')
        {
            printf("Syntax error\n");
        }
        printf("%s: %s %s\n", name , out, datatype);
        // dprintSTRING(buf);
        // dprintSTRING(out);
        // out[0] = '\0';
        bufp = 0;
    }
    
    return 0;
}
#else
/* undcl: conver word description to declaration */
main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
        {
            if (type == PARENS || type == BRACKETS)
            {
                strcat(out, token);
            }
            else if (type == '*')
            {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
            {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n",out);
    }
    return 0;
}
#endif

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';) /* count *'s */
    {
        ns++;
    }
    dirdcl();
    while (ns-- > 0)
    {
        strcat(out, " pointer to");
    }
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

    if (tokentype == '(') /* (dcl) */
    {
        dcl();
        if (tokentype != ')')
        {
            printf("Error: missing )\n");
        }
    }
    else if (tokentype == NAME) /* variable name */
    {
        strcpy(name, token);
    }
    else
    {
        printf("Error: expected name or (dcl)\n");
    }
    
    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
        {
            // printf("type - parens\n");
            strcat(out, " function returning");
        }
        else
        {
            // printf("type - brackets\n");
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
            // dprintSTRING(out);
        }
    }
}

/* int gettoken: return next token */
int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
    {
        ;
    }
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
        {
            // printf("hi\n");
            ;
        }
        // printf("got out\n");
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
        {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }
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
