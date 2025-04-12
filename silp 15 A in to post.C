/* Infix to Postfix */
#include<stdio.h>
#include<conio.h>
#include<string.h>

#define M 10

void push(char);
char pop();
int instackp();
int incomingp(char);

char ch,stack[M];
int top = 0;

void main()
{
  char inf[M],post[M];
  int i,k=0;
  int isp,icp;
  clrscr();

  printf("Enter the Infix expression : ");
  scanf("%s",&inf);

  for(i = 0 ; i < strlen(inf) ; i++)
  {
    if(inf[i] != '+' && inf[i] != '-' && inf[i] != '*' && inf[i] != '/')
    {
      if(inf[i] != '(' && inf[i] != ')')
      {
	post[k] = inf[i];
	k++;
      }
    } /* Operand */

    if(inf[i] == '(')
    {
      push('(');
    } /* '(' */

    if(inf[i] == ')')
    {
      ch = pop();
      while(ch != '(')
      {
	post[k] = ch;
	k++;
	ch = pop();
      };
    } /* ')' */

    if(inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/')
    {
      if(top == 0)
      {
	push(inf[i]);
	continue;
      }
      isp = instackp();
      icp = incomingp(inf[i]);
      while(isp > icp)
      {
	post[k] = pop();
	k++;
	isp = instackp();
	icp = incomingp(inf[i]);
      }

      if(icp > isp)
      {
	push(inf[i]);
      }
    }
  }

  while(top > 0)
  {
    post[k] = pop();
    k++;
  };
  stack[k] = '\0';
  printf("Postfix Expr : %s",post);
  getch();
}
/*-------------------------------------------------------------------*/
void push(char ch)
{
  if(top == M)
  {
    printf("\n\n\tStack is Full...");
    return;
  }
  else
  {
    stack[top] = ch;
    top++;
  }
}
/*-------------------------------------------------------------------*/
char pop()
{
  if(top == 0)
  {
    printf("\n\n\tStack is empty...");
    return 0;
  }
  else
  {
     top--;
     return stack[top];
  }
}
/*-------------------------------------------------------------------*/
int instackp()
{
  char op;

  op = stack[top - 1];

  switch(op)
  {
    case '+':
	return 2;
    case '-':
	return 2;
    case '*':
	return 4;
    case '/':
	return 4;
  }
}
/*-------------------------------------------------------------------*/
int incomingp(char ch)
{
  switch(ch)
  {
    case '+':
	return 1;
    case '-':
	return 1;
    case '*':
	return 3;
    case '/':
	return 3;

  }
}
/*-------------------------------------------------------------------*/