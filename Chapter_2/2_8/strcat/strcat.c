#include <stdio.h>

#define MAX 1000

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
void almogs_strcat(char s[], char t[])
{
    int i,j;

    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        ++i;
    while ((s[i++] = t[j++]) != '\0') /* copy t to end of s */
        ;
}