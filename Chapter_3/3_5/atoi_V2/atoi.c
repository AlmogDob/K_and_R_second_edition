#include <stdio.h>
#include <ctype.h>

int almogs_atoi(char s[]);

int main(int argc, char const *argv[])
{
    char s[] = "-5891";
    printf("%d",almogs_atoi(s));
    return 0;
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
