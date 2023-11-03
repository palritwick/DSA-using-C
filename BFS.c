#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

int enqueue(struct queue *q, int val)
{
    if (isFull(q))
        printf("The Queue is Full\n");
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqueueing the element %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        q->f++;
        return q->arr[q->f];
        // printf("Dequeuing the element %d\n");
    }
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Traversal

    //   0 -- 1-- 3
    //   |    |  /
    //   |    | /
    //   2 -- 4   

    int node;
    int i;
    int visited[5] = {0, 0, 0, 0, 0};
    int a[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
    };
    
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}