#include<stdio.h>
void main()
{
    int n;
    printf("\n\nENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&n);
    int arr[n],i,j,temp;
    printf("\n\nENTER THE %d ELEMENTS IN THE ARRAY \n\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    //sorting

    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    printf("\n\nTHE SORTED ARRAY \n\n");
     for(i=0;i<n;i++)
    printf("%d ",arr[i]);

}
void main()
{

    for(i=1;i<n;i++)
    {
        temp=arr[j+1];
        j=i+1;

        while(j<=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}