/*
    ADT STACK: ARRAY VERSION 3
    -> STACK is a structure containing variable top and a pointer to the first element
    of a dynamically allocated array(elemPtr)

    =====================> STACK cannot be traversed! <============================

    Utility operations:
    1. initializeStack()
    2. isEmpty() 
    3. isFull() 

    Note: I'm using array implementation of Stack view 1 (stack grows from 0 to MAX-1) 
                in this program.
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5

typedef struct nodeType{
    int *elemPtr;
    int top;
}STACK;

//function prototypes
void initializeStack(STACK *stack);
void populateStack(STACK *stack);
void displayStack(STACK stack);
void push(STACK *stack, int elem);
void pop(STACK *stack);
int top(STACK stack);
void deleteFirstOccurrence(STACK *stack, int elem);
void deleteAllOccurrence(STACK *stack, int elem);
bool isFull(STACK stack);
bool isEmpty(STACK stack);

int main()
{
    STACK myStack;
    initializeStack(&myStack);

    return 0;
}

void initializeStack(STACK *stack)
{
    stack->top = 0;
    stack->elemPtr = (int*)malloc(sizeof(sizeof(int) * SIZE));
    if(stack->elemPtr==NULL)
    {
        perror("Memory allocation failure");
    }
}

void populateStack(STACK *stack)
{

}

void displayStack(STACK stack)
{
    if(!isEmpty(stack))
    {
        printf("\n===\nSTACK: ");

        int elem;
        STACK tempStack;
        initializeStack(&tempStack);

        while(!isEmpty(stack))
        {
            elem = top(stack);
            push(&tempStack, elem);
            pop(&stack);
        }

        while(!isEmpty(tempStack))
        {
            elem = top(tempStack);
            printf("%c ", elem);
            push(&stack, elem);
            pop(&tempStack);
        }
        printf("\n");
    }
}

void push(STACK *stack, int elem)
{
    //NOTE: It is important to check whether stack is FULL or not before performing push(insertion of elem at the top of stack)
    if(!isFull(*stack))
    {
        stack->top++;
        stack->elemPtr[stack->top] = elem;
    }
}

void pop(STACK *stack)
{
    //NOTE: It is important to chec whether stack is EMPTY or not before performing pop(deletion of elem at the top of stack)
    if(!isEmpty(*stack))
    {
        stack->top--;
    }
}

int top(STACK stack)
{
    stack.elemPtr[stack.top];
}

void deleteFirstOccurrence(STACK *stack, int elem)
{

}

void deleteAllOccurrences(STACK *stack, int elem)
{

}

bool isEmpty(STACK stack)
{

}

bool isFull(STACK stack)
{

}