#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max #lines to be sorted*/
#define MAXLEN 1000     /* max length of any input line */
#define ALLOCSIZE 10000 /* size of available space */
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

int readlines(char *lineptr[], char *buff, int nlines);
void writelines(char *lineptr[], int nlines);
void almogs_qsort(char *lineptr[], int left, int rigth);
int pstrcmp(char *s, char *t);
int almogs_pgetline(char *s, int lim);
char *almogs_alloc(int n);
void swap(char *v[], int i, int j);

char *lineptr[MAXLINES];        /* pointers to text lines */
static int allocbuf[ALLOCSIZE]; /* storage for alloc */
static int *allocp = allocbuf;  /* next free position */

/* sort input lines */
int main(int argc, char const *argv[])
{
    char buff[ALLOCSIZE];
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, buff, MAXLINES)) >= 0)
    {
        almogs_qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("ERROR: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *buff, int maxlines)
{
    int len, nlines;
    char *p = buff, line[MAXLEN];

    nlines = 0;
    while ((len = almogs_pgetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (ALLOCSIZE -(p-buff)) < len)
        {
            return -1;
        }
        else
        {
            if (line[len - 1] == '\n')
            {
                line[len - 1] = '\0'; /* delete newline */
            }
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
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

/* alloc: return pointer to n characters */
char *almogs_alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    { /* it fits */
        allocp += n;
        return (char *)(allocp - n); /* old p */
    }
    else /* not enough room */
        return 0;
}

/* pstrcmp: retun <0 if s<t, 0 if s==t, >0 if s>t; pointer version */
int pstrcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* qsort: sort v[left]...v[right] into increasing order */
void almogs_qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    almogs_qsort(v, left, last - 1);
    almogs_qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
