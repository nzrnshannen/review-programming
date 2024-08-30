// A program to compute the perimeter and area of a circle with a given radius

#include<stdio.h>
#define PI 3.1415

int main()
{
    float radius, perimeter, area;
    printf("Enter radius: ");
    scanf("%f", &radius);

    perimeter = 2 * PI * radius;
    area = PI * radius * radius;

    printf("\n---\nPerimeter = %.2f", perimeter);
    printf("\nArea = %.2f", area);
    
    return 0;
}