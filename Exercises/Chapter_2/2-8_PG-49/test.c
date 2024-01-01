#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    int size = sizeof(unsigned) * 8; // Size of unsigned in bits
    n = n % size; // Ensure n is in the range [0, size)

    // Perform the right rotation
    return (x >> n) | (x << (size - n));
}

int main() {
    unsigned num = 0b10011; // Example binary number
    int rotation = 3;               // Example rotation count

    // Call the rightrot function and print the result
    unsigned result = rightrot(num, rotation);
    printf("x = %u\nans = %u",num,result);

    return 0;
}
