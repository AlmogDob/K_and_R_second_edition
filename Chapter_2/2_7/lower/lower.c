#include <stdio.h>

int main() 
{
    char s[] = "AlMog";
    for (int i = 0; i < 5; ++i)
        s[i] = almogs_lower(s[i]);
    printf("%s", s);
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int almogs_lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else 
        return c;
}
