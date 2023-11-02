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

void insert(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST.\n", key);
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct Node *new = createNode(key);
    if (key < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(4);
    struct Node *p5 = createNode(6);

    //      5
    //    /   \
    //   3     7
    //  / \   /
    // 2   4  6

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    insert(p, 9);
    printf("Value : %d\n", (p->right->right)->data);
    return 0;
}