/* STACK USING LINK LIST */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define M 3

typedef struct node
{
  int data;
  struct node *next;
}NODE;

NODE *top = NULL,*stk;

void push(int);
int pop();
void display();

void main()
{
  int ch,data;
  do
  {
    clrscr();
    printf("\n\n\t\t***MENU***");
    printf("\n\t#1 Push");
    printf("\n\t#2 Pop");
    printf("\n\t#3 Display");
    printf("\n\t#4 Exit");
    printf("\n\n\tEnter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:
		printf("\n\tEnter the data : ");
		scanf("%d",&data);
		push(data);
		break;
      case 2:
		data = pop();
		if(data != -99)
		{
		  printf("\n\tThe Popped data is : %d",data);
		}
		else
		{
		  printf("\n\tStack is empty...");
		}
		break;
      case 3:
		printf("\n\tList of nos in stack...");
		display();
		break;
      case 4:
		printf("\n\tThank You...");
		break;
      default:
		printf("\n\tYou have entered a wrong choice...");
    }
    getch();
  }while(ch != 4);
}
/*-------------------------------------------------------------------*/
void push(int data)
{
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->data = data;
  temp->next = NULL;

  if(top == NULL)
  {
    top = temp;
    stk = temp;
  }
  else
  {
    top->next = temp;
    top = temp;
  }
}
/*-------------------------------------------------------------------*/
int pop()
{
  NODE *t,*t1 = top;
  int d;

  if(top == NULL)
  {
    return -99;
  }

  if(top == stk)
  {
    d = top->data;
    free(top);
    top = NULL;
    return d;
  }

  t = stk;
  while(t->next != top)
  {
    t = t->next;
  };

  d = top->data;
  top = t;
  top->next = NULL;
  free(t1);
  return d;
}
/*-------------------------------------------------------------------*/
void display()
{
  NODE *t = stk;

  while(t != NULL)
  {
    printf("%d ",t->data);
    t = t->next;
  }
}
/*-------------------------------------------------------------------*/