#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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
    return root;
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

struct node *inorderPred(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node *root, int data)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (root->data > data)
    {
        root->left = deletenode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = deletenode(root->right, data);
    }
    else
    {
        ipre = inorderPred(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
}

int main()
{

    struct node *p = createnode(7);
    struct node *p1 = createnode(4);
    struct node *p2 = createnode(9);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(5);
    struct node *p5 = createnode(6);
    // struct node *p5 = createnode(10);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    inorder(p);
    printf("\n");
    deletenode(p, 7);
    deletenode(p, 9);
    inorder(p);
    return 0;
}