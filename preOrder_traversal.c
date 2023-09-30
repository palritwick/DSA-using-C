#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node * createNode(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}
void preOrder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(3);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    //      5
    //    /   \
    //   1     6
    //  / \   /
    // 2   4 3    
    printf("PreOrder Traversal of the Binary Tree is :\n");
    preOrder(p);
    return 0;
}