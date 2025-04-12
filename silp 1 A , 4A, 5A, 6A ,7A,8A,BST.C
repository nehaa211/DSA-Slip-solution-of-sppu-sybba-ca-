
/* Recursive Tree Creation and Display */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

#define M 10

typedef struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
}TREE;
/*-------------------------------------------------------------------*/
void joinNode(TREE *,TREE *);
void inOrder(TREE *);
void preOrder(TREE *);
void postOrder(TREE *);
/*-------------------------------------------------------------------*/
void main()
{
  TREE *root,*temp;
  char ch;
  clrscr();

  root = (TREE *)malloc(sizeof(TREE));
  printf("Enter the data for the root node : ");
  scanf("%d",&root->data);
  root->left = NULL;
  root->right = NULL;

  printf("\nDo u want to continue : ");
  ch = getche();
  while(ch == 'y' || ch == 'Y')
  {
    temp = (TREE *)malloc(sizeof(TREE));
    printf("\nEnter the data for the next node : ");
    scanf("%d",&temp->data);
    temp->left = NULL;
    temp->right = NULL;

    joinNode(root,temp);
    printf("\nDo u want to continue : ");
    ch = getche();
  };

  printf("\n\nInOrder Traversal : ");
  inOrder(root);
  printf("\n\nPreOrder Traversal : ");
  preOrder(root);
  printf("\n\nPostOrder Traversal : ");
  postOrder(root);
  getch();
}
/*-------------------------------------------------------------------*/
void joinNode(TREE *root,TREE *temp)
{
//  char ch;
//  printf("\nEnter l for left & r for right of %d : ",root->data);
//  ch = getche();

//  if(ch == 'l' || ch == 'L')
  if(root->data > temp->data)
  {
    if(root->left == NULL)
    {
      root->left = temp;
    }
    else
    {
      joinNode(root->left,temp);
    }
  }
//  if(ch == 'r' || ch == 'R')
  if(root->data < temp->data)
  {
    if(root->right == NULL)
    {
      root->right = temp;
    }
    else
    {
      joinNode(root->right,temp);
    }
  }
}
/*-------------------------------------------------------------------*/
void inOrder(TREE *t)
{
  if(t != NULL)
  {
    inOrder(t->left);
    printf("%d ",t->data);
    inOrder(t->right);
  }
}
/*-------------------------------------------------------------------*/
void preOrder(TREE *t)
{
  if(t != NULL)
  {
    printf("%d ",t->data);
    preOrder(t->left);
    preOrder(t->right);
  }
}
/*-------------------------------------------------------------------*/
void postOrder(TREE *t)
{
  if(t != NULL)
  {
    postOrder(t->left);
    postOrder(t->right);
    printf("%d ",t->data);
  }
}
/*-------------------------------------------------------------------*/
