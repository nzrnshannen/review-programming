#include<stdio.h>
int calculateStringLength(char *str);

int main()
{
    char str[] = "Shannen";
    
    printf("String = %s\n", str);
    printf("Length = %d", calculateStringLength(str));
    return 0;
}

int calculateStringLength(char *str)
{
    int ctr=0;
    char *ptr = str;

    while(*ptr!='\0')
    {
        ctr++;
        ptr++;
    }

    return ctr;
}