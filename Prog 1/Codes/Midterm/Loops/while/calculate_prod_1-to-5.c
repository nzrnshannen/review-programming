/*

    A program that calculates the product of numbers from 1 to 5
    using a while loop.

*/

#include<stdio.h>

int main()
{
    int prod = 1; 
    int i=1;

    while(i<=5)
    {
        prod *= i;
        i++;
    }

    printf("\n===\nProduct = %d", prod);

    return 0;
}