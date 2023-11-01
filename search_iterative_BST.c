#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

struct Node *search_iterative(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(4);
    struct Node *p5 = createNode(6);
    struct Node *p6 = createNode(9);

     //      5
     //    /  \
          3    7
     //  / \  / \
        2   4 6  9

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    struct Node *n = search_iterative(p, 9);
    if (n != NULL)
        printf("Found %d\n", n->data);
    else
        printf("Element not found\n");

    return 0;
}