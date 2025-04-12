/* Bubble Sort */
#include<stdio.h>
#include<conio.h>

#define M 10

void bubbleSort(int ar[],int);

void main()
{
  int ar[M],n,i;
  clrscr();

  printf("Enter the nos of elements : ");
  scanf("%d",&n);

  printf("Enter the elements :");
  for(i = 0 ; i < n ; i++)
  {
    scanf("%d",&ar[i]);
  }

  bubbleSort(ar,n);

  printf("\nThe array is : ");
  for(i = 0 ; i < n ; i++)
  {
    printf("%d ",ar[i]);
  }

  getch();
}
/*-------------------------------------------------------------------*/
void bubbleSort(int ar[],int n)
{
  int i,j,tmp;

  for(i = 0 ; i < n ; i++)
  {
    for(j = 0 ; j < n - i - 1 ; j++)
    {
      printf("%d %d\n",ar[j],ar[j+1]);
      if(ar[j] > ar[j+1])
      {
	tmp = ar[j];
	ar[j] = ar[j+1];
	ar[j+1] = tmp;
      }
    }
    for(j = 0 ; j < n ; j++)
    {
      printf("%d ",ar[j]);
    }
    printf("\n");
    getch();
  }
}
/*-------------------------------------------------------------------*/

