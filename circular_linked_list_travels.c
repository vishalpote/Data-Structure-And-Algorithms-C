#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void linklisttravles(struct node *head){
    struct node *p=head;
    

    // while (p->next!=head)
    // {
    //     printf("Data :%d\n", p->data);
    //     p=p->next;
    // }
    // printf("Data :%d\n", p->data);

    do
    {
        printf("Data :%d\n", p->data);
        p=p->next;
    } while (p != head);
    
    
}

struct node* insertatfirst(struct node *head,int ele){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head->next;
    ptr->data=ele;

    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
    

}

int main(){
    struct node*head;
    struct node*second;
    struct node*third;
    struct node*fourth;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=21;
    head->next=second;

    second->data = 22;
    second->next = third;

    third->data = 23;
    third->next = fourth;

    fourth->data = 24;
    fourth->next = head;


    linklisttravles(head);
    printf("\n");
    printf("=================insert element at first position =================\n");
    head=insertatfirst(head,20);
    linklisttravles(head);
}