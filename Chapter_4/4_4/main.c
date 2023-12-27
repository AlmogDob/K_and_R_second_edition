#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "push_pop.h"

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define OPERATOR '1'
#define COMMAND '2'
#define MATH_OPER '3'
#define VARIABLE '4'
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

double almogs_atof(char[]);
int almogs_getline(char[], int);

int getop(char[]);
int getch(void);
void ungetch(int);
void clear(void);
void duplicate(void);
void swap(void);
void raise_to_the_power(void);
// void assign(char variable, double value);
void show_variable(char variable);
int strindex(char s[], char t[]);
void ungets(char s[]);

int there_was_clear, end_of_line, to_print, there_was_backslash;
int sp = 0;                   /* next free stack position */
double val[MAXVAL];           /* value stack */
int buf[BUFSIZ];             /* buffer for ungetch */
double variables[26] = {0.0}; /* list of variables*/
int bufp = 0;                 /* next free position in buf */
double ans = 0;
int maxval = MAXVAL;
// double A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

/* reverse Polish calculator */
int main(int argc, char const *argv[])
{
    int type;
    double op2, op1;
    char s[MAXOP];
    char var;

    there_was_backslash = 0;
    there_was_clear = 0;
    end_of_line = 0;
    to_print = 1;

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
        case OPERATOR:
            switch (s[0])
            {
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
            case '=':
                /*test*/
                // printf("got =\n");
                /*test*/
                pop();
                push(variables[var - 'A'] = pop());
                to_print = 0;
                break;
            case '?':
                show_variable(var);
                to_print = 0;
                break;
            }
            break;
        case COMMAND:
            switch (s[0])
            {
            case 'p':
                push((op1 = pop()));
                printf("Top element of the stack: %.8g\n", op1);
                to_print = 0;
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear();
                break;
            }
            break;
        case MATH_OPER:
            if (!strindex(s, "sin"))
                push(sin(pop()));
            if (!strindex(s, "exp"))
                push(exp(pop()));
            if (!strindex(s, "pow"))
                raise_to_the_power();
            break;
        case VARIABLE:
            /*test*/
            // printf("was in case AVRIABLE\n");
            /*test*/
            var = s[0];
            push(variables[var - 'A']);
            break;
        case '\a':
            /*test*/
            // printf("\\a case, ans = %.8g\n", ans);
            /*test*/
            push(ans);
            printf("last ans: %.8g\n", ans);
            to_print = 0;
            break;
        case '\n':
            end_of_line = 1;
            /*test*/
            // printf("end of line case\n");
            /*test*/

            if (to_print && !there_was_clear)
            {
                /*test*/
                // printf("printing ans\n");
                /*test*/
                ans = pop();
                printf("\t%.8g\n", ans);
            }
            there_was_clear = 0;
            end_of_line = 0;
            to_print = 1;
            break;
        case 0:
            break;
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

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    i = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    /*test*/
    // printf("c: %c\n", c);
    /*test*/
    s[1] = '\0';
    if (c == '\n')
        return c;
    if (!isdigit(c) && c != '.')
    {
        /*test*/
        // printf("checking backslash: %d\n",there_was_backslash);
        /*test*/
        if (c == '\\')
        {
            there_was_backslash = 1;
            /*test*/
            // printf("there was a backlash\n");
            /*test*/
            return 0;
        }
        if (there_was_backslash)
        {
            /*test*/
            // printf("if of there was a backlash\n");
            /*test*/
            switch (c)
            {
            case 'a':
                /*test*/
                // printf("there was backslash - case a\n");
                /*test*/
                there_was_backslash = 0;
                return '\a';
                break;
            default:
                there_was_backslash = 0;
                return c;
                break;
            }
        }
    }

    while (isalnum(s[++i] = c = getch()) || c == '.')
        ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    /*test*/
    // printf("s[0]: %c\ni = %d\n",s[0],i);
    /*test*/
    /*determine if it is a NUMBER, a COMMAND, an OPERATOR...*/
    if (i == 1 && !isalnum(s[0]))
        return OPERATOR;
    if (i == 1 && islower(s[0]))
        return COMMAND;
    if (i > 1 && isalpha(s[0]))
        return MATH_OPER;
    if (i == 1 && isupper(s[0]))
    {
        /*test*/
        // printf("getop - VARIABLE\n");
        /*test*/
        return VARIABLE;
    }
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
    double op2, op1;
    if (sp < 2)
    {
        printf("ERROR: Can't swap, not enough elements in stack\n");
        return;
    }
    op1 = pop();
    op2 = pop();
    push(op1);
    push(op2);
}

/* raise to the power: raises op2 to the power of op1 */
void raise_to_the_power(void)
{
    double op2, op1;
    op1 = pop();
    op2 = pop();
    if ((op2 == 0 && op1 <= 0) || (op2 < 0 && !((op1 - (int)op1) == 0)))
    {
        printf("ERROR: Invalid exponentiation\n");
        return;
    }
    push(pow(op2, op1));
}

