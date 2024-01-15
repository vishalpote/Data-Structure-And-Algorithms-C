#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void listtravle(struct node *ptr)
{
    while(ptr!=NULL){
        printf("data: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * deletenodeusingele(struct node *head, int ele){
    struct node *p=head;
    struct node*q=head->next;

    while (q->data!=ele && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==ele){
        p->next=q->next;
        free(q);
    }
    return head;
    
}

int main(){
    struct node* head;
    struct node* sec;
    struct node* third;


    head=(struct node*)malloc(sizeof(struct node));
    sec=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=100;
    head->next=sec;

    sec->data=200;
    sec->next=third;

    third->data=300;
    third->next=NULL;

    listtravle(head);
    printf("=============delete node using element================================\n");
    head=deletenodeusingele(head,300);
    listtravle(head);
}