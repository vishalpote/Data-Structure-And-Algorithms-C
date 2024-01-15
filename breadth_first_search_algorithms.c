#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rare;
    int *arr;
};

int isempty(struct queue *q){
    if(q->front==q->rare){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct queue *q){
    if(q->rare==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

int enqueue(struct queue *q,int data){
    if(isfull(q)){
        printf("Queue Is Alredy Full\n");
    }else{
        q->arr[q->rare++]=data;
    }
}

int dequeue(struct queue *q){
    if(isempty(q)){
        printf("Queue Is Allready Empty\n");
    }else{
        return q->arr[q->front++];
    }
}


int main(){
    struct queue q;
    q.size=100;
    q.front=0;
    q.rare=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    int node;
    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,0,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    printf("%d\t",i);
    visited[i]=1;
    enqueue(&q,i);
    while (!isempty(&q))
    {
        node=dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j]==1 && visited[j]==0){
                printf("%d\t",j);
                visited[j]=1;
                enqueue(&q,j);

            }
        }
        

    }
    return 0;
    
}