#include <stdio.h>

#define MAXLINE 1000

int main(int argc, char const *argv[])
{
    char left_char = 'a';
    char right_char = 'd';
    char s[MAXLINE];
    int i = 0;
    switch((right_char - left_char) > 0)
    {
        case 0:
            printf("left biger then right\n");
            for (int j = 0; j <= right_char - left_char; j++)
            {
                s[i++] = right_char - j;
            }
            s[i] = '\0';
            printf("%s",s);
            break;
        default:
            printf("right biger then left\n");
            for (int j = 0; j <= right_char - left_char; j++)
            {
                s[i++] = left_char + j;
            }
            s[i] = '\0';
            printf("%s",s);
            break;
    }
    
    return 0;
}
