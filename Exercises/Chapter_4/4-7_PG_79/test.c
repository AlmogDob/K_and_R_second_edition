#include <stdio.h>

#define BUFSIZE 10

void ungets(char s[]);
void ungetch(int c);

char buf[BUFSIZ];  
int bufp = 0;

int main(int argc, char const *argv[])
{
    // for (int i = 0; i < 10; ++i)
    // {
    //     printf("%d",i);
    // }
    // printf("\n");
    // int j = 0;
    // while (j <10)
    // {
    //     printf("%d",++j);
    // }
    char s[] = "almog dobrescu";
    ungets(s);
    printf("%s", buf);

    return 0;
}

/* ungets: pushs back an entire string onto the input */
void ungets(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        {
            if (bufp >= BUFSIZE){
                printf("ungets: too many characters, not all the string past through ungets\n");
                return;
            }
            ungetch(s[i]);
        }
    ungetch(s[i]);
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}