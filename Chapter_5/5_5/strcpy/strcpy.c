#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

void astrcpy(char *s, char *t);
void pstrcpy1(char *s, char *t);
void pstrcpy2(char *s, char *t);
void pstrcpy3(char *s, char *t);

int main(int argc, char const *argv[])
{

    return 0;
}

/* astrcpy: copy t to s; array subscript version */
void astrcpy(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* pstrcpy1: copy t to s; pointer version 1 */
void pstrcpy1(char *s, char *t)
{
    while ((*s = *t) != '\0'){
        s++;
        t++;
    }
}

/* pstrcpy2: copy t to s; pointer version 2*/
void pstrcpy2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

/* pstrcpy3: copy t to s; pointer version 3*/
void pstrcpy3(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}
