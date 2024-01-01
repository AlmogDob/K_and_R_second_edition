#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101
#define MAXLINE 1000 /* maximum input line length */
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

struct nlist /*table entry: */
{
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

unsigned int hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *almogs_strdup(char *);
int almogs_pgetline(char *s, int lim);

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

int main(int argc, char const *argv[])
{
    char name1[] = "almog";
    char defn1[] = "dobrescu";
    char name2[] = "gabi";
    char defn2[] = "dobrescu";
    char line[MAXLINE];
    int len;
    struct nlist *p;

    install(name1, defn1);
    install(name2, defn2);
    while ((len = almogs_pgetline(line, MAXLINE)) != 0)
    {
        
        p = lookup(line);
        if (p == NULL)
        {
            printf("Error: entry '%s' does not exist\n", line);
            continue;
        }
        printf("%s\n\n", p->defn);
    }

    return 0;
}

/* hash: from hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval & HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
        {
            return np; /* found */
        }
    }
    return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) /* not found */
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = almogs_strdup(name)) == NULL)
        {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else /* already there */
    {
        free((void *)np->defn); /* free previous defn */
    }
    if ((np->defn = almogs_strdup(defn)) == NULL)
    {
        return NULL;
    }
    return np;
}

/* almogs_almogs_strdup: make a duplicate of s */
char *almogs_strdup(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
}

/* almogs_pgetline: get line into s, return length */
int almogs_pgetline(char *s, int lim)
{
    int c;
    char *start;

    start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    // if (c == '\n')
    //     *s++ = c;
    *s = '\0';
    return s - start + 1;
}
