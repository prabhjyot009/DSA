//Program to sort a sequence of characters given by user in an array, using Quick sort technique.
#include <stdio.h>
#include <stdlib.h>

void quickSort(char A[], int LB, int UB)
{
    int i = LB, j = UB;
    char key = A[LB], t;
    if (LB >= UB)
        return;
    while (i < j)
    {
        while (key >= A[i] && i < j)
            i++;
        while (key < A[j])
            j--;
        if (i < j)
        {
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    A[LB] = A[j];
    A[j] = key;
    quickSort(A, LB, j - 1);
    quickSort(A, j + 1, UB);
}

void main()
{
    char A[] = {'c', 'r', 'e', 'a', 'y', 'b', '\0'};
    int N = 6;
    printf("Before Sorting\n");
    for (int i = 0; i < N; i++)
        printf("%c\t", A[i]);
    printf("\n");
    printf("After Sorting\n");
    quickSort(A, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%c\t", A[i]);
}