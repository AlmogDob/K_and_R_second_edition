#include <stdio.h>

void almogs_squeeze(char s[], int c);
void super_squeeze(char s1[], char s2[]);
void replacing_spacial_char(char s[]);


int main(int argc, char const *argv[])
{
    char str1[] = "almog dobrescu";
    char str2[] = "gkicdlso";

    super_squeeze(str1, str2);

    printf("s1 is: %s\ns2 is: %s\nthe result is: %s\n","almog dobrescu",str2,str1);
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

/* super_squeeze: delets each character in s1 
that matches any character in the string s2 */
void super_squeeze(char s1[], char s2[])
{
    int i, j, c, there_was_a_match;

    there_was_a_match = c = 0;
    
    for (i = j = 0; s1[i] != '\0'; ++i)
    {
        // printf("i: %d\nj: %d\n",i,j);
        // printf("s1 is: %s\ns2 is: %s\n",s1,s2);

        for (c = 0; s2[c] != '\0'; ++c)
        {
            // printf("enterd the second for\n");
            if (s1[i] == s2[c])
            {
                // printf("s1 is: %s\ns2 is: %s\n",s1,s2);
                there_was_a_match = 1;
                // printf("c is - %d and there was a match is - %d\n",c, there_was_a_match);
            }
        }
        // printf("exited the second for\n");
        if (!there_was_a_match)
        {
            s1[j++] = s1[i];
        }
        there_was_a_match = 0;       
    }
    s1[j] = '\n';
    s1[j+1] = '\0';
}

void replacing_spacial_char(char s[])
{ 
    for (int c = 0; s[c] != '\0'; c++)
    {
        if (s[c] == '\t')
            s[c] = 'T';
        else if (s[c] == '\b')
            s[c] = 'B';
        else if (s[c] == '\\')
            s[c] = '\\';
        else if (s[c] == '\n')
            s[c] = 'N';
    }  
}
