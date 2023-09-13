#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}
struct node *push(struct node *top, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (isFull(top))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

int pop(struct node * *top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        struct node *n = *top;
        int x = n->data;
        *top = (*top)->next;
        free(n);
        return x;
    }
}

int peek(struct node *top, int pos)
{
    struct node *ptr = top;
    int i;
    for ( i = 0; (i <pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    return -1;
}

int main()
{
    struct node *top = NULL;
    // printf("%d\n",isEmpty(top));
    // printf("%d\n",isFull(top));1
    LinkedListTraversal(top);
    top = push(top, 56);
    top = push(top, 89);
    top = push(top, 15);
    top = push(top, 23);

    // printf("Before performing stack operation...\n");
    // LinkedListTraversal(top);

    // int element = pop(&top);
    // printf("Poped element is %d\n", element);
    // printf("After performing stack operation...\n");
     LinkedListTraversal(top);
    int i;
    for ( i = 1; i <= 4; i++)
    {
        printf("Element of %d postion is %d\n", i, peek(top, i));
    }

    return 0;
}
