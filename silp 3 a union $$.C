//my code
// union linked list
#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
} SNODE;

struct NODE *createList();
//void displayList(NODE *);
//NODE *deleteNode(NODE *st);
//NODE *insertNode(NODE *st);

void main()
{
    struct NODE *st1,*st2;
    int a[100],i=0;
    st1=createList();
    st2=createList();
    while(st1!=NULL)
    {
        a[i]=st1->data;
        st1=st1->next;
        i++;
    }

    for(k=0; st!=NULL; i++)
       {
           if(st2->data!=a[i])
        {
            a[i]=st2->data;
        }
        st2=st2->next;

       }





}

struct NODE *createList()
{
    int i=0;
    char c;
    struct NODE *t,*last,*st;
    st=(struct SNODE*)malloc(sizeof(SNODE));
    st->next=NULL;
    printf("\nEnter data");
    scanf("%d",&st->data);
    last=st;
    printf("\n Do you want to add more nodes:");
    c=getche();
    if(c=='y'||c=='Y')
    {
        t=(struct SNODE*)malloc(sizeof(SNODE));
        t->next=NULL;
        printf("\nEnter data");
        scanf("%d",&t->data);
        last=t;
        printf("\n Do you want to add more nodes:");
        c=getche();

    }
    return st;

}










//=======================================

/* Union of two Arrays */

#include<stdio.h>
#include<conio.h>

#define M 10

int main()
{
  int ar1[M],ar2[M],ar3[M];
  int n1,n2,i,j,k;


  printf("Enter the nos of elements in the first array : ");
  scanf("%d",&n1);

  printf("Enter the elements of the first array : ");
  for(i = 0 ; i < n1 ; i++)
  {
    scanf("%d",&ar1[i]);
  }

  printf("Enter the nos of elements in the second array : ");
  scanf("%d",&n2);

  printf("Enter the elements of the second array : ");
  for(i = 0 ; i < n2 ; i++)
  {
    scanf("%d",&ar2[i]);
  }

  printf("\nArray 1 : ");
  for(i = 0 ; i < n1 ; i++)
  {
    printf("%d ",ar1[i]);
  }

  printf("\nArray 2 : ");
  for(i = 0 ; i < n2 ; i++)
  {
    printf("%d ",ar2[i]);
  }

  for(i = 0 ; i < n1 ; i++)
  {
    ar3[i] = ar1[i];
  }

  k = i;
  for(i = 0 ; i < n2 ; i++)
  {
    for(j = 0 ; j < n1 ; j++)
    {
      if(ar1[j] == ar2[i])
      {
	break;
      }
    }
    if(j == n1)
    {
      ar3[k] = ar2[i];
      k++;
    }
  }

  printf("\nUnion of the two array : ");
  for(i = 0 ; i < k ; i++)
  {
    printf("%d ",ar3[i]);
  }
  getch();
}
