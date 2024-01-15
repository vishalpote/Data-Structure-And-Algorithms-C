#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


void linkedlisttravel(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Data: %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}


struct Node * addelementatfirst(struct Node *head,int ele){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=ele;
    return ptr;
}


struct Node * addelementatEnd(struct Node *head,int ele){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;

    while (p->next != NULL)
    {
        p=p->next;
    }
    ptr->data=ele;
    p->next=ptr;
    ptr->next=NULL;
    return ptr;
    
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;


    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;


    linkedlisttravel(head);
    printf("===============add element at first ================\n");
    head=addelementatfirst(head,5);
    linkedlisttravel(head);

    printf("===============add element at end ================\n");
    addelementatEnd(head, 50);
    linkedlisttravel(head);
}