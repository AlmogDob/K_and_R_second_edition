#include <stdio.h>

extern int sp;
extern double val[];           /* value stack */
extern int maxval;
extern int there_was_clear;
extern int end_of_line;

/* push: push f onto value stack */
void push(double f)
{
    /*test*/
    // printf("push - val[sp+1]: %.8g\n",f);
    /*test*/
    if (sp < maxval)
        val[sp++] = f;
    else
        printf("ERROR: Stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    /*test*/
    // printf("pop - val[sp-1]: %.8g\n",val[sp-1]);
    /*test*/
    if (sp > 0)
        return val[--sp];
    else
    {
        /*test*/
        // printf("end of line: %d\nthere was a clear: %d\n",end_of_line,there_was_clear);
        /*test*/
        if (!there_was_clear && !end_of_line)
            printf("ERROR: Stack empty\n");
        return 0.0;
    }
}
