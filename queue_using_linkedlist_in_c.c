#include<stdio.h>
#include<stdlib.h>

struct queue *front;
struct queue *rare;

struct queue{
    int data;
    struct queue *next;
};

int enqueue(int val){
    struct queue *new =(struct queue *) malloc(sizeof(struct queue));
    if(new == NULL){
        printf("Queue Is Full !\n");
    }else{
        new->data = val;
        new->next = NULL;
        if(front == NULL){
            front =rare=new;
        }else{
            rare->next = new;
            rare=new;
        }
    }
}

int dequeue(){
    struct queue*p=front;
    if(front == NULL){
        printf("Queue Is Empty !\n");
    }else{
        front=front->next;
        printf("Dequeue : %d\n", p->data);
    }
}

int display(struct queue*ptr){
    while (ptr!=NULL)
    {
        printf("Enqueue : %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}


int main(){
    struct queue *q;
    printf("==============================after adding some elements =============================\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display(front);
    printf("==============================after deleting some elements =============================\n");
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printf("==============================after deleting all elements =============================\n");
    dequeue();
    // display(front);
}