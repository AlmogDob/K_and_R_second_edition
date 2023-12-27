#include <stdio.h>

#define UPPER 300 /*upper limit*/
#define LOWER 0   /*lower limit of table*/
#define STEP 20
/*
print Fahrenheit-Celsius conversion table
*/

main()
{
    int fahr;
    printf("fahr celsius\n");
    for (int i = 0; i < 12; i++)
    {
        printf("-");
    }
    printf("\n");
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%4d %7.3f\n", fahr, (5.0/9.0)*(fahr-32));
    
}   