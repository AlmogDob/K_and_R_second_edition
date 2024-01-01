#include <stdio.h>
#include <ctype.h>

/* lower: converts input to lower case */
int main(int argc, char const *argv[])
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar (tolower(c));
    }
    return 0;
}
