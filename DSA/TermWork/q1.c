//Program to store N elements to an array and then send all positive elements of the array to the end without altering the original sequence.
#include <stdio.h>
#define max 100

void sort(int[], int);

void main()
{
    int N, A[max];
    printf("Enter range:");
    scanf("%d", &N);
    printf("Enter elements:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    sort(A, N);
    printf("After Sorting:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t", A[i]);
    }
}

void sort(int A[], int N)
{
    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < (N - 1) - i; j++)
        {
            if (A[j] >= 0 && A[j + 1] < 0)
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
