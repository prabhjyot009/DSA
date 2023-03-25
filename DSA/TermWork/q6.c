//Program to   create a linked list P, then write a ‘C’ function named split to create two  linked lists Q & R from P So that Q contains all elements in odd positions of P and R contains the remaining elements.
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int info;
    struct list *next;
} nodetype;

nodetype *insert(nodetype *P)
{
    nodetype *t = NULL;
    int X;
    t = (nodetype *)malloc(sizeof(nodetype));
    if (t != NULL)
    {
        printf("Enter Number: ");
        scanf("%d", &X);
        t->info = X;
        t->next = P;
        P = t;
    }
    return P;
}

void split(nodetype *P, nodetype **Q, nodetype **R)
{
    while (P != NULL)
    {
        nodetype *t = (nodetype *)malloc(sizeof(nodetype));
        t->info = P->info;
        if (t->info % 2 != 0)
        {
            t->next = (*Q);
            (*Q) = t;
        }
        else if (t->info % 2 == 0)
        {
            t->next = (*R);
            (*R) = t;
        }
        P = P->next;
    }
    printf("split the list into odd and even linked list\n");
}

void display(nodetype *Q, nodetype *R)
{
    printf("ODD Linked list:\n");
    while (Q != NULL)
    {
        printf("%d\t", Q->info);
        Q = Q->next;
    }
    printf("\nEven Linked list:\n");
    while (R != NULL)
    {
        printf("%d\t", R->info);
        R = R->next;
    }
}

void main()
{
    nodetype *P = NULL, *Q = NULL, *R = NULL;
    int ch;
    do
    {
        printf("\nEnter 1 to insert\nEnter 2 to split\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            P = insert(P);
            break;

        case 2:
            if (P == NULL)
                printf("empty");
            else
                split(P, &Q, &R);
            break;

        case 3:
            if (Q == NULL && R == NULL)
                printf("empty");
            else
                display(Q, R);
            break;
        }
    } while (ch <= 3);
}
