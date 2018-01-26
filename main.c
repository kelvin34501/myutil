#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "vector_template.h"
vector_(int,int)
vector_(double,double)
vector_(intarray,int *)

#include "library.h"

#include "list_template.h"
list_(int,int)
list_(intarray,int *)

#include "binarytree_template.h"
binarytree_(int,int)


#include "set_template.h"
#include "map_template.h"
#include "string_util.h"


typedef struct
{
        int x;
        int y;
        int z;
        double m;
} seta;

vector_(seta,seta)
list_(seta,seta)
binarytree_(seta,seta)

int cmp(int x, int y)
{
        if(x<y)
                return -1;
        else if(x==y)
                return 0;
        else
                return 1;
}

void intarray_cleanup(int ** parray)
{
        free(*parray);
        *parray = NULL;
}

int main()
{
/* stea test */
        seta a = {0,0,0,0.0};
        printf("%d,%d,%d,%lf\n", a.x, a.y , a.z , a.m);
        a.x = 1;
        a.m = 2.0;
        a.z = 2;
        printf("%d,%d,%d,%lf\n", a.x , a.y , a.z , a.m);
        printf("%d\n",a.z);

/* inmd test */
        vector_int inmd;
        vector_int_init(&inmd);
        for(int i=0;i<100;i++)
                vector_int_push(&inmd, i);

        for(int i=0;i<100;i++)
                printf("%d\t",vector_int_(&inmd,i));
        printf("\n");

        int * ip = vector_int_at(&inmd, 7);
        int * iip = vector_int_next(&inmd, ip);
        printf("\t%d\n", *iip);

        printf("\t%d\n", vector_int_pop(&inmd));
        for(int i=0;i<inmd.size;i++)
                printf("%d\t",vector_int_(&inmd,i));
        printf("\n");

        vector_int_remove(&inmd,84);
        for(int i=0;i<inmd.size;i++)
                printf("%d\t",vector_int_(&inmd,i));
        printf("\n");

        vector_int_remove_interval(&inmd,10,21);
        for(int i=0;i<inmd.size;i++)
                printf("%d\t",vector_int_(&inmd,i));
        printf("\n");

        vector_int_free(&inmd);

/* iset test */
        vector_seta iset;
        vector_seta_init(&iset);
        vector_seta_push(&iset, a);
        seta sp = vector_seta_(&iset, 0);
        seta * psp = &sp;
        vector_seta_free(&iset);

/* idbl test */
        vector_double idbl;
        vector_double_init(&idbl);
        vector_double_free(&idbl);

/* iv sort/locate test */
        vector_int iv;
        vector_int_init(&iv);
        for(int i=0;i<1000;i++)
                vector_int_push(&iv, i % 19);
        for(int i=0;i<iv.size;i++)
                printf("%d\t",vector_int_(&iv,i));
        printf("\n");

        vector_int_mergesort(&iv, cmp, 0, iv.size);
        for(int i=0;i<iv.size;i++)
                printf("%d\t",vector_int_(&iv,i));
        printf("\n");
        printf("index = %d\n",vector_int_search(&iv, cmp, 0));
        printf("index = %d\n",vector_int_search_interval(&iv, cmp, 0, iv.size-100, iv.size));
        printf("index = %d\n",vector_int_locate_interval(&iv, cmp, 0, 0, iv.size));
        printf("index = %d\n",vector_int_locate_interval(&iv, cmp, 0, iv.size - 200, iv.size));
        printf("index = %d\n",vector_int_locate_late_interval(&iv, cmp, 0, 0, iv.size));
        printf("index = %d\n",vector_int_locate_late_interval(&iv, cmp, 0, iv.size - 200, iv.size));

        vector_int_free(&iv);

/* iv remove test */
        vector_int_init(&iv);
        printf("iv.size=%d\n",iv.size);
        printf("iv.cap =%d\n",iv.cap);
        for(int i=0;i<1000;i++)
                vector_int_push(&iv, i % 23);
        printf("iv.size=%d\n",iv.size);
        printf("iv.cap =%d\n",iv.cap);
        vector_int_shrink(&iv);
        vector_int_remove_interval(&iv, 100, 950);
        printf("iv.size=%d\n",iv.size);
        printf("iv.cap =%d\n",iv.cap);
        vector_int_shrink(&iv);
        printf("iv.size=%d\n",iv.size);
        printf("iv.cap =%d\n",iv.cap);
        vector_int_free(&iv);

/* swap test */
       int k=8, kk = 10;
        printf("%d %d\n",k,kk);
        swap(k,kk);
        printf("%d %d\n",k,kk);

/* v1 sort preformance test */
        vector_int v1;
        vector_int_init(&v1);
        for(int i=0;i<1000000;i++)
                vector_int_push(&v1, rand());
        printf("start\n");
        vector_int_quicksort(&v1, cmp, 0, v1.size);
        //for(int i=0;i<v1.size;i++)
        //        printf("%d\t",vector_int_(&v1,i));
        //printf("\n");
        vector_int_free(&v1);

/* vnew locate test */
        vector_int vnew;
        vector_int_init(&vnew);
        for(int i=0;i<20;i++)
                vector_int_push(&vnew, i%5);
        vector_int_quicksort(&vnew, cmp, 0, vnew.size);
        for(int i=0;i<vnew.size;i++)
                printf("%d\t",vector_int_(&vnew,i));
        printf("\n");

        printf("index = %d\n",vector_int_locate(&vnew, cmp, 200));
        printf("index = %d\n",vector_int_locate_late(&vnew, cmp, 200));
        vector_int_insert(&vnew, vector_int_locate_late(&vnew, cmp, 10) + 1, 10);
        vector_int_insert(&vnew, vector_int_locate_late(&vnew, cmp, 1) + 1, 10);

        for(int i=0;i<vnew.size;i++)
                printf("%d\t",vector_int_(&vnew,i));
        printf("\n");

        vector_int_free(&vnew);

/* list tests */
        node_int * head;
        list_int_init(&head);
        printf("empty = %d\n", list_int_empty(head));
        for(int i=0; i<100; i++)
                list_int_push(head, i);
        for(node_int * iter = list_int_begin(head);
            iter != list_int_end(head);
            iter = list_int_next(iter))
                printf("%d\t",iter->key);
        printf("\n");
        printf("%d\n",list_int_pop(head));
        printf("%d\n",list_int_dequeue(head));
        for(node_int * iter = list_int_begin(head);
            iter != list_int_end(head);
            iter = list_int_next(iter))
                printf("%d\t",iter->key);
        printf("\n");
        list_int_push(head, 99);
        list_int_enqueue(head, 0);
        for(node_int * iter = list_int_begin(head);
            iter != list_int_end(head);
            iter = list_int_next(iter))
                printf("%d\t",iter->key);
        printf("\n");
        node_int * p1 = head->next;
        node_int * p2 = head->next->next->next;
        node_int_exchange(p1,p2);
        //node_int_swap(head, p2);

        for(node_int * iter = list_int_begin(head);
            iter != list_int_end(head);
            iter = list_int_next(iter))
                printf("%d\t",iter->key);
        printf("\n");

        list_int_free(&head);

        node_intarray * list2;
        list_intarray_init(&list2);
        list_intarray_free(&list2);

        vector_intarray vaa;
        vector_intarray_init(&vaa);
        for(int i=0;i<100;i++)
        {
                int * p = malloc(sizeof(int) * 20);
                memset(p, 0, sizeof(int) * 20);
                vector_intarray_push(&vaa, p);
        }
        printf("\t==%d==\n",vector_intarray_(&vaa, 8)[10]);
        vector_intarray_cleanup(&vaa, intarray_cleanup);

/* string util tests */
        vector_string buf;
        char stra[200] = " adfaskf jfkladsjfa fkjadsjf \t\t\tkdafjaskka;sj\\kfasdj\nfsadf\t ";
        string_split(stra,&buf);
        for(char ** iter = vector_string_begin(&buf);
            iter != vector_string_end(&buf);
            iter =  vector_string_next(&buf, iter)) //alt: iter++
        {
                printf("%s\n", *iter);
        }
        vector_string_cleanup(&buf, string_util_cleanup);

/* binary tests */
        binarytree_int tree;
        binarytree_int_init(&tree);
        binarytree_int_insert(&tree, cmp, 1);
        binarytree_int_insert(&tree, cmp, 2);

        return 0;
}
