#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define BUFSIZE 100

struct tnode
{                        /* the tree node: */
    char *word;          /* points to the text */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *almogs_strdup(char *s);
int getch(void);
void ungetch(int);

char buf[BUFSIZ];   /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
int there_was_underscore_before = 0;
int there_was_underscore_after = 0;

/* word frequency count */
int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if (there_was_underscore_before || there_was_underscore_after)
            {
                there_was_underscore_before = 0;
                there_was_underscore_after = 0;
                continue;
            }
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) /* a new word has arrived */
    {
        p = talloc(); /* make a new node */
        p->word = almogs_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++; /* repeated word */
    }
    else if (cond < 0) /* less than into left subtree */
    {
        p->left = addtree(p->left, w);
    }
    else /* greater than into right subtree*/
    {
        p->right = addtree(p->right, w);
    }
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* getword: get next word ro character from input */
int getword(char *word, int lim)
{
    /*test*/
    // printf("enterd getword\n");
    /*test*/
    int c, c1;
    char *w = word;

    while (isspace(c = getch()))
    {
        ;
    }
    /*test*/
    // dprintCHAR(c);
    // dprintCHAR(*(w-1));
    /*test*/

    if (c == '/')
    {
        /*test*/
        // printf("c = /\n");
        // dprintCHAR(c);
        /*test*/
        switch (c = getch())
        {
        case '*':
            /*test*/
            // printf("c = *\n");
            /*test*/
            while ((c = getch()) != EOF)
            {
                if (c == '*' && (c1 = getch()) == '/')
                {
                    break;
                }
            }
            if (c == EOF)
            {
                return EOF;
            }
            break;
        case '/':
            while ((c = getch()) != EOF && c != '\n')
            {
                ;
            }
            if (c == EOF)
            {
                return EOF;
            }
            break;
        default:
            break;
        }
    }
    
    if (c == '\"')
    {
        while ((c = getch()) != EOF && c != '\"')
        {
            ;
        }
        if (c == EOF)
        {
            return EOF;
        }
    }

    if (c == '#'){
        while ((c = getch()) != EOF && c != '\n')
        {
            ;
        }
        if (c == EOF)
        {
            return EOF;
        }
    }

    if (!isalpha(c))
    {
        /*test*/
        // printf("c is not alpha\n");
        /*test*/
        if (c == '_')
        {
            there_was_underscore_before = 1;
        }

        *w = '\0';
        return c;
    }
    if (c != EOF)
    {
        *w++ = c;
    }
    for (; --lim > 0; w++)
    {
        /*test*/
        // printf("enterd for loop\n");
        /*test*/
        if (!isalnum(*w = getch()))
        {
            /*test*/
            // dprintSTRING(w-2);
            // printf("c(%c) is not alunm\n", *(w));
            /*test*/
            if (*w == '_')
            {
                there_was_underscore_after = 1;
            }
            else
            {
                ungetch(*w);
            }
            break;
        }
    }
    *w = '\0';
    return word[0];
}

/* talloc: allocates memorry for a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* almogs_strdup: make a duplicate of s */
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

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp>0)?buf[--bufp]:getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}