#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char A = 'a';
    // printf("%c, %c",'A',tolower('a'));
    printf("%d - %c\n",'D','D');
    printf("%d - %c\n",'A','A');
    printf("%d - %c\n",'1','1');
    printf("%d - %c\n",'9','9');
    printf("%d - %c\n",'a','a');
    printf("%d - %c\n",'d','d');
    printf("%d - %c\n",'(','(');
    printf("%d - %c\n",'*','*');
    printf("%g\n",atof(&A));
    
    return 0;
}
