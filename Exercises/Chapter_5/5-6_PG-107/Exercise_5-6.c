#include <stdio.h>
#include <ctype.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define MAXLINE 1000

int almogs_getline(char[], int);
int almogs_pgetline(char *s, int lim);
int almogs_atoi(char s[]);
int almogs_patoi(char *s);

int main(int argc, char const *argv[])
{
    printf("Enter a number: ");
    char line[MAXLINE];
    int len = almogs_pgetline(line,MAXLINE);
    dprintINT(len);
    dprintSTRING(line);

    int ans = almogs_patoi(line);
    dprintINT(ans);

    return 0;
}

/* almogs_getline: get line into s, return length */
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

/* almogs_pgetline: get line into s, return length */
int almogs_pgetline(char *s, int lim)
{
    int c;
    char *start;
    
    start = s;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    // if (c == '\n')
    //     *s++ = c;
    *s = '\0';
    return s-start;
}

/* almogs_atoi: convert s to integer; version 2 */
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

/* almogs_patoi: convert s to integer; version 2 */
int almogs_patoi(char *s)
{
    int n, sign;

    while (isspace(*s++)){  /* skip white space */
        ;
    }
    s--;
    sign = (*s == '-') ? -1 : 1;
    // dprintINT(sign);
    // dprintCHAR(*s);
    if (*s == '+' || *s == '-')  /* skip sign */
        s++;
    n = 0;
    while (isdigit(*s)){
        // dprintCHAR(*s);
        n = 10*n + (*s - '0');
        s++;
    }
    return sign * n;
}


