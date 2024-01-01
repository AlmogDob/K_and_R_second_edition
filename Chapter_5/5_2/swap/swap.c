#include <stdio.h>

#define dprintINT(expr) printf(#expr " = %d\n", expr)

void swap (int *px, int *py);

int main(int argc, char const *argv[])
{
    int x = 1;
    int y = 2;
    dprintINT(x);
    dprintINT(y);
    printf("swap\n");
    swap(&x,&y);
    dprintINT(x);
    dprintINT(y);
    return 0;
}

/* swap: interchange *px and *py */
void swap (int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}
