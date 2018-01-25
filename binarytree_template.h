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
                binarytree_node_##TYPENAME * root)                      \
        {                                                               \
                                                                        \
        }                                                               \
                                                                        \

#endif
