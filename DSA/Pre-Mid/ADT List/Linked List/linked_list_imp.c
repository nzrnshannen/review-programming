#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int elem;
    struct node *link;
}nodetype, *List;

/*
    Based on the structure above, in terms of accessing its members:

    If List trav, then trav->_____
    List trav is equivalent to nodeType* trav OR struct node* trav. 

    If List *trav, then (*trav)->_____
    List *trav is equivalent to nodeType** trav OR struct node** trav.
*/

//function prototypes
List initializeList(); //same functionality with void initializeList(List *list), the return type is just different
void populateList(List *list);
void displayList(List list);

//insertion
void insertAtBeginning(List *list, int elem);
void insertAtEnd(List *list, int elem);

//deletion
void deleteAtBeginning(List *list);
void deleteAtEnd(List *list);
void deleteFirstOccurrence(List *list, int elem);
void deleteAllOccurrences(List *list, int elem);

void clearFunc(List *list); //to free all nodes
int main()
{
    List myList;
    myList = initializeList();
    populateList(&myList);

    displayList(myList);
    deleteAllOccurrences(&myList, 3);
    displayList(myList);

    clearFunc(&myList);
    
    return 0;
}

List initializeList()
{
    List test;
    test = NULL;

    return test; //datatype of test is List;
    //we should return something that is of List datatype
}

void populateList(List *list)
{
    insertAtBeginning(list, 1);
    insertAtBeginning(list, 3);
    insertAtBeginning(list, 3);
    insertAtEnd(list, 5);
    insertAtEnd(list, 3);
}

void displayList(List list)
{
    printf("\n===\nLIST: ");

    List trav;
    for(trav=list; trav!=NULL; trav=trav->link)
    {
        printf("%d ", trav->elem);
    }

    printf("\n\n");
}

void insertAtBeginning(List *list, int elem)
{
    //Note: Always check if allocation is successful or not
    List newNode = (List)malloc(sizeof(nodetype));
    if(newNode!=NULL)
    {
        newNode->elem = elem;
        newNode->link = *list;
        *list = newNode;
    }
    
}

void insertAtEnd(List *list, int elem)
{
    //Note: Always check if allocation is successful or not
    List newNode = (List)malloc(sizeof(nodetype));
    if(newNode!=NULL)
    {
        newNode->elem = elem;
        newNode->link = NULL;

        List *trav;
        for(trav=list; *trav!=NULL; trav=&(*trav)->link){}
        *trav = newNode;
    }
}

void deleteAtBeginning(List *list)
{
    //Note: Always check if list is empty or not before performing deletion
    if(*list != NULL)
    {
        List temp;
        temp = *list;
        *list = temp->link;
        free(temp);
    }
}

void deleteAtEnd(List *list)
{
    if(*list != NULL)
    {
        List *trav;
        for(trav=list; (*trav)->link!=NULL; trav=&(*trav)->link){}

        List temp;
        temp  = *trav;
        *trav = NULL;

        free(temp);
    }
}

void deleteFirstOccurrence(List *list, int elem)
{
    if(*list!=NULL)
    {
        List *trav;
        for(trav=list; *trav!=NULL && (*trav)->elem!=elem; trav=&(*trav)->link){}

        if(*trav!=NULL)
        {
            List temp;
            temp = *trav;
            *trav = temp->link;

            free(temp);
        }
    }
}

void deleteAllOccurrences(List *list, int elem)
{
    if(*list!=NULL)
    {
        List *trav;

        for(trav=list; *trav!=NULL; )
        {
            if((*trav)->elem==elem)
            {
                List temp;
                temp = *trav;
                *trav = temp->link;
                free(temp);
            }
            else
            {
                trav=&(*trav)->link;
            }
        }
    }
}

void clearFunc(List *list)
{
    while(*list!=NULL)
    {
        List temp;
        temp = *list;
        *list = temp->link;
        free(temp);
    }
}