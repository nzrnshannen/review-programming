//using if(), elseif(), else

#include<stdio.h>
float simpleCalc(float, float);

int main()
{
    float num1, num2;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("\n===\nResult = %.2f", simpleCalc(num1, num2)); // you can also store the value returned by simpleCalc also like ==> float result = simpleCalc(num1, num2);

    return 0;    
}

float simpleCalc(float a, float b)
{
    int choice;
    float retval = 0;

    printf("\n==============\n[1] Add\n[2] Subtract\n[3] Multiply\n[4] Divide\n");
    printf("---\nChoice: ");
    scanf("%d", &choice);

    if(choice==1)
    {
        retval = a + b;
    }
    else if(choice==2)
    {
        retval = a - b; // or b - a (up to your liking)
    }
    else if(choice==3)
    {
        retval = a * b;
    }
    else if(choice == 4)
    {
        retval = a / b; // or b / a (up to your liking)
    }
    else
    {
        printf("\n\tInvalid input!\n"); // hence, the value to be returned is '0' because we initialized retval to 0 at first
        // mind that our return type for the function is 'float' so it should return something despite we got an invalid input
    }

    return retval;
}