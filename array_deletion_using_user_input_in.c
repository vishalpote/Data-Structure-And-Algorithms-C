#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void deleteelement(int arr[], int size,int index){
    for (int i = index; i < size; i++)
    {
        arr[i]=arr[i+1];
    }
    
}

int main(){
    int arr[10]={0,1,2,3,4};
    int ele,index;
    int size=5;
    // printf("Enter Element You Want To Delete: ");
    // scanf("%d",&ele);
    printf("Enter Element Index You Want To Delete: ");
    scanf("%d",&index);
    display(arr,size);
    deleteelement(arr,size,index);
    printf("\nAfter Delete Element \n");
    size-=1;
    display(arr,size);
}
