#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void LinkedListTraversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

int main()
{
    struct Node * head = (struct Node * )malloc(sizeof(struct Node));
    struct Node * second = (struct Node * )malloc(sizeof(struct Node));
    struct Node * third = (struct Node * )malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node * )malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 17;
    third->next = fourth;

    fourth->data = 73;
    fourth->next = NULL;

    LinkedListTraversal(head);
    return 0;
}