// /* assign: assigns value to variavle */
// void assign(char variable, double value)
// {
//     int index = variable - 'A';
//     if (index < 26)
//     {
//         variables[index] = value;
//         return;
//     }
//     printf("ERROR: Undefined variable\n");
//     // switch (variable)
//     // {
//     // case 'A':
//     //     A = value;
//     //     break;
//     // case 'B':
//     //     B = value;
//     //     break;
//     // case 'C':
//     //     C = value;
//     //     break;
//     // case 'D':
//     //     D = value;
//     //     break;
//     // case 'E':
//     //     E = value;
//     //     break;
//     // case 'F':
//     //     F = value;
//     //     break;
//     // case 'G':
//     //     G = value;
//     //     break;
//     // case 'H':
//     //     H = value;
//     //     break;
//     // case 'I':
//     //     I = value;
//     //     break;
//     // case 'J':
//     //     J = value;
//     //     break;
//     // case 'K':
//     //     K = value;
//     //     break;
//     // case 'L':
//     //     L = value;
//     //     break;
//     // case 'M':
//     //     M = value;
//     //     break;
//     // case 'N':
//     //     N = value;
//     //     break;
//     // case 'O':
//     //     O = value;
//     //     break;
//     // case 'P':
//     //     P = value;
//     //     break;
//     // case 'Q':
//     //     Q = value;
//     //     break;
//     // case 'R':
//     //     R = value;
//     //     break;
//     // case 'S':
//     //     S = value;
//     //     break;
//     // case 'T':
//     //     T = value;
//     //     break;
//     // case 'U':
//     //     U = value;
//     //     break;
//     // case 'V':
//     //     V = value;
//     //     break;
//     // case 'W':
//     //     W = value;
//     //     break;
//     // case 'X':
//     //     X = value;
//     //     break;
//     // case 'Y':
//     //     Y = value;
//     //     break;
//     // case 'Z':
//     //     Z = value;
//     //     break;
//     // default:
//     //     printf("ERROR: Undefined variable\n");
//     //     break;
//     // }
// }

/* show variable: prints out the variabl */
void show_variable(char variable)
{
    int index = variable - 'A';
    if (index < 26)
    {
        printf("%c: %.8g\n", variable, variables[index]);
        return;
    }
    printf("ERROR: Undefined variable\n");
    // switch (variable)
    // {
    // case 'A':
    //     printf("%c: %.8g\n", variable, A);
    //     break;
    // case 'B':
    //     printf("%c: %.8g\n", variable, B);
    //     break;
    // case 'C':
    //     printf("%c: %.8g\n", variable, C);
    //     break;
    // case 'D':
    //     printf("%c: %.8g\n", variable, D);
    //     break;
    // case 'E':
    //     printf("%c: %.8g\n", variable, E);
    //     break;
    // case 'F':
    //     printf("%c: %.8g\n", variable, F);
    //     break;
    // case 'G':
    //     printf("%c: %.8g\n", variable, G);
    //     break;
    // case 'H':
    //     printf("%c: %.8g\n", variable, H);
    //     break;
    // case 'I':
    //     printf("%c: %.8g\n", variable, I);
    //     break;
    // case 'J':
    //     printf("%c: %.8g\n", variable, J);
    //     break;
    // case 'K':
    //     printf("%c: %.8g\n", variable, K);
    //     break;
    // case 'L':
    //     printf("%c: %.8g\n", variable, L);
    //     break;
    // case 'M':
    //     printf("%c: %.8g\n", variable, M);
    //     break;
    // case 'N':
    //     printf("%c: %.8g\n", variable, N);
    //     break;
    // case 'O':
    //     printf("%c: %.8g\n", variable, O);
    //     break;
    // case 'P':
    //     printf("%c: %.8g\n", variable, P);
    //     break;
    // case 'Q':
    //     printf("%c: %.8g\n", variable, Q);
    //     break;
    // case 'R':
    //     printf("%c: %.8g\n", variable, R);
    //     break;
    // case 'S':
    //     printf("%c: %.8g\n", variable, S);
    //     break;
    // case 'T':
    //     printf("%c: %.8g\n", variable, T);
    //     break;
    // case 'U':
    //     printf("%c: %.8g\n", variable, U);
    //     break;
    // case 'V':
    //     printf("%c: %.8g\n", variable, V);
    //     break;
    // case 'W':
    //     printf("%c: %.8g\n", variable, W);
    //     break;
    // case 'X':
    //     printf("%c: %.8g\n", variable, X);
    //     break;
    // case 'Y':
    //     printf("%c: %.8g\n", variable, Y);
    //     break;
    // case 'Z':
    //     printf("%c: %.8g\n", variable, Z);
    //     break;
    // default:
    //     printf("ERROR: Undefined variable\n");
    //     break;
    // }
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* ungets: pushs back an entire string onto the input */
void ungets(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        {
            if (bufp >= BUFSIZE){
                printf("ungets: too many characters, not all the string past through ungets\n");
                return;
            }
            ungetch(s[i]);
        }
    ungetch(s[i]);
}

