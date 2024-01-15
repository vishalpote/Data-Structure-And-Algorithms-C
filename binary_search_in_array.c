#include<stdio.h>
#include<stdlib.h>


void binarysearch(int arr[],int ele,int size){
    int low=0,mid,high=size-1;

    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==ele){
            printf("Element found At Position %d",mid);
        }
        if(arr[mid]<=ele){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    
}
// printf("element Not found in array");
}
int main(){
    int arr[8]={10,23,45,56,77,99,101,105};
    int size=sizeof(arr)/sizeof(int);
    int ele;
    printf("Enter elemenet You Want to find : ");
    scanf("%d",&ele);
    binarysearch(arr,ele,size);
}