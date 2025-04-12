#include<stdio.h>
#include<conio.h>

void main()
{
    int n,a[20],top=0,i=0,ele=0;
    printf("Enter n");
    scanf("%d",&n);
    printf("\nEnter ele 1");
    scanf("%d",&a[0]);
    for(i=1;i<n;i++)
    {
          printf("\nEnter ele %d::",i);
    scanf("%d",&ele);
    top=i-1;
    while(a[top]>ele)
    {
        a[top+1]=a[top];
        top--;
        if(top==-1)
            break;

    };
    a[top+1]=ele;

    }
    for(i=0;i<n;i++)
        printf("\n%d",a[i]);
}
/*int main()
{
    int i,j=0,x,temp,n,a[20];
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The original array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n");
    printf("\n");
//Insertion Sort Logic
    for(i=0; i<n; i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = temp;
        printf("\n");
        printf("\n");
        for(x=0; x<n; x++)
        {
            printf("\t%d",a[x]);
        }
    }
    printf("\n");
    printf("\n");
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    return 0;
}
*/
