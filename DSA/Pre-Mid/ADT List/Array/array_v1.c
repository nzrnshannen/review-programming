/*
    ADT LIST: ARRAY VERSION 1
    -> LIST is a structure containing an array and variable count
*/

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

//insertion
void insertAtBeginning(LIST *list, int elem);
void insertAtEnd(LIST *list, int elem);

//deletion
void deleteAtBeginning(LIST *list);
void deleteAtEnd(LIST *list);
void deleteFirstOccurrence(LIST *list, int elem);
void deleteAllOccurrences(LIST *list, int elem);

int main()
{
    LIST myList;
    initializeList(&myList);
    populateList(&myList);

    displayList(myList); 
    deleteAllOccurrences(&myList, 3);
    displayList(myList);
    return 0;
}

void initializeList(LIST *list)
{
    list->count = 0;
}

void populateList(LIST *list)
{
    //use insert___() functions here
    insertAtBeginning(list, 3);
    insertAtBeginning(list, 2);
    insertAtBeginning(list, 3);
    insertAtEnd(list, 10);
}

void displayList(LIST list)
{
    int x;

    printf("\n===\nLIST: ");
    for(x=0; x<list.count; x++)
    {
        printf("%d ", list.elem[x]);
    }

    printf("\n\n");
}

void insertAtBeginning(LIST *list, int elem)
{
    //Note: It is important to check if list is full or not before performing insertion
    if(list->count < SIZE)
    {
        int x;
        for(x=list->count; x>0; x--)
        {
            list->elem[x] = list->elem[x-1];
        }

        list->count++; //increment count by 1
        list->elem[x] = elem; //elem inserted now at index 0 (beginning)
    }
}

void insertAtEnd(LIST *list, int elem)
{
    //Note: It is important to check if list is full or not before performing insertion
    if(list->count < SIZE)
    {
        list->elem[list->count] = elem;
        list->count++; //increment count by 1
    }
}

void deleteAtBeginning(LIST *list)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if(list->count > 0)
    {
        int x;
        list->count--; //decrement count by 1

        for(x=0; x<list->count; x++)
        {
            list->elem[x] = list->elem[x+1];
        }

    }
}

void deleteAtEnd(LIST *list)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if(list->count > 0)
    {
        list->count--; //decrement count by 1
    }
}

void deleteFirstOccurrence(LIST *list, int elem)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if(list->count > 0)
    {
        int x, y;

        for(x=0; x < list->count && list->elem[x] != elem; x++){}

        if(list->elem[x] == elem)
        {
            list->count--; //decrement count by 1
            for(y = x; y < list->count; y++)
            {
                list->elem[y] = list->elem[y+1];
            }
        }
    }
}

void deleteAllOccurrences(LIST *list, int elem)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if(list->count > 0)
    {
        int x, y;
        for(x=0; x<list->count;)
        {
            if(list->elem[x] == elem)
            {
                list->count--; //decrement count by 1
                for(y=x; y<list->count; y++)
                {
                    list->elem[y] = list->elem[y+1]; //shift elements from right to left
                }
            }
            else
            {
                x++;
            } 
        }
    }
}