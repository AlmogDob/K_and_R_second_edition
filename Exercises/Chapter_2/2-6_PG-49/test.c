// #include <stdio.h>



// int main(int argc, char const *argv[])
// {
//     unsigned int n,p,x;
//     n = 2;
//     x = 0b1111;


//     return 0;
// }
// #include <stdio.h>

// unsigned setbits(unsigned x, int p, int n, unsigned y) {
//     // Create a mask to clear the bits in x that will be replaced
//     unsigned mask = ~(~0 << n) << (p - n + 1);

//     // Clear the bits in x and OR them with the corresponding bits from y
//     return (x & ~mask) | ((y & ~(~0 << n)) << (p - n + 1));
// }

// int main() {
//     unsigned x = 0b110110101101;  // Example value for x
//     unsigned y = 0b1000;          // Example value for y
//     int p = 6;                    // Example position
//     int n = 3;                    // Example number of bits

//     // Call the setbits function and print the result
//     unsigned result = setbits(x, p, n, y);
//     printf("%u\n", result);

//     return 0;
// }

#include <stdio.h>



int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; ++i)
        printf("%d",i+1);    
    return 0;
}
