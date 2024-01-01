#include <stdio.h>

void almogs_srand(unsigned int seed);

unsigned long int next = 1;

int main()
{
    printf("first round: %d\n", almogs_rand());
    printf("second round: %d\n", almogs_rand());
    printf("third round: %d\n", almogs_rand());

    return 0;
}

/* rand: return pseudo-random integer on 0...32767 */
int almogs_rand(void)
{
    next = next*1103515245+12345;
    return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand() */
void almogs_srand(unsigned int seed)
{
    next = seed;
}
