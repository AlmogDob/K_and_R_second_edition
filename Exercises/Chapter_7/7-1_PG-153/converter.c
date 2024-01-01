#include <stdio.h>
#include <ctype.h>

int upper = 0;
int lower = 0;
int main(int argc, char const *argv[])
{
    int c;

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while ((c = *++argv[0]))
        {
            switch (c)
            {
            case 'U':
                upper = 1;
                break;
            case 'L':
                lower = 1;
                break;
            default:
                printf("converter: illegal option %c\n", c);
                argc = 0;
                break;
            }
        }
    }
    if (argc != 0)
    {
        printf("Usage: converter -U -L \n");
        return 1;
    }

    if (upper){
        while ((c = getchar()) != EOF)
        {
            putchar (toupper(c));
        }
    }

    if (lower){
        while ((c = getchar()) != EOF)
        {
            putchar (tolower(c));
        }
    }
    
    return 0;
}
