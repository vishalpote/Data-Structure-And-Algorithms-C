#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

struct node *searchbst(struct node *root, int ele)
{
    while (root!=NULL)
    {
        if(root->data==ele){
            return root;
        }
        if(root->data>ele){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    return NULL;
    

}

int main()
{

    struct node *p1 = createnode(5);
    struct node *p2 = createnode(3);
    struct node *p3 = createnode(6);
    struct node *p4 = createnode(2);
    struct node *p5 = createnode(8);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    printf("=============================Inorder Method============================\n");
    inorder(p1);

    printf("\n=============================Searching Method============================\n");
    struct node *x = searchbst(p1, 5);
    if (x != NULL)
    {
        printf("Found : %d\n", x->data);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}