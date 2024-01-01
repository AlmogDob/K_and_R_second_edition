// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>

// #define MAXWORD 100
// #define dprintSTRING(expr) printf(#expr " = %s\n", expr)
// #define dprintCHAR(expr) printf(#expr " = %c\n", expr)
// #define dprintINT(expr) printf(#expr " = %d\n", expr)
// #define dprintUINT(expr) printf(#expr " = %u\n", expr)
// #define BUFSIZE 100

// struct lines_numbers
// {
//     unsigned int line_number;
//     int count;
//     struct lines_numbers *left;
//     struct lines_numbers *right;
// };

// struct tnode
// {                        /* the tree node: */
//     char *word;          /* points to the text */
//     int count;           /* number of occurrences */
//     struct tnode *left;  /* left child */
//     struct tnode *right; /* right child */
//     struct lines_numbers *line_number_tree;
// };

// struct tnode *addtree(struct tnode *, char *);
// struct lines_numbers *add_line_number(struct lines_numbers *, unsigned int);
// void treeprint(struct tnode *);
// void line_number_print(struct lines_numbers *);
// int getword(char *, int);
// struct tnode *talloc(void);
// struct lines_numbers *lnalloc(void);
// char *almogs_strdup(char *s);
// int getch(void);
// void ungetch(int);

// char buf[BUFSIZ]; /* buffer for ungetch */
// int bufp = 0;     /* next free position in buf */
// int there_was_underscore_before = 0;
// int there_was_underscore_after = 0;
// int all = 0;
// unsigned int number_of_lines = 0;

// /* word frequency count */
// int main(int argc, char *argv[])
// {
//     int c;

//     while (--argc > 0 && (*++argv)[0] == '-')
//     {
//         while ((c = *++argv[0]))
//         {
//             switch (c)
//             {
//             case 'a':
//                 all = 1;
//                 break;
//             default:
//                 printf("cross referencer: illegal option %c\n", c);
//                 argc = 0;
//                 break;
//             }
//         }
//     }
//     if (argc != 0)
//     {
//         printf("Usage: sort -a \n");
//         return 1;
//     }

//     printf("occurrences\tword\n"
//            "---------------------\n");
//     // dprintINT(all);
//     struct tnode *root;
//     char word[MAXWORD];

//     root = NULL;
//     while (getword(word, MAXWORD) != EOF)
//     {
//         // dprintUINT(number_of_lines);
//         if (isalpha(word[0]))
//         {
//             if ((there_was_underscore_before || there_was_underscore_after) && !all)
//             {
//                 there_was_underscore_before = 0;
//                 there_was_underscore_after = 0;
//                 continue;
//             }
//             root = addtree(root, word);
//         }
//     }
//     treeprint(root);
//     dprintUINT(number_of_lines);
//     return 0;
// }

// /* addtree: add a node with w, at or below p */
// struct tnode *addtree(struct tnode *p, char *w)
// {
//     int cond;

//     if (p == NULL) /* a new word has arrived */
//     {
//         p = talloc(); /* make a new node */
//         p->word = almogs_strdup(w);
//         p->count = 1;
//         p->line_number_tree = NULL;
//         dprintUINT(number_of_lines);
//         p->line_number_tree = add_line_number(p->line_number_tree, number_of_lines);
//         p->left = p->right = NULL;
//     }
//     else if ((cond = strcmp(w, p->word)) == 0)
//     {
//         p->count++; /* repeated word */
//     }
//     else if (cond < 0) /* less than into left subtree */
//     {
//         p->left = addtree(p->left, w);
//     }
//     else /* greater than into right subtree*/
//     {
//         p->right = addtree(p->right, w);
//     }
//     return p;
// }

// /* addtree: add a node with n, at or below l */
// struct lines_numbers *add_line_number(struct lines_numbers *l, unsigned int n)
// {
//     int cond;

//     if (l == NULL) /* a new word has arrived */
//     {
//         l = lnalloc(); /* make a new node */
//         l->count = 1;
//         l->line_number = n;
//         l->left = l->right = NULL;
//     }
//     else if ((cond = (n - (int)l->line_number)) == 0)
//     {
//         l->count++;
//         ;
//     }
//     else if (cond < 0) /* less than into left subtree */
//     {
//         l->left = add_line_number(l->left, n);
//     }
//     else /* greater than into right subtree*/
//     {
//         l->right = add_line_number(l->right, n);
//     }
//     return l;
// }

