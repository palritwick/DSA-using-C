#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void LinkedListTraversal(struct node *head){
    struct node *ptr = head;
	printf("Forward move\n");
    while (ptr->next != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ->", ptr->data);
    printf("\nBackward move\n");
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->prev;
    }
}

struct node * InsertAtFirst(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr ;
    return head;
}

struct node * InsertAtIndex(struct node * head,int index,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    int i = 0;
    struct node *p = head;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p; 
    p->next = ptr;
    ptr->next->prev = ptr;
    return head;
}

int main()
{
    struct node * n1 = (struct node *)malloc(sizeof(struct node));
    struct node * n2 = (struct node *)malloc(sizeof(struct node));
    struct node * n3 = (struct node *)malloc(sizeof(struct node));
    struct node * n4 = (struct node *)malloc(sizeof(struct node));

    n1->data = 12;
    n1->prev = NULL;
    n1->next = n2;

    n2->data = 7;
    n2->prev = n1;
    n2->next = n3;

    n3->data = 14;
    n3->prev = n2;
    n3->next = n4;

    n4->data = 17;
    n4->prev = n3;
    n4->next = NULL;

    printf("Linked List before insertion...\n");
    LinkedListTraversal(n1);
    n1 = InsertAtFirst(n1,44);
//    n1 = InsertAtIndex(n1,2,44);
    printf("\nLinked List after insertion...\n");
    LinkedListTraversal(n1);
    return 0;
}
