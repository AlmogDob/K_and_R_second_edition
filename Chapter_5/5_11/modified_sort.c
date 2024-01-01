#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000   /* max number of lines to be sorted */
#define MAXLEN 1000     /* max length of any input line */
#define ALLOCSIZE 10000 /* size of available space */
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int almogs_pgetline(char *s, int lim);
void almogs_qsort(void *lineptr[], int left, int right,
                  int (*comp)(void *, void *));
int numcmp(char *, char *);
void swap(void *v[], int, int);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;      /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int c;

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while ((c = *++argv[0]))
        {
            switch (c)
            {
            case 'n':
                numeric = 1;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                argc = 0;
                break;
            }
        }
    }
    if (argc != 0)
    {
        printf("Usage: sort -n\n");
        return 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        almogs_qsort((void **)lineptr, 0, nlines - 1,
                     (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    printf("input too big to sort\n");
    return 1;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = almogs_pgetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
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

/* almogs_qsort: sort v[left]...v[right] into increasing order */
void almogs_qsort(void *v[], int left, int right,
                  int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right) /* do nothing if array contains */
    {                  /*   fewer than two elements*/
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    almogs_qsort(v, left, last - 1, comp);
    almogs_qsort(v, last + 1, right, comp);
}

/* numcmp: comper s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    if (v1 == v2)
        return 0;
    return 1;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
