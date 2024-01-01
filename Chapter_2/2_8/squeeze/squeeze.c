#include <stdio.h>

void almogs_squeeze(char s[], int c);

int main()
{
    char s[] = "almog";
    almogs_squeeze(s,'l');
    printf("%s",s);
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

