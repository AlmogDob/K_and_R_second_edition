#include <stdio.h>

void almogs_squeeze(char s[], int c);
int any(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
    char str1[] = "almog dobrescu";
    char str2[] = "ql";

    printf("s1 is: %s\ns2 is: %s\nthe result is: %d\n", str1, str2, any(str1, str2));
    // replacing_spacial_char(str1);
    // printf("%s",str1);
    return 0;
}

/* almogs_squeeze: delete all c from s */
void almogs_squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

/* any: delets each character in s1
that matches any character in the string s2 */
int any(char s1[], char s2[])
{
    int i, c;

    c = 0;

    for (i = 0; s1[i] != '\0'; ++i)
    {
        printf("i: %d\n", i);
        printf("s1 is: %s\ns2 is: %s\n", s1, s2);

        for (c = 0; s2[c] != '\0'; ++c)
        {
            printf("enterd the second for\n");
            printf("c is - %d\n", c);
            if (s1[i] == s2[c])
            {
                printf("s1 is: %s\ns2 is: %s\n", s1, s2);
                return i;
            }
        }
        printf("exited the second for\n");
    }
    return -1;
}
