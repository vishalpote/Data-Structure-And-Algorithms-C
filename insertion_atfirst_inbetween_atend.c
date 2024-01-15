#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*next;
    int data;
};

void linkedlisttravels(struct Node *ptr){
    while (ptr->next != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr=ptr->next;
    }
    
}


struct Node * insertatFirst(struct Node *head,int ele){
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=ele;
    ptr->next=head;
    return ptr;
};

struct Node *insertatIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i=0;
    while (i = index - 1)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    return head;
}

struct Node * insertatEnd(struct Node *head,int ele){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p=p->next;
    }
    ptr->data=ele;
    p->next=ptr;
    ptr->next=NULL;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;


    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    linkedlisttravels(head);

    // printf("After Inserting Element in First Node\n");
    // head=insertatFirst(head,5);
    // linkedlisttravels(head);
    printf("After Inserting Element at Index Number\n");
    head=insertatIndex(head,25,1);
    linkedlisttravels(head);
    insertatEnd(head,45);
    linkedlisttravels(head);
}