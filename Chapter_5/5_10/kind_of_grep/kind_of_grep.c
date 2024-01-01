#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

int almogs_pgetline(char *s, int lim);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && **++argv == '-')
    {
        while ((c = *++argv[0]))
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("kind_of_grep: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    }

    if (argc != 1)
    {
        printf("Usage: kind_of_grep -x -n pattern\n");
    }
    else
    {
        while (almogs_pgetline(line, MAXLINE) > 0)
        {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (number){
                    printf("%ld:", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

/* almogs_pgetline: get line into s, return length */
int almogs_pgetline(char *s, int lim)
{
    int c;
    char *start;

    start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}
