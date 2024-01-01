#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXNUMLINE 1000 /* maximum number of inputed line */
#define MAXLINE 1000    /* maximum length of inputed line */
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)

int almogs_pgetline(char *s, int lim);

/* tail; prints the last n lines of its input. n can be changed by an optional argument (-n)*/
int main(int argc, char *argv[])
{
    int n = 10, num_of_lines = 0;
    char *c, *input_file[MAXNUMLINE];
    if (argc > 1)
    {
        while (--argc > 0)
        {
            c = *++argv;
            // dprintSTRING(c);
            // dprintCHAR(*c);
            // dprintCHAR(*(c+1));
            // strcat(c,)
            switch (*c)
            {
            case '-':
                n = atoi((c + 1));
                break;

            default:
                printf("Usage: -n\n");
                break;
            }
        }
    }
    
    for (int i = 0; i < MAXNUMLINE; i++)
    {
        input_file[i] = malloc(sizeof(char) * MAXLINE);
    }
    
    while (almogs_pgetline(input_file[num_of_lines++], MAXLINE) > 0)
    {
        // dprintINT(num_of_lines);
        assert(num_of_lines < MAXNUMLINE);
        ;
    }
    // dprintINT(num_of_lines);

    // dprintINT(n);
    n = (n > num_of_lines) ? num_of_lines : n;
    // dprintINT(n);

    // dprintSTRING(input_file[num_of_lines - 1 + i]);
    while (n > 0)
    {
        printf("%d. %s", num_of_lines - n + 1, input_file[num_of_lines - n]);
        n--;
    }
    putchar('\n');
    return 0;
}

/* almogs_pgetline: get line into s, return length */
int almogs_pgetline(char *s, int lim)
{
    int c;
    char *start;

    start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        // dprintCHAR(c);
        *s++ = c;
        // dprintCHAR(*s);
    }
    assert(lim > 0);
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}
