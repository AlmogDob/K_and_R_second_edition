#include <stdio.h>

// main()
// {
//     if (!0)
//         putchar(254);
//     if (!1)
//     ;
//     else
//         putchar('f');
// }
// #include <stdio.h>

/* replacing special char */

// int main()
// {
//     int c;

//     while ((c=getchar()) != EOF)
//     {
//         if (c == '\t')
//             printf("\\t");
//         else if (c == '\b')
//             printf("\\b");
//         else if (c == '\\')
//             printf("\\\\"); 
//         else if (c == '\n')
//             printf("\\n");
//         else if (c == '\0')
//             printf("\\0");
//         else if (c == ' ')
//             printf("\\(space)");
//         else 
//             printf("%c",c);
//     }  
// }

main()
{
    printf("asdfasdf:");
    int c = '\24';
    putchar(c);
    return 0;
}