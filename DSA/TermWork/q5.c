//Program to create two link lists positive and negative from a Original linked list, so that positive linked list contains all positive elements and negative linked list contains negative elements.
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int info;
    struct list *next;
} nodetype;

nodetype *insert(nodetype *L)
{
    nodetype *p = NULL;
    int X;
    p = (nodetype *)malloc(sizeof(nodetype));
    if (p != NULL)
    {
        printf("Enter Number: ");
        scanf("%d", &X);
        p->info = X;
        p->next = L;
        L = p;
    }
    return L;
}

void split(nodetype *L, nodetype **P, nodetype **N)
{
    while (L != NULL)
    {
        nodetype *t = (nodetype *)malloc(sizeof(nodetype));
        t->info = L->info;
        if (t->info < 0)
        {
            t->next = (*P);
            (*P) = t;
        }
        else if (t->info >= 0)
        {
            t->next = (*N);
            (*N) = t;
        }
        L = L->next;
    }
    printf("split the list into positive and negative linked list\n");
}

void display(nodetype *P, nodetype *N)
{
    printf("Positive Linked list:\n");
    while (P != NULL)
    {
        printf("%d\t", P->info);
        P = P->next;
    }
    printf("\nNegative Linked list:\n");
    while (N != NULL)
    {
        printf("%d\t", N->info);
        N = N->next;
    }
}

void main()
{
    nodetype *L = NULL, *positive = NULL, *negative = NULL;
    int ch;
    do
    {
        printf("\nEnter 1 to insert\nEnter 2 to split\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            L = insert(L);
            break;

        case 2:
            if (L == NULL)
                printf("empty");
            else
                split(L, &positive, &negative);
            break;

        case 3:
            if (positive == NULL && negative == NULL)
                printf("empty");
            else
                display(positive, negative);
            break;
        }
    } while (ch <= 3);
}
