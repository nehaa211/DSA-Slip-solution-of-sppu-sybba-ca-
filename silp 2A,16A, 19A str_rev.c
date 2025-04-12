
//my code
#include <stdio.h>
#include <string.h>
#define MAX 50

int top=0;
char stk[MAX];
void push(char);
char pop();
int isempty();
int isfull();

void main()
{
    char a[MAX],ch;
    int i,j;
    printf("Enter string");
    gets(a);
    /* for(i=0;i<strlen(a);i++)
     {
         ch=a[i];
         push(ch);
     }
      for(i=0;i<strlen(a);i++)
     {
        ch=pop();
        if(ch!=-99)
        {
            printf("%c",ch);
        }
     }*/

     strcat(a," ");
    for(i=0; a[i]!='\0'; i++)
    {
        ch=a[i];
        if(ch!=' ')
        {
            push(ch);
        }
        else
        {
            while(top!=0)
            {
                ch=pop();
                if(ch!=-99)
                {
                    printf("%c",ch);
                }
            }


        }
    }

}
void push(char ch)
{
    if(top==MAX)
    {
        printf("\n stack is full");
    }
    else
    {
        stk[top]=ch;
        top++;
    }
}
char pop()
{
    char c;
    if(top==0)
    {
        printf("\nstk is empty");
        return -99;
    }
    else
    {
        top--;
        c=stk[top];
    }
    return c;
}







//---------------------------==========================--------------------
//Write a 'C' program which accept the string and reverse each word of the string using Static
//implementation of stack.
//Example: Input - This is an input string
//Output - sihTsinatupnignirts

/*#include <stdio.h>
#include <string.h>
#define max 100
int top,stack[max];
void push(char x)
{
    if(top == max-1)
    {
        printf("stack overflow");
    }
    else
    {
        stack[++top]=x;
    }
}
void pop()
{
    printf("%c",stack[top--]);
}
 void main()
{
    char str[]="Testing";
    int len = strlen(str);
    int i;
    for(i=0; i<len; i++)
    {
        push(str[i]);
    }
    printf("\nThis the reversed string: ");
    for(i=0; i<len; i++)
    {
        pop();
    }
}
*/
