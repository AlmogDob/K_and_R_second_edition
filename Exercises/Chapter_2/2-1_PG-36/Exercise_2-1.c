#include <stdio.h>
#include <limits.h>

main()
{
    printf("short max: %d\n",SHRT_MAX);
    printf("short min: %d\n",SHRT_MIN);
    printf("unsigned short max: %u\n",USHRT_MAX);
    printf("int max: %d\n",INT_MAX);
    printf("int min: %d\n",INT_MIN);
    printf("unsigned int max: %u\n",UINT_MAX);
    printf("long max: %d\n",LONG_MAX);
    printf("long min: %d\n",LONG_MIN);
    printf("unsigned long max: %x\n",ULONG_MAX);

    
    return 0;
}