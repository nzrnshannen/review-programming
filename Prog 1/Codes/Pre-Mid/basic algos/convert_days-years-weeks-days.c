// A program to convert specified days into years, weeks, and days
// Note: Ignore leap year

#include<stdio.h>

int main()
{
    int num_of_days, years, weeks, days;
    // num_of_days for user input

    printf("Enter number of days:  ");
    scanf("%d", &num_of_days);
    
    // Conversion
    years = num_of_days % 365;
    weeks = (num_of_days % 365)/7;
    days = num_of_days - ((years * 365) + (weeks * 7));

    printf("\n---\nYears = %d\nWeeks: %d\nDays: %d\n", years, weeks, days);
    return 0;
}