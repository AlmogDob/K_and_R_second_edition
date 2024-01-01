#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXWORD 100 /* maximum input line length */
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define BUFSIZE 100
enum types
{
    DEFETION = 1,
    EXIST,
};

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
void undef(char *name);
int getword(char *, int);
int almogs_getch(void);
void almogs_ungetch(int);
int what_action(char *word);

char buf[BUFSIZE]; /* buffer for almogs_ungetch */
int bufp = 0;      /* next free position in buf */
char *defenition;
char *name;
int end_of_line = 0;
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

int main(int argc, char const *argv[])
{
    char word[MAXWORD];
    int len, type;
    
    while ((len = getword(word, MAXWORD)) != 0)
    {
        dprintINT(end_of_line);
        type = what_action(word);
        // dprintINT(type);
        switch (type)
        {
        case DEFETION:
            /*test*/
            printf("defetion\n");
            /*test*/
            /*test*/
            dprintSTRING(word);
            /*test*/
            getword(word, MAXWORD);
            /*test*/
            dprintSTRING(word);
            /*test*/
            if (end_of_line)
            {
                printf("Error: not enough input for defenition\n");
                break;
            }
            name = almogs_strdup(word);
            if (end_of_line)
            {
                printf("Error: not enough input for defenition\n");
                break;
            }
            getword(word, MAXWORD);
            /*test*/
            printf("last word\n");
            dprintSTRING(word);
            /*test*/
            
            defenition = almogs_strdup(word);
            install(name, defenition);
            printf("#define %s %s", name, defenition);
            /*test*/
            printf("\n");
            /*test*/
            end_of_line = 0;
            break;
        case EXIST:
            /*test*/
            printf("default\n");
            /*test*/
            printf("%s", lookup(word)->defn);
            break;
        default:
            /*test*/
            printf("default\n");
            /*test*/
            printf("%s", word);
            /*test*/
            printf("\n");
            /*test*/
            break;
        }
    }
    // printf("exited main while\n");
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

/* undef: removes a name and definition from the hash table */
void undef(char *name)
{
    struct nlist *np;
    if ((np = lookup(name)) == NULL)
    {
        printf("Error: entry '%s' does not exist\n", name);
        return;
    }
    np->name = "";
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

/* getword: get next word ro character from input */
int getword(char *word, int lim)
{
    /*test*/
    // printf("enterd getword\n");
    /*test*/
    int c, c1;
    char *w = word;

    while (isspace(c = almogs_getch()))
    {
        ;
    }
    /*test*/
    // dprintCHAR(c);
    // dprintCHAR(*(w-1));
    /*test*/

    if (c != EOF)
    {
        *w++ = c;
    }
    for (; --lim > 0; w++)
    {
        /*test*/
        // printf("enterd for loop\n");
        // dprintCHAR(*w);
        /*test*/
        if (isspace(*w = almogs_getch()) && *w != EOF && *w != '\n')
        {
            /*test*/
            // printf("1\n");
            // dprintCHAR(*w);
            // if (*w == '\0')
            // {
                // printf("*w= \\n\n");
            // }
            /*test*/
            almogs_ungetch(*w);
            break;
        }
        else if (*w == EOF)
        {
            /*test*/
            // printf("2\n");
            // dprintCHAR(*w);
            /*test*/
            return 0;
        }
        else if (*w == '\n')
        {
            *w++ = '\n';
            /*test*/
            // printf("3\n");
            // dprintCHAR(*w);
            /*test*/
            end_of_line = 1;
            /*test*/
            // dprintCHAR(end_of_line);
            /*test*/
            break;
        }
        /*test*/
        // printf("outside of else if\n");
        // dprintCHAR(*w);
        /*test*/
    }
    *w = '\0';
    if (!word[0])
    {
        /*test*/
        // printf("empt\n");
        /*test*/
    }
    return word[0];
}

/* almogs_getch: get a (possibly pushed back) character */
int almogs_getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* almogs_ungetch: push character back on input */
void almogs_ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("almogs_ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* what_action: retuens what action to do */
int what_action(char *word)
{
    if (!strcmp(word, "#define"))
    {
        return DEFETION;
    }
    struct nlist *p = lookup(word);
    dprintSTRING(p->name);
    if (!(p == NULL || strcmp((p->name), "")))
    {
        return EXIST;
    }
    return 0;
}
