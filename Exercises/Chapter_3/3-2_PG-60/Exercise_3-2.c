#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void reverse_escape(char r[], char e[]);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
    char s[MAXLINE];
    char t[] = "monky\tD\nluf\b\t\vfy";
    escape(s, t);
    printf("t - %s\ns - %s\n\n", t, s);

    char r[MAXLINE];
    char e[MAXLINE];
    copy(e, s);
    reverse_escape(r, e);
    printf("e - %s\nr - %s\n", e, r);
    return 0;
}

/* escape: converts characters like newline
and tab into visible escape swquences like
\n and \t as it copies the string t to s */
void escape(char s[], char t[])
{

    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i)
    {
        switch (t[i])
        {
        case '\a':
            s[j++] = '\\';
            s[j++] = 'a';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        case '\f':
            s[j++] = '\\';
            s[j++] = 'f';
            break;
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\r':
            s[j++] = '\\';
            s[j++] = 'r';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\v':
            s[j++] = '\\';
            s[j++] = 'v';
            break;
        default:
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

/* reverse_escape: the oposite of escape */
void reverse_escape(char r[], char e[])
{
    int i, j;
    int there_was_backslash = 0;
    for (i = j = 0; e[i] != '\0'; ++i)
    {
        // printf("e[i] - %c\n",e[i]);

        switch (e[i])
        {
        case '\\':
            ++i;
            there_was_backslash = 1;
            switch (e[i])
            {
            case 'a':
                r[j++] = '\a';
                break;
            case 'b':
                r[j++] = '\b';
                break;
            case 'f':
                r[j++] = '\f';
                break;
            case 'n':
                r[j++] = '\n';
                break;
            case 'r':
                r[j++] = '\r';
                break;
            case 't':
                r[j++] = '\t';
                break;
            case 'v':
                r[j++] = '\v';
                break;
            }
        default:
            if (there_was_backslash)
            {
                there_was_backslash = 0;
            }else
                r[j++] = e[i];
            break;
        }
    }
    r[j] = '\0';
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}