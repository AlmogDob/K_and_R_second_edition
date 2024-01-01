#include <stdio.h>

#define MAX 1000
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

void almogs_strcat(char s[], char t[]);

int main(int argc, char const *argv[])
{
    char s[MAX];
    char t[] = "dobrescu";
    
    s[0] = 'a';
    s[1] = 'l';
    s[2] = 'm';
    s[3] = 'o';
    s[4] = 'g';
    s[5] = ' ';
    s[6] = '\0';
    
    almogs_strcat(s,t);
    printf("%s",s);
    return 0;
}

/* almogs_strcat: concatenate t to end of s; s must be big enough */
void almogs_strcat(char *s, char *t)
{
    while (*(s++) != '\0') /* find end of s */
        // dprintCHAR(*s);
        ;
    s--;
    // dprintCHAR(*s);
    // printf("started coping");
    while (*(s++) = *(t++)) /* copy t to end of s */
        // dprintCHAR(*t);
        ;
}