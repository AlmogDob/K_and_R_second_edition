#include <stdio.h>

void almogs_printd(int n);

int main()
{
    int n = 896;
    almogs_printd(n);
    return 0;
}

/* printd: print n in decimal*/
void almogs_printd(int n)
{
    if (n < 0){
        putchar('-');
        n = -n;
    }
    printf("n - %d\n",n);
    if (n/10)
        almogs_printd(n/10);
    putchar(n % 10 +'0');
}
