/*
    CURSOR-BASED IMPLEMENTATION
    - uses array nodes/cells but treated as a linked list
    - can be implemented ising any of the 4 array versions

    Note: Make sure to familiarize yourself with linked list.
*/

#include<stdio.h>
#define SIZE 5

typedef struct{
    char elem;
    int link;
}nodeType;

typedef struct{
    nodeType Node[SIZE];
    int avail;
}VirtualHeap;

typedef int CLIST;
/*
    When we say CLIST head, it's just equivalent to --> int head;
*/

//management operations
CLIST initializeList(); //the head set to -1 (equivalent to NULL); same functionality with void initializeList(CLIST* Clist), the return type and no. of parameters are just different
void initializeVH(VirtualHeap *VH); //links all cells in the array; stores available node in avail 
int allocSpace(VirtualHeap *VH); //acts like malloc(), returns index; acts like deleteAtBeginning() in linked list
void deallocSpace(VirtualHeap *VH, int ndx); //acts like free(), similar to insertAtBeginning() in linked list

//insertion 
void insertAtBeginning(CLIST *head, VirtualHeap *VH, char elem);
void insertAtEnd(CLIST *head, VirtualHeap *VH, char elem);

//deletion
void deleteAtBeginning(CLIST *head, VirtualHeap *VH);
void deleteAtEnd(CLIST *head, VirtualHeap *VH);
void deleteFirstOccurrence(CLIST *head, VirtualHeap *VH, char elem);
void deleteAllOccurrences(CLIST *head, VirtualHeap *VH, char elem);

void populateList(CLIST *head, VirtualHeap *VH);
void displayList(CLIST head, VirtualHeap VH);


int main()
{
    CLIST CB;
    VirtualHeap VH;

    CB = initializeList();
    initializeVH(&VH);

    displayList(CB, VH);
    populateList(&CB, &VH);

    displayList(CB, VH);

    deleteAllOccurrences(&CB, &VH, 3);

    displayList(CB, VH);
    return 0;
}
CLIST initializeList()
{
    return -1;
}

void initializeVH(VirtualHeap *VH)
{

    //Version 2 of initializing the virtual heap
    VH->avail = SIZE-1;
    int x;
    for(x=VH->avail; x>=0; x--)
    {
        VH->Node[x].link = x-1;
    }

/*

Version 1 of intiializing the virtual heap

    VH->avail = 0;
    int x;
    int totalSize = SIZE-1;

    for(x=0; x<totalSize; x++)
    {
        VH->Node[x].link = x+1;
    }

    VH->Node[x].link = -1;


--> this code can still be modified :)

*/
}

int allocSpace(VirtualHeap *VH)
{
    int retval = VH->avail; //retval holds the index of available space

    //Note: It is important to check if there's still an available space in the virtual heap
    if(retval!=-1)
    {
        VH->avail = VH->Node[retval].link; //acts like deleteAtBeginning() in linked list
    }

    return retval;
}

void deallocSpace(VirtualHeap *VH, int ndx)
{
    //Note: It is important to check if the ndx passed is 0 - (SIZE-1)
    if(ndx>=0 && ndx<SIZE)
    {
        VH->Node[VH->avail].link = ndx; //acts like insertAtBeginning() in linked list
        VH->avail = ndx;
    }
}

void insertAtBeginning(CLIST *head, VirtualHeap *VH, char elem)
{
    int ndx = allocSpace(VH);

    //Note: Always check if there's an available space in the virtual heap
    if(ndx!=-1)
    {
        VH->Node[ndx].elem = elem;
        VH->Node[ndx].link = *head;
        *head = ndx;
    }
}

void insertAtEnd(CLIST *head, VirtualHeap *VH, char elem)
{
    int ndx = allocSpace(VH);

    //Note: Always check if there's an available space in the virtual heap
    if(ndx!=-1)
    {
        CLIST *trav;
        for(trav=head; *trav!=-1; trav=&VH->Node[*trav].link){}

        VH->Node[ndx].elem = elem;
        VH->Node[ndx].link = -1;
        *trav = ndx;
    }
}

void deleteAtBeginning(CLIST *head, VirtualHeap *VH)
{
    //Note: Always check if the list is empty or not before performing deletion
    if(*head!=-1)
    {
        int ndx = *head;
        *head = VH->Node[ndx].link;
        deallocSpace(VH, ndx);
    }
}

void deleteAtEnd(CLIST *head, VirtualHeap *VH)
{
    //Note: Always check if the list is empty or not before performing deletion
    if(*head!=-1)
    {
        int ndx;
        CLIST *trav;

        for(trav=head; VH->Node[*trav].link!=-1; trav=&VH->Node[*trav].link){}

        ndx = *trav;
        *trav = -1;
        deallocSpace(VH, ndx);
    }
}

void deleteFirstOccurrence(CLIST *head, VirtualHeap *VH, char elem)
{
    //Note: Always check if the list is empty or not before performign deletion
    if(*head!=-1)
    {
        CLIST *trav;

        for(trav=head; *trav!=-1 && VH->Node[*trav].elem!= elem; trav=&VH->Node[*trav].link){}

        //if *trav is not equal to -1, it means we found the elem
        if(*trav!=-1)
        {
            int ndx;
            ndx = *trav;

            *trav = VH->Node[ndx].link;
            deallocSpace(VH, ndx);
        }
    }
}

void deleteAllOccurrences(CLIST *head, VirtualHeap *VH, char elem)
{
    //Note: Always check if the list is empty or not before performing deletion
    if(*head!=-1)
    {
        CLIST *trav;
        
        for(trav=head; *trav!=-1; )
        {
            if(VH->Node[*trav].elem==elem)
            {
                int ndx;
                ndx = *trav;
                
                *trav = VH->Node[ndx].link;
                deallocSpace(VH, ndx);
            }
            else
            {
                trav=&VH->Node[*trav].link;
            }
        }
    }
}

void populateList(CLIST *head, VirtualHeap *VH)
{
    insertAtBeginning(head, VH, 1);
    insertAtBeginning(head, VH, 3);
    insertAtBeginning(head, VH, 3);
    insertAtEnd(head, VH, 4);
    insertAtEnd(head, VH, 3);

    insertAtBeginning(head, VH, 100); //this won't be included in the list
}

void displayList(CLIST head, VirtualHeap VH)
{
    printf("\n====\nLIST: ");
    CLIST trav;
    for(trav=head; trav!=-1; trav=VH.Node[trav].link)
    {
        printf("%d ", VH.Node[trav].elem);
    }

    printf("\n\n");
}