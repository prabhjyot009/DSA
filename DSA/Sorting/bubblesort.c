#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubble(int A[],int n)     //array and size.
{
    int i,j;         //flag is initialize for adaptive
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                flag=1;
                swap(&A[j],&A[j+1]);     //Main swapping of bubble.
            }
        }
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10,i;
        bubble(A,10);
            for(i=0;i<10;i++)
                printf(" %d ", A[i]);
                    printf("\n ");
                        return n;
}