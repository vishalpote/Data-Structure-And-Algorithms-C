// #include<stdio.h>
// #include<stdlib.h>

// struct stack{
//     int size;
//     int top;
//     int *arr[];
// };

// int isempty(struct stack* p){
//     if(p->top==-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void push(struct stack* s,int ele){
//     if(s->top==s->size-1){
//         printf("stack is full\n");
// }
// else{
//     s->top++;
//     s->arr[s->top]=ele;
// }
// }

// void travel(struct stack *s){
//     if(s->top==-1){
//         printf("stack is empty\n");
//     }
//     else{

//     for(int i=0;i<s->top;i++){
//         printf("Data :%d\n",s->arr[i]);
//     }
//     }
// }

// int main(){

//     struct stack *s;
//     s->top=-1;
//     s->size = 100;
//     s->arr=(int *)malloc(s->size * sizeof(int));
//     s->arr[0]=20;
//     s->top++;

//     travel(s);
//     isempty(s);
//     // isfull(s);
//     push(s,20);
//     travel(s);
    
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack
{
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow! Cannot push element %d.\n", value);
    }
    else
    {
        stack->items[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1; // Return a sentinel value or handle the error accordingly
    }
    else
    {
        return stack->items[stack->top--];
    }
}

// Function to display the elements in the stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; ++i)
        {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    display(&myStack);

    printf("Popped element: %d\n", pop(&myStack));
    display(&myStack);

    return 0;
}
