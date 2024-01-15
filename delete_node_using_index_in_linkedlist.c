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


struct node * deleteelementatindex(struct node *head,int index){
    int i;
    struct node *p=head;
    struct node * q=head->next;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
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
    printf("=================Delete element using index number================\n");
    head=deleteelementatindex(head,1);
    listtravel(head);
   
}