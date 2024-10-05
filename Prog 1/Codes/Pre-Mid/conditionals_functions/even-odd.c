/*
    A program to check whether the number entered by user is even or odd
*/

#include<stdio.h>
void evenOrOdd(int);

int main()
{
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    evenOrOdd(input);
    return 0;
}

void evenOrOdd(int num)
{
    if(num%2==0)
    {
        printf("\n%d is an even number.", num);
    }
    else
    {
        printf("\n%d is an odd number.", num);
    }
}