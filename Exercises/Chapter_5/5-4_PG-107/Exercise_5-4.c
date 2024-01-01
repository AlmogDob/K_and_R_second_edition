#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

int pstrcmp(char *s, char *t);
int strend(char *s, char *t);

int main(int argc, char const *argv[])
{
    char s[] = "almog dobrescu mog";
    char t[] = "mog";

    if (strend(s, t))
    {
        printf("succes");
        return 0;
    }
    printf("failed");

    return 0;
}

/* pstrcmp: retun <0 if s<t, 0 if s==t, >0 if s>t; pointer version */
int pstrcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* strend: returns 1 if the string t occurs at the end of the string s, and zero otherwise */
int strend(char *s, char *t)
{
    int i, j;

    for (i = 0; *(s + i) != '\0'; i++)
    {
        ;
    }
    for (j = 0; *(t + j) != '\0'; j++)
    {
        ;
    }
    dprintINT(i);
    dprintINT(j);
    printf("--------\n");
    while (*(s + (--i)) == *(t + (--j)) && j >= 0)
    {
        dprintCHAR(*(s + i));
        dprintCHAR(*(t + j));
        ;
    }
    // dprintINT(i);
    dprintINT(j);
    if (j == -1)
        return 1;
    return 0;

//     for (; *s != *t; ++s)
//         if (*s == '\0')
//             return 0;
//     for (; *s == *t; s++, t++)
//         if (*s == '\0' && *t == '\0')
//             return 1;
//     return 0;
}
