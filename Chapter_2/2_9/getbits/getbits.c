#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(int argc, char const *argv[])
{
    char c = ~0;
    printf("%u", getbits(c,4,3));
    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
