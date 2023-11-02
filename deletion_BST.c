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
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}
struct Node *delete(struct Node *root, int value)
{
    struct Node *iPre;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // search the value is to be deleted
    if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete(root->left, iPre->data);
    }
    return root;
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
    //    /   \
    //   3     7
    //  / \   / \ 
    // 2   4  6  9

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    inOrder(p);
    delete (p, 3);
    printf("\n");
    printf("|Element is %d|\n", p1->data);
    inOrder(p);
    return 0;
}