#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100

double almogs_atof(char[]);
int getline(char[], int);
void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);
void clear(void);
void duplicate(void);
void swap(void);

int there_was_clear;
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZ];   /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* reverse Polish calculator */
int main(int argc, char const *argv[])
{
    int type;
    double op2, op1;
    char s[MAXOP];

    there_was_clear = 0;

    while ((type = getop(s)) != EOF)
    {
        // printf("\nstack: %s\n",s);
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
                printf("ERROR: Divtion by zero");
            break;
        case '%':
            op2 = pop();
            op1 = pop();
            if (op2 != 0.0)
                push(op1 - op2 * (int)(op1 / op2));
            else
                printf("ERROR: Divtion by zero");
            break;
        case '?':
            push((op1 = pop()));
            printf("Top element of the stack: %.8g\n", op1);
            break;
        case '$':
            duplicate();
            break;
        case '!':
            swap();
            break;
        case '#':
            clear();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            there_was_clear = 0;
            break;
        default:
            printf("ERROR: Unknown command %s", s);
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
int getline(char s[], int lim)
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
        if (!there_was_clear)
            printf("ERROR: Stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == 't')
        ;
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

/* clear: clears the stack */
void clear(void)
{
    there_was_clear = 1;
    while (pop() != 0)
        ;
}

/* duplicate: duplicates the top of the stack */
void duplicate(void)
{
    double op2, op1;
    if (sp < 1)
    {
        printf("ERROR: Can't duplicat, stack is empty\n");
        return;
    }
    push((op1 = pop()));
    push(op1);
}

/* swap: swaps the top two elements */
void swap(void)
{
    if (sp < 2)
    {
        printf("ERROR: Can't swap, not enough elements in stack\n");
        return;
    }
    double op2, op1;
    op1 = pop();
    op2 = pop();
    push(op1);
    push(op2);
}

