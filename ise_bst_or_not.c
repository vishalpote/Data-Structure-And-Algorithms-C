#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*createnode(int data){
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data =data;
    root->left =NULL;
    root->right =NULL;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}



int isbst(struct node *root){
    static struct node *prev=NULL;
    if (root!=NULL)
    {
        if(!isbst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isbst(root->right);
    }else{
        return 1;
    }
    
}


int main(){

    struct node *x1=createnode(8);
    struct node *x2=createnode(5);
    struct node *x3=createnode(10);
    struct node *x21=createnode(4);
    struct node *x22=createnode(6);
    struct node *x31=createnode(9);
    struct node *x32=createnode(11);

    x1->left=x2;
    x1->right=x3;
    x2->left=x21;
    x2->right=x22;
    x3->left=x31;
    x3->right=x32;

    inorder(x1);
   int x=isbst(x1);
    if(x==1){
        printf("\nIt Is Binary Search Tree\n");
    }else{
        printf("\nIt Is Not Binary Search Tree\n");

    }
    return 0;
}