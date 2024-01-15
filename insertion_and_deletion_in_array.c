#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void insertion(int arr[],int size,int index,int ele,int capacity){
    if(size>=capacity){
        printf("Size Is bigger than capacity !");
    }
    for (int i = size-1; i > index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=ele;
    // printf("\n");
    printf("Element Add Successfully !\n");
    
}

void deletion(int arr[], int index,int size){
    for (int i = index; i < size; i++)
    {
        arr[i]=arr[i+1];
    }
    
}
int main(){
    int arr[10]={2,5,3,4,6};
    int size=5;
    int ele,capacity=10,index;
    printf("Enter the Element You Want to Add : ");
    scanf("%d",&ele);
    printf("Enter the Index Number You Want To Add : ");
    scanf("%d",&index);
    printf("=================x================\n");
    display(arr,size);
    printf("\n");
    printf("=================After Adding Element================\n");
    insertion(arr,size,index,ele,capacity);
    display(arr,size);
    size+=1;
    printf("\n");
    printf("=================After Deleting Element================\n");
    printf("Enter The Index Number You Want To Delete :");
    scanf("%d",&index);
    deletion(arr,index,size);
    printf("\n");
    display(arr,size);
    size-=1;

}