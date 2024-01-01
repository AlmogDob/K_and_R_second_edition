#include <stdio.h>



int main(int argc, char const *argv[])
{
    char s[] = "almog dobrescu";
    int i = 0;
    s[i++] = 'A';
    printf("%s\n",s);
    i = 0;
    s[++i] = 'L';
    printf("%s\n",s);

    return 0;
}
