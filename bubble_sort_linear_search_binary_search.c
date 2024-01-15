#include<stdio.h>
#include<stdlib.h>

int linearsearch(int arr[],int n,int ele){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==ele){
            printf("Element Found At %d\n",i);
        }
    }
    return -1;
    
}

int display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t",arr[i]);
    }
    
}

int bubblsort(int arr[],int n){
    int i,j,temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n-i-1; j++)
        {
            if(arr[j]> arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
    
}


int binarysearch(int arr[],int n,int ele){
    int low=0,mid,high=n-1;
    while (low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid]==ele){
            printf("Element Found At Position %d\n",ele);
        }
        if(arr[mid]<ele){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
    
}

int main(){
    int arr[10]={10,3,9,5,7,8,2,6,4,1};
    int size=10;
    printf("========================original Arrays============================================================\n");
    display(arr,size);
    printf("\n====================linear search algorithm ==================================\n");
    linearsearch(arr,size,9);
    printf("====================bubble sort algorithm ======================================\n");
    bubblsort(arr,size);
    display(arr,size);
    printf("\n====================binary search algorithm ==================================\n");
    binarysearch(arr,size,5);

}