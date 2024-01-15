#include<stdio.h>
#include<stdlib.h>

void display(int arr[] ,int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

void indinsertion(int arr[],int size,int element,int index,int capacity){
    if(size>=capacity){
        printf("Out of capacity");
    }
    else
    {
        printf("Element Not Add Successfully at Posiion %d\n", index);
    }

    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    printf("\n");
   printf("Add Element Successfully at Posiion %d\n",index);
   
}

int main(){
    int arr[100]={2,3,1,5,6,4,7,8,9,11,12,13,14,15,16,17,18,19};
    int size=20,element=20,index=11;
    display(arr,size);
    indinsertion(arr,size,element,index,100);
    printf("\n");
    display(arr,size);
    size+=1;
}
