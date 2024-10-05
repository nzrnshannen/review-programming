/*
    NOTE: includes arrays and boolean
    ANOTHER NOTE: inefficient code

    A program that prompts the user to input a series of numbers until 
    they input a duplicate number. Use a while loop to check for duplicates
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 100

int main()
{
    int arrNum[MAX];
    int len = 0, input;
    bool hasDuplicate = false;

    while(hasDuplicate == false)
    {
        printf("Enter a number: ");
        scanf("%d", &input);

        int check = 0;
        while(check < len && hasDuplicate == false)
        {
            hasDuplicate = input == arrNum[check] ? true : false;
            check++;
        }

        check = 0;

        if(!hasDuplicate)
        {
            arrNum[len] = input;
            len++;
        }
    }
    

    printf("\n===\nArray: ");
    int i=0;
    while(i<len)
    {
        printf("%d ", arrNum[i]);
        i++;
    }

    return 0;
}