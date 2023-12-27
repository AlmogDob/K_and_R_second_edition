#include <stdio.h>

int main() {
    printf("%d", almogs_atoi("0123"));
    return 0;
}

/* atoi: converts s to integer */
int almogs_atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
