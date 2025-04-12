#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
} node;
void display(struct node*);
struct node *start=NULL, *temp=NULL,*last;
void main()
{
    int num,a,i,j;
    printf("enter the number: ");
    scanf("%d",&num);
    while(num>0)
    {
        a=num%10;
        temp=(struct node *)malloc(sizeof(node));
        temp->next=NULL;
        temp->data=a;
        if(start==NULL)
            start=temp;
        else
        {
            last->next=temp;
        }
        // start->next=temp;
        num=num/10;
        last=temp;
    }
    printf("\n list is ");
    display(start);

}

void display(struct node *start)
{
    int i=1;
    if(start!=NULL)
    {
        display(start->next);
        printf("\n%d is ele at %d",start->data,i);
        i++;
    }
}
