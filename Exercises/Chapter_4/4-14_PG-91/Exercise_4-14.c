#include <stdio.h>

#define swap(t,x,y) {t temp = x; x = y; y = temp;}
#define dprintint(expr) printf(#expr " = %d\n", expr)
#define dprintdouble(expr) printf(#expr " = %g\n", expr)

int main(int argc, char const *argv[])
{
    int x = 1;
    int y = 2;

    swap(int,x,y);
    dprintint(x);
    dprintint(y);
    
    return 0;
}
