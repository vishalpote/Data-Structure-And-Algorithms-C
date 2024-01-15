#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void listtravel(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * deletenodeatend(struct node *head){
    struct node*p=head;
    struct node *q=head->next;

    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
    
}

int main()
{
    struct node *head;
    struct node *s;
    struct node *t;

    head = (struct node *)malloc(sizeof(struct node));
    s = (struct node *)malloc(sizeof(struct node));
    t = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = s;

    s->data = 20;
    s->next = t;

    t->data = 30;
    t->next = NULL;
    printf("===============linked list =================\n");
    listtravel(head);
    printf("=================Delete the last element in list================\n");
    head=deletenodeatend(head);
    listtravel(head);
}