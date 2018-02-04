#include <stdio.h>
#include <stdlib.h>

void merge(int data[], int lo, int mi, int hi)
{
        int lb = mi - lo;
        int lc = hi - mi;
        int * A = data + lo;
        int * B = malloc(sizeof(int) * lb);
        int * C = data + mi;

        int i, j, k;
        for(i=0; i<lb; i++)
        {
                B[i] = A[i];
        }
        for(i=0,j=0,k=0; (j<lb) || (k<lc); )
        {
                if( (j<lb) && ((k>=lc) || B[j] <= C[k]) )
                        A[i++] = B[j++];
                if( (k<lc) && ((j>=lb) || B[j] >  C[k]) )
                        A[i++] = C[k++];
        }
        free(B);
}

void mergesort(int data[], int lo, int hi)
{
        if (hi - lo < 2)
                return;
        int mi = lo + (hi - lo) / 2;
        mergesort(data, lo, mi);
        mergesort(data, mi, hi);
        merge(data, lo, mi, hi);
}

#define N 10000000

int main(void)
{
        int * a = malloc(sizeof(int) * N);
        for(int i=0;i<N;i++)
                a[i] = rand();
        mergesort(a, 0, N);
        //for(int i=0;i<N;i++)
        //        printf("%d ",a[i]);
        //printf("\n");
        free(a);
        return 0;
}
