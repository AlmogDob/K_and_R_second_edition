#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define MAXLINE 100

char *almogs_strncpy(char *s,char *t,int n);
void almogs_strcat(char s[], char t[]);
char *almogs_strncat(char *s, char *t, int n);
int almogs_strncmp(char *s, char *t,int n);

int main(int argc, char const *argv[])
{
    int n = 10;
    char t[] = "almog dobrescu";
    char s[MAXLINE];

    dprintSTRING(almogs_strncpy(s,t,n));
    
    n = 4;
    char cu[] = " doob";
    char v[MAXLINE];

    v[0] = 'a';
    v[1] = 'l';
    v[2] = 'm';
    v[3] = 'o';
    v[4] = 'g';
    v[5] = '\0';

    dprintSTRING(almogs_strncat(v,cu,n));
    
    n = 20;

    dprintINT(almogs_strncmp(s,v,n));
    
    
    
    
    return 0;
}

/* almogs_strncpy: copy at most n characters of string t to s;
return s*/
char *almogs_strncpy(char *s,char *t,int n)
{
    int i;

    for (i = 0; (*(s+i) = *(t+i)) != '\0' && i < n; i++){
        // dprintINT(i);
        // dprintCHAR(*(s+i));
        ;
    }
    if (*(s+i)){
        *(s+i) = '\0';
    }
    return s;
}

/* almogs_strcat: concatenate t to end of s; s must be big enough */
void almogs_strcat(char *s, char *t)
{
    while (*(s++) != '\0') /* find end of s */
        // dprintCHAR(*s);
        ;
    s--;
    // dprintCHAR(*s);
    // printf("started coping");
    while (*(s++) = *(t++)) /* copy t to end of s */
        // dprintCHAR(*t);
        ;
}

/* almogs_strncat: concatenate at most n characters of string t to string s, terminate s with '\0';
return s*/
char *almogs_strncat(char *s, char *t, int n)
{
    int j = 0, i = 0;
    while (*(s+ (i++)) != '\0') /* find end of s */
        // dprintCHAR(*(s+i));
        ;
    i--;
    // dprintCHAR(*(s+i+j));
    // dprintCHAR(*(t+i+j));
    for (; (*(s+i+j) = *(t+j)) && j < n; j++){
        // dprintINT(j);
        // dprintCHAR(*(s+i+j));
        ;
    }
    *(s+i+j) = '\0';
    return s;
}

/* almogs_strncmp: compare at most n characters of string s to string t;
return <0 if s<t, 0 if s==t, or > 0 is s>t*/
int almogs_strncmp(char *s, char *t,int n)
{
    int i = 0;
    for (; *(s+i) == *(t+i) && i < n; i++){
        // dprintINT(i);
        // dprintCHAR(*(s+i));
        // dprintCHAR(*(t+i));
        if (*(s+i) =='\0' || *(t+i) =='\0')
            return 0;
    }
    return *(s+i) - *(t+i);
}
