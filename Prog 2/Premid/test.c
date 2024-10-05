//pass by address/dereference/pass by reference

#include<stdio.h>

void testFunc(int *num) 
{
    *num = 10; //derefence --> change val
    printf("The num in testFunc is = %d\n", *num);
}

int main()
{
    int num;
    num = 5;
    printf("The num in main is = %d\n", num);
    testFunc(&num);
    printf("The num in main is = %d", num);
}

/*
    int a = 5;
    int *ptr = &a; 
    .
    .


    int **dptr = &ptr;
    .
    .
    int **dptr;
    dptr = &ptr;
*/
#include<stdio.h>
int main()
{
    char str[] = "Hello";
    char *ptr = str;
    printf("%c", *(ptr + 1));

    int arr[5] = {1, 2, 3, 4, 5};

    
}