#ifndef __MYUTIL_VECTOR_TEMPLATE_H__
#define __MYUTIL_VECTOR_TEMPLATE_H__

#include <stdlib.h>
#include <assert.h>

#include "library.h"

#define __MYUTIL_VECTOR_DEFAULT_CAP 8

#define vector_(TYPENAME,ELEMTYPE)                                      \
        typedef struct {                                                \
                int size;                                               \
                int cap;                                                \
                ELEMTYPE * data;                                        \
        } vector_##TYPENAME;                                            \
                                                                        \
        static void vector_##TYPENAME##_init(vector_##TYPENAME * vec)   \
        {                                                               \
                vec->size = 0;                                          \
                vec->cap  = __MYUTIL_VECTOR_DEFAULT_CAP;                \
                vec->data = malloc(sizeof(ELEMTYPE) * 8);               \
        }                                                               \
                                                                        \
        static void vector_##TYPENAME##_free(vector_##TYPENAME * vec)   \
        {                                                               \
                vec->size = 0;                                          \
                vec->cap  = 0;                                          \
                free(vec->data);                                        \
                vec->data = NULL;                                       \
        }                                                               \
                                                                        \
        static ELEMTYPE vector_##TYPENAME##_(                           \
                vector_##TYPENAME * vec, int i)                         \
        {                                                               \
                assert(vec->size > i);                                  \
                return vec->data[i];                                    \
        }                                                               \
                                                                        \
        static ELEMTYPE * vector_##TYPENAME##_at(                       \
                vector_##TYPENAME * vec, int i)                         \
        {                                                               \
                assert(vec->size > i);                                  \
                return vec->data + i;                                   \
        }                                                               \
                                                                        \
        static ELEMTYPE * vector_##TYPENAME##_begin(                    \
                vector_##TYPENAME * vec)                                \
        {                                                               \
                return vec->data;                                       \
        }                                                               \
                                                                        \
        static ELEMTYPE * vector_##TYPENAME##_end(                      \
                vector_##TYPENAME * vec)                                \
        {                                                               \
                return vec->data + vec->size;                           \
        }                                                               \
                                                                        \
        static ELEMTYPE * vector_##TYPENAME##_next(                     \
                vector_##TYPENAME * vec, ELEMTYPE * posi)               \
        {                                                               \
                return posi + 1;                                        \
        }                                                               \
                                                                        \
        static void vector_##TYPENAME##_push(                           \
                vector_##TYPENAME * vec, ELEMTYPE e)                    \
        {                                                               \
                if (vec->size == vec->cap) {                            \
                        vec->cap *= 2;                                  \
                        vec->data = realloc(vec->data,                  \
                                            sizeof(ELEMTYPE)*vec->cap); \
                }                                                       \
                vec->data[vec->size++] = e;                             \
        }                                                               \
                                                                        \
        static void vector_##TYPENAME##_insert(                         \
                vector_##TYPENAME * vec, int i, ELEMTYPE e)             \
        {                                                               \
                assert(0 <= i && i <= vec->size);                       \
                if (vec->size == vec->cap)                              \
                {                                                       \
                        vec->cap *= 2;                                  \
                        vec->data = realloc(vec->data,                  \
                                            sizeof(ELEMTYPE)*vec->cap); \
                }                                                       \
                for(int iter = vec->size; iter > i; iter--)             \
                {                                                       \
                        vec->data[iter] = vec->data[iter - 1];          \
                }                                                       \
                vec->size++;                                            \
                vec->data[i] = e;                                       \
                return;                                                 \
        }                                                               \
                                                                        \
        static ELEMTYPE vector_##TYPENAME##_pop(                        \
                vector_##TYPENAME * vec)                                \
        {                                                               \
                assert(vec->size > 0);                                  \
                int tmp = vec->size - 1;                                \
                vec->size--;                                            \
                return vec->data[tmp];                                  \
        }                                                               \
                                                                        \
        static ELEMTYPE vector_##TYPENAME##_remove(                     \
                vector_##TYPENAME * vec, int i)                         \
        {                                                               \
                assert(0 <= i && i <= vec->size);                       \
                ELEMTYPE tmp = vec->data[i];                            \
                for(int iter = i; iter < vec->size - 1; iter++)         \
                {                                                       \
                        vec->data[iter] = vec->data[iter + 1];          \
                }                                                       \
                vec->size--;                                            \
                return tmp;                                             \
        }                                                               \
                                                                        \
        static int vector_##TYPENAME##_remove_interval(                 \
                vector_##TYPENAME * vec, int lo, int hi)                \
        {                                                               \
                assert(0 <= lo && lo <= vec->size);                     \
                assert(0 <= hi && hi <= vec->size);                     \
                int i,j;                                                \
                for(i = hi, j = lo; i < vec->size; i++, j++)            \
                {                                                       \
                        vec->data[j] = vec->data[i];                    \
                }                                                       \
                vec->size = j;                                          \
                return 0;                                               \
        }                                                               \
                                                                        \
        static void vector_##TYPENAME##_shrink(vector_##TYPENAME * vec) \
        {                                                               \
                int i;                                                  \
                for(i=vec->cap; i/2 > vec->size; i/=2);                 \
                if(i < vec->cap && i > __MYUTIL_VECTOR_DEFAULT_CAP)     \
                {                                                       \
                        vec->cap = i;                                   \
                        vec->data = realloc(vec->data,                  \
                                            sizeof(ELEMTYPE)*vec->cap); \
                }                                                       \
        }                                                               \
                                                                        \
        /* If you want to release some resources for every object       \
         * in the vector when vector is freed,                          \
         * Pass your cleanup into this function.                        \
         */                                                             \
        static void vector_##TYPENAME##_cleanup(                        \
                vector_##TYPENAME * vec, void (*cleanup)(ELEMTYPE *))   \
        {                                                               \
                for(int i=0; i<vec->size; i++)                          \
                        cleanup(vec->data + i);                         \
                vec->size = 0;                                          \
                vec->cap  = 0;                                          \
                free(vec->data);                                        \
                vec->data = NULL;                                       \
        }                                                               \
                                                                        \
        /* Sort Functions */                                            \
        static void vector_##TYPENAME##_merge(                          \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                int lo, int mi, int hi)                                 \
        {                                                               \
                int lb = mi - lo;                                       \
                int lc = hi - mi;                                       \
                ELEMTYPE * A = vec->data + lo;                          \
                ELEMTYPE * B = malloc(sizeof(ELEMTYPE) * lb);           \
                ELEMTYPE * C = vec->data + mi;                          \
                                                                        \
                int i, j, k;                                            \
                for(i=0; i<lb; i++)                                     \
                {                                                       \
                        B[i] = A[i];                                    \
                }                                                       \
                for(i=0,j=0,k=0; (j<lb) || (k<lc); )                    \
                {                                                       \
                        if( (j<lb) &&                                   \
                            ((k>=lc) || cmp(B[j],C[k]) <= 0) )          \
                                A[i++] = B[j++];                        \
                        if( (k<lc) &&                                   \
                            ((j>=lb) || cmp(B[j],C[k]) > 0 ) )          \
                                A[i++] = C[k++];                        \
                }                                                       \
                free(B);                                                \
        }                                                               \
                                                                        \
        static void vector_##TYPENAME##_mergesort(                      \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                int lo, int hi)                                         \
        {                                                               \
                if (hi - lo < 2)                                        \
                        return;                                         \
                int mi = lo + (hi - lo) / 2;                            \
                vector_##TYPENAME##_mergesort(vec, cmp, lo, mi);        \
                vector_##TYPENAME##_mergesort(vec, cmp, mi, hi);        \
                vector_##TYPENAME##_merge(vec, cmp, lo, mi, hi);        \
        }                                                               \
                                                                        \
        static void vector_##TYPENAME##_quicksort(                      \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                int lo, int hi)                                         \
        {                                                               \
                if (hi - lo < 2)                                        \
                        return;                                         \
                int r = (rand() % (hi - lo)) + lo;                      \
                swap(vec->data[r],vec->data[hi-1]);                     \
                int i, j=lo;                                            \
                for(i=lo; i<hi; i++)                                    \
                {                                                       \
                        if(cmp(vec->data[i],vec->data[hi-1]) <= 0)      \
                        {                                               \
                                swap(vec->data[i],vec->data[j++]);      \
                        }                                               \
                }                                                       \
                vector_##TYPENAME##_quicksort(vec, cmp, lo, j-1);       \
                vector_##TYPENAME##_quicksort(vec, cmp, j , hi );       \
        }                                                               \
                                                                        \
        static int vector_##TYPENAME##_find(                            \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e)                                             \
        {                                                               \
                int i;                                                  \
                for(i = 0; i < vec->size; i++)                          \
                        if(cmp(vec->data[i],e))                         \
                                return i;                               \
                return -1;                                              \
        }                                                               \
                                                                        \
        static int vector_##TYPENAME##_find_interval(                   \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e, int lo, int hi)                             \
        {                                                               \
                assert(0 <= lo && lo <= vec->size);                     \
                assert(0 <= hi && hi <= vec->size);                     \
                int i;                                                  \
                for(i = lo; i < hi; i++)                                \
                        if(cmp(vec->data[i], e) == 0)                   \
                                return i;                               \
                return -1;                                              \
        }                                                               \
                                                                        \
        /* These 6 functions should only be used on sorted vectors. */  \
        static int vector_##TYPENAME##_search(                          \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e)                                             \
        {                                                               \
                int lo = 0, hi = vec->size;                             \
                int mi = lo + (hi - lo)/2;                              \
                int fg = 0;                                             \
                while(hi - lo > 0)                                      \
                {                                                       \
                        mi = lo + (hi - lo)/2;                          \
                        fg = cmp(vec->data[mi],e);                      \
                        if(fg == 0)                                     \
                                return mi;                              \
                        else if(fg < 0)                                 \
                                lo = mi + 1;                            \
                        else                                            \
                                hi = mi;                                \
                }                                                       \
                return -1;                                              \
                                                                        \
        }                                                               \
                                                                        \
        static int vector_##TYPENAME##_search_interval(                 \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e, int lo, int hi)                             \
        {                                                               \
                int mi = lo + (hi - lo)/2;                              \
                int fg = 0;                                             \
                while(hi - lo > 0)                                      \
                {                                                       \
                        mi = lo + (hi - lo)/2;                          \
                        fg = cmp(vec->data[mi],e);                      \
                        if(fg == 0)                                     \
                                return mi;                              \
                        else if(fg < 0)                                 \
                                lo = mi + 1;                            \
                        else                                            \
                                hi = mi;                                \
                }                                                       \
                return -1;                                              \
        }                                                               \
                                                                        \
        /* _locate returns the first if element repeats*/               \
        static int vector_##TYPENAME##_locate(                          \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e)                                             \
        {                                                               \
                int lo = 0, hi = vec->size;                             \
                int mi = lo + (hi - lo)/2;                              \
                int fg = 0;                                             \
                while(hi - lo > 0)                                      \
                {                                                       \
                        mi = lo + (hi - lo)/2;                          \
                        fg = cmp(vec->data[mi],e);                      \
                        if(fg < 0)                                      \
                                lo = mi + 1;                            \
                        else                                            \
                                hi = mi;                                \
                }                                                       \
                return mi;                                              \
        }                                                               \
                                                                        \
        static int vector_##TYPENAME##_locate_interval(                 \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e, int lo, int hi)                             \
        {                                                               \
                int mi = lo + (hi - lo)/2;                              \
                int fg = 0;                                             \
                while(hi - lo > 0)                                      \
                {                                                       \
                        mi = lo + (hi - lo)/2;                          \
                        fg = cmp(vec->data[mi],e);                      \
                        if(fg < 0)                                      \
                                lo = mi + 1;                            \
                        else                                            \
                                hi = mi;                                \
                }                                                       \
                return mi;                                              \
        }                                                               \
                                                                        \
        /* _locate_late returns last if element repeats */              \
        static int vector_##TYPENAME##_locate_late(                     \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e)                                             \
        {                                                               \
                int lo = 0, hi = vec->size;                             \
                int mi = lo + (hi - lo)/2;                              \
                int fg = 0;                                             \
                while(hi - lo > 0)                                      \
                {                                                       \
                        mi = lo + (hi - lo)/2;                          \
                        fg = cmp(vec->data[mi],e);                      \
                        if(fg > 0)                                      \
                                hi = mi;                                \
                        else                                            \
                                lo = mi + 1;                            \
                }                                                       \
                return mi;                                              \
        }                                                               \
                                                                        \
        static int vector_##TYPENAME##_locate_late_interval(            \
                vector_##TYPENAME * vec, int (*cmp)(ELEMTYPE,ELEMTYPE), \
                ELEMTYPE e, int lo, int hi)                             \
        {                                                               \
                int mi = lo + (hi - lo)/2;                              \
                int fg = 0;                                             \
                while(hi - lo > 0)                                      \
                {                                                       \
                        mi = lo + (hi - lo)/2;                          \
                        fg = cmp(vec->data[mi],e);                      \
                        if(fg > 0)                                      \
                                hi = mi;                                \
                        else                                            \
                                lo = mi + 1;                            \
                }                                                       \
                return mi;                                              \
        }



#endif
