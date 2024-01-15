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
       printf("empty queue\n");
    }else{
        printf("queue is not empty \n");
    }
}


int isfull(struct queue *q){
    if(q->rare==q->size-1){
        printf("full queue\n");
    }else{
        printf(" queue is not full \n");
    }
}

int enqueue(struct queue *q,int val){
    if(isfull(q)){
        printf("queue is overflow\n");
    }else{
        q->rare+=1;
        q->arr[q->rare]=val;
        printf("Element Add In Queue :%d\n",val);
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("Queue is Already Empty\n");
    }
    else{
        q->front++;
        a=q->arr[q->front];
        printf("Dequeue In Queue: %d\n",a);
    }
}

// void display(struct queue *q){
//     for(int i=q->front;i<q->size-1;i++){
//         printf("queue : %d\n",q->arr[i]);
//     }
// }
int main(){
    struct queue q;
    q.size = 100;
    q.front=q.rare=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,100);
    enqueue(&q,200);
    enqueue(&q,300);
    enqueue(&q,400);
    enqueue(&q,500);
    // display(&q);

    printf("===================== Dequeue Operations =============================\n");
    dequeue(&q);
    

}