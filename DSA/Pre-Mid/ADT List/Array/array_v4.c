/*
    ADT LIST: ARRAY VERSION 4
    -> LIST is a pointer to a structure containing variable count and a pointer to the first element
    of a dynamically allocated array
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct{
    int *elemPtr;
    int count;
}nodeType, *LIST;

//Note: When we say LIST myList, it's equivalent to nodeType* myList
        //By that, we access the members of the structure using -> : (mylist->____)


/*
    Based on the given structure above, we can access members,

    if LIST example, then example-> ______
    LIST example is the equivalent of nodeType* example.

    if LIST *example, then (*example)->_____  
    LIST *example is the equivalent of nodeType** example.
*/

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
    nodeType test;
    LIST myList = &test;

    initializeList(&myList);
    populateList(&myList);
    displayList(myList);

    deleteAllOccurrences(&myList, 3);
    displayList(myList);
    free(myList->elemPtr);
    return 0;
}

void initializeList(LIST *list)
{
    (*list)->count = 0;
    (*list)->elemPtr = (int*)malloc(sizeof(int) * SIZE);//we need an array of datatype int
    
    //Note: When doing dynamic allocation, always check if it's successful or not
    if((*list)->elemPtr == NULL)
    {
        perror("Memory allocation failure!");
        exit(1);
    }
}

void populateList(LIST *list)
{
    insertAtBeginning(list, 1);
    insertAtBeginning(list, 3);
    insertAtBeginning(list, 3);
    insertAtEnd(list, 5);
    insertAtEnd(list, 3);

    insertAtEnd(list, 99); //this won't be included in the list
}

void displayList(LIST list)
{
    int x;

    printf("\n====\nLIST: ");
    for(x=0; x<list->count; x++)
    {
        printf("%d ", list->elemPtr[x]);
    }

    printf("\n\n");
}

void insertAtBeginning(LIST *list, int elem)
{
    //Note: It is important to check if list is full or not before performing insertion
    if((*list)->count < SIZE)
    {
        int x;
        for(x=(*list)->count; x>0; x--)
        {
            (*list)->elemPtr[x] = (*list)->elemPtr[x-1];
        }

        (*list)->count++; //increment count by 1
        (*list)->elemPtr[x] = elem; //elem inserted now at index 0 (beginning)
    }
}

void insertAtEnd(LIST *list, int elem)
{
    //Note: It is important to check if list is full or not before performing insertion
    if((*list)->count < SIZE)
    {
        (*list)->elemPtr[(*list)->count] = elem;
        (*list)->count++; //increment count by 1
    }
}

void deleteAtBeginning(LIST *list)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if((*list)->count > 0)
    {
        int x;
        (*list)->count--; //decrement count by 1
        
        for(x=0; x<(*list)->count; x++)
        {
            (*list)->elemPtr[x] = (*list)->elemPtr[x+1];
        }
    }
}

void deleteAtEnd(LIST *list)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if((*list)->count > 0)
    {
        (*list)->count--; //decrement count by 1
    }
}

void deleteFirstOccurrence(LIST *list, int elem)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if((*list)->count > 0)
    {
        int x, y;

        for(x=0; x < (*list)->count && (*list)->elemPtr[x] != elem; x++){}

        if((*list)->elemPtr[x] == elem)
        {
            (*list)->count--; //decrement count by 1
            for(y = x; y < (*list)->count; y++)
            {
                (*list)->elemPtr[y] = (*list)->elemPtr[y+1];
            }
        }
    }
}

void deleteAllOccurrences(LIST *list, int elem)
{
    //Note: It is important to check if list is EMPTY or not before performing deletion
    if((*list)->count > 0)
    {
        int x, y;
        for(x=0; x < (*list)->count;)
        {
            if((*list)->elemPtr[x] == elem)
            {
                (*list)->count--; //decrement count by 1
                for(y = x; y<(*list)->count; y++)
                {
                    (*list)->elemPtr[y] = (*list)->elemPtr[y+1]; //shift elements from right to left
                }
            }
            else
            {
                x++;
            }
        }
    }
}