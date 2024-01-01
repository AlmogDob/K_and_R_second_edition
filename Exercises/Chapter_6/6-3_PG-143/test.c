#include <stdio.h>

int main(int argc, char const *argv[])
{
    // unsigned int n = 0;
    // for (int i =0; i< 100; i++)
    // {
    //     n++;
    //     printf("%u\n",n);
    // }

    char c;
    while ((c = getchar()) != EOF)
    {
        printf("c:%c\n",c);
    }
    return 0;
}
