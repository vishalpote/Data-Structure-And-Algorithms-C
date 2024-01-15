#include<stdio.h>
#include<stdlib.h>

struct circularqueue{
    int front;
    int rare;
    int size;
    int *arr;
    struct circularqueue* next;
};

int isempty(struct circularqueue* q){
    if(q->front == q->rare){
        printf("circularqueue is empty\n");
    }
    return 0;
}


int isfull(struct circularqueue* q){
    if((q->rare+1)%q->size==q->front){
        printf("circularqueue is full\n");
    }
    return 0;
}

int encircularqueue(struct circularqueue* q,int val){
    if(isfull(q)){
        printf("circularqueue is already full\n");
    }else{
        q->rare=(q->rare)%q->size;
        q->arr[q->rare]=val;
        printf("Encircularqueue :%d\n",val);
    }
}

int decircularqueue(struct circularqueue *q){
    if(isempty(q)){
        printf("circularqueue is already empty\n");
    }else{
        q->front++;
        printf("Dequeue : %d\n", q->arr[q->front]);
    }
       
}

int main(){

    struct circularqueue q;
    q.front=0;
    q.rare=0;
    q.size=100;
    q.arr=(int*)malloc(q.size*sizeof(int));
    encircularqueue(&q,10);
    encircularqueue(&q,20);
    encircularqueue(&q,30);
    decircularqueue(&q);
    decircularqueue(&q);
    decircularqueue(&q);
}