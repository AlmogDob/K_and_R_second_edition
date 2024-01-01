#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

char *month_name(int n);

int main(int argc, char const *argv[])
{
    dprintSTRING(month_name(2));
    dprintSTRING(month_name(13));
    
    return 0;
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "Febuary", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"};


    return (n<1 || n >12) ? name[0] : name[n];
}
