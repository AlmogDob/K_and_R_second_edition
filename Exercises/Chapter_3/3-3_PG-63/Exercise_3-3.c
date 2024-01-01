#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]);
int creat_complete_list(int sign, int i, char left_char, char right_char, char s[]);

int main(int argc, char const *argv[])
{
    char s1[] = "----- a-b-e, 0-7-6--";
    printf("s1: %s\n", s1);
    char s2[MAXLINE];
    expand(s1, s2);
    for (int i = 0; i < (MAXLINE/50); ++i)
    {
        putchar('-');
    }
    putchar('\n');
    printf("s1: %s\ns2: %s\n", s1, s2);

    return 0;
}

/* expand: expands shorthand notations like a-z in the string s1 into the epuivalent complete list abc...xyz in s2 */
void expand(char s1[], char s2[])
{
    int i, j;
    int sign = 1;
    int counter = 0;

    for (i = j = 0; s1[i] != '\0'; ++i)
    {
        counter++;
        printf("i: %d\ns1[i]: %c\n", i, s1[i]);
        // if (isspace(s1[i]))
        //     continue;
        switch (s1[i])
        {
        case '-':
            if (isalnum(s1[1]) && i == 0 || (isdigit(s1[i - 1]) && isalpha(s1[i + 1])) || (isdigit(s1[i + 1]) && isalpha(s1[i - 1])) || (!isalnum(s1[i-1]) && isalnum(s1[i+1])))
            {
                // /*test*/
                // if (isalnum(s1[1]) && i == 0)
                // {
                //     printf("first test\n");
                // }
                // if (isdigit(s1[i - 1]) && isalpha(s1[i + 1]))
                // {
                //     printf("second test\n");
                // }
                // if (isdigit(s1[i + 1]) && isalpha(s1[i - 1]))
                // {
                //     printf("third test\n");
                // }
                // if (!isalnum(s1[i-1]) && isalnum(s1[i+1]))
                // {
                //     printf("forth test\n");
                // }
                // /*test*/
                sign = -1;
                printf("sign: %d\n", sign);
            }
            else if ((isalpha(s1[i - 1]) && isalpha(s1[i + 1])) || (isdigit(s1[i - 1]) && isdigit(s1[i + 1])))
            {
                j = creat_complete_list(sign, j, s1[i - 1], s1[i + 1], s2);
                sign = 1;
            } 
            else
            {
                s2[j++] = '-';
            }
        default:
            if ((isalpha(s1[i]) && s1[i-1] == s1[i+1] == '-') || (s1[i+1] == '-' && isalnum(s1[i]) && isalpha(s1[i]) == isalpha(s1[i+2])) || s1[i] == '-' || (s1[i-1] == '-' && isalnum(s1[i]) && isalpha(s1[i]) == isalpha(s1[i-2])))
            {
                continue;
            }
            s2[j++] = s1[i];
            break;
        }
        if (counter > MAXLINE)
        {
            printf("function halted!\n");
            break;
        }
    }
    s2[j] = '\0';
}

/* creat_complete_list: creats the full list of abc...xyz acording to the edges and sign*/
int creat_complete_list(int sign, int k, char left_char, char right_char, char s[])
{

    printf("print function was cold\n");
    printf("left char: %c and right char: %c\n", left_char, right_char);
    if (s[k-1] == left_char)
    {
        k -= 1;
    }
    if ((right_char - left_char) > 0)
    {
        printf("right char - left char > 0\n");
        switch (sign)
        {
        case 1:
            printf("func sign: %d\n", sign);
            for (int j = 0; j <= right_char - left_char; j++)
            {
                s[k++] = left_char + j;
                printf("s[k-1]: %c\n", s[k - 1]);
            }
            break;
        case -1:
            printf("func sign: %d\n", sign);
            for (int j = 0; j <= right_char - left_char; j++)
            {
                s[k++] = right_char - j;
                printf("s[k-1]: %c\n", s[k - 1]);
            }
            break;
        }
    }
    if ((right_char - left_char) < 0)
    {
        printf("right char - left char < 0\n");
        switch (sign)
        {
        case 1:
            printf("func sign: %d\n", sign);

            for (int j = 0; j <= left_char - right_char; j++)
            {
                s[k++] = left_char - j;
                printf("s[k-1]: %c\n", s[k - 1]);
            }
            break;
        case -1:
            printf("func sign: %d\n", sign);

            for (int j = 0; j <= left_char - right_char; j++)
            {
                s[k++] = right_char + j;
                printf("s[k-1]: %c\n", s[k - 1]);
            }
            break;
        }
    }
    if (!(right_char - left_char))
    {
        s[k++] = right_char;
    }
    return k;
}
