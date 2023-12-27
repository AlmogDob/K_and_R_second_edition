#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

int astrcmp(char *s, char *t);
int pstrcmp(char *s, char *t);

int main(int argc, char const *argv[])
{
    char s1[] = "acc";
    char s2[] = "cbb";

    dprintINT(astrcmp(s1,s2));
    dprintINT(pstrcmp(s1,s2));

    return 0;
}

/* astrcmp: retun <0 if s<t, 0 if s==t, >0 if s>t; array version */
int astrcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] =='\0')
            return 0;
    return s[i] - t[i];
}

/* pstrcmp: retun <0 if s<t, 0 if s==t, >0 if s>t; pointer version */
int pstrcmp(char *s, char *t)
{
    for (; *s == *t; s++,t++)
        if (*s =='\0')
            return 0;
    return *s - *t;
}
