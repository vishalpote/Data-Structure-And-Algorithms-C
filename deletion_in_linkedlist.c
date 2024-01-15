#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


void listtravel(struct node *ptr){
    while (ptr!=NULL)
    {
        printf("Data: %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}


struct node * deletefirstelement(struct node *head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

int main(){
    struct node *head;
    struct node *s;
    struct node *t;

    head=(struct node *)malloc(sizeof(struct node));
    s=(struct node *)malloc(sizeof(struct node));
    t=(struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next =s;

    s->data = 20;
    s->next = t;

    t->data = 30;
    t->next = NULL;


    listtravel(head);
    printf("=================Deletion of first element================\n");
    head=deletefirstelement(head);
    listtravel(head);
}