/*
    A program that prompts the user to input a series of integers until 
    the user stops entering 0 using a while loop.
    Calculate and print the sum of all the positive integers entered.
*/

#include<stdio.h>

int main()
{
    int sum = 0;
    int userInput;

    printf("Enter a number: ");
    scanf("%d", &userInput);

    while(userInput!=0)
    {
        if(userInput > 0)
        {
            sum += userInput;
        }

        printf("Enter a number: ");
        scanf("%d", &userInput);
    }

    printf("\n===\nSum of all positive integers = %d", sum);

    return 0;
}