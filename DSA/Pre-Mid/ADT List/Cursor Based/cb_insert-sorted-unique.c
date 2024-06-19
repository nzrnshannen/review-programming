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

//management operations
void initializeList(CLIST *head); //head set to -1 (equivalent to NULL)
void initializeVH(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int ndx);

void insert(CLIST *head, VirtualHeap *VH, char elem);
void display(CLIST head, VirtualHeap VH);
void populate(CLIST *head, VirtualHeap *VH);

int main()
{
    CLIST Cursor;
    VirtualHeap VH;

    initializeList(&Cursor);
    initializeVH(&VH);
    populate(&Cursor, &VH);
    display(Cursor, VH);

    return 0;
}

void initializeList(CLIST *head)
{
    *head = -1;
}

void initializeVH(VirtualHeap *VH)
{
    //version 2 of initializing the virtual heap
    VH->avail = SIZE-1;
    int x;
    for(x=VH->avail; x>=0; x--)
    {
        VH->Node[x].link = x-1;
    }
}

int allocSpace(VirtualHeap *VH)
{
    int retval = VH->avail;
    if(retval!=-1)
    {
        VH->avail = VH->Node[retval].link;
    }

    return retval;  
}

void deallocSpace(VirtualHeap *VH, int ndx)
{
    if (ndx>=0 && ndx<SIZE-1)
    {
        VH->Node[VH->avail].link = ndx; //acts like insertAtBeginning() 
        VH->avail = ndx;
    }
}


void insert(CLIST *head, VirtualHeap *VH, char elem)
{
    CLIST *trav;
    for(trav=head; *trav!=-1 && VH->Node[*trav].elem < elem; trav = &VH->Node[*trav].link){}

    if(*trav == -1 || elem != VH->Node[*trav].elem)
    {

        int ndx = allocSpace(VH);
        if(ndx!=-1)
        {
            VH->Node[ndx].elem = elem;
            VH->Node[ndx].link = *trav;
            *trav = ndx;
        }
    }
}

void display(CLIST head, VirtualHeap VH)
{
    printf("\nList: ");
    CLIST trav;

    for(trav=head; trav!=-1; trav = VH.Node[trav].link)
    {
        printf("%c ", VH.Node[trav].elem);
    }

    printf("\n\n");
}

void populate(CLIST *head, VirtualHeap *VH)
{
    insert(head, VH, 'A');
    insert(head, VH, 'A'); 
    insert(head, VH, 'Z');
    insert(head, VH, 'C');
    insert(head, VH, 'J');
    insert(head, VH, 'S');
    insert(head, VH, 'K'); //won't be included in the list
}