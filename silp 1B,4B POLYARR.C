/* Polynomial Operations using Array of Structures */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define M 10

typedef struct
{
  int coeff;
  int exp;
}POLY;

int readPoly(POLY p[]);
void displayPoly(POLY p[],int);
int evalPoly(POLY p[],int);
void addPoly(POLY p1[],POLY p2[],int,int);
void multPoly(POLY p1[],POLY p2[],int,int);

int main()
{
  POLY p1[M],p2[M];
  int n1,n2,ans;
  int ch;

  do
  {

    printf("\n\n\t\t***MENU***");
    printf("\n\t#1 READ POLY 1");
    printf("\n\t#2 DISPLAY POLY 1");
    printf("\n\t#3 EVALUATE POLY 1");
    printf("\n\t#4 READ POLY 2");
    printf("\n\t#5 DISPLAY POLY 2");
    printf("\n\t#6 EVALUATE POLY 2");
    printf("\n\t#7 ADD TWO POLY");
    printf("\n\t#8 MULTIPLY TWO POLY");
    printf("\n\t#9 EXIT");
    printf("\n\tENTER YOUR CHOICE : ");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:
		n1 = readPoly(p1);
		break;
      case 2:
		displayPoly(p1,n1);
		break;
      case 3:
		ans = evalPoly(p1,n1);
		printf("\n\tANS : %d",ans);
		break;
      case 4:
		n2 = readPoly(p2);
		break;
      case 5:
		displayPoly(p2,n2);
		break;
      case 6:
		ans = evalPoly(p2,n2);
		printf("\n\tANS : %d",ans);
		break;
      case 7:
		addPoly(p1,p2,n1,n2);
		break;
      case 8:
		multPoly(p1,p2,n1,n2);
		break;
      case 9:
		printf("\n\tTHANK YOU....");
		break;
      default:
		printf("\n\tWRONG CHOICE....");
    }
    getch();
  }while(ch != 9);
}
/*-------------------------------------------------------------------*/
int readPoly(POLY p[])
{
  int n,i,j;
  printf("\n\tENTER THE NOS OF TERMS : ");
  scanf("%d",&n);

  printf("\n\tENTER THE POLYNOMIAL TERMS : ");
  for(i = 0 ; i < n ; i++)
  {
    printf("\nCoeff : ");
    scanf("%d",&p[i].coeff);
    printf("\nExp : ");
    scanf("%d",&p[i].exp);
  }
  return n;
}
/*-------------------------------------------------------------------*/
void displayPoly(POLY p[],int n)
{
  int i;

  printf("\n\tPoly : ");
  for(i = 0 ; i < n ; i++)
  {
    printf("%d x^%d + ",p[i].coeff,p[i].exp);
  }
}
/*-------------------------------------------------------------------*/
void addPoly(POLY p1[],POLY p2[],int n1,int n2)
{
  POLY p3[M];
  int i,j,k=0;

  i = 0 ; j = 0;
  while(i < n1 && j < n2)
  {
    if(p1[i].exp > p2[j].exp)
    {
      p3[k] = p1[i];
      i++;
      k++;
      continue;
    }
    if(p1[i].exp < p2[j].exp)
    {
      p3[k] = p2[j];
      j++;
      k++;
      continue;
    }
    if(p1[i].exp == p2[j].exp)
    {
      p3[k].coeff = p1[i].coeff + p2[j].coeff;
      p3[k].exp = p1[i].exp;
      i++;
      j++;
      k++;
    }
  };

  while(i < n1)
  {
    p3[k] = p1[i];
    i++;
    k++;
  };
  while(j < n2)
  {
    p3[k] = p2[j];
    j++;
    k++;
  };

  displayPoly(p3,k);
}
/*-------------------------------------------------------------------*/
void multPoly(POLY p1[],POLY p2[],int n1,int n2)
{
  POLY p3[M];
  int i,j,k,l;
  int flag,c,e;

  k = 0;
  for(i = 0 ; i < n1 ; i++)
  {
    for(j = 0 ; j < n2 ; j++)
    {
      c = p1[i].coeff * p2[j].coeff;
      e = p1[i].exp + p2[j].exp;
      flag = 0;
      for(l = 0 ; l < k ; l++)
      {
	if(p3[l].exp == e)
	{
	  p3[l].coeff = p3[l].coeff + c;
	  flag = 1;
	  break;
	}
      }
      if(flag == 0)
      {
	p3[k].coeff = c;
	p3[k].exp = e;
	k++;
      }
    }
  }

  displayPoly(p3,k);
}
/*-------------------------------------------------------------------*/
int evalPoly(POLY p[],int n)
{
  int x,ans,i;

  printf("\n\tENTER THE VALUE OF X : ");
  scanf("%d",&x);

  ans = 0;
  for(i = 0 ; i < n ; i++)
  {
    ans = ans + p[i].coeff * pow(x,p[i].exp);
  }
  return ans;
}
/*-------------------------------------------------------------------*/
