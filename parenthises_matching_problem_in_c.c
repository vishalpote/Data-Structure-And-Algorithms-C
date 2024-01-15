#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack
{
    char items[MAX_SIZE];
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
void push(struct Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack overflow! Cannot push element %c.\n", value);
    }
    else
    {
        stack->items[++stack->top] = value;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return '\0'; // Return a sentinel value or handle the error accordingly
    }
    else
    {
        return stack->items[stack->top--];
    }
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(char expression[])
{
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(&stack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (isEmpty(&stack))
            {
                return 0; // Unbalanced if closing parenthesis without a matching opening parenthesis
            }

            char topElement = pop(&stack);

            // Check if the closing parenthesis matches the corresponding opening parenthesis
            if ((expression[i] == ')' && topElement != '(') ||
                (expression[i] == ']' && topElement != '[') ||
                (expression[i] == '}' && topElement != '{'))
            {
                return 0; // Unbalanced if parentheses do not match
            }
        }
    }

    // The parentheses are balanced if the stack is empty at the end
    return isEmpty(&stack);
}

int main()
{
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    if (areParenthesesBalanced(expression))
    {
        printf("Parentheses are balanced.\n");
    }
    else
    {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
