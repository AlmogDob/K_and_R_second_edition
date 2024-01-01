#include <stdio.h>

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define dprintUINT(expr) printf(#expr " = %u\n", expr)

struct {
    unsigned int is_keyword : 1;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
} flags;

int main(int argc, char const *argv[])
{
    unsigned int flag;

    flag |= EXTERNAL | STATIC;

    dprintUINT(flag);

    flags.is_keyword = 3;
    dprintUINT(flags.is_keyword);
    return 0;
}

