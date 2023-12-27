#include <stdio.h>

/*print Fahrengit-Celsius table
for fahr = 0, 20, ..., 300*/

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /*lower limit of temperature table*/
    upper = 300;    /*upper limit*/
    step = 20;      /*step size*/
    fahr = lower;
    printf("fahr\tcelsius\n");
    for (int i = 0; i < 15; i++)
    {
        printf("-");
    }
    printf("\n");
    while (fahr <= upper)
    {
        celsius = 5.0*(fahr-32.0)/9.0;
        printf("%4.0f\t%7.3f\n", fahr, celsius);
        /*printf also recognizes
        %0 for octal,
        %x for hexasecimal,
        %c for character,
        %s for characer sting,
        %% for % itself*/

        /*adding an argument befor the type:
        for exemple - 
        (%6d)    print as decimal integer, at least 6 characters wide
        (%.2f)   print as floating point, 2 characters after decimal point
        (%6.2f)  print as floating point, at least 6 wide and 2 after decimal point*/
        fahr = fahr + step;
    }

}