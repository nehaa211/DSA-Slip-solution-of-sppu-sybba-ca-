/* Selection Sort */
#include<stdio.h>
#include<conio.h>

#define M 10

void main()
{
  int ar[M],n,i,j,tmp,k;
  clrscr();

  printf("Enter the nos of elements : ");
  scanf("%d",&n);

  printf("Enter the elements :");
  for(i = 0 ; i < n ; i++)
  {
    scanf("%d",&ar[i]);
  }

  for(i = 0 ; i < n ; i ++)
  {
    for(j = i + 1 ; j < n ; j++)
    {
      printf("\n%d %d",ar[i],ar[j]);
      if(ar[i] > ar[j])
      {
	tmp = ar[i];
	ar[i] = ar[j];
	ar[j] = tmp;
      }
    }
    printf("\n");
    for(k = 0 ; k < n ; k++)
    {
      printf("%d ",ar[k]);
    }
  }

  printf("\nThe array is : ");
  for(i = 0 ; i < n ; i++)
  {
    printf("%d ",ar[i]);
  }

  getch();
}