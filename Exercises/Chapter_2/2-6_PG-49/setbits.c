#include <stdio.h>

unsigned int almogs_setbits(unsigned int x, int p, int n, unsigned int y);

int main(int argc, char const *argv[])
{
    // 0000 1110
    unsigned int x = 0b110110101101;
    unsigned int y = 0b1000;
    int p = 6;
    int n = 3;
    unsigned int ans = almogs_setbits(x,p,n,y);
    printf("x is - %u\np - %d\nn - %d\ny - %u\nans is - %u",x,p,n,y, ans);
    return 0;
}

/* almogs_setbits: returns x with the n bits 
that begin at position p set to the rightmost 
n bits of y, leaving the other bits unchanged*/
unsigned int almogs_setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int bits_to_move = (y & ~(~0 << n)) << (p - n + 1);
    unsigned int mask = ~(~0 << n) << (p - n + 1);
    // printf("n - %d\nmask befor inversion - %d\n",n, mask);
    x = x & ~mask;
    // printf("x with mask - %u\nbits to move - %u\n",x,bits_to_move);
    x = x | bits_to_move;
    return x;
}

