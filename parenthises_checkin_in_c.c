#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct stack{
    int top;
    char arr[MAX_SIZE];
};

int isempty(struct stack *s){
    return (s->top==-1);
}

int isfull(struct stack *s){
    return s->top==MAX_SIZE-1;
}

void push(struct stack *s, int ele){
    if(s->top == (MAX_SIZE-1)){
        printf("stack is overflow\n");
    }
    else{
        s->top+=1;
        s->arr[s->top++] = ele;
        printf("Element %d is pushed in stack \n", ele);
    }
}

void display(struct stack *s){
    if(s->top==-1){
        printf("stack is empty\n");
    }
    for (int i = 0; i <= s->top; i++)
    {
        printf("Data : %d\n", s->arr[i]);
    }
    
}
char pop(struct stack *s){
    if(isempty(s)){
        return 0;
    }else{
        return s->arr[s->top--];
    }
}

int parenthises(char exp[]){
    struct stack *s;
    s->top=-1;
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=="("){
            push(s,exp[i]);
        }else if(exp[i]==")"){
            if(isempty(&s)){
                return 0;
            }
            char topele=pop(s);

            if((exp[i]=="(" && topele!=")")||(exp[i]=="{" && topele!="}") || (exp[i]="[" && topele!="]")){
                return 0;
            }
        }
    }
    return isempty(s);
    
}

int main()
{
    char arr[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(arr, sizeof(arr), stdin);
    // scanf("%s", arr);
    struct stack s;
    s.top=-1;
    // isempty(&s);
    // isfull(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    display(&s);

    printf("===============parenthises check problem ==================\n");
    // char ex;
    // printf("Eneter The Expression You Want To Check :\n");
    // scanf("%c",&ex);
    if(parenthises(arr)){
        printf("Expression Is Balanced :\n");
    }
    else{
        printf("Expression Is Not Balanced :\n");
    }
}