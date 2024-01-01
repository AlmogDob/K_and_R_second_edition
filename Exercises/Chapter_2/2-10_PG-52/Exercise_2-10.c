#include <stdio.h>



int main(int argc, char const *argv[])
{
    char s[] = "ALMOG DOBRESCU";
    for (int i = 0; s[i] != '\0'; ++i)
        s[i] = almogs_lower(s[i]);
    printf("%s", s);
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int almogs_lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A'):c;
}