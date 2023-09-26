#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int f,r;
    int *arr;
};
int isFull(struct Queue *q){
    if((q->r+1)%q->size == q->f)
        return 1;
    return 0;
}
int isEmpty(struct Queue *q){
    if(q->f == q->r)
        return 1;
    return 0;
}

void enqueue(struct Queue *q, int val){
    if(isFull(q))
        printf("Queue Overflow\n");
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued element %d\n",val);
    }
}
int dequeue(struct Queue *q){
    int x = -1;
    if(isEmpty(q))
        printf("Queue Underflow\n");
    else{
        q->f = (q->f +1)%q->size;
        x = q->arr[q->f];
    }
    return x;
}

int main()
{
    struct Queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 7);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    if (isEmpty(&q))
        printf("Circular Queue is empty\n");
    if (isFull(&q))
        printf("Circular Queue is full\n");
    return 0;
}