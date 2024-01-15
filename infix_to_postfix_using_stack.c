#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #define MAX_SIZE 100

struct stack{
    int top;
    int size;
    char *arr;
};

int isempty(struct stack *s){
    return s->top==-1;
}

int isfull(struct stack *s){
    return s->top==s->size-1;
}


int push(struct stack *s, int ele){
    if(isfull(s)){
        return 0;
    }else{
        s->top++;
        s->arr[s->top] = ele;
    }
}

int pop(struct stack *s){
    if(isempty(s)){
        return 0;
    }
    else{
        s->arr[s->top--] ;
    }
}
// void display(struct stack *s){
//     if(isempty(s)){
//         return 0;
//     }
//     for (int i = 0; i <= s->top; i++)
//     {
//         printf("Data : %d\n", s->arr[i]);
//     }
    
// }


int stacktop(struct stack *s){
   printf("%d\n", s->arr[s->top]);
}

int precedence(char ch){
    if(ch=='*' && ch=='/'){
        return 2;
    }
   else if(ch=='+' && ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

int isoperator(char ch){
    if(ch=='+' || ch=='-'|| ch=='*' || ch=='/'){
        return 1;
}else{
    return 0;
}
}
char * infixtopostfix(char *infix){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=100;
    s->arr=(char*)malloc(s->size * sizeof(char));
    char * postfix=(char*)malloc((strlen(infix)+1) * sizeof(char));
    int i=0,j=0;
    while (infix[i]!='\0')
    {
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }else{
            if(precedence(infix[i])>precedence(stacktop(s))){
                push(s,infix[i]);
            }else{
                postfix[j]=pop(s);
                j++;
            }
        }
    }
    while (!isempty(s))
    {
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
    
    
}

int main(){
    struct stack s;
    s.top=-1;
    s.size=100;

    char *infix="a+b-c+d/7";
    // push(&s,10);
    // push(&s,20);
    // push(&s,30);
    // display(&s);
    // // printf("After Poped Element :\n");
    // // pop(&s);
    // // display(&s);
    // printf("===============top most element===============\n");
    // stacktop(&s);

    printf("Postfix Expression :%s",infixtopostfix(infix));

}