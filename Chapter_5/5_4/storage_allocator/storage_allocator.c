#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define ALLOCSIZE 10000 /* size of available space */
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define MAXLINE 1000 /* maximum input line size */

int *alloc(int n);
void afree(int *p);
int almogs_atoi(char s[]);
int almogs_getline(char line[], int maxline);

static int allocbuf[ALLOCSIZE]; /* storage for alloc */
static int *allocp = allocbuf;  /* next free position */

int main(int argc, char const *argv[])
{
    char line[MAXLINE];      /* curret input line */

    printf("How much integers do you want to store?\n");
    int len = almogs_getline(line, MAXLINE);
    int n = almogs_atoi(line);

    // dprintINT(n);

    int *ptr = alloc(n*4);
    for (int i = 0; i < n; i++){
        printf("Enter an integer: ");
        len = almogs_getline(line,MAXLINE);
        *(ptr + i) = almogs_atoi(line);
    }

    printf("You enterd:\n");
    for (int i = 0; i< n; i++){
        printf("i = %d | ",i);
        dprintINT(*(ptr + i));
    }
    afree(ptr);
    printf("press any key to exit\n");
    getchar();
    return 0;
}

/* alloc: return pointer to n characters */
int *alloc(int n) 
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    }
    else /* not enough room */
        return NULL;
}

/* afree: free storage pointed to by p */
void afree(int *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/* atoi: convert s to integer; version 2 */
int almogs_atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')  /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10*n + (s[i] - '0');
    return sign * n;
}

/* getline: read a line into s, return length */
int almogs_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim -1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;       
}