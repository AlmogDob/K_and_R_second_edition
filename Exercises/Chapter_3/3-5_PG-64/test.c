#include <stdio.h>



int main(int argc, char const *argv[])
{  
    int n;
    int b = 16;

    for (n = 0; n<16;n++)
    {
        int c = (n % b <= 9)?(n % b + '0'):((n % b) - 10 + 'a');
        printf("%c", c);
    }
    
    return 0;
}
