#include <stdio.h>

#define dprintINT(expr) printf(#expr " = %d\n", expr)

int main(int argc, char const *argv[])
{
    dprintINT('r'-'b');
    return 0;
}
