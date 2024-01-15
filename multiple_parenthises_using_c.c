#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct stack{
    int top;
    char arr[MAX_SIZE];
};
void intialize(struct stack *s){
    s->top=-1;
}

int isemepty(struct stack *s){
   return (s->top==-1);
}

int isfull(struct stack *s){
   return (s->top==MAX_SIZE-1);
}

int push(struct stack *s,int ele){
    if(isfull(s)){
        printf("Stack Is Overflow!\n");
    }else{
        s->arr[++s->top]=ele;
    }
}

char pop(struct stack *s){
    if(isemepty(s)){
        printf("Stack is underflow!\n");
        return "\0";
    }else{
       return s->arr[s->top--];
    }
}

int paranthesismatch(char *exp){
    struct stack s;
    intialize(&s);
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(&s, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isemepty(&s)){
                return 0;
            }

            char topele=pop(&s);

            if((exp[i] == ')' && topele!='(' )||
                (exp[i] == '}' && topele!='{') ||
                (exp[i] == ']' && topele!='[') 
            ){
                return 0;
            }
        }
    }
    return isemepty(&s);
    
}


int main(){

    char *exp="3+2+(3)({)";
    // printf("Enter an expression: ");
    // fgets(exp, sizeof(exp), stdin);
  
    if (paranthesismatch(exp)){
        printf("Parenthesis match !");
    }else{
        printf("Parenthesis Not match \n");
    }
    return 0;
}
