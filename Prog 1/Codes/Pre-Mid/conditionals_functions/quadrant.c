/*
    To know more about quadrants: https://helpingwithmath.com/all-four-quadrants/
    
    In short,

    Quadrant 1 = x values are positive, y values are positive
    Quadrant 2 = x values are negative, y values are positive
    Quadrant 3 = x values are negative, y values are negative
    Quadrant 4 = x values are positive, y values are negative

*/

#include<stdio.h>
void quadrantNumber(int, int); // determines the quadrant number

int main()
{
    int x, y; // you can name anything that you like
    printf("Enter the x value: ");
    scanf("%d", &x);

    printf("Enter the y value: ");
    scanf("%d", &y);

    quadrantNumber(x, y);

    return 0;
}

void quadrantNumber(int x, int y)
{
    if(x > 0 && y > 0)
    {
        printf("\nQuadrant I\n");
    }
    else if(x < 0 && y > 0)
    {
        printf("\nQuadrant II\n");
    }
    else if(x < 0 && y < 0)
    {
        printf("\nQuadrant III\n");
    }
    else // you can also do (I don't recommend this): else if (x > 0 && y < 0)
    {
        printf("\nQuadrant IV\n"); 
    }
}