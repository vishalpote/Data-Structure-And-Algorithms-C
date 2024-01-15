#include<stdio.h>
#include<stdlib.h>

struct queue * front;
struct queue * rare;

struct queue{
    int data;
    int size;
    struct queue *next;
};

int display(struct queue *q){
    while (q!=NULL)  {
        printf("Data: %d\n", q->data);
        q=q->next;
    }
    
}


// int isempty(struct queue *front,struct queue *rare){
//     if(front==rare){
//         printf("Empty queue\n");
//     }
//     return 0;
// }


// int isfull(struct queue *rare,struct queue *q){
//     if(rare==q->size-1){
//         printf("Full queue\n");
//     }
//     return 0;
// }

int enqueue(int val){
    struct queue *end=(struct queue*)malloc(sizeof(struct queue));
    if(end==NULL){
        printf("Queue is Overflow\n");
    }else{
        end->next=NULL;
        end->data=val;
        if(front==NULL){
            front=rare=end;
        }else{
            rare->next=end;
            rare=end;
        }
    }
}

int dequeue(){
    struct queue *new=front;
    int val;
    if(front==NULL){
        printf("Queue is empty\n");
    }else{
        front=front->next;
        printf("Dequeu : %d\n", new->data);
        free(front);
        
    }
}
int main(){
    // struct queue*head;
    // struct queue*sec;
    // struct queue*third;
    // struct queue*front;
    // struct queue*rare;

    // head=(struct queue*)malloc(sizeof(struct queue));
    // sec=(struct queue*)malloc(sizeof(struct queue));
    // third=(struct queue*)malloc(sizeof(struct queue));

    // head->data=10;
    // head->next=sec;

    // sec->data = 20;
    // sec->next = third;

    // third->data = 30;
    // third->next = NULL;

    display(front);
    printf("Dequeue: %d\n", dequeue());
    printf("=========================after adding some elements =============================\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display(front);
    printf("=========================after deleting some elements =============================\n");
    dequeue();
    // display(front);
}