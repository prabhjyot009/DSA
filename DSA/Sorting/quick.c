#include<stdio.h>
#define max 50


void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//************************
int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb,end=ub;

    while(start<end)
    {
        while(arr[start]<=pivot)
            start++;

        while (arr[end]>pivot)
            end--;

        if(start<end)
            swap(&arr[end],&arr[start]);
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
    
//**********************soritng starts

void quick_sort(int arr[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(arr,lb,ub);
        quick_sort(arr,loc+1,ub);
        quick_sort(arr,lb,loc-1);
    }
}
//***********************ends
void main()
{
   int arr[max],ub,lb=0;
    printf("\n\nENTER THE LIMIT OF THE ARRAY:");
    scanf("%d",&ub);

    printf("\nNOW ENTER THE %d ELEMENTS IN THE ARRAY:\n",ub);

    for(int i=0;i<ub;i++)
        scanf("%d",&arr[i]);

    quick_sort(arr,lb,ub-1);

    printf("\n\nTHE SOERTED ARRAY:\n");
     for(int i=0;i<ub;i++)
        printf("%d ",arr[i]);
}