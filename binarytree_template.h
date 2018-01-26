#ifndef __MYUTIL_BINARYTREE_TEMPLATE_H__
#define __MYUTIL_BINARYTREE_TEMPLATE_H__

#include <stdlib.h>
#include <assert.h>

#define binarytree_(TYPENAME,ELEMTYPE)                                  \
        typedef struct _bint_node_##TYPENAME binarytree_node_##TYPENAME; \
        typedef binarytree_node_##TYPENAME * binarytree_##TYPENAME;     \
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
                (*proot) = NULL;                                        \
        }                                                               \
                                                                        \
        static binarytree_node_##TYPENAME *                             \
        binarytree_##TYPENAME##_locate(                                 \
                binarytree_node_##TYPENAME * root,                      \
                int (* cmp)(ELEMTYPE,ELEMTYPE), ELEMTYPE e)             \
        {                                                               \
                binarytree_node_##ELEMTYPE *ptr  = root;                \
                binarytree_node_##ELEMTYPE *prev = NULL;                \
                while( ptr != NULL ) {                                  \
                        if(cmp(e,ptr->key) < 0)                         \
                        {                                               \
                                prev = ptr;                             \
                                ptr = ptr->left;                        \
                        }                                               \
                        else if(cmp(e,ptr->key) > 0)                    \
                        {                                               \
                                prev = ptr;                             \
                                ptr = ptr->right;                       \
                        }                                               \
                        else                                            \
                        {                                               \
                                prev = ptr;                             \
                                break;                                  \
                        }                                               \
                }                                                       \
                return prev;                                            \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_insert(                     \
                binarytree_node_##TYPENAME ** proot,                    \
                int (* cmp)(ELEMTYPE,ELEMTYPE), ELEMTYPE e)             \
        {                                                               \
                if((*proot) == NULL)                                    \
                {                                                       \
                        (*proot) =                                      \
                                malloc(sizeof(**proot));                \
                        (*proot)->parent = NULL;                        \
                        (*proot)->left   = NULL;                        \
                        (*proot)->right  = NULL;                        \
                }                                                       \
                else                                                    \
                {                                                       \
                        binarytree_node_##TYPENAME * pnode =            \
                                binarytree_##TYPENAME##_locate((*proot),cmp,e); \
                        assert(pnode != NULL);                          \
                        if(cmp(e,pnode->key) < 0)                       \
                        {                                               \
                                assert(pnode->left == NULL);            \
                                pnode->left = malloc(sizeof(*pnode));		\
                                pnode->left->key  = e;                  \
                                pnode->left->left  = NULL;              \
                                pnode->left->right = NULL;              \
                        }                                               \
                        else if(cmp(e,pnode->key) > 0)                  \
                        {                                               \
                                assert(pnode->right==NULL);             \
                                pnode->right = malloc(sizeof(*pnode));  \
                                pnode->right->key  = e;                 \
                                pnode->right->left  = NULL;             \
                                pnode->right->right = NULL;             \
                        }                                               \
                }                                                       \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_delete(                     \
                binarytree_node_##TYPENAME ** proot, ELEMTYPE e)        \
        {                                                               \
                                                                        \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_free(                       \
                binarytree_node_##TYPENAME ** proot)                    \
        {                                                               \
                                                                        \
        }


#endif
