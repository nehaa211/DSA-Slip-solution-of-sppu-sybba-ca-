//my code
#include <stdio.h>
#include <stdlib.h>
struct stnode
{
    int data;
    struct node * next,*prev;
}stnode;


void main()
{
    struct stnode *last,*st,*t;
    int i=0,j,k,n;
    printf("Enter no of nodes");
    scanf("%d",&n);

    for(i; i<n; i++)
    {
        t=(struct stnode*)malloc(sizeof(stnode));
        t->next=NULL;
        t->prev=NULL;
        printf("\nEnter data");
        scanf("%d",&t->data);
        if(i==0)
        {
            st=t;
           // last=t;
        }
        else
        {
            t->prev=last;
            last->next=t;

        }
        last=t;
        last->next=st;
        st->prev=last;

    }


    //for printing
    t=st;
    do
    {
        printf("\n%d",t->data);
        t=t->next;
    }while(t!=st);

}


//--------------------------------------------------------------------




//Write a ‘C’ program to create Circularly Doubly Linked list and display it
/*#include <stdio.h>
#include <stdlib.h>
struct node {
int num;
struct node * nextptr;
}*stnode;
void ClListcreation(int n)
{
int i, num;
struct node *preptr, *newnode;
if(n >= 1)
{
stnode = (struct node *)malloc(sizeof(struct node));
printf(" Input data for node 1 : ");
scanf("%d", &num);
stnode->num = num;
stnode->nextptr = NULL;
preptr = stnode;
for(i=2; i<=n; i++)
{
newnode = (struct node *)malloc(sizeof(struct node));
printf(" Input data for node %d : ", i);
scanf("%d", &num);
newnode->num = num;
newnode->nextptr = NULL; // next address of new node set as NULL
preptr->nextptr = newnode; // previous node is linking with new node
preptr = newnode; // previous node is advanced
}
preptr->nextptr = stnode; //last node is linking with first node
}
}
void displayClList()
{
struct node *tmp;
int n = 1;
if(stnode == NULL)
{
printf(" No data found in the List yet.");
}
else
{
tmp = stnode;
printf("\n\n Data entered in the list are :\n");
do {
printf(" Data %d = %d\n", n, tmp->num);
tmp = tmp->nextptr;
n++;
}while(tmp != stnode);
}
}
void main()
{
int n;
stnode = NULL;
printf("\n\n Circular Linked List \n");
printf("-----------------------------------------------------------------------\n");
printf(" Input the number of nodes : ");
scanf("%d", &n);
ClListcreation(n);
displayClList();
}
*/
