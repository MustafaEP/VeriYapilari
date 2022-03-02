#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    void* dataPtr;
    struct node* left;
    struct node* right;
} NODE;

typedef struct
{
    int count;
    int (*compare)(void* argu1, void* argu2);
    NODE* root;
} BST_TREE;

BST_TREE* BST_Create(int (*compare) (void* argu1, void* argu2))
{
    BST_TREE* tree;

    tree = (BST_TREE*) malloc (sizeof(BST_TREE));
    if(tree)
    {
        tree->root = NULL;
        tree->count = 0;
        tree->compare = compare;
    }
    return tree;
}

bool BST_Insert(BST_TREE* tree, void* dataPtr)
{
    NODE* newPtr;

    newPtr = (NODE*)malloc(sizeof(NODE));
    if(!newPtr)
        return false;

    newPtr->right = NULL;
    newPtr->left = NULL;
    newPtr->dataPtr = dataPtr;

    if(tree->count == 0)
    {
        tree->root = newPtr;
    }
    else
        _insert(tree, tree->root, newPtr);

    (tree->count)++;
    return tree;
}

NODE* _insert(BST_TREE* tree, NODE* root, NODE* newPtr)
{
    if(!root)
        return newPtr;

    if(tree->compare(newPtr->dataPtr, root->dataPtr) < 0)
    {
        root->left = _insert(tree, root->left, newPtr);
        return root;
    }
    else
    {
        root->right = _insert(tree, root->left, newPtr);
        return root
    }
    return root;
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
