#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[], char reverse_s[], int len);

/* print longest input line */

int main()
{
    int len;                 /* current line length */
    int max;                 /* maximum length seen so far */
    char line[MAXLINE];      /* curret input line */
    char longest[MAXLINE];   /* longest line is saved here */
    char reverse_s[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {        
        max = len;
        reverse(line,reverse_s,len);
        printf("%s",reverse_s);
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

/* reverse: teverses the character string s */
void reverse(char s[], char reverse_s[], int len)
{
    int i;
    
    for (i = 0; i < len-1; ++i)
    {
         reverse_s[i] = s[len-2-i];
    } 
    reverse_s[len-1] = '\n'; 
    reverse_s[len] = '\0';
}