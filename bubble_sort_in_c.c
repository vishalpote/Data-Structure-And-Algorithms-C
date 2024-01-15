#include<stdio.h>
#include<stdlib.h>
int swap_count,comp_count;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

void bubblesort(int arr[],int n){
    int i,j,temp,issorted=0;
    for(i=0;i<=n-1;i++){
        printf("The Number of Passes :%d\n",i+1);
        issorted=1;//for already sorted array;
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                issorted=0;
            }
        }
        if(issorted){
            return ;
        }
        
    }
}

int main(){
    int arr[20];
    int n;
    printf("How Many Element U Want To add:\n");
    scanf("%d",&n);
    printf("Enter Element U Want To Add :\n");
    for(int i=0; i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("=========== Unsorted Arrays =================================\n");
    display(arr,n);
    printf("\n");
    printf("=========== Sorted Arrays =================================\n");
    bubblesort(arr,n);
    display(arr,n);
}