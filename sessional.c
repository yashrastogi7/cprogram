#include <stdio.h>
int a[100],b[100];
int main()
{
    int i,n,j,count=0;
    printf("Enter number of elements to be filled in array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!='\0')
        {
            for(j=(i+1);j<n;j++)
            {
                if(a[i]==a[j])
                    a[j]='\0';
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!='\0')
        {
          b[count] =a[i] ;
          count++;
        }

    }
    for(i=0;i<count;i++)
    {
        printf("%d",b[i]);
    }
}
