#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

/* echo command-line arguments; 1st version */
// int main(int argc, char const *argv[])
// {
//     int i;

//     for (i = 1; i < argc; i++){
//         printf("%s%s", argv[i], (i < argc-1)? " ": "");
//     }
//     printf("\n");

//     return 0;
// }

/* echo command-line arguments; 2nd version */
int main(int argc, char const *argv[])
{
    while (--argc > 0)
    {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}
