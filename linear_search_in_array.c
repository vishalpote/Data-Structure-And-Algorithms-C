#include<stdio.h>
#include<stdlib.h>


void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
       printf("%d ",arr[i]);
    }
    
}


void linearsearch(int arr[],int size,int ele){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
        {
            printf("Element Fount At Position : %d ",i);
        }
    }
    
}

int main(){
    int arr[5]={1,5,2,8,6};
    int ele,size=sizeof(arr)/sizeof(int);
    display(arr,size);
    printf("\n");
    printf("%d",size);
    printf("\n");
    printf("====================linear search in array==================\n");
    printf("Enter Element you Want to search :");
    scanf("%d",&ele);
    linearsearch(arr,size,ele);
    // display(arr,size);
    
}