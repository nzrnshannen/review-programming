/*
    A program to check whether the number (user input) is positive or negative
*/

#include<stdio.h>
void positiveOrNegative(int num);

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    positiveOrNegative(num);

    return 0;
}

void positiveOrNegative(int num)
{
    if(num < 0) // if num is LESSER than zero, 
    {
        printf("\nNegative"); // ... then it is negative
    }
    else if(num > 0) // if num is GREATER than zero,
    {
        printf("\nPositive"); // ... then it is positive
    }
    else // when num = 0  (zero is neither positive nor negative)
    {
        printf("Neither a positive/negative");
    }
}