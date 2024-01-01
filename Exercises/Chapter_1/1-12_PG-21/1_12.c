#include <stdio.h>

#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/

/*count lines, words, and characters in input and prints the output word by word*/

main()
{
    int c,nl,nw,fw,nc,state;

    state = OUT;
    nl = nw = nc = fw = 0;
    while ((c=getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }  
               
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
            {
                state = IN;
                ++nw;
                ++fw;  
            }
        if (state == IN)
            putchar(c); 
        if (state == OUT && fw == 1)
        {
                putchar('\n');
            fw = 0;
        }
    }
    printf("nl = %d, nw = %d, nc = %d\n", nl, nw, nc);
}