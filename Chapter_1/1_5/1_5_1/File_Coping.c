#include <stdio.h>

/*copy input to output; 1st version*/
// main()
// {
//     int c;

//     c = getchar();
//     while (c != EOF)
//     {
//         putchar(c);
//         c = getchar();
//     }
    
// }

/*copy input to output; 2nd version*/
main()
{
    int c;
    printf("%d\n",EOF);
    while ((c = getchar()) != EOF)
        putchar(c);
    
}
