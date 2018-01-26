#include <stdio.h>
#include <stdlib.h>

#include "../../vector_template.h"

vector_(int,int)

int cmp(int x, int y)
{
        if(x<y)
                return -1;
        else if(x==y)
                return 0;
        else
                return 1;
}

int main(void)
{
        vector_int v1;
        vector_int_init(&v1);
        for(int i=0; i<10000000; i++)
                vector_int_push(&v1, rand());
        vector_int_quicksort(&v1, cmp, 0, v1.size);
        vector_int_free(&v1);
}
