#include<stdio.h>
#include<stdlib.h>

void arraytravel(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void addelementatindex(int arr[],int size,int capacity,int ele,int index)
{
    if(size>=capacity){
        printf("Array is full !");
    }
    for (int i =size-1; i > index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=ele;
    printf("element add successfull!");
    
}

void deleteelementfromarray(int arr[], int size, int index){
    for (int i = index; i < size; i++)
    {
        arr[i]=arr[i+1];
    }
    printf("Deleted element from array successfully !!\n");
    
} 

void linearsearch(int arr[],int n,int ele){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==ele){
            printf("Found element at index %d",i);
        }
    }
    
}


void binarysearch(int arr[],int n,int ele){
    int low=0,mid,high=n-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==ele){
            printf("element found at index %d\n",mid);
        }
        if(arr[mid]<=ele){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
    
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8};
    int size=8;
    int capacity=10;
    arraytravel(arr,size);
    printf("\n");
    addelementatindex(arr,size,capacity,0,2);
    size+=1;
    printf("\n");
    arraytravel(arr,size);
    printf("\n");
    deleteelementfromarray(arr,size,2);
    size-=1;
    arraytravel(arr,size);
    printf("\n");
    printf("============linear search============");
    printf("\n");
    linearsearch(arr,size,8);
    printf("\n");
    printf("============binary search============");
    printf("\n");
    binarysearch(arr, size, 4);
}