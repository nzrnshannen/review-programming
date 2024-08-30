/*
    ADT STACK: ARRAY VERSION 2
    -> STACK is a pointer to a structure containing an array and variable top

    =====================> STACK cannot be traversed! <============================

    Utility operations:
    1. initializeStack()
    2. isEmpty()
    3. isFull() 

    Note: I'm using array implementation of Stack view 2 (stack grows from MAX-1 to 0) 
                in this program.
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    char elem[MAX];
    int top;
}arrStack, *STACK;

//Note: When we say STACK myStack, it's equivalent to arrStack* myStack
        //By that, we access the members of the structure using -> : (myStack->____)


/*
    Based on the given structure above, we can access members

    if STACK example, then example->______
    STACK example is the equivalent of arrStack* example.

    if STACK *example, then (*example)->_____
    STACK *example is the equivalent of arrStack** example.
*/


//funtion prototypes
void initializeStack(STACK *stack);
void populateStack(STACK *stack);
void displayStack(STACK stack);
void push(STACK *stack, char elem);
void pop(STACK *stack);
char top(STACK stack);
bool isEmpty(STACK stack);
bool isFull(STACK stack);
void deleteFirstOccurrence(STACK *stack, char elem);
void deleteAllOccurrences(STACK *stack, char elem);

int main()
{
    arrStack test;
    STACK myStack = &test;
    initializeStack(&myStack);

    displayStack(myStack);
    populateStack(&myStack);
    displayStack(myStack);

    deleteAllOccurrences(&myStack, 'Z');
    displayStack(myStack);

    return 0;
}

void initializeStack(STACK *stack)
{
    (*stack)->top = MAX;
}

void populateStack(STACK *stack)
{
    push(stack, 'A');
    push(stack, 'A');
    push(stack, 'A');
    push(stack, 'A');
    push(stack, 'A');
    push(stack, 'A');
}

void displayStack(STACK stack)
{
    if(!isEmpty(stack))
    {
        printf("\n===\nSTACK: ");

        char elem;
        arrStack test;
        STACK tempStack = &test;
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

void push(STACK *stack, char elem)
{
    //NOTE: It is important to check whether stack is FULL or not before performing push (insertion of elem at the top of stack)
    if(!isFull(*stack))
    {
        (*stack)->top--;
        (*stack)->elem[(*stack)->top] = elem;
    }
}

void pop(STACK *stack)
{
    //NOTE: It is important to check whether stack is EMPTY or not before performing pop (deletion of elem at the top of stack)
    if(!isEmpty(*stack))
    {
        (*stack)->top++;
    }
}

char top(STACK stack)
{
    //if stack is NOT empty, it will return an elem
    //else, it will return NULL
    return (!isEmpty(stack)) ? stack->elem[stack->top] : '\0';

    //you can use return stack->elem[stack->top]; if stack is not empty
}

void deleteFirstOccurrence(STACK *stack, char elem)
{
    //NOTE: It is important to check whether the stack is EMPTY or not before performing deletion
    if(!isEmpty(*stack))
    {
        arrStack test;
        STACK tempStack = &test;
        initializeStack(&tempStack);

         //all contents will be placed in a tempStack (this is to keep the elements be in order when printing)
         while(!isEmpty(*stack))
         {
            push(&tempStack, top(*stack));
            pop(stack);
         }

        //loop runs while tempStack is not empty AND current top of tempStack is not equal to elem
            //the loop is for transferring the elements of tempStack to original stack and it will stop when tempStack is empty or we found a similar elem
        while(!isEmpty(tempStack) && top(tempStack)!=elem)
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
         while(!isEmpty(tempStack))
         {
            push(stack, top(tempStack));
            pop(&tempStack);
         }
    }
}

void deleteAllOccurrences(STACK *stack, char elem)
{
    //NOTE: It is important to check whether the stack is EMPTY or not before performing deletion
    if(!isEmpty(*stack))
    {
        arrStack test;
        STACK tempStack = &test;
        initializeStack(&tempStack);

        //loop will only add elements of original stack to tempStack that IS NOT equal to elem
            //hence, contents of tempStack won't contain any elements similar to elem
        while(!isEmpty(*stack))
        {
            if(top(*stack)!=elem)
            {
                push(&tempStack, top(*stack));
            }
            pop(stack);
        }

        //elements of tempStack will be transferred to original stack
        while(!isEmpty(tempStack))
        {
            push(stack, top(tempStack));
            pop(&tempStack);
        }
    }
}

bool isEmpty(STACK stack)
{
    return (stack->top == MAX) ? true : false;
}

bool isFull(STACK stack)
{
    return (stack->top == 0) ? true : false;
}