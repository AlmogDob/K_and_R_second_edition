#include <stdio.h>

void recursive_reverse(char s[]);
void swap(char v[], int i, int j);

int main(int argc, char const *argv[])
{
    char s[] = "abcde";
    printf("s: %s\n", s);
    recursive_reverse(s);
    printf("revese s: %s\n", s);
    return 0;
}

/* recursive_reverse: reverses the string s in place */
void recursive_reverse(char s[])
{
    static int first = 0;
    int last = strlen(s) - 1 - first;
    if (first >= last)
        return;
    swap(s, first, last);
    ++first;
    --last; 
    recursive_reverse(s);
}

/* swap: interchange v[i] and v[j] */
void swap(char v[], int i, int j)
{
    char temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* reverse: reverse strnig s in place */
/*
void almogs_reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
*/