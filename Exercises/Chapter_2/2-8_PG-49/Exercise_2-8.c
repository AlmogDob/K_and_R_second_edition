#include <stdio.h>

unsigned int almogs_rightrot(unsigned int x, int n);

int main(int argc, char const *argv[])
{
    unsigned int x = 0b11;
    int n = 29;

    printf("x = %u\nans = %u", x, almogs_rightrot(x, n));
    return 0;
}

/* almogs_rightrot: returns the value of the
integer x rotated to the right by n bit positions */
unsigned int almogs_rightrot(unsigned int x, int n)
{
    unsigned int mask_of_leftmost_one = ~(~0 << 1);

    while (mask_of_leftmost_one)
    {
        if (!(mask_of_leftmost_one << 1))
        {
            break;
        }
        mask_of_leftmost_one <<= 1;
        // printf("%u\n",mask_of_leftmost_one);
    }

    for (int i = 0; i < n; ++i)
    {
        x = (x & 01) ? ((x >> 1) | mask_of_leftmost_one) : ((x >> 1));
    }
    return x;
}