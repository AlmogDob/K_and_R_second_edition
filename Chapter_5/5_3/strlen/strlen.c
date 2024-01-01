#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

int almogs_strlen(char *s);

int main(int argc, char const *argv[])
{
    char str[] = "almog";
    dprintSTRING(str);
    dprintINT(almogs_strlen(str));
    return 0;
}

/* strlen: return length of string s */
int almogs_strlen(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
