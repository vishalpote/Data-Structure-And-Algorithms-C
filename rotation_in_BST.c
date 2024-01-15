#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}

int balancefactor(struct node *root){
    if(root==NULL){
        return 0;
    }
    return getheight(root->left)-getheight(root->right);
}

int max(int a,int b){
    return a > b ? a : b;
}


struct node * createnode(int data){
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left =NULL;
    root->right =NULL;
    root->height=1;
    return root;
}


struct node *rightrotate(struct node *y){
    struct node *x=y->left;
    struct node *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->left),getheight(x->right))+1;

    return x;

}

struct node *leftrotate(struct node *x){
    struct node *y=x->right;
    struct node *t2=y->left;

    y->left=x;
    x->right=t2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    return y;
}


struct node *insert(struct node *root,int data){
    if(root==NULL){
        return (createnode(data));
    }
    else if(root->data >data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;

    root->height=1+max(getheight(root->left),getheight(root->right));

    int bf=balancefactor(root);


    // for left left rotation
    if(bf > 1 && root->left->data >data){
       return  rightrotate(root);
    }

    // for right right rotation

    if(bf< -1 && root->right->data <data){
       return  leftrotate(root);
    }

    // for left right roatation
    if (bf > 1 && root->left->data < data)
    {
        root->left=leftrotate(root->left);
       return  rightrotate(root);
    }

    // for right left roatation
    if (bf < -1 && root->right->data > data)
    {
        root->right = rightrotate(root->right);
       return  leftrotate(root);
    }

    return root;
}

int preorder(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node *root =NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);
    preorder(root);
    return 0;
}