#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


void linkedlisttravels(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}


struct Node * insertatEnd(struct Node *head,int ele){
    struct Node*ptr =(struct Node*)malloc(sizeof(struct Node));
    struct Node * p=head;
    ptr->data = ele;

    while (p->next != NULL)
    {
        p=p->next;
       
    }
    p->next=ptr;
    ptr->next = NULL;
    return head;
}

int main(){

    struct Node*head;
    struct Node*second;
    struct Node*third;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=20;
    head->next=second;

    second->data=23;
    second->next=third;

    third->data=34;
    third->next=NULL;

    linkedlisttravels(head);
    printf(" After Inserting At The End \n");
    insertatEnd(head,45);
    insertatEnd(head,50);
    insertatEnd(head,5);
    linkedlisttravels(head);
}