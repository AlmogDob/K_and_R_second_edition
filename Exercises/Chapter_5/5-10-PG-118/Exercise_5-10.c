#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXLINE 1000
#define STOP '1'
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)

int almogs_getline(char[], int);
double almogs_atof(char[]);
int getop(char[]);
void push(double);
double pop(void);
void almogs_copy(char *to[], char *from[]);

char input[MAXLINE] = {0};
int inputp = 0;
int input_len = 0;

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    if (argc == 1){
        printf("Usage: num1 num2 num3... oper1 oper2...\n");
        return -1;
    }
    while (--argc > 0)
    {
        strcat(input, *++argv);
        strcat(input, " ");
    }
    strcat(input, "\n\0");
    input_len = strlen(input);

    while ((type = getop(s)) != EOF)
    {
        /*test*/
        // printf("\nstack: %s\n",s);
        /*test*/
        switch (type)
        {
        case NUMBER:
            push(almogs_atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("ERROR: Divtion by zero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case STOP:
            return 0;
        default:
            printf("ERROR: Unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* almogs_atof: conver string s to double */
double almogs_atof(char s[])
{
    double val, power, scientific_power;
    int i, sign, scientific_sign;

    scientific_power = 1;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        scientific_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (scientific_power = 0.0; isdigit(s[i]); i++)
            scientific_power = 10.0 * scientific_power + (s[i] - '0');
        scientific_power = pow(10, scientific_power * scientific_sign);
    }
    return sign * val * scientific_power / power;
}

/* getline: get line into s, return length */
int almogs_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ERROR: Stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("ERROR: Stack empty\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c, counter = 0;

    while ((s[0] = c = getch()) == ' ' || c == 't')
        ;
    /*test*/
    // dprintCHAR(c);
    /*test*/
    if (c == '\0')
    {
        if (!counter){
            return STOP;
        }
        counter = 1;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZ]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    if (!(inputp < input_len))
    {
        return '\0';
    }
    /*test*/
    // printf("inputp: %d\n", inputp);
    /*test*/
    char return_value;
    if (bufp > 0)
    {
        return_value = buf[--bufp];
    }
    else if(inputp < MAXLINE)
    {
        return_value = input[inputp++];
    }
    return return_value;
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* almogs_copy: copy 'from' into 'to'; assume to is big enough */
void almogs_copy(char *to[], char *from[])
{
    while ((*(to++) = *(from++)))
        ;
}
