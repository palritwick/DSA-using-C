#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("NULL\n");
}

struct node *InsertAtBegining(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

struct node *InsertInBetween(struct node *head, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
	p->next = ptr;
	
    return head;    
}

struct node *InsertAtEnd(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;

    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    second->data = 4;
    second->next = third;
    third->data = 8;
    third->next = fourth;
    fourth->data = 1;
    fourth->next = head;

    printf("CircularLinked List before insertion...\n");
    LinkedListTraversal(head);
//    head = InsertAtBegining(head,54);
    head = InsertInBetween(head, 2, 54);
//    head = InsertAtEnd(head,44);
    printf("CircularLinked List after insertion...\n");
    LinkedListTraversal(head);
    return 0;
}
