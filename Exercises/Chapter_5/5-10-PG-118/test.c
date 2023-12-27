#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

void almogs_copy(char *to[], char *from[]);

int main(int argc, char *argv[])
{
    char input[MAXLINE] = {0};
    int inputp = 0;
    
    while (--argc > 0)
    {
        strcat(input,*++argv);
        strcat(input," ");
    }

    dprintSTRING(input);
    
    return 0;
}

/* almogs_copy: copy 'from' into 'to'; assume to is big enough */
void almogs_copy(char *to[], char *from[])
{
    while ((*(to++) = *(from++)))
        ;
}