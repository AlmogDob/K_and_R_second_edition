#include <stdio.h>

unsigned int almogs_invert(unsigned int x, int p, int n);

int main(int argc, char const *argv[])
{
    unsigned int x = 0b1111;
    int p = 3;
    int n = 1;

    printf("x  - %u\nans - %u", x, almogs_invert(x, p, n));
    return 0;
}

/* almogs_invert: returns x with the n 
bits that begin at position p inverted */
unsigned int almogs_invert(unsigned int x, int p, int n)
{
    return x ^= ~(~0 << n) << (p - n + 1);
}