// /* treeprint: in-order print of tree p */
// void treeprint(struct tnode *p)
// {
//     if (p != NULL)
//     {
//         treeprint(p->left);
//         printf("%11d\t%s\t", p->count, p->word);
//         line_number_print(p->line_number_tree);
//         printf("\n");
//         treeprint(p->right);
//     }
// }

// /* line_nubers_print: in-order print of line_numbers ln*/
// void line_number_print(struct lines_numbers *ln)
// {
//     if (ln != NULL)
//     {
//         line_number_print(ln->left);
//         printf("%5d: %3d ", ln->line_number, ln->count);
//         line_number_print(ln->right);
//     }
// }

// /* getword: get next word ro character from input */
// int getword(char *word, int lim)
// {
//     /*test*/
//     // printf("enterd getword\n");
//     /*test*/
//     int c, c1;
//     char *w = word;

//     while (isspace(c = getch()))
//     {
//         if (c == '\n')
//         {
//             number_of_lines++;
//         }
//         /*test*/
//         // dprintCHAR(c);
//         // dprintUINT(number_of_lines);
//         /*test*/
//         ;
//     }
//     if (c == '\n')
//     {
//         number_of_lines++;
//     }
//     /*test*/
//     // dprintCHAR(c);
//     // dprintUINT(number_of_lines);
//     // dprintCHAR(*(w-1));
//     /*test*/
//     if (!all)
//     {
//         if (c == '/')
//         {
//             /*test*/
//             // printf("c = /\n");
//             // dprintCHAR(c);
//             // dprintUINT(number_of_lines);
//             /*test*/
//             switch (c = getch())
//             {
//             case '*':
//                 /*test*/
//                 // printf("c = *\n");
//                 /*test*/
//                 while ((c = getch()) != EOF)
//                 {
//                     /*test*/
//                     // dprintCHAR(c);
//                     // printf("1\n");
//                     // dprintUINT(number_of_lines);
//                     /*test*/
//                     // if (c == '\n')
//                     // {
//                     //     number_of_lines++;
//                     // }
//                     if (c == '*' && (c1 = getch()) == '/')
//                     {
//                         break;
//                     }
//                     /*test*/
//                     // dprintCHAR(c1);
//                     // printf("11\n");
//                     /*test*/
//                     // if (c1 == '\n')
//                     // {
//                     //     number_of_lines++;
//                     // }
//                 }
//                 if (c == EOF)
//                 {
//                     return EOF;
//                 }
//                 break;
//             case '/':
//                 while ((c = getch()) != EOF && c != '\n')
//                 {
//                     ;
//                 }
//                 /*test*/
//                 // dprintCHAR(c);
//                 // printf("2\n");
//                 // dprintUINT(number_of_lines);
//                 /*test*/
//                 // if (c == '\n')
//                 // {
//                 //     number_of_lines++;
//                 // }
//                 if (c == EOF)
//                 {
//                     return EOF;
//                 }
//                 break;
//             default:
//                 break;
//             }
//         }

//         if (c == '\"')
//         {
//             while ((c = getch()) != EOF && c != '\"')
//             {
//                 if (c == '\n')
//                 {
//                     number_of_lines++;
//                 };
//             }
//             if (c == EOF)
//             {
//                 return EOF;
//             }
//         }

//         if (c == '#')
//         {
//             while ((c = getch()) != EOF && c != '\n')
//             {
//                 ;
//             }
//             /*test*/
//             // dprintCHAR(c);
//             // printf("3\n");
//             // dprintUINT(number_of_lines);
//             /*test*/
//             // if (c == '\n')
//             // {
//             //     number_of_lines++;
//             // }
//             if (c == EOF)
//             {
//                 return EOF;
//             }
//         }
//     }
//     if (!isalpha(c))
//     {
//         /*test*/
//         // dprintCHAR(c);
//         // dprintUINT(number_of_lines);
//         /*test*/
//         if (c == '\n')
//         {
//             number_of_lines++;
//         }
//         /*test*/
//         // printf("c is not alpha\n");
//         /*test*/
//         if (c == '_')
//         {
//             there_was_underscore_before = 1;
//         }

