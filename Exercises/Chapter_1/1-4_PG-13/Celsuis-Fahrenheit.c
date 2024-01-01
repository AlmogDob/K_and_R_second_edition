#include <stdio.h>

#define UPPER 300 /*upper limit*/
#define LOWER 0   /*lower limit of table*/
#define STEP 20
/*
print Celsius-Fahrenheit conversion table
*/

main()
{
    int cels;
    printf("celsius   fahr\n");
    for (int i = 0; i < 16; i++)
    {
        printf("-");
    }
    printf("\n");
    for (cels = LOWER; cels <= UPPER; cels = cels + STEP)
        printf(" %4d   %7.3f\n", cels, (9.0/5)*cels+32);
    
}   