#include <stdio.h>

#define NOC 256 /* number of characters in ASCII */
#define IN 1      /* inside a word */
#define OUT 0     /* outside a word */
#define MAX 10000 /* maximum length of the input */

/*prints histogram of frequencies of different characters */

main()
{
    int c, i, j, k, indicator, state, len_of_input, error, all_other_are_zeros;
    int char_hist[NOC];

    len_of_input = error = 0;
    state = OUT;

    indicator = 254; /* in ASCII */

    /* zeroing the histogram */
    for (i = 0; i < NOC; ++i)
        char_hist[i] = 0;

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
        
        ++char_hist[c];
    }

    if (error == 0)
    {
        /* printing the histogram horizontaly */
        for (i = 1; i < NOC; ++i)
        {

            all_other_are_zeros = 1;

            /* checking if that it */
            for (k = i; k < NOC; ++k)
            {
                if (char_hist[k] != 0)
                    all_other_are_zeros = 0;
            }

            if (all_other_are_zeros)
            {
                printf("rest of histogream is zeros\n");
                break;
            }

            printf("%3d (%c): ", i, i);

            if (char_hist[i] > 0)
            {
                for (j = 0; j < char_hist[i]; ++j)
                {
                    putchar(indicator);
                }
            }
            printf("\n");
        }
    }
    printf("there were %d characters", len_of_input);
}