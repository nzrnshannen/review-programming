#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char elem;
    struct node *link;
}nodeType, *List;

void initializeList(List *list);
void populateList(List *list);
void displayList(List list);
void insert(List *list, char elem);
void clearFunc(List *list);


int main()
{
    List myList;
    initializeList(&myList);
    populateList(&myList);
    displayList(myList);

    clearFunc(&myList);
    return 0;
}

void initializeList(List *list)
{
    *list = NULL;
}

void populateList(List *list)
{
    insert(list, 3);
    insert(list, 4);
    insert(list, -1);
    insert(list, 10);
    insert(list, 7);
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

void insert(List* list, char elem)
{
    List *trav;
    for(trav=list; *trav!=NULL && (*trav)->elem < elem; trav=&(*trav)->link){}

    if(*trav==NULL || (*trav)->elem != elem)
    {
        List newNode = (List)malloc(sizeof(nodeType));
        if(newNode!=NULL)
        {
            newNode->elem = elem;
            newNode->link = *trav;
            *trav = newNode;
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