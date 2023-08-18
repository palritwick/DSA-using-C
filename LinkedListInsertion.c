#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

struct Node * insertionAtBegening(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
}

struct Node * insertionAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head;
    int i = 0;
    while (i != index- 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertionAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;

    return head;
}

struct Node * insertionAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data =  data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 17;
    third->next = fourth;

    fourth->data = 73;
    fourth->next = NULL;

    printf("Linked list before insertion...\n");
    LinkedListTraversal(head);
//     head = insertionAtBegening(head,56);
//     head = insertionAtEnd(head,56);
//     head = insertionAtIndex(head,56,3);
    head = insertionAfterNode(head,second,56);

    printf("\nLinked list after insertion...\n");
    LinkedListTraversal(head);
    return 0;
}
