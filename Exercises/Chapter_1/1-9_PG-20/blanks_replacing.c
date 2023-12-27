#include <stdio.h>

/* count lines in input*/
main()
{
    int c, n1, there_was_blank;
    n1 = 0;
    there_was_blank = 0;
    char blank = ' ';
    while ((c = getchar()) != EOF)
    {
        //printf("\nthere_was_blank - %d\n",there_was_blank);
        if (c == blank)
        {
            if (!(there_was_blank))
                putchar(c);
            there_was_blank = 1;
        }
        if (c != blank)
            there_was_blank = 0;
        if (there_was_blank)
            continue;
        putchar(c);
    }
}
