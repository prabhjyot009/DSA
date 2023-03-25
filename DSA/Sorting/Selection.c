#include<stdio.h>

void main()
{
    int n;
    printf("\n\nENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&n);
    int arr[n],i,j,temp,min;

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
                min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

    printf("\n\nSORTED ARRAY\n");

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}