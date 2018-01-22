#include <stdio.h>
#include <stdlib.h>

void quicksort(int data[], int lo, int hi)
{
        if (hi - lo < 2)
                return;
        int i, j=lo;
        for(i=lo; i<hi; i++)
        {
                if(data[i] <= data[hi-1])
                {
                        int tmp = data[i];
                        data[i] = data[j];
                        data[j] = tmp;
                        j++;
                }
        }
        quicksort(data, lo, j-1);
        quicksort(data, j , hi );
}

#define N 1000000

int main(void)
{
        int a[N];
        for(int i=0;i<N;i++)
                a[i] = rand();
        quicksort(a, 0, N);
        for(int i=0;i<N;i++)
                printf("%d\t",a[i]);
        return 0;
}
