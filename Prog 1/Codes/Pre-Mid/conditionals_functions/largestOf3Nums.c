/*
    A program to determine which among the three of the numbers being entered by the user is the largest.
*/

#include<stdio.h>
int largestOfThree(int, int, int);

int main()
{
    int num1, num2, num3;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter third number: ");
    scanf("%d", &num3);

    int result = largestOfThree(num1, num2, num3);

    printf("\n===\nLargest = %d", result);

    return 0;
}

int largestOfThree(int a, int b, int c)
{
    int returnLargest;

    if(a > b && a > c) // if 'a' is greater than 'b' AND 'a' is greater than 'c'
    {
        returnLargest = a; // ... then 'a' is the largest 
    }
    else if(b > a && b > c) // if 'b' is greater than 'a' AND 'b' is greater than 'c'
    {
        returnLargest = b; // ... then 'b' is the largest
    }
    else //or do: else if(c > a && c > b) but I don't recommend this
    {
        returnLargest = c; 
    }

    return returnLargest;
}