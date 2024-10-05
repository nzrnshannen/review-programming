/*
    Temp < 0 then Freezing weather
    Temp 0-9 then Very Cold weather
    Temp 10-19 then Cold weather
    Temp 20-29 then Normal in Temp
    Temp 30-39 then Its Hot
    Temp >=40 then Its Very Hot

*/

#include<stdio.h>
void tempCheck(int);

int main()
{
    int temp;
    printf("Enter temperature: ");
    scanf("%d", &temp);

    tempCheck(temp);
    
    return 0;
}   

void tempCheck(int temp)
{
// you can modify this code btw
// you can use switch statements (try converting this into a switch statement)
    if(temp < 0)
    {
        printf("\nFreezing weather");
    }
    else if(temp >=0 && temp <10)
    {
        printf("\nVery cold weather");
    }
    else if(temp >= 10 && temp < 20)
    {
        printf("\nCold weather");
    }
    else if(temp >= 20 && temp < 30)
    {
        printf("\nNormal");
    }
    else if(temp >= 30 && temp < 40)
    {
        printf("\nIt's hot");
    }
    else
    {
        printf("\nVery hot");
    }
}