#include <stdio.h>

#define max(A, B) (A > B ? A : B)
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back

int main(int argc, char const *argv[])
{
    double x = 5;
    double y = 15;
    double x1 = 1;
    double x2 = 2;
    printf("%g\n", max(x + y, x - y));

    dprint(x/y);
    dprint(x1);
    dprint(x2);

    return 0;
}