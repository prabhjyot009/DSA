//Program to Merge two different single linked lists of different size and sorted values, into a single list.
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int info;
    struct list *next;
} nodetype;

nodetype *insert(nodetype *L, int X)
{
    nodetype *p = NULL;
    p = (nodetype *)malloc(sizeof(nodetype));
    if (p != NULL)
    {
        p->info = X;
        p->next = L;
        L = p;
    }
    return L;
}

nodetype *merge(nodetype *L1, nodetype *L2, nodetype *L3)
{
    while (L1 != NULL && L2 != NULL)
    {
        if (L1->info > L2->info)
        {
            L3 = insert(L3, L1->info);
            L1 = L1->next;
        }
        else
        {
            L3 = insert(L3, L2->info);
            L2 = L2->next;
        }
    }
    while (L1 != NULL)
    {
        L3 = insert(L3, L1->info);
        L1 = L1->next;
    }
    while (L2 != NULL)
    {
        L3 = insert(L3, L2->info);
        L2 = L2->next;
    }
    return L3;
}

void display(nodetype *L)
{
    while (L != NULL)
    {
        printf("%d\t", L->info);
        L = L->next;
    }
}

void main()
{
    nodetype *L1 = NULL, *L2 = NULL, *L3 = NULL;
    L1 = insert(L1, 5);
    L1 = insert(L1, 10);
    L1 = insert(L1, 15);
    L2 = insert(L2, 2);
    L2 = insert(L2, 4);
    L2 = insert(L2, 8);
    L2 = insert(L2, 12);
    printf("Before Merge\n");
    display(L1);
    printf("\n");
    display(L2);
    printf("\nAfter Merge\n");
    L3 = merge(L1, L2, L3);
    display(L3);
}
