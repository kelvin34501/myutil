#include <stdlib.h>

#define N 10000000

int cmp(const void * x, const void * y)
{
        return (*((int *)x) - *((int *)y));
}

int main(void)
{
        int * a = malloc(sizeof(int) * N);
        for(int i=0;i<N;i++)
                a[i] = rand();
        qsort(a, N, sizeof(int), cmp);
        free(a);
        return 0;

}
