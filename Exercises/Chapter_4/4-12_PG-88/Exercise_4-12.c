#include <stdio.h>

#define MAXLINE 1000

void recursive_itoa(int n, char s[]);

int main(int argc, char const *argv[])
{
    int n = -1898;
    char s[MAXLINE];
    recursive_itoa(n,s);
    printf("n: %d\ns: %s\n",n,s);
    return 0;
}

// int index = 0;

/* itoa: conver n to characters in s */
void recursive_itoa(int n, char s[])
{    
    static int index;
    /*test*/
    printf("n: %d\n",n);
    /*test*/
    if (n < 0){
        s[index++] = '-';
        n = -n;
        /*test*/
        printf("revered n\n");
        /*test*/
    }
    
    if (n / 10)
        recursive_itoa(n/10,s);
    s[index++] = n%10 +'0';
    /*test*/
    printf("index: %d\n",index);
    /*test*/
    s[index] = '\0';
}

