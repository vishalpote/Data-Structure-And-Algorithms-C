#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void isempty(struct node *top) {
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
}

void isfull(struct node *top) {
    struct node *p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }
}


struct node * push(struct node *top,int ele){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("stack is overflow\n");
    }
    else{
        p->data=ele;
        p->next=top;
        top=p;
        return top;
    }
}

struct node * pop(struct node * top){
    struct node*p=top;
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        top=top->next;
        int x=p->data;
        free(p);
        return top;
    }
}

void display(struct node*top){
    while (top!=NULL)
    {
        printf("Data:%d\n",top->data);
        top=top->next;
    }
    
    
}

int peek(struct node*top,int pos){
    struct node * p=top;
    for(int i=0;(i<pos-1 && p!=NULL);i++){
        p=p->next;
    }
    if(p!=NULL){
    return p->data;
    }
    else{
        return -1;
    }
}

void stacktop(struct node*top){
    printf("Top Element: %d\n",top->data);
}

void stackbottom(struct node*top){
    struct node * p=top;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    if(p->next!=NULL){
        printf(p->data);
    }
    
}


int main(){
    struct node *top=NULL;
    isempty(top);
    isfull(top);
    top=push(top,10);
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    display(top);

    // printf("============after deleteing the element in stack =================\n");
    // top=pop(top);
    // display(top);
    // printf("The first Postion element is :%d\n",peek(top,2));
    for(int i=1;i<=4;i++){
        printf("The Position %d and element : %d \n",i,peek(top,i));
    }

    // stacktop(top);
    // stackbottom(top);

}