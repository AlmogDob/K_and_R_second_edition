#include <stdio.h>

int bitcount(unsigned x);

int main(int argc, char const *argv[])
{
    printf("%d", bitcount(0b00001101));
    return 0;
}

/* bitcount: count 1 bits int x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
        {
            b++;
        }
    }
    return b;
}