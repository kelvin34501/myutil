#include <stdio.h>
#include <stdlib.h>

void quicksort(int data[], int lo, int hi)
{
        if (hi - lo < 2)
                return;
        int r = (rand() % (hi - lo)) + lo;
        int temp = data[r];
        data[r] = data[hi-1];
        data[hi - 1] = temp;

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

#define N 10000000

int main(void)
{
        int * a = malloc(sizeof(int) * N);
        for(int i=0;i<N;i++)
                a[i] = rand();
        quicksort(a, 0, N);
        free(a);
        return 0;
}
