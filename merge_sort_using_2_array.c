#include<stdio.h>
#include<stdlib.h>

int merge(int arr[],int low,int mid,int high){
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    int arr2[100];

    while (i<mid && j<high)
    {
        if(arr[i]<arr[j]){
            arr2[k++]=arr[i++];
        }else{
            arr2[k++]=arr[j++];
        }
    }
    while (i<=mid)
    {
        arr2[k++]=arr[i++];
    }

    while (j <= high)
    {
        arr2[k++] = arr[j++];
    }
    // for storing all merged element into the orignal array
    for (int i = low; i <=high; i++)
    {
        arr[i] = arr2[i];
    }
}

void mergesort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main(){

    int arr1[10]={6,5,7,8,9};
    int low=0;
    int high=5;
    printf("========================original array========================\n");
    for (int i = low; i < high; i++)
    {
        printf("%d\t",arr1[i]);
    }
    
    printf("\n========================merged array========================\n");
    mergesort(arr1,low,high);
    for (int i = low; i < high; i++)
    {
        printf("%d\t", arr1[i]);
    }
}