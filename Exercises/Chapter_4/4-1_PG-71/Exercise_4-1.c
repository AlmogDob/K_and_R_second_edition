#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "al"; /* pattern to search for */

/* find all lines matching pattern */
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found = 0;
    int index;

    while (getline(line, MAXLINE) > 0)
        if ((index = strrindex(line, pattern)) >= 0)
        {
            printf("\n%s\nthe rightmost occurrence is on index %d (starting from zero)", line,index);
            found++;
        }
    printf("%d", found);

    return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k;
    int p = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            p = i;
    }
    return p;
}