//         *w = '\0';
//         return c;
//     }
//     if (c != EOF)
//     {
//         *w++ = c;
//     }
//     for (; --lim > 0; w++)
//     {
//         /*test*/
//         // printf("enterd for loop\n");
//         /*test*/
//         /*test*/
//         // dprintCHAR(*w);
//         /*test*/
//         if (!isalnum(*w = getch()))
//         {
//             /*test*/
//             // dprintCHAR(*w);
//             /*test*/
//             if (*w == '\n')
//             {
//                 number_of_lines++;
//             }
//             /*test*/
//             // dprintSTRING(w-2);
//             // printf("c(%c) is not alunm\n", *(w));
//             /*test*/
//             if (*w == '_')
//             {
//                 there_was_underscore_after = 1;
//             }
//             else
//             {
//                 ungetch(*w);
//             }
//             break;
//         }
//         /*test*/
//         // dprintCHAR(*w);
//         /*test*/
//         if (*w == '\n')
//         {
//             number_of_lines++;
//         }
//     }
//     /*test*/
//     // dprintCHAR(*w);
//     /*test*/
//     if (*w == '\n')
//     {
//         number_of_lines++;
//     }
//     assert(lim >= 0);
//     *w = '\0';
//     return word[0];
// }

// /* talloc: allocates memorry for a tnode */
// struct tnode *talloc(void)
// {
//     return (struct tnode *)malloc(sizeof(struct tnode));
// }

// /* lnalloc: allocates memorry for a lines_numbers */
// struct lines_numbers *lnalloc(void)
// {
//     return (struct lines_numbers *)malloc(sizeof(struct lines_numbers));
// }

// /* almogs_strdup: make a duplicate of s */
// char *almogs_strdup(char *s)
// {
//     char *p;

//     p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
//     if (p != NULL)
//     {
//         strcpy(p, s);
//     }
//     return p;
// }

// /* getch: get a (possibly pushed back) character */
// int getch(void)
// {
//     return (bufp > 0) ? buf[--bufp] : getchar();
// }

// /* ungetch: push character back on input */
// void ungetch(int c)
// {
//     if (bufp >= BUFSIZE)
//         printf("ungetch: too many characters\n");
//     else
//         buf[bufp++] = c;
// }


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAX_WORD_COUNT 100

#define NOISEWORDS_SIZE   (sizeof noisewords / sizeof noisewords[0])

// words in noisewords must be ordered lexicographically

char *noisewords[] = {
    "a", "an", "and", "are", "at", "be", "by", "can", "did", "do", "done", 
    "for", "from", "have", "he", "her", "his", "if", "in", "into", "is", "it", 
    "its", "many", "must", "no", "none", "not", "of", "off", "on", "or",  
    "our", "ours", "so", "such", "that", "the", "them", "they", "their", 
    "this", "to", "too", "us", "was", "we", "were", "what", "who", "with", 
    "without"
};

struct tnode {
    char *word;
    int lines[MAX_WORD_COUNT];
    int index;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int binsearch(char *, char * noisewords[], int);

int LINE_NUMBER = 1;

/* word frequency count */
int main() {

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if (binsearch(word, noisewords, NOISEWORDS_SIZE) == -1)
                root = addtree(root, word);
    treeprint(root);

    return 0;
}

struct tnode *talloc(void);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {

    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->lines[p->index++] = LINE_NUMBER;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        if (p->lines[p->index - 1] != LINE_NUMBER)
            p->lines[p->index++] = LINE_NUMBER;
    } else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);

    return p;
}

/* treeprint: in-order print of tree */
void treeprint(struct tnode *p) {

    int i;

    if (p != NULL) {
        treeprint(p->left);
        printf("%s - ", p->word);
        for (i = 0; i < p->index; i++)
            printf("%d, ", p->lines[i]);
        printf("\n");
        treeprint(p->right);
    }
}

int binsearch(char *word, char *noisewords[], int n) {

    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        // use strcasecmp from string.h - case-insensitive comparison 
        if ((cond = strcasecmp(word, noisewords[mid])) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int getword(char *word, int lim) {

    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()) && c != '\n')
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        if (c == '\n')
            LINE_NUMBER++;
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* talloc: make a node */
struct tnode *talloc(void) {
    struct tnode *p = (struct tnode *) malloc(sizeof (struct tnode));
    p->index = 0;
    return p;
}