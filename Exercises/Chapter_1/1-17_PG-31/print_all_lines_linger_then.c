#include <stdio.h>

#define MAXLINE 1000 /*Maximum characters per line*/
#define MINLENGTH 100

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;                 /* current line length */
    char line[MAXLINE];      /* curret input line */
    char longenogh[MAXLINE]; /*line to print*/
    
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > MINLENGTH)
        {
            copy(longenogh, line);
            printf("%d: %s\n",len-1, longenogh);
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from [i]) != '\0')
        ++i;
}