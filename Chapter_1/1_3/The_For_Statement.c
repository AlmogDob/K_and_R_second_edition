#include <stdio.h>

/*
print Fahrenheit-Celsius table
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
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%4d %7.3f\n", fahr, (5.0/9.0)*(fahr-32));
    
    for (int i = 0; i < 12; i++)
    {
        printf("-");
    }
    printf("\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%4d %7.3f\n", fahr, (5.0/9.0)*(fahr-32));
}   