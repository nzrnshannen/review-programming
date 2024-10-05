/*

For conversionType:
    'C' for Celsius to Fahrenheit
    'F' for Fahrenheit to Celsius


*/

#include<stdio.h>
void convertTemperature(float, char);

int main()
{
    float temp;
    char conversionType;
    
    printf("Enter temperature: ");
    scanf("%f", &temp);

    printf("Enter conversion type [C/F]: ");
    scanf(" %c", &conversionType);

    convertTemperature(temp, conversionType);

    return 0;
}

void convertTemperature(float temp, char conversionType)
{
    float newtemp = 0;

    if(conversionType=='C' || conversionType=='c')
    {
        newtemp = (temp * 9/5) + 32;
        printf("\nCelsius [%.2f] => Fahrenheit [%.2f]", temp, newtemp);
    }
    else if(conversionType=='F' || conversionType == 'f')
    {
        newtemp = (temp - 32) * 5/9;
        printf("\nFahrenheit [%.2f] => Celsius [%.2f]", temp, newtemp);
    }
    else
    {
        printf("Invalid conversion type.\n");
    }
}