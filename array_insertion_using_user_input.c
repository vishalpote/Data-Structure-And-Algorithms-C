#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int n){
    for (int i = 0; i <n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void intinsertion(int arr[],int size,int index,int capacity,int ele){
    if(size>=capacity){
        printf("Size is Bigger than capacity !");
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = ele;
    printf("Inserted element at index %d\n",index);
    
}



int main(){
    int arr[50]={0,1,2,3,4};
    int size=5;
    int capacity=50;
    int ele,index;
    printf("Enter The Element :");
    scanf("%d",&ele);
    printf("Enter The Position You Want To Add:");
    scanf("%d",&index);
    size+=1;

    display(arr,size);
    printf("\n");
    intinsertion(arr, size, index, capacity,ele);
    display(arr, size);
}