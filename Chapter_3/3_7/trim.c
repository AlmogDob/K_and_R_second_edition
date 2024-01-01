#include <stdio.h>



int main(int argc, char const *argv[])
{
    char s[] = "almog \t";
    int current_len = 7;
    printf("s: %s\n",s);
    int new_len = trim(s) + 1;
    printf("new s: %s| with lenght: %d",s,new_len);
    return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}