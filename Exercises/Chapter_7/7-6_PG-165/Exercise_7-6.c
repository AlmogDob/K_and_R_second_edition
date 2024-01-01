#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void filecopy(FILE *, FILE *);
int getline_from_file(char *line, int max, FILE *);

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char *prog = argv[0];   /* program name for errors */
    char line1[MAXLINE], line2[MAXLINE];
    int len1, len2, line_num1 = 0, line_num2 = 0;

    if (argc < 3) { /* no args; copy standard input */
        fprintf(stderr, "%s: not enough arguments, expects 2 arguments", prog);
        exit(1);
    }
    else {
        --argc;
        if ((fp1= fopen(*++argv, "r")) == NULL){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(2);
        }
        --argc;
        if ((fp2= fopen(*++argv, "r")) == NULL){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(3);
        }
    }

    // filecopy(fp1, stdout);
    // putchar('\n');
    // printf("-------------------------------------------\n");
    // filecopy(fp2, stdout);

    while (((len1 = getline_from_file(line1, MAXLINE, fp1)) != 0) && ((len2 = getline_from_file(line2, MAXLINE, fp2)) != 0)) {
        line_num1++;
        line_num2++;
        if (strcmp(line1, line2)) {
            printf("file1:\n%d. %s",line_num1, line1);
            printf("----------------\n");
            printf("file2:\n%d. %s",line_num2, line2);
            break;
        }
    }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(4);
    }
    exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE*ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF){
        putc(c,ofp);
    }
}

/* getline_from_file: read a line, return length */
int getline_from_file(char *line, int max, FILE *fp)
{
    if (fgets(line,max,fp) == NULL) {
        return 0;
    }
    else {
        return strlen(line);
    }
}