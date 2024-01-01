#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main(int argc, char const *argv[])
{
    unsigned birth_year = 2003;
    char name[] = "Almog Dobrescu";

    minprintf("name: %s\nbirth year: %u\n", name, birth_year);
    minprintf("%c\n", name[0]);
    return 0;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    char cval;
    unsigned uval;

    va_start(ap, fmt);  /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }
        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++){
                putchar(*sval);
            }
            break;
        case 'c':
            cval = va_arg(ap, char);
            printf("%c", cval);
            break;
        case 'u':
            uval = va_arg(ap, unsigned);
            printf("%u", uval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap); /* clean up when done */
}