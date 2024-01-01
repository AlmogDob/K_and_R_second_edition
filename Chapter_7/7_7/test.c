#include <stdio.h>

int main(int argc, char const *argv[])
{
    char line[1000];

    getline(line, 1000);

    printf("%s\n", line);
    return 0;
}
