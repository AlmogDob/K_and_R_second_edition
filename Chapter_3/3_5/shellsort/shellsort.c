#include <stdio.h>

void shellsort(int v[], int t);

int main(int argc, char const *argv[])
{
    int n = 7;
    int v[] = {1,2,100,8,9,10,3};
    printf("v befor: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
    shellsort(v,n);
    printf("v after: ",v);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order*/
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /=2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j]> v[j+gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
