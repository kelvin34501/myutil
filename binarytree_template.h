#ifndef __MYUTIL_BINARYTREE_TEMPLATE_H__
#define __MYUTIL_BINARYTREE_TEMPLATE_H__

#include <stdlib.h>
#include <assert.h>

#include "list_template.h"

#define binarytree_(TYPENAME,ELEMTYPE)                                  \
        typedef struct _binarytree_node_##TYPENAME binarytree_node_##TYPENAME; \
        typedef binarytree_node_##TYPENAME * binarytree_##TYPENAME;     \
        struct _binarytree_node_##TYPENAME {                            \
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
                while( ptr != NULL )                                    \
                {                                                       \
                        if(cmp(e,ptr->key) < 0)                         \
                        {                                               \
                                prev = ptr;                             \
                                ptr = ptr->left;                        \
                        }                                               \
                        else if(cmp(e,ptr->key) > 0)                    \
                        {                                               \
                                                                        \
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
                        (*proot)->key = e;                              \
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
                                pnode->left->key    = e;                \
                                pnode->left->parent = pnode;            \
                                pnode->left->left   = NULL;             \
                                pnode->left->right  = NULL;             \
                        }                                               \
                        else if(cmp(e,pnode->key) > 0)                  \
                        {                                               \
                                assert(pnode->right==NULL);             \
                                pnode->right = malloc(sizeof(*pnode));  \
                                pnode->right->key    = e;               \
                                pnode->right->parent = pnode;           \
                                pnode->right->left   = NULL;            \
                                pnode->right->right  = NULL;            \
                        }                                               \
                }                                                       \
        }                                                               \
                                                                        \
        /* Inorder traversal */                                         \
        static binarytree_node_##TYPENAME *                             \
        binarytree_##TYPENAME##_begin(binarytree_node_##TYPENAME * root) \
        {                                                               \
                if(root == NULL)                                        \
                        return NULL;                                    \
                else                                                    \
                {                                                       \
                        binarytree_node_##TYPENAME * ptr = root;        \
                        while(ptr->left != NULL)                        \
                                ptr = ptr->left;                        \
                        return ptr;                                     \
                }                                                       \
        }                                                               \
                                                                        \
        static binarytree_node_##TYPENAME *                             \
        binarytree_##TYPENAME##_end(binarytree_node_##TYPENAME * root)  \
        {                                                               \
                if(root == NULL)                                        \
                        return NULL;                                    \
                else                                                    \
                {                                                       \
                        binarytree_node_##TYPENAME * ptr = root;        \
                        while(ptr->right != NULL)                       \
                                ptr = ptr->left;                        \
                        return ptr;                                     \
                }                                                       \
        }                                                               \
                                                                        \
        static binarytree_node_##TYPENAME *                             \
        binarytree_##TYPENAME##_pred(binarytree_node_##TYPENAME * root, \
                                     binarytree_node_##TYPENAME * posi) \
        {                                                               \
                                                                        \
        }                                                               \
                                                                        \
        static binarytree_node_##TYPENAME *                             \
        binarytree_##TYPENAME##_succ(binarytree_node_##TYPENAME * root, \
                                     binarytree_node_##TYPENAME * posi) \
        {                                                               \
                                                                        \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_delete(                     \
                binarytree_node_##TYPENAME ** proot,                    \
                int (* cmp)(ELEMTYPE,ELEMTYPE), ELEMTYPE e)             \
        {                                                               \
                binarytree_node_##TYPENAME * pnode =                    \
                        binarytree_##TYPENAME##_locate((*proot),cmp,e); \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_free(                       \
                binarytree_node_##TYPENAME ** proot)                    \
        {                                                               \
                if(*proot == NULL)                                      \
                        return;                                         \
                binarytree_##TYPENAME##_free( &((*proot)->left ));      \
                binarytree_##TYPENAME##_free( &((*proot)->right));      \
                free(*proot);                                           \
                *proot = NULL;                                          \
        }                                                               \
                                                                        \
        /* If the returned value of the traversal function can be       \
         * just thrown away, then use these functions.                  \
         */                                                             \
                                                                        \
        list_(_p_binarytree_node_##TYPENAME,                            \
              binarytree_node_##TYPENAME *)                             \
        static void binarytree_##TYPENAME##_traverse_preorder(          \
                binarytree_node_##TYPENAME * root,                      \
                void (* func)(ELEMTYPE *))                              \
        {                                                               \
                if(root == NULL)                                        \
                        return;                                         \
                func(&(root->key));                                     \
                binarytree_##TYPENAME##_traverse_preorder(root->left, func); \
                binarytree_##TYPENAME##_traverse_preorder(root->right,func); \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_traverse_inorder(           \
                binarytree_node_##TYPENAME * root,                      \
                void (* func)(ELEMTYPE *))                              \
        {                                                               \
                if(root == NULL)                                        \
                        return;                                         \
                binarytree_##TYPENAME##_traverse_inorder(root->left, func); \
                func(&(root->key));                                     \
                binarytree_##TYPENAME##_traverse_inorder(root->right,func); \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_traverse_postorder(         \
                binarytree_node_##TYPENAME * root,                      \
                void (* func)(ELEMTYPE *))                              \
        {                                                               \
                if(root == NULL)                                        \
                        return;                                         \
                binarytree_##TYPENAME##_traverse_postorder(root->left, func); \
                binarytree_##TYPENAME##_traverse_postorder(root->right,func); \
                func(&(root->key));                                     \
        }                                                               \
                                                                        \
        static void binarytree_##TYPENAME##_traverse_hierarchy(         \
                binarytree_node_##TYPENAME * root,                      \
                void (* func)(ELEMTYPE *))                              \
        {                                                               \
                if(root==NULL)                                          \
                        return;                                         \
                list__p_binarytree_node_##TYPENAME queue;               \
                list__p_binarytree_node_##TYPENAME##_init(&queue);      \
                list__p_binarytree_node_##TYPENAME##_insert(queue, root); \
                binarytree_node_##TYPENAME * tmp;                       \
                while(!list__p_binarytree_node_##TYPENAME##_empty(queue)) \
                {                                                       \
                        tmp = list__p_binarytree_node_##TYPENAME##_pop(queue); \
                        func(&(tmp->key));                              \
                        if(tmp->left  != NULL)                          \
                                list__p_binarytree_node_##TYPENAME##_insert(queue,tmp->left ); \
                        if(tmp->right != NULL)                          \
                                list__p_binarytree_node_##TYPENAME##_insert(queue,tmp->right); \
                }                                                       \
                list__p_binarytree_node_##TYPENAME##_free(&queue);      \
        }                                                               \
                                                                        \
        /* Following are iterator-style traversal functions. */         \
        typedef struct {                                                \
                list__p_binarytree_node_##TYPENAME stack;               \
                binarytree_node_##TYPENAME * posi;                      \
        } binarytree_iterator_##TYPENAME;                               \
                                                                        \
                                                                        \
        /* Debug functions */                                           \



#endif
