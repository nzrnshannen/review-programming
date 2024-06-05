#include<stdio.h>
#define SIZE 5

typedef struct{
    int elem[SIZE];
    int count;
}LIST;

//function prototypes
void initializeList(LIST *list);
void populateList(LIST *list);
void displayList(LIST list);
void insert(LIST *list, int elem); //insert sorted & unique

int main()
{
    LIST myList;
    initializeList(&myList);
    displayList(myList);

    populateList(&myList);
    displayList(myList);
    return 0;
}
void initializeList(LIST *list)
{
    list->count = 0;
}

void populateList(LIST *list)
{
    insert(list, 21);
    insert(list, 5);
    insert(list, 5);
    insert(list, 1);
    insert(list, 19);
    insert(list, 7);

    insert(list, 100); //this won't be included in the list
}

void displayList(LIST list)
{
    printf("\n====\nLIST: ");
    int x;
    
    for(x=0; x<list.count; x++)
    {
        printf("%d ", list.elem[x]);
    }

    printf("\n\n");
}
void insert(LIST *list, int elem)
{
    if(list->count < SIZE) 
    {
        int x, y;
        for(x=0; x < list->count && list->elem[x] < elem; x++){}

        if(list->elem[x] != elem)
        {
            for(y=list->count; y>x; y--)
            {
                list->elem[y] = list->elem[y-1];
            }

            list->elem[y] = elem;
            list->count++;
        }
    }
}

