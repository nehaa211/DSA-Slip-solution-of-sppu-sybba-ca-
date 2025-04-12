/* Link List Operation */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define M 10

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;
/*-------------------------------------------------------------------*/
NODE *createList();
void displayList(NODE *);
NODE *deleteNode(NODE *st);
void odddisplayList(NODE *);
 NODE *insertNode(NODE *st);
/*-------------------------------------------------------------------*/
int main()
{
    NODE *first;
    int ch;

    do
    {
        printf("\n\n\t\t***MENU***");
        printf("\n\t#1 CREATE LIST");
        printf("\n\t#2 DISPLAY LIST");
        printf("\n\t#3 INSERT NODE");
        printf("\n\t#4 DELETE NODE");
        printf("\n\t#5 EXIT");
        printf("\n#6 odd");
        printf("\n\tENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            first = createList();
            printf("\n\tLIST CREATED.....");
            break;
        case 2:
            displayList(first);
            printf("\n\tLIST DISPLAYED.....");
            break;
        case 3:
            first = insertNode(first);
            printf("\n\tNODE INSERTED.....");
            break;
        case 4:
            first = deleteNode(first);
            printf("\n\tNODE DELETED....");
            break;
        case 5:
            printf("\n\tTHANK YOU....");
            break;
        case 6:
 odddisplayList(first);

        default:
            printf("\n\tWRONG CHOICE.....");
        }
        getch();
    }
    while(ch != 5);
}
/*-------------------------------------------------------------------*/
NODE *createList()
{
    NODE *start,*last,*temp;
    char ch;

    start = (NODE *)malloc(sizeof(NODE));
    printf("\n\tEnter the data : ");
    scanf("%d",&start->data);
    start->next = NULL;
    start->prev = NULL;
    last = start;

    printf("\n\tDo u want to continue : ");
    ch = getche();

    while(ch == 'y' || ch == 'Y')
    {
        temp = (NODE *)malloc(sizeof(NODE));
        printf("\n\tEnter the data : ");
        scanf("%d",&temp->data);
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp;

        printf("\n\tDo u want to continue : ");
        ch = getche();
    };

    return start;
}
/*-------------------------------------------------------------------*/
void displayList(NODE *st)
{
    while(st != NULL)
    {
        printf(" %d ",st->data);
        st = st->next;
    };
}
//-------------------------------------------------
void odddisplayList(NODE *st)
  {while(st != NULL)
            {
               if(st->data%2==1)
               {
                    printf(" %d ",st->data);

               }
                               st = st->next;
            };
  }
/*-------------------------------------------------------------------*/
NODE *insertNode(NODE *st)
{
    NODE *temp,*head = st;
    char ch;
    int d;

    temp = (NODE *)malloc(sizeof(NODE));
    printf("\n\tEnter the data to be inserted : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    printf("\n\tDo u want to insert at start or else where (y/n): ");
    ch = getche();

    if(ch == 'y' || ch == 'Y')
    {
        temp->next = st;
        st->prev = temp;
        st = temp;
        return st;
    }
    else
    {
        printf("\n\tEnter the data after which u want to insert node : ");
        scanf("%d",&d);
        while(st != NULL)
        {
            if(st->data == d)
            {
                temp->next = st->next;
                st->next = temp;
                temp->prev = st;
                temp->next->prev = temp;
                break;
            }
            else
            {
                st = st->next;
            }
        }
        return head;
    }
}
/*-------------------------------------------------------------------*/
NODE *deleteNode(NODE *st)
{
    NODE *temp,*st1,*head = st;
    int d;

    printf("\n\tEnter the data to be deleted : ");
    scanf("%d",&d);

    if(st->data == d)
    {
        temp = st;
        st = st->next;
        free(temp);
        st->prev = NULL;
        return st;
    }
    else
    {
        st1 = st->next;
        while(st1 != NULL)
        {
            if(st1->data == d)
            {
                st->next = st1->next;
                st1->next->prev = st;
                free(st1);
                break;
            }
            else
            {
                st = st->next;
                st1 = st1->next;
            }
        };
    }
    return head;
}
/*-------------------------------------------------------------------*/
