/*
    ADT STACK: ARRAY VERSION 1
    -> STACK is a structure containing an array and variable top

    =====================> STACK cannot be traversed! <============================

    Utility operations:
    1. initializeStack()
    2. isEmpty() => stack->top!=-1 in this program
    3. isFull() => stack->top < MAX-1 in this program

    Note: I'm using array implementation of Stack view 1 (stack grows from 0 to MAX-1) 
                in this program.
*/

#include<stdio.h>
#define MAX 5

typedef struct{
    char elem[MAX];
    int top;
}STACK;

//function prototypes
void initializeStack(STACK *stack);
void populateStack(STACK *stack);
void displayStack(STACK stack);
void push(STACK *stack, char elem); //inserts the element (elem) at the top of the stack
void pop(STACK *stack); //deletes the top element of stack
char top(STACK stack); //returns the element at the top of stack
void deleteFirstOccurrence(STACK *stack, char elem);
void deleteAllOccurrences(STACK *stack, char elem);

int main()
{
    STACK myStack;
    initializeStack(&myStack);

    populateStack(&myStack);
    displayStack(myStack);

    deleteFirstOccurrence(&myStack, 'J');
    displayStack(myStack);
    return 0;
}

void initializeStack(STACK *stack)
{
    stack->top = -1;
}

void populateStack(STACK *stack)
{
    push(stack, 'A');
    push(stack, 'A');
    push(stack, 'B');
    push(stack, 'C');
    push(stack, 'Z');
    push(stack, 'A');
}

void displayStack(STACK stack)
{
    if(stack.top!=-1)
    {
        printf("\n===\nSTACK: ");

        char elem;
        STACK tempStack;
        initializeStack(&tempStack);

        while(stack.top!=-1)
        {
            elem = top(stack);
            push(&tempStack, elem);
            pop(&stack);
        }

        while(tempStack.top!=-1)
        {
            elem = top(tempStack);
            printf("%c ", elem);
            push(&stack, elem);
            pop(&tempStack);
        }
        printf("\n");
    }
}


void push(STACK *stack, char elem)
{
    //NOTE: It is important to check whether stack is FULL or not before performing push (insertion of elem at the top of stack)
    if(stack->top < MAX-1)
    {
        stack->top++;
        stack->elem[stack->top] = elem;
    }
}

void pop(STACK *stack)
{
    //NOTE: It is important to check whether stack is EMPTY or not before performing pop (deletion of elem at the top of stack)
    if(stack->top!=-1)
    {
        stack->top--;
    }
}

char top(STACK stack)
{
    //if stack is NOT empty, it will return an elem
    //else, it will return NULL
    return (stack.top!=-1) ? stack.elem[stack.top] : '\0'; 

    //you can use return stack->elem[stack->top]; if stack is not empty
}

void deleteFirstOccurrence(STACK *stack, char elem)
{
    //NOTE: It is important to check whether the stack is EMPTY or not before performing deletion
    if(stack->top!=-1)
    {
        STACK tempStack; 
        initializeStack(&tempStack);

        //all contents will be placed in a tempStack (this is to keep the elements be in order when printing)
        while(stack->top!=-1) 
        {
            push(&tempStack, top(*stack));
            pop(stack);
        }

        //loop runs while tempStack is not empty AND current top of tempStack is not equal to elem
            //the loop is for transferring the elements of tempStack to original stack and it will stop when tempStack is empty or we found a similar elem
        while(tempStack.top!=-1 && top(tempStack)!=elem)
        {
            push(stack, top(tempStack));
            pop(&tempStack);
        }

        //if we stopped when top(tempStack)==elem (meaning, similar elem has been found), the top of tempStack will be popped out
            //hence, in the next while() below this if() condition, that elem won't be included in the original stack
        if(top(tempStack) == elem)
        {
            pop(&tempStack);
        }

        //loop will continuously transfer elements of tempStack to original stack
        while(tempStack.top!=-1)
        {
            push(stack, top(tempStack));
            pop(&tempStack);
        }
    }
}

void deleteAllOccurrences(STACK *stack, char elem)
{
    //NOTE: It is important to check whether the stack is EMPTY or not before performing deletion
    if(stack->top!=-1)
    {
        STACK tempStack;
        initializeStack(&tempStack);

        //loop will only add elements of original stack to tempStack that IS NOT equal to elem
            //hence, contents of tempStack won't contain any elements similar to elem
        while(stack->top!=-1)
        {
            if(top(*stack)!=elem)
            {
                push(&tempStack, top(*stack));
            }
            pop(stack);
        }

        //elements of tempStack will be transferred to original stack
        while(tempStack.top!=-1)
        {
            push(stack, top(tempStack));
            pop(&tempStack);
        }
    }
}




