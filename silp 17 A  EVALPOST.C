/* Evaluation of Postfix Expression */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

#define M 50

void push(int);
int pop();
void evalPost(char post[M]);

int stack[M];
int top = 0;

int main()
{
  char post[M];


  printf("Enter the Postfix expression : ");
  scanf("%s",&post);

  evalPost(post);
  getch();
}
/*-------------------------------------------------------------------*/
void push(int ch)
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
int pop()
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
void evalPost(char inf[M])
{
  int i,p1,p2,val,res;

  for(i = 0 ; inf[i] != '\0' ; i++)
  {
    if(inf[i] != '+' && inf[i] != '-' && inf[i] != '*' && inf[i] != '/' && inf[i] != '^')
    {
      printf("Enter the value of %c : ",inf[i]);
      scanf("%d",&val);
      push(val);
    }
    else
    {
      p1 = pop();
      p2 = pop();
      switch(inf[i])
      {
	case '+':
		res = p2 + p1;
		break;
	case '-':
		res = p2 - p1;
		break;
	case '*':
		res = p2 * p1;
		break;
	case '/':
		res = p2 / p1;
		break;
		case '^':
		res = pow(p2,p1);
		break;
      }
      push(res);
    }
  }
  printf("Ans : %d",pop());
}
