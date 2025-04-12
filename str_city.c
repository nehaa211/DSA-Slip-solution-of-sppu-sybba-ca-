#include<string.h>
#include<stdio.h>
void main()
{
    char a[30][30],ch,ele[30];
    int i,n,r,c=0;
    printf("Enter no of citys");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n city name:::");
        scanf("%s",&a[i]);
    }
    printf("\nEntre city to be search");
    scanf("%s",&ele);

    for(i=0;i<n;i++)
    {
        r=strcmp(a[i],ele);
        if(r==0)
           c++;

    }
    if(c==1)
    {
        printf("found");
    }
    else{
        printf("not found");
    }
}
