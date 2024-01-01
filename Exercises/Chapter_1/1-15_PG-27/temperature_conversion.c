#include <stdio.h>

/*conversion between Fahrengit and Celsius*/

int Fahr_to_cels(int fahr)
{
    int celsius;
    celsius = 5.0*(fahr-32.0)/9.0;
    return celsius;
}

int main()
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
        celsius = Fahr_to_cels(fahr);
        printf("%4.0f\t%7.3f\n", fahr, celsius);

        fahr = fahr + step;
    }
    return 0;
}