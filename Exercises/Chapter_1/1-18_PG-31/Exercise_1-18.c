#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void putline(char line[], int len);
int to_remove(char to_check);

/* print longest input line */

int main()
{
    int len;                 /* current line length */
    int max;                 /* maximum length seen so far */
    int i;
    char line[MAXLINE];      /* curret input line */
    char line_to_print[MAXLINE];   /* longest line is saved here */
    max = 0;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("len is: %d", len);
        for (i = len-2; i >= 0; --i)
        {
            printf("%d.1. line now is  %s",i , line);
            if (to_remove(line[i]) && !(to_remove(line[i-1])) && line[i+1] == '\n')
            {
                line[i] = '\n';
                line[i+1] = '\0';
            }
            printf("%d.2. line now is  %s", i, line);
            if (to_remove(line[i]) && to_remove(line[i-1]) && line[i+1] == '\n')
            {
                line[i-1] = '\n';
                line[i] = '\0';
            }
            printf("%d.3. line now is  %s", i, line);

        }
        printf("len is: %d\n",getline(line_to_print, MAXLINE));
        copy(line_to_print,line);
        printf("len is: %d\n",getline(line_to_print, MAXLINE));
        putline(line_to_print, getline(line_to_print, MAXLINE));
    }
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    // printf("lines: %s\n", s);
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

/* to_remove:checking if the char is a blank or a tab */
int to_remove(char to_check)
{
    if (to_check == ' ' || to_check == '    ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* putline: prints the line to the consol */
void putline(char line[], int len)
{
    if (len > 0)
    {
        for(int i = 0; i < len; ++i)
        {
            char c = line[i];
            putchar(c);
        }
    }
    printf("putline");
    ;
}