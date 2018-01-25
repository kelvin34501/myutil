#ifndef __MYUTIL_BINARYTREE_TEMPLATE_H__
#define __MYUTIL_BINARYTREE_TEMPLATE_H__

#include <stdlib.h>
#include <assert.h>

#define binarytree_(TYPENAME,ELEMTYPE)                                  \
        typedef struct _bint_node_##TYPENAME binarytree_node_##TYPENAME; \
        struct _bint_node_##TYPENAME {                                  \
                ELEMTYPE key;                                           \
                binarytree_node_##TYPENAME * parent;                    \
                binarytree_node_##TYPENAME * left;                      \
                binarytree_node_##TYPENAME * right;                     \
        };                                                              \
                                                                        \
        static void binarytree_##TYPENAME##_init(                       \
                binarytree_node_##TYPENAME ** proot)                    \
        {                                                               \
                (*proot) = malloc(sizeof(binarytree_node_##TYPENAME));  \
                (*proot)->parent = NULL;                                \
                (*proot)->left = NULL;                                  \
                (*proot)->right = NULL;                                 \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_insert(                     \
                binarytree_node_##TYPENAME * root,                      \
                ELEMTYPE e)                                             \
        {                                                               \
                                                                        \
        }                                                               \
                                                                        \
        static binarytree_node_##TYPENAME *                             \
        binarytree_##TYPENAME##_search(                                 \
                binarytree_node_##TYPENAME * root,                      \
                int (* cmp)(ELEMTYPE,ELEMTYPE), ELEMTYPE e)             \
        {                                                               \
                                                                        \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_delete(                     \
                binarytree_node_##TYPENAME ** proot,                    \
                binarytree_node_##TYPENAME * posi)                      \
        {                                                               \
                                                                        \
        }


#endif
