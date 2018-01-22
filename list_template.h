#ifndef __MYUTIL_LIST_TEMPLATE_H__
#define __MYUTIL_LIST_TEMPLATE_H__

#include <stdlib.h>
#include <assert.h>

#define list_(TYPENAME,ELEMTYPE)                                        \
        typedef struct _node_##TYPENAME node_##TYPENAME;                \
        struct _node_##TYPENAME {                                       \
                ELEMTYPE key;                                           \
                node_##TYPENAME * prev;                                 \
                node_##TYPENAME * next;                                 \
        };                                                              \
                                                                        \
        static void list_##TYPENAME##_init(node_##TYPENAME ** pphead)   \
        {                                                               \
                (*pphead) = malloc(sizeof(node_##TYPENAME));            \
                /*Field: key is uninitialized.*/                        \
                (*pphead)->prev = (*pphead)->next = (*pphead);          \
        }                                                               \
                                                                        \
        static int list_##TYPENAME##_empty(node_##TYPENAME * pnode)     \
        {                                                               \
                return (pnode->next == pnode);                          \
        }                                                               \
                                                                        \
        static void node_##TYPENAME##_insert_after(                     \
                node_##TYPENAME * posi, ELEMTYPE e)                     \
        {                                                               \
                node_##TYPENAME * node =                                \
                        malloc(sizeof(node_##TYPENAME));                \
                node->key = e;                                          \
                node->prev = posi;                                      \
                node->next = posi->next;                                \
                node->next->prev = node;                                \
                node->prev->next = node;                                \
        }                                                               \
                                                                        \
        static void node_##TYPENAME##_insert_before(                    \
                node_##TYPENAME * posi, ELEMTYPE e)                     \
        {                                                               \
                node_##TYPENAME * node =                                \
                        malloc(sizeof(node_##TYPENAME));                \
                node->key = e;                                          \
                node->next = posi;                                      \
                node->prev = posi->prev;                                \
                node->prev->next = node;                                \
                node->next->prev = node;                                \
        }                                                               \
                                                                        \
        /* The pointer is not set to NULL. Watch out. */                \
        static void node_##TYPENAME##_delete(node_##TYPENAME * posi)    \
        {                                                               \
                posi->prev->next = posi->next;                          \
                posi->next->prev = posi->prev;                          \
                free(posi);                                             \
        }                                                               \
                                                                        \
        /* Add to the tail */                                           \
        static void list_##TYPENAME##_push(                             \
                node_##TYPENAME * phead, ELEMTYPE e)                    \
        {                                                               \
                node_##TYPENAME##_insert_before(phead,e);               \
        }                                                               \
                                                                        \
        /* Delete the tail */                                           \
        static ELEMTYPE list_##TYPENAME##_pop(node_##TYPENAME * phead)  \
        {                                                               \
                ELEMTYPE tmp = phead->prev->key;                        \
                node_##TYPENAME##_delete(phead->prev);                  \
                return tmp;                                             \
        }                                                               \
                                                                        \
        /* Add to the head */                                           \
        static void list_##TYPENAME##_insert(                           \
                node_##TYPENAME * phead, ELEMTYPE e)                    \
        {                                                               \
                node_##TYPENAME##_insert_after(phead,e);                \
        }                                                               \
                                                                        \
        /* Delete the head */                                           \
        static ELEMTYPE list_##TYPENAME##_drop(node_##TYPENAME * phead) \
        {                                                               \
                ELEMTYPE tmp = phead->next->key;                        \
                node_##TYPENAME##_delete(phead->next);                  \
                return tmp;                                             \
        }                                                               \
                                                                        \
        static void list_##TYPENAME##_free(node_##TYPENAME ** pphead)   \
        {                                                               \
                node_##TYPENAME * iter, * ihdl;                         \
                for(iter = (*pphead)->next; iter != (*pphead); )        \
                {                                                       \
                        ihdl = iter;                                    \
                        iter = iter->next;                              \
                        free(ihdl);                                     \
                }                                                       \
                free(*pphead);                                          \
                *pphead = NULL;                                         \
        }                                                               \
                                                                        \
        static void node_##TYPENAME##_swap(                             \
                node_##TYPENAME * posi1, node_##TYPENAME * posi2)       \
        {                                                               \
                /* posi1 is posi2 ---> do nothing */                    \
                if(posi1 == posi2)                                      \
                        return;                                         \
                /* posi1 is pred of posi2 */                            \
                else if(posi1->next == posi2)                           \
                {                                                       \
                        node_##TYPENAME * posi0 = posi1->prev;          \
                        node_##TYPENAME * posi3 = posi2->next;          \
                        posi0->next = posi2;                            \
                        posi2->prev = posi0;                            \
                        posi2->next = posi1;                            \
                        posi1->prev = posi2;                            \
                        posi1->next = posi3;                            \
                        posi3->prev = posi1;                            \
                }                                                       \
                /* posi1 is succ of posi2 */                            \
                else if(posi1->prev == posi2)                           \
                {                                                       \
                        node_##TYPENAME * posi0 = posi2->prev;          \
                        node_##TYPENAME * posi3 = posi1->next;          \
                        posi0->next = posi1;                            \
                        posi1->prev = posi0;                            \
                        posi1->next = posi2;                            \
                        posi2->prev = posi1;                            \
                        posi2->next = posi3;                            \
                        posi3->prev = posi2;                            \
                }                                                       \
                /* general case */                                      \
                else                                                    \
                {                                                       \
                        node_##TYPENAME * posia = posi1->prev;          \
                        node_##TYPENAME * posib = posi1->next;          \
                        node_##TYPENAME * posic = posi2->prev;          \
                        node_##TYPENAME * posid = posi2->next;          \
                        posia->next = posi2;                            \
                        posi2->prev = posia;                            \
                        posi2->next = posib;                            \
                        posib->prev = posi2;                            \
                        posic->next = posi1;                            \
                        posi1->prev = posic;                            \
                        posi1->next = posid;                            \
                        posid->prev = posi1;                            \
                }                                                       \
        }                                                               \
                                                                        \
        static void node_##TYPENAME##_exchange(                         \
                node_##TYPENAME * posi1, node_##TYPENAME * posi2)       \
        {                                                               \
                ELEMTYPE tmp = posi1->key;                              \
                posi1->key   = posi2->key;                              \
                posi2->key   = tmp;                                     \
        }                                                               \
                                                                        \
        /* Note that if the index overflows                             \
         * Something bad happens.                                       \
         * Key of the guard may be returned.                            \
         * Use at your own risk. */                                     \
        static ELEMTYPE list_##TYPENAME##_(                             \
                node_##TYPENAME * phead, int i)                         \
        {                                                               \
                node_##TYPENAME * p = phead->next;                      \
                for(int c=0; c<i; c++)                                  \
                        p = p->next;                                    \
                return p->key;                                          \
        }                                                               \
                                                                        \
        static node_##TYPENAME * list_##TYPENAME##_at(                  \
                node_##TYPENAME * phead, int i)                         \
        {                                                               \
                node_##TYPENAME * p = phead->next;                      \
                for(int c=0; c<i; c++)                                  \
                        p = p->next;                                    \
                return p;                                               \
        }                                                               \
                                                                        \
        static node_##TYPENAME * list_##TYPENAME##_begin(               \
                node_##TYPENAME * phead)                                \
        {                                                               \
                return phead->next;                                     \
        }                                                               \
                                                                        \
        static node_##TYPENAME * list_##TYPENAME##_end(                 \
                node_##TYPENAME * phead)                                \
        {                                                               \
                return phead;                                           \
        }                                                               \
                                                                        \
        static node_##TYPENAME * list_##TYPENAME##_prev(                \
                node_##TYPENAME * posi)                                 \
        {                                                               \
                return posi->prev;                                      \
        }                                                               \
                                                                        \
        static node_##TYPENAME * list_##TYPENAME##_next(                \
                node_##TYPENAME * posi)                                 \
        {                                                               \
                return posi->next;                                      \
        }                                                               \
                                                                        \
        static node_##TYPENAME * list_##TYPENAME##_locate(              \
                node_##TYPENAME * phead, ELEMTYPE e)                    \
        {                                                               \
                node_##TYPENAME * iter;                                 \
                for(iter=phead->next; iter!=phead; iter=iter->next)     \
                        if(iter->key == e)                              \
                                return iter;                            \
                return NULL;                                            \
        }


#endif
