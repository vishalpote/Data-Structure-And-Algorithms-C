#include<stdio.h>
#include<stdlib.h>
struct arrayadt
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct arrayadt *a, int tsize, int usize){
    a-> total_size=tsize;
    a-> used_size=usize;
    a-> ptr=(int *)malloc(tsize*sizeof(int));
}

void show(struct arrayadt *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n ",(a->ptr)[i]);
    }
    
}

void setvalue(struct arrayadt *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter The Element: ",i);
        scanf("%d",&n);
        (a->ptr)[i] =n;
    }
    
}

int main(){
    struct arrayadt marks;
    createarray(&marks,10,5);
    printf("Takeing Marks From User \n ");
    setvalue(&marks);
    printf("Showing Marks to Student \n ");
    show(&marks);
    return 0;
}