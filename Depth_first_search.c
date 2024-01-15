#include<stdio.h>
#include<stdlib.h>

int visited[7]={0,0,0,0,0,0,0};
int a[7][7] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void depthfirstsearch(int i){
    int j;
    printf("%d\t",i);
    visited[i] = 1;
    for ( j = 0; j < 7; j++)
    {
        if(a[i][j]==1 && !visited[j]){
            depthfirstsearch(j);
        }
    }
    
}

int main(){
    depthfirstsearch(4);
    return 0;
}