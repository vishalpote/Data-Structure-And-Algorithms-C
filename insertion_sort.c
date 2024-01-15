#include<stdio.h>
#include<stdlib.h>

void display(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int insertionsort(int arr[], int n)
{
    int j, x;
    for (int i = 0; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main(){
    int arr[10]={8,4,7,3,2,1,8,5};
    int size=8;
    printf("====================Before Sortings =============================\n");
    display(arr,size);
    printf("\n====================after  Sortings =============================\n");
    insertionsort(arr, size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}