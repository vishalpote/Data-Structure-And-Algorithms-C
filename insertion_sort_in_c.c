#include<stdio.h>
#include<stdlib.h>


int display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t ",arr[i]);
    }
}

void insertionsort(int arr[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        x=arr[i];
        for (j=i-1;j>=0 && arr[j]>x; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=x;
        
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    printf("=============================unsorted array================================\n");
    display(arr,n);
    printf("\n=============================sorted array==================================\n");
    insertionsort(arr, n);
    display(arr,n);
}