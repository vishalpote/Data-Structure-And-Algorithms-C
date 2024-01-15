#include<stdio.h>
#include<stdlib.h>

void display(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
}

int selectionsort(int a[],int n){
    int i,min,j,temp;
    for(i=0; i < n; i++){
        min=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[min]){
            
                min=j;

            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        
    }


}

int main(){
    int a[10]={9,2,6,4,3,8,5,1,0,10};
    int n=10;
    printf("==========================original array======================================\n");
    display(a,n);
    printf("\n==========================sorted array======================================\n");
    selectionsort(a,n);
    display(a,n);
}