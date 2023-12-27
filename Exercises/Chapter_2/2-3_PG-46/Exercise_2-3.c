#include <stdio.h>

int almogs_htoi(char s[]);
int almogs_lower(int c);

int main()
{
    printf("%d\n",almogs_htoi("A25"));
    return 0;
}

/* htoi: converts a sting of hexadecimal 
digits into its equivaakent integer value */
int almogs_htoi(char s[])
{
    for (int i = 0; i < 5; ++i)
        s[i] = almogs_lower(s[i]);

    int i, n;

    n = 0;
    for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f'); ++i)
    {
        // printf("loop - hii\ns[i] = %c\n",s[i]);
        if (s[i] >= '0' && s[i] <= '9')
        {
            // printf("09 - hii\n");
            n = 16 * n + (s[i] - '0');
        }
        
        if (s[i] >= 'a' && s[i] <= 'f')
        {
            // printf("af - hii\n");
            n = 16 * n + 9 + (s[i] - 'a' + 1);
        }
    }
        
    // printf("%s\n",s);    
    return n;

}

/* lower: convert c to lower case; ASCII only */
int almogs_lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else 
        return c;
}

