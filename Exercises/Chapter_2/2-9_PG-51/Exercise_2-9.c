#include <stdio.h>



int main(int argc, char const *argv[])
{
    int b;
    unsigned int x = 0b00001101;

    for (b = 0; x != 0; b++)
    {
        x &= (x-1);
    }
    printf("%d\n",b);
   
    return 0;
}
