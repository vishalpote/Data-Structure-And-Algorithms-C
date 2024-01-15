#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void linkedlisttravels(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Data: %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}

struct Node * insertatfirst(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct Node * insertinbetween(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

    
}

 
 int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    

    int ele;
    printf("Enter the element you want to add : ");
    scanf("%d",&ele);

    head->data = 5;
    head->next=second;

    second->data = 7;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;


    linkedlisttravels(head);
    // head=insertatfirst(head,ele);
    // printf("After adding element at first \n");
    linkedlisttravels(head);
    printf("After adding element in between  \n");
    head=insertinbetween(head,ele,2);
    linkedlisttravels(head);

    return 0;
}