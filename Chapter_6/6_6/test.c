#include <stdio.h>

int main(int argc, char const *argv[])
{
    #define MAX 10
    printf("%d\n", MAX);
    #define MAX 100
    printf("%d\n", MAX);

    return 0;
}
