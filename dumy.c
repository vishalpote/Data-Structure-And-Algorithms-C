#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int rare;
    int size;
    int *arr;
};

int isempty(struct queue *q)
{
    if (q->front == q->rare)
    {
        printf("Queue Is Empty!\n");
    }
    return 0;
}

int isfull(struct queue *q)
{
    if (q->rare == q->size - 1)
    {
        printf("Queue Is Full!\n");
    }
    return 0;
}

int enqueue(struct queue *q, int ele)
{
    if (isfull(q))
    {
        printf("Queues Is Already Full !\n");
    }
    else
    {
        q->rare++;
        q->arr[q->rare] = ele;
        printf("Enqueue :%d\n", ele);
    }
}

int dequeue(struct queue *q){
    if(isempty(q)){
        printf("Queue is empty\n");
    }else{
        q->front++;
        printf("Dequeue :%d\n", q->arr[q->front]);
    }
}

int queuetop(struct queue *q){
    printf("Top :%d\n", q->arr[q->rare]);
}

int queuelast(struct queue *q){
    printf("Last :%d\n", q->arr[q->front]);
}

void main()
{
    struct queue q;
    q.size = 10;
    q.front = -1;
    q.rare = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    printf("==========================after adding some items===========================\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printf("==========================after Deleting some items===========================\n");
    dequeue(&q);
    printf("==========================top items===========================================\n");
    queuetop(&q);
    printf("==========================Last items===========================================\n");
    queuelast(&q);
    
}