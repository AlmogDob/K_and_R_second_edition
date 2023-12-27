#include <stdio.h>

#define MAX 10000 /* max length of an input */
#define IN 1      /*inside a word */
#define OUT 0     /*outside a word */

/*prints histogram of length of words */

main()
{
    int c, i, j, k, indicator, state, len_of_a_word, nw, fw, len_of_input, error, all_other_are_zeros;
    int lw[MAX];

    fw = nw = len_of_a_word = len_of_input = error = 0;
    state = OUT;

    indicator = 254; /* in ASCII */

    /* zeroing the histogram */
    for (i = 0; i < MAX; ++i)
        lw[i] = 0;

    /* creating the histogram */
    while ((c = getchar()) != EOF)
    {
        ++len_of_input;

        if (len_of_input > MAX)
        {
            printf("ERROR!!!\ninput is bigger then the alowed amount");
            error = 1;
            break;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++fw;
            ++nw;
        }

        if (state == IN)
            ++len_of_a_word;

        if (state == OUT && fw == 1)
        {
            lw[len_of_a_word] = lw[len_of_a_word] + 1;
            len_of_a_word = 0;
            fw = 0;
        }
    }

    if (error == 0)
    {
        /* printing the histogram horizontaly */
        for (i = 1; i < MAX; ++i)
        {

            all_other_are_zeros = 1;

            /* checking if that it */
            for (k = i; k < MAX; ++k)
            {
                if (lw[k] != 0)
                    all_other_are_zeros = 0;
            }

            if (all_other_are_zeros)
            {
                printf("rest of histogream is zeros\n");
                break;
            }

            printf("%3d: ", i);

            if (lw[i] > 0)
            {
                for (j = 0; j < lw[i]; ++j)
                {
                    putchar(indicator);
                }
            }
            printf("\n");
        }
    }
    printf("there were %d words", nw);
}